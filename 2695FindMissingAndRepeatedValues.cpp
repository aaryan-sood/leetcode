// time O(n^2) space O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> nums(n * n + 1, 0);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                nums[grid[i][j]]+=1;
            }
        }
        vector<int> ans;
        for(int i = 1;i < n*n + 1;i++){
            if(nums[i] == 2){
                ans.insert(ans.begin(),i);
            }
            else if(nums[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};