class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> distance(V,1e8);
        distance[S]=0;
        
        for(int i=0;i<V-1;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                if(distance[edges[j][0]] != 1e8 && (distance[edges[j][0]] + edges[j][2] < distance[edges[j][1]]))
                {
                    distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
                }
            }
        }
        
        // nth relaxation to check negative cycle
        
        for(int i=0;i<edges.size();i++)
        {
            if(distance[edges[i][0]] != 1e8 && (distance[edges[i][0]] + edges[i][2] < distance[edges[i][1]]))
            {
                return {-1};
            }
        }
        return distance;
        
        
    }
};