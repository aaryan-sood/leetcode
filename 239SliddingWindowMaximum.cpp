// problem link
// https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force
        int n=nums.size();
        int left=0;
        int right=k-1;
        vector<int> ans;
        while(right < n)
        {
            int max=INT_MIN;
            for(int i=left;i<=right;i++)
            {
                if(nums[i] > max)
                {
                    max=nums[i];
                }
            }
            ans.push_back(max);
            left++;
            right++;
        }
        return ans;
    }
};
// optimised approach
// sliding window
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
