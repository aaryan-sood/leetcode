// problem link
// https://leetcode.com/problems/binary-tree-right-side-view/description/
class Solution {
public:
    void helper(TreeNode *root,int level,vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            if(ans.size() == level)
            {
                ans.push_back(root->val);
            }
            helper(root->right,level+1,ans);
            helper(root->left,level+1,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
       helper(root,0,ans);
       return ans;
    }
};