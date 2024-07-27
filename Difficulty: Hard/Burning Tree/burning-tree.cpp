//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  void traverse(Node* root, int target, map<Node*,Node*>&mp,map<Node*,int>&visited,Node*& temp){
      if(root==NULL) return;
      
      if(root->data == target) temp = root;
      visited[root] = 0;
      if(root->left != NULL){
          mp[root->left] = root;
          traverse(root->left,target,mp,visited,temp);
      }
      if(root->right != NULL){
          mp[root->right] = root;
          traverse(root->right,target,mp,visited,temp);
      }
      
  }
  
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root==NULL) return 0;
        map<Node*,Node*> mp; // use to store the 
        Node* temp;
        map<Node*,int> visited;
        traverse(root,target,mp,visited,temp);
        
        queue<Node*> q;
        q.push(temp);
        int ans =0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                root = q.front(); q.pop();
                visited[root] =1;
                if(root->left != NULL && visited[root->left]==0){
                    q.push(root->left);
                }
                if(root->right != NULL && visited[root->right]==0){
                    q.push(root->right);
                }
                if(mp.find(root) != mp.end() && visited[mp[root]]==0){
                    q.push(mp[root]);
                }
            }
            ans++;
        }
        
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends