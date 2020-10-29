#include<iostream>
#include<stack>
#define max 10
int top= -1;
using namespace std;
int main()
{
	char exp[max];
	char temp;
	stack<char> st;
	int i,flag=1;
	cout<<" Enter an Expression to be evaluated: ";
	cin>>exp;
	size_t size = sizeof(exp) / sizeof(exp[0]);
	for(i=0;i<size;i++)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
			st.push(exp[i]);
			top++;
		}
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(top==-1)
				flag=0;
			else
			{
				temp=st.top();
				st.pop();
				top--;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(exp[i]==']' && (temp=='(' || temp=='{'))
					flag=0;
			}
		}
	}
	if(top>=0)
		flag=0;
	if(flag==1)
		printf("PARENTHESIS CHECK SUCCESSFULL! VALID EXPRESSION\n");
	else if(flag==0)
		printf("PARENTHESIS CHECK FAILED! INVALID EXPRESSION\n");
}
