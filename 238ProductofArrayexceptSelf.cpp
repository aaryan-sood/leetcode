class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        // calculation of left
        left[0]=1;
        for(int i=1;i<n;i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        //calculation of right
        right[n - 1]=1;
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1] * nums[i + 1];
        }

        //final result
        vector<int> result(n,0);
        for(int i=0;i<n;i++)
        {
            result[i]=left[i] * right[i];
        }
        return result;
    }
};