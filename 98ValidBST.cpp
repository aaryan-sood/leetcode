// problem link
// https://leetcode.com/problems/validate-binary-search-tree/description/
class Solution {
public:
    bool helper(TreeNode *root,long long min,long long max)
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            if(root-> val  >= max || root->val <= min)
            {
                return false;
            }

            return (helper(root->left,min,root->val) && helper(root->right,root->val,max));
        }
    }
    bool isValidBST(TreeNode* root) {
        cout<<INT_MAX;
        return helper(root,LLONG_MIN,LLONG_MAX);
    }
};