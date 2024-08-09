// problem link
// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(pow(nums[i],2));
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
//Alternate Solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0,right=nums.size() - 1;
        vector<int> ans;
        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans.push_back(pow(nums[left++] , 2));
            }
            else
            {
                ans.push_back(pow(nums[right--] , 2));
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
