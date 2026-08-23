// leetcode 75. Sort Colors
// https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero = 0, count_one = 0, count_two = 0;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                count_zero++;
            }
            else if(nums[i] == 1){
                count_one++;
            }
            else{
                count_two++;
            }
        }
        int i = 0;
        while(count_zero > 0){
            nums[i] = 0;
            count_zero--;
            i++;
        }
        while(count_one > 0){
            nums[i] = 1;
            count_one--;
            i++;
        }
        while(count_two > 0){
            nums[i] = 2;
            count_two--;
            i++;
        }
    }
};