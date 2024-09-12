// problem link
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        // adjajency list
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++)
        {
            int first=edges[i][0];
            int second=edges[i][1];
            int weight=edges[i][2];
            adj[first].push_back(pair<int,int>(second,weight));
            adj[second].push_back(pair<int,int>(first,weight));
        }
        
        vector<int> parent(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0,1));
        
        vector<int> distance(n+1,INT_MAX);
        distance[1]=0;
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int rootDistance=p.first;
            int node=p.second;
            
            if(node == n)
            {
                vector<int> path;
                int currentNode=n;
                while(currentNode != -1)
                {
                    path.push_back(currentNode);
                    currentNode=parent[currentNode];
                }
                reverse(path.begin(),path.end());
                path.insert(path.begin(),rootDistance);
                return path;
            }
            
            for(int i=0;i<adj[node].size();i++)
            {
                int tempDistance=adj[node][i].second;
                int temp=adj[node][i].first;
                
                if(rootDistance + tempDistance < distance[temp])
                {
                    distance[temp]= rootDistance + tempDistance;
                    pq.push(pair<int,int>(distance[temp],temp));
                    parent[temp]=node;
                }
            }
        }
        vector<int> ans={-1};
        return ans;
    }
};