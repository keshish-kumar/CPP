//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};

void addNode(Node *head, int pos, int data);

Node *insert(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *n = new Node(x);
    
    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head)
{
  // The purpose of below two loops is
  // to test the created DLL
  Node *temp=head;
  if (temp != NULL) {
    int ct1=0,ct2=0;
  while (temp->next!=NULL)
    temp=temp->next,ct1++;
  while (temp->prev!=NULL)
   temp = temp->prev,ct2++;
   if(ct1!=ct2){
       cout<<-1<<"\n";
       return;
   }
  }
  while (temp != NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  
  cout << endl;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
  Node *head = NULL; 
  Node *root = NULL;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
     int x;
     scanf("%d",&x);
     head = insert(head, x);
     if(root==NULL) root = head;
  }     
  head = root;
  int pos,data;
  cin>>pos>>data;
  addNode(head, pos, data);
  printList(head);
  }
  return 0;
}
// } Driver Code Ends


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
    Node* node = new Node(data);
   Node* temp = head;
   Node* next1 = NULL;
//   if(pos==0){
//       node->next=head;
//       node->prev=NULL;
//       head->prev=node;
//       head=node;
//       return;
//   }
   int count=0;
   
   while(count<pos){
       temp=temp->next;
       count++;
   }
   
   // cout<<count<<temp->data<<endl;
   
   if(temp->next==NULL){
       temp->next=node;
       node->next=NULL;
       node->prev=temp;
   }
   else{
       next1=temp->next;
       temp->next=node;
       node->prev = temp;
       node->next=next1;
       next1->prev=node;
   }
      
}