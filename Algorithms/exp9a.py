from itertools import combinations
from tabulate import tabulate
import numpy as np



def getData():
    n=int(input("Enter the total no. of item sets: "))
    data=[]
    for i in range(n):
        temp=[]
        print("Enter item set",i+1,": ")
        s=input()
        temp=[i for i in s.split(",")]
        data.append(temp)
    print()
    minSupport=float(input("Enter minimum support: "))
    minConf=float(input("Enter minimum confidence: "))
    print()
    for i in range(n):
        print("iteration",i+1,": ",data[i])
    print()
    return minSupport, minConf, data


def makeGroups(c,n):
    x=np.array(c)
    if(x.ndim>1):
        c=sorted(list(set(sum(c,[]))))
    perm=list(combinations(c,n))
    for i in range(len(perm)):
        perm[i]=list(perm[i])
    return perm

def count_(c,d):
    count=[0 for i in range(len(c))]
    for x in c:
        index=c.index(x)
        for i in d:
            check = all(item in i for item in x)
            if(check==True):
                count[index]+=1
    return count

def candidateSet(d,c,ms,it):
    count=count_(c,d)
    print()
    print("C"+str(i))
    print(tabulate(zip(c,count),headers=['Item','Count'],showindex='always',tablefmt='fancy_grid'))
    c = [c[i] for i in range(len(c)) if(count[i]>=ms)]
    count = [i for i in count if(i>=ms)]
    print()
    print("L"+str(i))
    print(tabulate(zip(c,count),headers=['Item','Count'],showindex='always',tablefmt='fancy_grid'))
    print()
    return c,count
 
def rules(l,count,k,v,minConf):
    print("\nAssociation Rules are: ")
    for i in range(len(l)):
        if(len(l[i])==2):
            cnt=count[i]
            sup1=v[k.index(l[i][0].split())]
            sup2=v[k.index(l[i][1].split())]
            conf1=(cnt/sup1)*100
            conf2=(cnt/sup2)*100
            if(conf1>=minConf):
                print(l[i][0].split()," -> ",l[i][1].split()," = ",conf1,"%")
            else:
                print(l[i][0].split()," -> ",l[i][1].split()," = ",conf1,"%(REJECTED!)")
            if(conf2>=minConf):
                print(l[i][1].split()," -> ",l[i][0].split()," = ",conf2,"%")
            else:
                print(l[i][1].split()," -> ",l[i][0].split()," = ",conf2,"%(REJECTED!)")
            continue
        for x in range(1,len(l[i])):
            comb=makeGroups(l[i],len(l[i])-x)
            for j in comb:
                cnt=count[i]
                sup=v[k.index(j)]
                conf=(cnt/sup)*100
                temp=[x for x in l[i] if x not in j]
                if(conf>=minConf):
                    print(j," -> ",temp," = ",conf,"%")
                else:
                    print(j," -> ",temp," = ",conf,"% (REJECTED!)")

minSupport, minConf, data = getData()

c=[[i] for i in sorted(list(set(sum(data,[]))))]
count=l=temp1=temp2=[]
supportList=[]
itemList=[]
i=0
while(True):
    i+=1
    print("Iteration: ",i)
    temp1=l
    temp2=count
    l,count=candidateSet(data,c,minSupport,i)
    itemList.append(l)
    supportList.append(count)
    c=makeGroups(l,i+1)
    if(l==temp1 or l==[]):
        l=temp1
        itemList.append(l)
        count=temp2
        supportList.append(count)
        break
    if(c==[]):
        break
    print()
k=[i for j in itemList for i in j]
v=[i for j in supportList for i in j]
print("Frequent Itemset: ",l)
print("Count: ",count)
print()
print("All itemsets and their support counts: ")
print(tabulate(zip(k,v),headers=['Items','Support Counts'],showindex='always',tablefmt='fancy_grid'))
rules(l,count,k,v,minConf)
