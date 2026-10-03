// problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// not in place solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            if(map.contains(nums[i])){
                continue;
            }
            else{
                ans.push_back(nums[i]);
            }
            map[nums[i]] += 1;

        }

        for(int i = 0;i < ans.size();i++){
            nums[i] = ans[i];
        }
        return ans.size();
    }
};
// in place solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,j = 1;
        while(j < nums.size()){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};