class Solution {
public:
    string predictPartyVictory(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int r=0;
        int d=0;
        for(int i=0;i<n;i++){
                mp[s[i]]++;
        }
        for(int i=0;i<n;i++){     
            for(int j=0;j<n;j++){
            if(mp['R']==0 && mp['D']!=0)return "Dire";
            if(mp['D']==0 && mp['R']!=0)return "Radiant";
                if(s[j]=='R'){
                    if(r>0){
                        r--;
                        s[j]='o';

                        continue;
                    }else{
                        d++;
                        mp['D']--;
                    }
                }else if(s[j]=='D'){
                    if(d>0){
                        d--;
                        s[j]='o';
                        continue;
                    }else{
                        r++;
                        mp['R']--;
                    }
                }
            }
        }
        string a="";
         if(mp['R']==0 && mp['D']!=0)a= "Dire";
        else if(mp['D']==0 && mp['R']!=0)a= "Radiant";
        return a;
    }
};