// problem link
// https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        vector<vector<int>> ans(rows,vector<int>(columns,INT_MAX));
        ans[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push(pair<int,pair<int,int>>(0,pair<int,int>(0,0)));
        
        vector<int> dx={0,-1,0,1};
        vector<int> dy={-1,0,1,0};
        
        while(!pq.empty())
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            
            int rootDiff=p.first;
            int i=p.second.first;
            int j=p.second.second;
            
            for(int k=0;k<4;k++)
            {
                int delrow=i+dx[k];
                int delcol=j+dy[k];
                
                if(delrow >=0 && delcol >=0 && delrow < rows && delcol < columns)
                {
                    int tempDiff=abs(heights[i][j] - heights[delrow][delcol]);
                    int effort=max(rootDiff,tempDiff);
                    
                    if(effort < ans[delrow][delcol])
                    {
                        ans[delrow][delcol]=effort;
                        pq.push(pair<int,pair<int,int>>(ans[delrow][delcol],pair<int,int>(delrow,delcol)));
                    }
                }
            }
            
        }
        return ans[rows-1][columns-1];
    }
};