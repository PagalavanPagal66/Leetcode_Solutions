class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag=0;
        int len=s.length();
        int curlen=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]!=' '){
                flag++;
            }
            if(flag!=0 && s[i]==' '){
                return curlen;
            }
            if(flag!=0){
                curlen++;
            }
        }
        return curlen;
    }
};