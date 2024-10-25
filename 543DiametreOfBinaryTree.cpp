// problem link
// https://leetcode.com/problems/diameter-of-binary-tree/description/
class Solution {
public:
    int helper(TreeNode *root,int &ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int left=helper(root->left,ans);
            int right=helper(root->right,ans);
            ans=max(ans,left+right);
            return 1+max(left,right);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};