# coding: utf-8

#import the necessary packages
import pandas as pd
import numpy as np
from sklearn.externals import joblib 

from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.compose import ColumnTransformer

import keras
from keras.models import Sequential
from keras.layers import Dense, Dropout

from keras.wrappers.scikit_learn import KerasClassifier
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import GridSearchCV


#import the dataset using pandas library
df = pd.read_csv("Churn_Modelling.csv")

#selecting the input features and the targets
df_x = df.iloc[:, 3:13]
df_y = df.iloc[:, 13]

# df.isna().sum()

#cleaning the dataset
def clean_data(df):

    le = LabelEncoder()
    df.Gender = le.fit_transform(df.Gender)
    df = pd.get_dummies(data = df, columns=["Geography"], drop_first = False)
    df = df.sort_index(axis=1)
    return df

df_x = clean_data(df_x)
# df_x.head()

# columnTransformer = ColumnTransformer([('encoder', OneHotEncoder(), [1])], remainder='passthrough')
# col_tnf = columnTransformer.fit_transform(df_x)
# df_x = np.array(col_tnf, dtype = np.str)
# df_x = df_x[:, 1:]

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(df_x, df_y, test_size = 0.2, random_state = 0)
joblib.dump(X_train.columns, "columns.pkl")

#scaling the data to avoid hierarchies
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
joblib.dump(scaler, "std_scaler.pkl")
print(X_test)
print(X_train.shape[1])





#displaying results
def generate_report():
    # predicting values
    y_pred = classifier.predict(X_test)
    print("\nPredicted values: "+str(y_pred)+"\n")
    y_pred = (y_pred > 0.5)
    
    # Making the Confusion Matrix
    from sklearn.metrics import confusion_matrix
    cm = confusion_matrix(y_test, y_pred)
    accuracy = (cm[0,0]+cm[1, 1])/(cm[0,0]+cm[1, 1]+cm[1,0]+cm[0, 1])
    print("\nTest Accuracy: "+str(accuracy)+"\n")
    






# Build basic ANN model 
def build_model():
    classifier = Sequential()
    classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu', input_dim = X_train.shape[1]))
    classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu'))
    classifier.add(Dense(units = 1, kernel_initializer = 'uniform', activation = 'sigmoid'))
    classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])
    return classifier
classifier = build_model()
classifier.fit(X_train, y_train, batch_size = 10, epochs = 30)
generate_report()






# Implementing K-fold Cross validation

def build_model():
    classifier = Sequential()
    classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu', input_dim = X_train.shape[1]))
    classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu'))
    classifier.add(Dense(units = 1, kernel_initializer = 'uniform', activation = 'sigmoid'))
    classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])
    return classifier
classifier = KerasClassifier(build_fn = build_model, batch_size = 10, epochs = 40)
accuracy_list = cross_val_score(estimator = classifier, X = X_train, y = y_train, cv = 10)
mean_acc = accuracy_list.mean()
std_acc = accuracy_list.std()
print(mean_acc, std_acc)

classifier.fit(X_train, y_train)
generate_report()








# implement Hyperparameter tuning for getting better accuracy using Grid Search
def build_model(optimizer):
    classifier = Sequential()
    classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu', input_dim = X_train.shape[1]))
    classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu'))
    classifier.add(Dense(units = 1, kernel_initializer = 'uniform', activation = 'sigmoid'))
    classifier.compile(optimizer = optimizer, loss = 'binary_crossentropy', metrics = ['accuracy'])
    return classifier
classifier = KerasClassifier(build_fn = build_model)
parameters = {"batch_size": [5, 15, 30], 
              "epochs": [30, 100],
              "optimizer": ["adam", "rmsprop"]}
grid_search = GridSearchCV(estimator = classifier,
                           param_grid = parameters,
                           scoring = "accuracy",
                           cv=10)
grid_search = grid_search.fit(X_train, y_train)
best_parameters = grid_search.best_params_
best_accuracy = grid_search.best_score_
print(best_parameters, best_accuracy)
generate_report()





# save the model so created above into a pickle file.
joblib.dump(classifier, 'prediction_classifier.pkl')