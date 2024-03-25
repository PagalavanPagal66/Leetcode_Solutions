class Solution {
public:
    int f(int i, char start, char end , vector<string>&words,vector<vector<vector<int>>>&dp){
        if(i>=words.size()) return 0;
        if(dp[i][start-'a'][end-'a']!=-1) return dp[i][start-'a'][end-'a'];
        int first=0,second=0,third;
        if(words[i][0]==end){
            first= 1+f(i+1,start,words[i][words[i].size()-1],words,dp);
        }else{
            first = f(i+1,start,words[i][words[i].size()-1],words,dp);
        } 
        if(words[i][words[i].size()-1]==start){
            second=1+f(i+1,words[i][0],end,words,dp);
        }else{
            second=f(i+1,words[i][0],end,words,dp);
        }
        return dp[i][start-'a'][end-'a']=max(first,second);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n= words.size();
        string target = words[0];
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(26,vector<int>(26,-1)));
        int c= f(1,target[0],target[target.size()-1],words,dp);
        int total=0;
        for(auto it: words){
            total+=it.size();
        }
        return total-c;
    }
};