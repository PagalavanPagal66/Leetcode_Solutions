class Solution {
public:
    int maxF(map<char,int>&mp){
        int mx=0;
        for(auto it:mp)
            mx=max(mx,it.second);
        return mx;
    }
    int characterReplacement(string s, int k) {
        int mx=0;
        map<char,int>mp;
        int n=s.size();
        int start=0,end=0;
        while(end<n){
            mp[s[end]]++;
            int mf=maxF(mp);
            int len = end-start+1;
            if(len-mf<=k)
                mx=max(mx,len);
            else{
                mp[s[start]]--;
                start++;
            }
            end++;
        }
        return mx;
    }
};