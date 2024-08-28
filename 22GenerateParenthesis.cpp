class Solution {
public:
    // brute force solution
    bool isValid(string curr_str)
    {
        cout<<curr_str<<" ";
        int left_count=0;
        for(int i=0;i<curr_str.size();i++)
        {
            if(left_count < 0)
            {
                return false;
            }
            if(curr_str[i] == '(')
            {
                left_count++;
            }
            else
            {
                left_count--;
            }
        }
        return left_count == 0;
    }
    vector<string> generateParenthesis(int n) {
        queue<string> q;
        vector<string> ans;
        q.push("");
        while(!q.empty())
        {
            string curr_str=q.front();
            q.pop();
            if(curr_str.length() == 2*n)
            {
                if(isValid(curr_str))
                {
                    ans.push_back(curr_str);
                }
            }
            else
            {
                string left=curr_str + '(';
                string right=curr_str + ')';
                q.push(left);
                q.push(right);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void backtracking(vector<string> &answer,string curr_str,int leftCount,int rightCount,int n)
    {
        if(curr_str.size() == 2 * n)
        {
            answer.push_back(curr_str);
            return;
        }
        else
        {
            if(leftCount < n)
            {
                backtracking(answer,curr_str+'(',leftCount+1,rightCount,n);
            }
            if(leftCount > rightCount)
            {
                backtracking(answer,curr_str+')',leftCount,rightCount+1,n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        // optimised approach backtracking
        vector<string> answer;
        string curr_str="";
        backtracking(answer,curr_str,0,0,n);
        return answer;
    }
};
