// problem link
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<vector<int>> adj(n);
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n,0);
        vector<int> distance(n,-1);
        distance[src]=0;
        queue<pair<int,int>> q;
        visited[src]=1;
        q.push(pair<int,int>(src,0));
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            int  node=p.first;
            int dist=p.second;
            distance[node]=dist;
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i];
                if(!visited[temp])
                {
                    q.push(pair<int,int>(temp,dist+1));
                    visited[temp]=1;
                }
                
            }
        }
        
        return distance;
    }
};