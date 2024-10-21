// problem link
// https://leetcode.com/problems/invert-binary-tree/description/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
        {
            return root;
        }
        else
        {
            TreeNode *righttemp=invertTree(root->right);
            TreeNode *lefttemp=invertTree(root->left);

            root->right=lefttemp;
            root->left=righttemp;
            return root;
        }
    }
};