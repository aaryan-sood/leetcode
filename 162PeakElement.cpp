// Problem link
// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // O(N) complexity
        if(nums.size() == 1)
        return 0;

        if(nums[0] > nums[1])
        return 0;

        int n=nums.size();

        if(nums[n-1] > nums[n-2])
        return n-1;

        for(int i=1;i<n-1;i++)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
            {
                return i;
            }
        }
        return n;
    }
};


// O(log(N))
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return 0;
        }

        if(nums[0] > nums[1])
        {
            return 0;
        }

        int n=nums.size();
        if(nums[n-1] > nums[n-2])
        {
            return n-1;
        }

        int left=1,right=n-2;
        int mid;
        while(left <= right)
        {
            mid=left+(right-left)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
                // break;
            }
            else if(nums[mid] > nums[mid-1])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return -1;
    }
};
