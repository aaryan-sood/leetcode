class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int start=i+1,end=nums.size() - 1;
            while(start < end)
            {
                int sum=nums[i] + nums[start] + nums[end];
                if(sum == 0)
                {
                    ans.push_back({nums[i] , nums[start] , nums[end]});

                    int low=nums[start],high=nums[end];
                    while(start < end && nums[start] == low)
                    {
                        low++;
                    }
                    while(start < end && nums[end] == high)
                    {
                        end--;
                    }
                }
                else if(sum > 0)
                {
                    end--;
                }
                else if(sum < 0)
                {
                    start++;
                }
            }

        }
        return ans;
    }
};
// one more solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size();i++){
            int start = i + 1, end = nums.size() - 1;
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            while(start < end){
                if(nums[i] + nums[start] + nums[end] > 0){
                    end--;
                }
                else if(nums[i] + nums[start] + nums[end] < 0){
                    start++;
                }
                else{
                    vector<int> temp({nums[i], nums[start], nums[end]});
                    ans.push_back(temp);
                    start++;
                    while(nums[start] == nums[start - 1] && start < end){
                        start++;
                    }
                }
            }
        }
        return ans;
    }
};