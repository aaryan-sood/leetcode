#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
// O(n^3)
int maximumSubarray(vector<int> input)
{
    int n=input.size();
    int ans=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        
        for(int j=i;j < n;j++)
        {
            int curr=0;
            for(int k=i;k <= j;k++)
            {
                curr+=input[k];
            }
            ans=max(curr,ans);
        }
    }
    return ans;
    
}
// O(n^2)
int maximumSubarrayOptimised(vector<int> input)
{
    int ans=INT_MIN;
    int n=input.size();
    for(int i = 0;i < n;i++)
    {
        int curr=0;
        for(int j=i;j < n;j++)
        {
            curr+=input[j];
            ans=max(ans,curr);
        }
    }
    return ans;
}
// Kadane's Algorithm
// O(n)
int kadanes_algo(vector<int> input)
{
    int sum=0;
    int ans=INT_MIN;
    for (int i = 0; i < input.size(); i++)
    {
        sum+=input[i];
        if(sum > ans)
        {
            ans=sum;
        }
          if(sum < 0)
        {
            sum=0;
        }
    }
    return ans;
    
}
int main()
{
    vector<int> input;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    cout<<"maximum subarray : "<<maximumSubarray(input)<<endl; 
    cout<<"maximum subarray : "<<maximumSubarrayOptimised(input)<<endl; 
    cout<<"maximum subarray : "<<kadanes_algo(input)<<endl;

    return 0;
}