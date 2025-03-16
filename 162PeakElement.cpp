// Problem link
// https://leetcode.com/problems/find-peak-element/
// O(log(N))
class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int start = 0,end = nums.size() - 1;
            while(start < end)
            {
                int mid = (end - start)/2 + start;
                if(nums[mid] > nums[mid+1])
                {
                    end = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
            return start;
        }
    };
