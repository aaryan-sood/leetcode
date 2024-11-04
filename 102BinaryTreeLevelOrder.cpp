// problem link
// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        else
        {
            vector<vector<int>> ans;
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);

            vector<vector<int>> left=levelOrder(root->left);
            vector<vector<int>> right=levelOrder(root->right);

            for(int i=0;i<max(left.size(),right.size());i++)
            {
                vector<int> current;

                if(i < left.size())
                {
                    current.insert(current.end(),left[i].begin(),left[i].end());
                }
                if(i < right.size())
                {
                    current.insert(current.end(),right[i].begin(),right[i].end());
                }
                ans.push_back(current);
            }
            return ans;
        }
    }
};