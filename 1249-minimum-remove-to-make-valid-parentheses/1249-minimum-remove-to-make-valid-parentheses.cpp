class Solution {
public:
string minRemoveToMakeValid(string s) {
        stack<char> s1;
        stack<int> s2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s1.push(s[i]);
                s2.push(i);
            }
            else if(s[i]==')'){
                if(s1.empty()){
                    s.erase(s.begin()+i);
                    i--;
                }
                else{
                    s1.pop();
                    s2.pop();
                }
            }
        }
        if(!s1.empty()){
            while(!s2.empty()){
                int pos=s2.top();
                s2.pop();
                s1.pop();
                s.erase(s.begin()+pos);
            }
        }
        return s;
    }
};