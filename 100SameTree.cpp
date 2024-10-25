// problem link
// https://leetcode.com/problems/same-tree/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        else if((!p && q) || (p && !q))
        {
            return false;
        }
        else
        {
            bool left=isSameTree(p->left,q->left);
            bool right=isSameTree(p->right,q->right);

            if(left && right)
            {
                if(p->val == q->val)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

    }
};