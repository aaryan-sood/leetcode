//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int> &newArr,vector<vector<int>> &dp,int sum1,int target,int index,int m)
    {
        if(sum1 == target)
        {
            return 1;
        }
        if(sum1 > target || index >= m)
        {
            return 0;
        }
        if(dp[sum1][index] != -1)
        {
            return dp[sum1][index];
        }
        else
        {
            int include = helper(newArr,dp,sum1+newArr[index],target,index + 1,m);
            int exclude = helper(newArr,dp,sum1,target,index + 1,m);
            return dp[sum1][index]=include + exclude;
        }
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        vector<int> newArr;
        int count = 0;
        int n=arr.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
            {
                count++;
            }
            else
            {
                newArr.push_back(arr[i]);
            }
        }
        if((sum + d) % 2 != 0)
        {
            return 0;
        }
        
        int target = (sum + d)/2; 
        int m = newArr.size();
        
        vector<vector<int>> dp(target+1,vector<int>(m,-1));
        
        int ans = helper(newArr,dp,0,target,0,m);
        
        return (1 << count) * ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends