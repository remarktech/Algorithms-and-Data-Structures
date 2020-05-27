#include <bits/stdc++.h>
struct Node
{
	int data;
	struct Node * next;
	struct Node * bottom;
	Node (int x)
	{
		data = x;
		next = NULL;
		bottom = NULL;
	}
};

using namespace std;


void print_arr(int *arr,int n){
	for(int i=0;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void printList(Node *Node)
{
	while (Node != NULL)
	{
		printf("%d ", Node->data);
		Node = Node -> bottom;
	}
}

Node *flatten(Node *root)
{
    Node *temp=root;
    priority_queue <int,vector<int>,greater<int> > q;
    while(temp){
        Node *curr=temp;
        while(curr){
            q.push(curr->data);
            curr=curr->bottom;
        }
        temp=temp->next;
    }
    root=NULL;
    temp=NULL;
    while(!q.empty()){
        if(!root){
            root=new Node(q.top());
            temp=root;
            q.pop();
        }
        else{
            temp->bottom=new Node(q.top());
            temp=temp->bottom;
            q.pop();
        }
    }
    return root;
    
}
int main(void) 
 {
 	
 	FILE *fp;
	string name;
	int arr[100000] ={0};
	int arr2[100000] = {0};
	char c;
	int flag=0,num1 =0,i=0,n=0,cnt=1,j=0;
 
	 fp=fopen("C:\\Users\\anmol\\OneDrive\\Desktop\\coding\\flattering\\inputfile.txt","r");
	 c=fgetc(fp);
 
 	while(c!=EOF)
	{
	    if(c==' ' && cnt ==2)  
	    i++;
	    else if (c==' ' && cnt ==3)
	    j++;
	    
	    if(flag ==0)
		{
			num1 = (num1*10)+(c-48);
		}
	    else if(c!=' ' && cnt == 2)
	    {
	    	arr[i] = (arr[i]*10)+(c-48);
		}
		else if (c!=' ')
		{
			arr2[j] = (arr2[j]*10)+(c-48);
		}
		
	    c=fgetc(fp);
	    if(c=='\n'){
	    	cnt++;
	    	c=fgetc(fp);
	      	flag =1;
	  	}
  }
  fclose(fp);
  cout<<num1<<endl;
  print_arr(arr,i);
  print_arr(arr2,j);
 	
		int m,flag1=1;
		flag=1;
		struct Node	*temp=NULL;
		struct Node	*head=NULL;
		struct Node	*pre=NULL;
		struct Node	*tempB=NULL;
		struct Node	*preB=NULL;
			
		n= num1;
		int j1=0;

		for (int i=0;i<n;i++){
			m=arr[i];
			--m;
			int data = arr2[j1++];
			temp = new Node (data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag)
			{
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else
			{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for (int j=0;j<m;j++)
			{
				int temp_data=arr2[j1++];
				
				tempB = new Node (temp_data);
				
				if(flag1)
				{
					temp->bottom = tempB;
					preB = tempB;
					flag1 = 0;
				}
				else
				{
					preB->bottom = tempB;
					preB = tempB;
				}
			}			
						
		}
			
		Node *fun = head;
		Node *fun2 = head;
		
		Node* root = flatten (head);
		printList(root);
		cout<<endl;
return 0;
 }	
				
