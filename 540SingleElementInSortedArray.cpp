// problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};