//Method 1
Node* LCA(Node *root, int n1, int n2)
{
    if(n1<root->data and n2<root->data)
    {
        return LCA(root->left,n1,n2);
    }
    else if(n1>root->data and n2>root->data)
    {
        return LCA(root->right,n1,n2);
    }
    else
    {
        return root;
    }
}

//Method 2
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data==n1 || root->data==n2)
        {
            return root;
        }
        Node* ld=lca(root->left,n1,n2);
        Node* rd=lca(root->right,n1,n2);
        if(ld!=NULL and rd!=NULL)
        {
            return root;
        }
        else if(ld!=NULL)
        {
            return ld;
        }
        else
        {
            return rd;
        }
    }
};

//Method 3
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,bool &f1,bool &f2) {
        if(!root) return NULL;
        else if(root==p){
            f1 = true;
            return root;
        }
        else if(root==q){
            f2 = true;
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q,f1,f2);
        TreeNode* right = lowestCommonAncestor(root->right,p,q,f1,f2);
        
        if(!left && !right) return NULL;
        else if(left && right) return root;
        else return left ? left:right;
    }
    bool findNode(TreeNode* root,TreeNode* target){
        if(root==NULL){
            return false;
        }
        if(root==target){
            return true;
        }
        return findNode(root->left,target)||findNode(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || !p || !q){
            return NULL;
        }
        bool f1=false ,f2=false;
        TreeNode* temp = lowestCommonAncestor(root,p,q,f1,f2);
        if(!temp) return NULL;
        if(f1 && !f2 && !findNode(temp,q)) return NULL;
        if(!f1 && f2 && !findNode(temp,p)) return NULL;
        return temp;
    }
};
