#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct ll
{
	int data;
	struct ll *next;
};
struct ll *head=NULL;
int main(){
	int n,i,val=0,sum=0;
	struct ll *ptr,*new_node;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new_node = (struct ll*)malloc(sizeof(struct ll));
		scanf("%d", &val);
		new_node->data=val;
		if(head==NULL)
		{
			new_node->next=NULL;
			head=new_node;		
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
		}
	}
	ptr=head;
	printf("\n[ ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		sum +=((ptr->data) * (pow(2,(n-1))));
		n--;
		ptr=ptr->next;
	}
	printf("]\n");
	printf("Integer: %d \n",sum);
	return 0;
}
