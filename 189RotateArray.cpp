// leetcode problem link
// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// OR
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size(), -1);

        for(int i = 0;i < nums.size();i++){
            temp[i] = nums[i];
        }

        for(int i = 0;i < nums.size();i++){
            nums[(i + k) % nums.size()] = temp[i];
        }


    }
};