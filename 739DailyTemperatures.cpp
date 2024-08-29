class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // brute force will give tle
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
            for(int j=i+1;j < temperatures.size();j++)
            {
                if(temperatures[j] - temperatures[i] > 0)
                {
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // optimised approach using monotonic stack
        stack<int> s;
        vector<int> ans(temperatures.size());
        for(int i=0;i<temperatures.size();i++)
        {
            while(!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;


    }
};
