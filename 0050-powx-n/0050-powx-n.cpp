class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        else{
            return pow(x,n);
        }
        return 1;
    }
    double pow(double x,long long n){
        if(n==0){
            return 1;
        }
        if(n<0){
            n=-n;
            x=1/x;
        }
        if(n%2==0){
            return pow(x*x,n/2);
        }
        else{
            return x*pow(x,n-1);
        }
        return x;
    }
};