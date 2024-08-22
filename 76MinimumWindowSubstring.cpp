class Solution {
public:
    string minWindow(string s, string t) {
        // Brute force solution
        if(t.size() > s.size()) return "";

        int startIndex=0;
        int minlen=INT_MAX;

        for(int i=0;i<s.size();i++)
        {
            vector<int> map(256,0);
            int count=0;
            for(int j=0;j<t.size();j++)
            {
                map[t[j]]++;
            }

            for(int j=i;j<s.size();j++)
            {
                if(map[s[j]] > 0)
                {
                    count++;
                }
                map[s[j]]--;

                if(count == t.size())
                {
                    if(j-i+1 < minlen)
                    {
                        minlen=min(minlen,j-i+1);
                        startIndex=i;
                    }

                }
            }
        }
        cout<<minlen;
        if(minlen == INT_MAX)
        return "";
        return s.substr(startIndex,minlen);
    }
};
