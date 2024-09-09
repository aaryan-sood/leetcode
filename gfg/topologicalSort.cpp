class Solution
{
    private:
    void dfs(int node,vector<int> adj[],vector<int> &visited,stack<int> &topoSort)
    {
        visited[node]=1;
        
        for(int i=0;i<adj[node].size();i++)
        {
            int temp=adj[node][i];
            
            if(visited[temp] == 0)
            {
                dfs(temp,adj,visited,topoSort);
            }
        }
        
        topoSort.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V,0);
	    stack<int> topoSort;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(i,adj,visited,topoSort);
	        }
	    }
	    
	    vector<int> ans;
	    while(!topoSort.empty())
	    {
	        ans.push_back(topoSort.top());
	        topoSort.pop();
	    }
	    return ans;
	    
	}
};