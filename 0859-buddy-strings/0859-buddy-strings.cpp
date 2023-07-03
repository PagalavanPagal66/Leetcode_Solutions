class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        vector<int>mp(26,0);
        vector<int>mp2(26,0);
        for(auto i:s){
            mp[i-'a']++;
        }
        for(auto i:goal){
            mp2[i-'a']++;
        }
        if(mp!=mp2){
            return false;
        }
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                temp++;
            }
            if(temp>2){
                return false;
            }
        }
        int flag=0;
        for(auto i:mp){
            if(i>=2){
                flag++;
            }
        }
        if(temp==0 && flag!=0){
            return true;
        }
        else if(temp==0 && flag==0){
            return false;
        }
        return true;
    }
};