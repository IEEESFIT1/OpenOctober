
d= 0.85 #damping factor

PR=[]
page_matrix =[]


no_of_pages =int(input('Enter no of pages'))
#initial PR = 1
for i in range (no_of_pages):
    PR.append(1)

#accept in bount and out bounds for each page
def matrixInitilization():

    for i in range(no_of_pages):
        temp =[]
        for j in range(no_of_pages):
            val =int(input(f'if link between {i} and {j} enter 1 else 0 '))
            temp.append(val)
        page_matrix.append(temp)    

#printing matrix
def printMatrix():
    for i in range(no_of_pages):
        for j in range(no_of_pages):
            print(page_matrix[i][j],end=" ")
        print()
#calculating PR for each page
def calculatePR():
    for i in range(no_of_pages):
        pr =0
        count_incoming =[]
        count_outgoing ={}
        # PR_val_for_current_page=[]
        for j in range(no_of_pages):
            if page_matrix[j][i] == 1:
                count_incoming.append(j)
                out=no_of_outbount_link(j)
                count_outgoing.update({j:out})
        
        for k in range(len(count_incoming)):
            
            pr += PR[count_incoming[k]]/count_outgoing[count_incoming[k]]
        PR[i]= 1-d +( d*(pr))    

def no_of_outbount_link(page):
    count_outgoing=0
    for i in range(no_of_pages):
        if page_matrix[page][i] ==1:
            count_outgoing+=1
    return count_outgoing


matrixInitilization()
printMatrix()
for i in range(2):
    print(PR)
    calculatePR()
print(f'Final PR :{PR}')