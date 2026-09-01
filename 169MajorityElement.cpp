// hashmap approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i < n;i++){
            map[nums[i]]+=1;
            if (map[nums[i]] > n / 2){
                ans = nums[i];
            }
        }
        return ans;
    }
};
// sorting approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};