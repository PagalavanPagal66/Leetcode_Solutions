class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_map<char,bool>cnt;
        for(int i=0;s[i];i++){
            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                if(cnt[t[i]]){
                    return false;
                }
                mp[s[i]]=t[i];
                cnt[t[i]]=true;
            }
        }
        return true;
    }
};