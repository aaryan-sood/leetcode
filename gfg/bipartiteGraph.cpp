// problem link
// https://www.geeksforgeeks.org/problems/bipartite-graph/1
class Solution {
public:
    bool bfs(queue<int> &q,vector<int> adj[],vector<int> &color)
    {
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i];
                if(color[temp] == -1)
                {
                    color[temp]=!color[node];
                    q.push(temp);
                }
                else if(color[temp] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i] == -1)
	        {
	            color[i]=0;
	            q.push(i);
	            if(bfs(q,adj,color) == false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};