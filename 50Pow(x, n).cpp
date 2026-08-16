class Solution {
public:
    double myPow(double x, int n) {
        return helper(x , (long long ) n);
    }
    double helper(double x, long long n){
        if(n == 0 || x == 1) return 1;
        else if(n<0){
            return 1/helper(x,abs(n));
        }
       else if(n%2 == 0){
            x = x * x;
            n = n/2;
            return helper(x,n);
        }
        else{
            n = n-1;
            return helper(x,n)*x;
        }
    }
};