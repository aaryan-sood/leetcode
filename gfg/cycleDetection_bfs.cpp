class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int src,vector<int> adj[],vector<int> &visited)
    {
        visited[src]=1;
        queue<pair<int,int>> q;
        q.push(pair<int,int>(src,-1));

        while(!q.empty())
        {
            int node=q.front().first;
            int parent =q.front().second;
            q.pop();

            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i];
                if(!visited[temp])
                {
                    q.push(pair<int,int>(temp,node));
                    visited[temp]=1;
                }
                else if(visited[temp] && temp != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here

        vector<int> visited(V,0);
        // return isCycle(0,adj,visited);

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(isCycle(i,adj,visited))
                {
                    return true;
                }
            }
        }
        return false;

    }
};
