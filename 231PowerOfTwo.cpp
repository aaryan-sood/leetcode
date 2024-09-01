// problem link
// https://leetcode.com/problems/power-of-two/description/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int temp=1;
        while(temp != n && temp < n)
        {
            temp=temp<<1;
        }
        return temp == n;
    }
};