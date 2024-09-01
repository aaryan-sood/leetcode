class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        // elements are marked visited once they are put inside of the queue and before putting any element back into to the queue we check has it been already visited 
        
        vector<int> bfs;
        queue<int> q;
        
        vector<int> visited(V,0);
        
        q.push(0);
        visited[0]=1;
        
        while(!q.empty())
        {
            int node =q.front();
            bfs.push_back(node);
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i];
                if(!visited[temp])
                {
                    q.push(temp);
                    visited[temp]=1;
                    
                }
            }
        }
        return bfs;
    }
};