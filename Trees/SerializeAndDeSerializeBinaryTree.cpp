//Method 1
class Codec {
public:
    string s;
    void preorder(TreeNode* root)
    {
        if(!root)
        {
            s+='n';
            s+=',';
            return;
        } 
        s+=to_string(root->val);
        s+=',';
        preorder(root->left);
        preorder(root->right);
    }
    
    string serialize(TreeNode* root) 
    {    
        if(!root)
        {
            return "";
        }
        s="";
        preorder(root);
        return s;
    }
    // Decodes your encoded data to tree.
    int i;
    TreeNode* solve(string s,int n)
    {
        string t="";
        for(i;i<n;i++)
        {
            if(s[i]==',')
                break;
            t+=s[i];
        }
        i++;
        if(t=="n")
            return NULL;
        TreeNode *root=new TreeNode(stoi(t));
        root->left=solve(s,n);
        root->right=solve(s,n);
        return root;
    }
    
    TreeNode* deserialize(string s) 
    {
        if(s.size()==0)
            return NULL;
        int n=s.size();  
        i=0;
        return solve(s,n);
    }
};

//Method 2
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void find(Node *root, vector<int> &vec)
    {
        if(root==NULL)
        {
            vec.push_back(-1);
            return;
        }
        vec.push_back(root->data);
        find(root->left,vec);
        find(root->right,vec);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> vec;
        find(root,vec);
        return vec;
    }
    
    //Function to deserialize a list and construct the tree.
    Node *cal(vector<int> &a,int &i)
    {
        if(a.size()==i || a[i]==-1)
        {
            i++;
            return NULL;
        }
        Node *temp=new Node(a[i]);
        i++;
        temp->left=cal(a,i);
        temp->right=cal(a,i);
        return temp;
    }
    Node * deSerialize(vector<int> &A)
    {
       int i=0;
       return cal(A,i);
    }

};

//Method 3
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
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
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        queue<Node*> q;
        vector<int> v;
        if(!root)
        {
            v.push_back(-1);
            return v;
        }
        q.push(root);
        v.push_back(root->data);
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            if(front->left)
            {
                q.push(front->left);
                v.push_back(front->left->data);
            }
            else
                v.push_back(-1);
            if(front->right)
            {
                q.push(front->right);
                v.push_back(front->right->data);
            }
            else
                v.push_back(-1);
        }
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        //Your code here
        Node *root;
        if(A[0] == -1)
        {
            root = NULL;
            return root;
        }
        root = new Node(A[0]);
        queue<Node*> q;
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            if(A[i+1] != -1)
            {
                front->left = new Node(A[i+1]);
                q.push(front->left);
            }
            else
                front->left = NULL;
            if(A[i+2] != -1)
            {
                front->right = new Node(A[i+2]);
                q.push(front->right);
            }
            else
                front->right = NULL;
            i += 2;
        }
        return root;
    }

};

// { Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    _deleteTree(node->left);  
    _deleteTree(node->right);  
  
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;  
    delete node;  
}  
  
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout << "\n";

    }


    return 0;
}  // } Driver Code Ends
