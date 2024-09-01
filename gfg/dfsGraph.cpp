class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void helper(int node,vector<int> adj[],vector<int> &dfs,vector<int> &visited)
    {
        visited[node]=1;
        dfs.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            int temp=adj[node][i];
            if(!visited[temp])
            {
                // visited[temp]=1;
                helper(temp,adj,dfs,visited);
            }
            
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V,0);
        vector<int> dfs;
         
        helper(0,adj,dfs,visited);
        return dfs;
    }
};