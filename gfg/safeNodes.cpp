// problem link
// https://www.geeksforgeeks.org/problems/eventual-safe-states/1
class Solution {
  private:
  bool dfs(int node,vector<int> &visited,vector<int> &pathVisited,vector<int> &safeNodes,vector<int> adj[])
  {
      visited[node]=1;
      pathVisited[node]=1;
      
    //   check for the adjacent nodes
      for(int i=0;i<adj[node].size();i++)
      {
          int temp=adj[node][i];
          if(visited[temp] == 0)
          {
              if(dfs(temp,visited,pathVisited,safeNodes,adj))
              {
                  return true;
              }
          }
          else if(pathVisited[temp] == 1)
          {
              return true;
          }
      }
      
    //   if not returned true yet means none of it's adjacent nodes form a cycle
    
     pathVisited[node]=0;
     safeNodes.push_back(node);
     return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        
        vector<int> safeNodes;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,pathVisited,safeNodes,adj);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};