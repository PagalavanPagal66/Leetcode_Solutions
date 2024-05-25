class Solution {
public:
    void solve(int ind,string temp, string s,vector<string>&ans, map<string,int>& mp,string str){
        //cout<<temp<<" ";
        if(ind==s.length()){
            if(mp.count(temp)!=0){
                ans.push_back(str+temp);
                return;
            }
            return;
        }
        if(mp.count(temp)!=0){
            string empty = "";
            empty+=s[ind];
            solve(ind+1,empty,s,ans,mp,str+temp+" ");
        }
        string t = temp+s[ind];
        solve(ind+1,t,s,ans,mp,str);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        map<string,int>mp;
        for(auto i:wordDict){
            mp[i]++;
        }
        string temp="";
        string str="";
        solve(0,temp,s,ans,mp,str);
        return ans;
    }
};