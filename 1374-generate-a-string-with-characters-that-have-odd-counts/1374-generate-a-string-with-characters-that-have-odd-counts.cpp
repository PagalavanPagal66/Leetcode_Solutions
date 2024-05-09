class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(n%2==0){
            ans+='a';
            n--;
        }
        while(n--){
            ans+='b';
        }
        return ans;
    }
};