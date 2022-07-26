class Solution{
  public:
    void solve(Node *root, int len, int x, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->data==x)
        {
            len++;
        }
        else
        {
            len=1;
        }
        ans=max(ans,len);
        solve(root->left,len,root->data+1,ans);
        solve(root->right,len,root->data+1,ans);
    }
    int longestConsecutive(Node* root)
    {
         if(root==NULL)
         {
             return 0;
         }
         int ans=0;
         solve(root,0,root->data,ans);
         if(ans<2)
         {
             return -1;
         }
         return ans;
    }
};
