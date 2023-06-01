class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp,mp2;
        int ss=s.length();
        int ts=t.length();
        if(ss!=ts){
            return false;
        }
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        if(mp==mp2){
            return true;
        }
        else{
            return false;
        }
    }
};