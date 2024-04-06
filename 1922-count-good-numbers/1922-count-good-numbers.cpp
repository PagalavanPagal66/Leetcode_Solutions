class Solution {
public:
    int mod = 1e9+7;

    int fn(long long n){
        if(n == 2){
            return 5*4;
        }
        if((n/2)%2 == 0){
            long long ans1 = fn(n/2);
            return (1LL * ans1 * ans1)%mod ;
        }else{
            long long ans1 = fn((n-2)/2);
            return ((ans1%mod * ans1%mod)%mod * 20)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        int ans = 1 ;
        if(n==1){
            return 5;
        }
        if(n == 2){
            return 5*4;
        }
        if(n==3){
            return 5*4*5;
        }
        if(n%2 == 0){
            return fn(n);
        }else{
            return (1LL*(fn(n-1)%mod)*5)%mod;
        }
    }
};