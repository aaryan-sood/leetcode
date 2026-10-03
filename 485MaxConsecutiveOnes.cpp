// problem link: https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = INT_MIN;
        int consecutive_one = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1){
                consecutive_one++;
            }
            else{
                consecutive_one = 0;
            }
            ans = max(ans, consecutive_one);
        }
        return ans;
    }
};