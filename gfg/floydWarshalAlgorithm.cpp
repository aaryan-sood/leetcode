class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    vector<vector<int>> distance(n,vector<int>(n,1e8));
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j] == -1)
	            {
	                continue;
	            }
	            else
	            {
	                distance[i][j]=matrix[i][j];
	            }
	        }
	    }
	    
	   // calculating the distance 2D array
	   
	   for(int var=0;var<n;var++)
	   {
	       for(int i=0;i<n;i++)
	       {
	           for(int j=0;j<n;j++)
	           {
	               int temp=distance[i][var] + distance[var][j];
	               distance[i][j] = min(distance[i][j],temp);
	           }
	       }
	   }
	    
	   // substituting INT_MAX for -1
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(distance[i][j] == 1e8)
	            {
	                distance[i][j]=-1;
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            matrix[i][j]=distance[i][j];
	        }
	    }
	}
};