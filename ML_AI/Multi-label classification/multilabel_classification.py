import numpy as np
from sklearn.pipeline import Pipeline
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.svm import LinearSVC
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.multiclass import OneVsRestClassifier
from sklearn import preprocessing
from sklearn.metrics import accuracy_score
from sklearn.cross_validation import train_test_split
from sklearn.metrics import precision_recall_curve
from sklearn.metrics import average_precision_score
import matplotlib.pyplot as plt
from nltk.corpus import stopwords
from sklearn.feature_selection import SelectKBest, chi2
from sklearn.linear_model import SGDClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.linear_model import RidgeClassifier
from sklearn.metrics import f1_score
from sklearn.naive_bayes import MultinomialNB
from sklearn.pipeline import make_pipeline

X_train = np.array(["new york is a hell of a town",
                    "new york was originally dutch",
                    "the big apple is great",
                    "new york is also called the big apple",
                    "nyc is nice",
                    "people abbreviate new york city as nyc",
                    "the capital of great britain is london",
                    "london is in the uk",
                    "london is in england",
                    "london is in great britain",
                    "it rains a lot in london",
                    "london hosts the british museum",
                    "new york is great and so is london",
                    "i like london better than new york"])
y_train_text = [["new york"],["new york"],["new york"],["new york"],["new york"],
                ["new york"],["london"],["london"],["london"],["london"],
                ["london"],["london"],["new york","london"],["new york","london"]]



lb = preprocessing.MultiLabelBinarizer()

# Run classifier
stop_words = stopwords.words('english')

classifier=make_pipeline(CountVectorizer(),
						TfidfTransformer(),
						#SelectKBest(chi2, k=4),
						OneVsRestClassifier(SGDClassifier())) 

#combined_features = FeatureUnion([("pca", pca), ("univ_select", selection)])


random_state = np.random.RandomState(0)
# Split into training and test
X_train, X_test, y_train, y_test = train_test_split(X_train, y_train_text, test_size=.3,
                                                    random_state=random_state)

# Binarize the output classes
Y = lb.fit_transform(y_train)
Y_test=lb.transform(y_test)

classifier.fit(X_train, Y)
y_score = classifier.fit(X_train, Y).decision_function(X_test)
print "y_score"+str(y_score)


predicted = classifier.predict(X_test)
all_labels = lb.inverse_transform(predicted)

#print accuracy_score
print "accuracy : "+str(accuracy_score(Y_test, predicted))

print "micro f-measure "+str(f1_score(Y_test, predicted, average='micro'))


for item, labels in zip(X_test, all_labels):
    print '%s => %s' % (item, ', '.join(labels))


# Compute micro-average ROC curve and ROC area
precision_micro, recall_micro, _ = precision_recall_curve(Y_test.ravel(),y_score.ravel())
average_precision_micro = average_precision_score(Y_test, y_score,average="micro")

print "precision : "+str(precision_micro)+",recall :"+str(recall_micro)+"average precision"+str(average_precision_micro)


# Compute Precision-Recall and plot curve
n_classes = Y.shape[1]
precision = dict()
recall = dict()
average_precision = dict()
for i in range(n_classes):
    print Y_test[:,i]
    print y_score[:,i]
    precision[i], recall[i], _ = precision_recall_curve(Y_test[:, i],
                                                        y_score[:, i])
    #print "here"
    print precision[i]
    average_precision[i] = average_precision_score(Y_test[:, i], y_score[:, i])
    print average_precision[i]


# Plot Precision-Recall curve
plt.clf()
plt.plot(recall[0], precision[0], label='Precision-Recall curve')
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.ylim([0.0, 1.05])
plt.xlim([0.0, 1.0])
plt.title('Precision-Recall example: AUC={0:0.2f}'.format(average_precision[0]))
plt.legend(loc="lower left")
plt.show()


# Plot Precision-Recall curve for each class
plt.clf()
plt.plot(recall_micro, precision_micro,
         label='micro-average Precision-recall curve (area = {0:0.2f})'
               ''.format(average_precision_micro))
for i in range(n_classes):
    plt.plot(recall[i], precision[i],
             label='Precision-recall curve of class {0} (area = {1:0.2f})'
                   ''.format(i, average_precision[i]))

plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.title('Extension of Precision-Recall curve to multi-class')
plt.legend(loc="lower right")
plt.show()
