class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        int ans;
        for(int i = 0; i < nums.size();i++){
            if(temp[nums[i]] > 0){
                ans = nums[i];
            }
            temp[nums[i]]++;
        }
        return ans;
    }
};