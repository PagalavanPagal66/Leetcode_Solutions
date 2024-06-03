class Solution {
public:
    int appendCharacters(string s, string t) {
        int tind=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[tind]){
                tind++;
            }
            if(tind==t.size()){
                return 0;
            }
        }
        return t.size()-tind;
    }
};