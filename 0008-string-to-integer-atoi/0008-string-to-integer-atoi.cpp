class Solution {
public:
    int myAtoi(string s) {
        int i = 0, flag = 0;
        while(i < s.size()) {
            if(s[i] == ' ') i++;   
            else break;       
        }
        if(s[i] == '-') {
            flag = 1;
            i++;
        }
        else if(s[i] == '+') i++;

        long long num = 0;
        for(int j=i; j<s.size(); j++) {
            if(s[j] >= '0' and s[j] <= '9') {
                num = num * 10 + (s[j] - '0');
                if(num >= INT_MAX) break;   
            }
            else break;
        }
        
        if(flag) num *= -1;
        if(num <= INT_MIN) return INT_MIN;
        else if(num >= INT_MAX) return INT_MAX;
        return num;
    }
};