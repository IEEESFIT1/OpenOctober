import math

lst = []

# number of elements as input
n = int(input("Enter number of objects : "))


# iterating till the range
for i in range(0, n):
    item = int(input())
 
    lst.append(item) # adding the element
     
print(lst)

k =int(input("Enter number of clusters: "))


data = [float(n())]
centroids = dict(zip(range(k), data[0:k]))
clusters = dict(zip(range(k), [[] for i in range(k)]))
point_assignments = dict(zip(range(k), [[] for i in range(k)]))
old_point_assignments = dict()
real_point_assignments = dict(zip(data, [0 for i in range(len(data))]))

def assign_to_clusters(data, clusters, centroids, point_assignments):
  for i in data:
   closest_index = 0
   dist_to_centroid = 100
   for j in centroids:
    if abs(i - centroids[j]) < dist_to_centroid:
     closest_index = j
     dist_to_centroid = abs(i - centroids[j])
     clusters[closest_index].append(i)
     real_point_assignments[i] = closest_index


def assign_to_centroids(data, clusters, centroids):
  for n in clusters:
   clust_sum = sum(clusters[x])
   avg = float(clust_sum / len(clusters[n]))
   centroids[n] = min(clusters[n], key=lambda y:abs(y-avg))
   counter = 0
   
while point_assignments != old_point_assignments:
    
  old_point_assignments = point_assignments
  
  assign_to_clusters(data, clusters, centroids, point_assignments)
  
  assign_to_centroids(data, clusters, centroids)
  
  point_assignments = clusters
  clusters = dict(zip(range(k), [[] for i in range(k)]))
  counter += 1
  print("Iteration %d" % counter)
  for n in point_assignments:
    print("%d [%s]" % (n, str(point_assignments[n]).strip("[]")))
  print()
 
newline_counter = 0
for n in real_point_assignments:
  print("Point %s in cluster %d" % (str(x).rstrip("0"), real_point_assignments[x]))
  newline_counter += 1
  if newline_counter < len(data):
    outputFile.write("Point %s in cluster %d\n" % (str(n).rstrip("0"), real_point_assignments[x]))
  else:
    outputFile.write("Point %s in cluster %d" % (str(n).rstrip("0"), real_point_assignments[x]))
    inputFile.close()
    outputFile.close()
