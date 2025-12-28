#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string str1 = "brute";
    string str2 = "groot";
    int index1 = str1.length();
    int index2 = str2.length();

    vector<vector<int>> dp(index1 + 1 , vector<int>(index2 + 1, 0));

    for(int i = 1;i <= index1;i++){

        for(int j = 1;j <= index2;j++){

            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }

    int j = index2, i = index1 ;
    string lcs = "";
    while(i > 0 && j > 0){
        if(str1[i - 1] == str2[j - 1]){
            lcs = lcs + str1[i - 1];
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<lcs<<endl;
    reverse(lcs.begin(), lcs.end());
    cout<<lcs<<endl;
    return 0;
}