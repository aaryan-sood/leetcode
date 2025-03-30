// problem link
// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
    public:
        int search(vector<int>& nums, int target) {
    
            int start = 0,end = nums.size() - 1,mid;
    
            while(start < end)
            {
                mid = (end-start)/2 + start;
                if(nums[start] <= nums[mid])
                {
                    if(target >= nums[start] && target <= nums[mid])
                    {
                        end = mid;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
                else
                {
                    if(nums[mid] <= target && target <= nums[end])
                    {
                        start = mid;
                    }
                    else
                    {
                        end = mid;
                    }
                }
            }
            // cout<<nums[start]<<" "<<nums[mid]<<" "<<nums[end];
            return nums[start] == target ? start : -1;
        }
    };