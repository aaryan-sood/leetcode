// problem link
// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n=arr.size();
        
        vector<int> distance(100000,INT_MAX);
        distance[start]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int steps=p.first;
            int num=p.second;
            for(int i=0;i<n;i++)
            {
                int temp=(num * arr[i]) % 100000;
                if(steps + 1 < distance[temp])
                {
                    distance[temp]=steps+1;
                    pq.push({steps + 1,temp});
                }
            }
        }
        if(distance[end] == INT_MAX)
        {
            return -1;
        }
        return distance[end];
    }
};