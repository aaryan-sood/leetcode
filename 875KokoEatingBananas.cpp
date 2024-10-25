// problem link
// https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
public:

    long isenough(vector<int> piles,int k)
    {
        long ans=0;
        for(int i=0;i<piles.size();i++)
        {
            ans+=(piles[i]/k);
            if(piles[i] % k != 0)
            {
                ans++;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int result=right;
        while(left <= right)
        {
            int mid=left+(right-left)/2;
            long required=isenough(piles,mid);
            if(required <= h)
            {
                result=mid;
                right=mid-1;
            }
            else if(required > h)
            {
                left=mid+1;
            }
        }
        return result;
    }
};
