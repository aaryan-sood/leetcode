#include<iostream>
#include<bits/stdc++.h>
#include<typeinfo>
using namespace std ;
int main()
{
    // n nodes and m edges
    // int n,m;
    // cin >>n>>m;
    // vector<vector<int>> adj(n+1,vector<int> (n+1,0));
    // graph stored adjaceny matrix
    // for (int i = 0; i < m; i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }

    // vector<vector<int>> list(n+1);      //Space O(2*E)
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     list[u].push_back(v);
    //     list[v].push_back(u);
    // }

    // print the graph
    // for(int i=0;i<n+1;i++)
    // {
    //     for(int j=0;j<list[i].size();j++)
    //     {
    //         cout<<list[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // vector<char> temp;
    // temp.push_back('0');
    // temp.push_back('1');

    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout<<temp[i] - '0'<<" ";
    // }

    // char temp='a';
    // char ne=temp+25;
    // cout<<ne<<endl;
    // char ne=temp-97;
    // cout<<ne+97;
    // vector<int> ans;

    // ans.push_back(temp);
    string temp="hit";
    cout<<typeid(temp[0]).name()<<endl;
    temp[0]=temp[0]+10;
    cout<<temp;

    
    return 0;
}