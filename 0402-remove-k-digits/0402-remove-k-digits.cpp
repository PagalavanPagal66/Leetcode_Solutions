class Solution {
public:
    string removeKdigits(string num, int k) {
  stack<char>st;
  for(char & ch :num){
    while(k>0  && !st.empty() &&st.top()>ch ){
        st.pop();
        k--;  
  }
   st.push(ch);
  }
// if every time top ele is < ele to be inserted
  while(k>0 && !st.empty()){
    st.pop();
    k--;
  }
  string ans;
while(!st.empty()){
    ans+=st.top();
    st.pop();
}
reverse(ans.begin(),ans.end());
// removing the prceeding zeros.
int i=0;
while(ans[i]=='0')
    i++;
ans.erase(0,i);
if(ans.size()==0)
ans.push_back('0');

return ans;
    }
};