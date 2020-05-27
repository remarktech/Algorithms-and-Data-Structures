#include<iostream>
#include<string.h>
#include <fstream>
using namespace std;

struct node
{
	int data;
	struct node *next = NULL;
};

struct node *q1 = NULL;
struct node *q2 = NULL;

void print(struct node *start)
{
	struct node *ptr = start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void print_arr(int *arr,int n){
	for(int i=0;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

struct node *create_new_node_back(struct node *start,int num)
{
	struct node *n,*ptr;
		n=new node;
		n->data=num;
		n->next=NULL;
		if(!start)
		start=n;
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=n;
		}
	return start;
}

struct node *insert_all(struct node *q1,struct node *q2)
{
	struct node *ptr=q1;
	while(ptr!=NULL)
	{
		q2 = create_new_node_back(q2,ptr->data);
		ptr=ptr->next;
	}
	return q2;
}

struct node * merge_both(struct node *q1,struct node *q2)
{
	struct node *ptr =q2;
	while(ptr!=NULL)
	{
		q1 = create_new_node_back(q1,ptr->data);
		ptr = ptr->next;
	}
	return q1;
}

void push(int num)
{

	if(q1!=NULL)
	q2 = insert_all(q1,q2);

	
	q1 =  NULL;
	q1 = create_new_node_back(q1,num);
	q1 = merge_both(q1,q2);
	q2 = NULL;
}

void pop()
{
	if(q1==NULL)
	cout<<"-1 ";
	else
	{
	cout<<q1->data<<" ";
	q1=q1->next;
	}
}

int main(){
	
FILE *fp;
  string name;
  int arr[100000] ={0};
  char c;
  int flag=0,num1 =0,i=0,n=0;
 
 fp=fopen("C:\\Users\\bipul\\OneDrive\\Desktop\\coding\\inputfile.txt","r");
 c=fgetc(fp);
 
 while(c!=EOF){
    if(c==' ')
    i++;
    
    if(flag ==0)
	{
		num1 = (num1*10)+(c-48);
	}
    else if(c!=' ')
    {
    	arr[i] = (arr[i]*10)+(c-48);
	}
	
    c=fgetc(fp);
    if(c=='\n'){
    	c=fgetc(fp);
      	flag =1;
  	}
  }
  fclose(fp);
 
	int num,opt,elmt;
	num = num1;
	while(num>0)
	{
		opt = arr[n++];
		
		if(opt == 1)
		{
			elmt = arr[n++];
			push(elmt);
		}
		else
		{
			pop();
		}
		/*cout<<"Final q1"<<endl;
		print(q1);*/
		num--;
	}
	
	return 0;
	
}
