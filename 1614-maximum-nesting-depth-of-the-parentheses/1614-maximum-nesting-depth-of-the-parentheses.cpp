class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        for(auto i:s){
            if(i=='('){
                st.push(i);
                int t = st.size();
                ans =max(ans,t);
            }
            if(i==')'){
                st.pop();
            }
        }
        return ans;
    }
};