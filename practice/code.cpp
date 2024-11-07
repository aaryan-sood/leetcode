#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> inorder={9,3,15,20,7};
    vector<int> preorder={3,9,20,15,7};
    vector<int> temp;
    temp.insert(temp.end(),preorder.begin()+1+1,preorder.end());
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }
    
    return 0;
}