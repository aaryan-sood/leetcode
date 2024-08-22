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
// slidding window
// class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int left=0,right=0;
        int minlen=INT_MAX;
        int startIndex=-1;

        for(int i=0;i<t.size();i++)
        {
            hash[t[i]]++;
        }

        int count=0;
        while(right < s.size())
        {
            if(hash[s[right]] > 0)
            {
                count++;
            }
            hash[s[right]]--;
            while(count == t.size())
            {
                if(right-left+1 < minlen)
                {
                    minlen=right-left+1;
                    startIndex=left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
            right++;
        }
       if(startIndex == -1)
       {
            return "";
       }
       return s.substr(startIndex,minlen);
    }
};
