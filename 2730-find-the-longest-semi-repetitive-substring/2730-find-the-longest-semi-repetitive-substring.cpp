class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans=0;
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            stack<int>st;
            int cc=0;
            cnt=0;
            for(int j=i;j<n;j++){
                if(!st.empty() && st.top()==s[j]){
                    cc++;
                }
                st.push(s[j]);
                if(cc==2){
                    break;
                }
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};