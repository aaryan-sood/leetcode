// problem link
// https://leetcode.com/problems/balanced-binary-tree/description/
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            int left=height(root->left);
            int right=height(root->right);
            return max(right,left) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            if(isBalanced(root->left) && isBalanced(root->right))
            {
                int left=height(root->left);
                int right=height(root->right);
                if(abs(left - right) > 1)
                {
                    return false;
                }
                else
                {
                    return true;
                } 
            }
            else
            {
                return false;
            }
            
        }
    }
};