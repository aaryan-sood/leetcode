// problem link
// https://www.geeksforgeeks.org/problems/alien-dictionary/1
class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<vector<int>> adj(k);
        vector<int> indegree(k,0);
        int secondIndex=1;
        
        // making the adjaceny list
        while(secondIndex < n)
        {
            string first=dict[secondIndex-1];
            string second=dict[secondIndex];
            int i=0;
            while(i < first.size() && i < second.size() && first[i] == second[i])
            {
                i++;
            }
            if(i < first.size() && i < second.size())
            {
                adj[first[i] - 'a'].push_back(second[i] - 'a');

            }
            secondIndex++;
        }
        
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int temp=adj[i][j];
                indegree[temp]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        string ans="";
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i];
                indegree[temp]--;
                if(indegree[temp] == 0)
                {
                    q.push(temp);
                }
            }
            
            ans+=(char)(node + 'a');
        }
        
        return ans;
        
    }
};