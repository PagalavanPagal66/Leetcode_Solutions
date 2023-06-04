const int MOD = 1e9 + 7;
int dp[405][23][2];
typedef long long int ll;
class Solution {
public:
    ll add(ll a, ll b){
        return ((a%MOD) + (b%MOD))%MOD;
    }
    ll sub(ll a, ll b){
        return ((a%MOD) - (b%MOD) + MOD)%MOD;
    }
    ll helper(string &s, ll sum, ll ind, bool tight, ll mn, ll mx){
        if(sum < 0)return 0;
        if(ind == s.length())return (sum >= mn && sum <= mx);
        if(dp[sum][ind][tight] != -1)return dp[sum][ind][tight];
        ll ans = 0;
        ll d = tight?(s[ind] - '0'):9;
        for(ll i = 0; i <= d; i++){
            ans = add(ans, helper(s, sum + i, ind + 1, (tight && (i == d)), mn, mx));
        }
        return dp[sum][ind][tight] = ans%MOD;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        ll ans = 0;
        memset(dp, -1, sizeof dp);
        ans = add(ans, helper(num2, 0, 0, true, min_sum, max_sum));
        memset(dp, -1, sizeof dp);
        ans = sub(ans, helper(num1, 0, 0, true, min_sum, max_sum));
        ll sum = 0;
        for(auto i : num1)sum += (i - '0');
        if(sum >= min_sum && sum <= max_sum)ans= add(ans, 1);
        return ans;
    }
};