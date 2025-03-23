// problem link
// https://leetcode.com/problems/koko-eating-bananas/description/
class Solution {
    public:
        long long countHours(vector<int> &piles,int mid)
        {
            long long ans = 0;
            for(int i=0;i<piles.size();i++)
            {
                ans+=ceil((double)piles[i]/mid);
            }
            return ans;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int start = 1,end = *max_element(piles.begin(),piles.end());
            long long mid;
            while(start <= end)
            {
                mid = (end-start)/2 + start;
                long long hours = countHours(piles,mid);
                if(hours <= h)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            return start;
        }
    };