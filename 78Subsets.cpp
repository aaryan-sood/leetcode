class Solution {
public:
    vector<vector<int>> helper(int i, int n, vector<int> temp, vector<int> nums){
        if(i < 0){
            vector<vector<int>> ans;
            ans.push_back(temp);
            return ans;
        }
        else{
            vector<vector<int>> without = helper(i - 1, n, temp, nums);
            temp.push_back(nums[i]);
            vector<vector<int>> with = helper(i - 1, n, temp, nums);
            vector<vector<int>> ans;
            for(int i = 0;i < with.size();i++){
                ans.push_back(with[i]);
            }

            for(int i = 0;i < without.size();i++){
                ans.push_back(without[i]);
            }
            return ans;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        return helper(n - 1, n, vector<int>({}), nums);
    }
};