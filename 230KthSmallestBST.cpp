// problem link
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    void inorder(TreeNode *root,vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        return ans[k-1];
    }
};