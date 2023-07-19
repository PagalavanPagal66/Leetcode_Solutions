class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(!st.empty() && st.top()=='(' && i==')'){
                st.pop();
                continue;
            }
            st.push(i);
        }
        return st.size();
    }
};