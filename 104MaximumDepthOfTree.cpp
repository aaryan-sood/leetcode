// problem link
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        else if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            int leftHeight=maxDepth(root->left);
            int rightHeight=maxDepth(root->right);
            return (rightHeight > leftHeight) ? rightHeight+1 : leftHeight+1;
        }
    }
};