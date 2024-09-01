#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    // n nodes and m edges
    int n,m;
    cin >>n>>m;
    // vector<vector<int>> adj(n+1,vector<int> (n+1,0));
    // graph stored adjaceny matrix
    // for (int i = 0; i < m; i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }

    vector<vector<int>> list(n+1);      //Space O(2*E)
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    // print the graph
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<list[i].size();j++)
        {
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }


    
    return 0;
}