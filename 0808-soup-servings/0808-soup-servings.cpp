class Solution {
private:
     double help(int A, int B, unordered_map<int, unordered_map<int, double>> &dp){
        if(A <= 0) return B <= 0 ? 0.5 : 1.0;
        if(B <= 0) return 0.0;

        if(dp.find(A) != dp.end() && dp.at(A).find(B) != dp.at(A).end())
            return dp.at(A).at(B);


        double ans = help(A - 100, B, dp);
        ans += help(A - 75, B - 25, dp);
        ans += help(A - 50, B - 50, dp);
        ans += help(A - 25, B - 75, dp);

        return dp[A][B] = 0.25 * ans;
    }   
    
public:
    double soupServings(int n){
        if(n > 4750) return 1;

        unordered_map<int, unordered_map<int, double>> dp;
        return help(n, n, dp);
    }
};