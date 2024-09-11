class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0,S));
        
        vector<int> distance(V,INT_MAX);
        distance[S]=0;
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int node=p.second;
            int rootDistance=p.first;
            
            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i][0];
                int tempDistance=adj[node][i][1];
                
                if(rootDistance + tempDistance < distance[temp])
                {
                    distance[temp]=rootDistance + tempDistance;
                    pq.push(pair<int,int>(distance[temp],temp));
                }
            }
        }
        return distance;
        
    }
};