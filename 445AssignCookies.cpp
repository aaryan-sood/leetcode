class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

         int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = n < m ? n : m;
        int ans = 0;
        for(int i = 0;i < count; i++){
            if(s[i] >= g[i]){
                ans++;
            }
        }
        return ans;
    }
};