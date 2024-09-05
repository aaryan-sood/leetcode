// problem link
// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
class Solution {
    
  private : 
  void dfs(int i,int j,int baserow,int basecol,vector<vector<int>> &grid,vector<vector<int>> &visited,vector<pair<int,int>> &vec)
  {
      visited[i][j]=1;
      vec.push_back(pair<int,int>(i-baserow,j-basecol));
      
      vector<pair<int,int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
      
      int n=grid.size();
      int m=grid[0].size();
      
      for(int k=0;k<4;k++)
      {
          int delrow=i+directions[k].first;
          int delcol=j+directions[k].second;
          
          if(delrow >= 0 && delcol >= 0 && delrow < n && delcol < m)
          {
              if(grid[delrow][delcol] == 1 && !visited[delrow][delcol])
              {
                  dfs(delrow,delcol,baserow,basecol,grid,visited,vec);
              }
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,i,j,grid,visited,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};