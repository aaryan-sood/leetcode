// problem link
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        
        for(int i=0;i<edges.size();i++)
        {
            
            adj[edges[i][0]].push_back(pair<int,int>(edges[i][1],edges[i][2]));
        }
        vector<int> distance(N,INT_MAX);
        
        vector<int> visited(N,0);
        visited[0]=1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0,0));
        
        distance[0]=0;
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int rootDistance=p.first;
            int node=p.second;
            
            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i].first;
                int tempDistance=adj[node][i].second; 
                visited[temp]=1;
                if(rootDistance + tempDistance < distance[temp])
                {
                    distance[temp]=rootDistance + tempDistance;
                    pq.push(pair<int,int>(distance[temp],temp));
                }
            }
        }
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                distance[i]=-1;
            }
        }
        return distance;
    }
};