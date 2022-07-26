class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        {
            return NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *tmp=q.front();
            q.pop();
            swap(tmp->left,tmp->right);
            if(tmp->left)
            {
                q.push(tmp->left);
            }
            if(tmp->right)
            {
                q.push(tmp->right);
            }
        }
        return root;
    }
};
