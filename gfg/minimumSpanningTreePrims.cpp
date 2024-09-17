class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int> visited(V,0);
        
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        
        int mstWeight=0;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            
            int weight=p.first;
            int node=p.second.first;
            int parent=p.second.second;
            
            if(visited[node] == 0)
            {
                for(int i=0;i<adj[node].size();i++)
                {
                    int temp=adj[node][i][0];
                    int tempDistance=adj[node][i][1];
                    if(!visited[temp])
                    {
                        pq.push({tempDistance,{temp,node}});
                    }
                }
                if(parent != -1)
                {
                    mstWeight+=weight;
                }
                visited[node]=1;
            }
        }
        return mstWeight;
        
    }
};