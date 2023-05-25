//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<string> ans;
long long precedence(char op){
if(op == '+'||op == '-')
return 1;
if(op == '*'||op == '/')
return 2;
return 0;
}
long long applyOp(long long a, long long b, char op){
switch(op){
case '+': return a + b;
case '-': return a - b;
case '*': return a * b;
case '/': return a / b;
}
}
long long evaluate(string tokens){
int i;
stack <long long> values;
stack <char> ops;
for(i = 0; i < tokens.length(); i++){
if(tokens[i] == ' ')
continue;
else if(tokens[i] == '('){
ops.push(tokens[i]);
}
else if(isdigit(tokens[i])){
long long val = 0;
while(i < tokens.length() && isdigit(tokens[i]))
{
val = (val*10) + (tokens[i]-'0');
i++;
}
values.push(val);
i--;
}
else if(tokens[i] == ')')
{
while(!ops.empty() && ops.top() != '(')
{
long long val2 = values.top();
values.pop();
 
long long val1 = values.top();
values.pop();
 
char op = ops.top();
ops.pop();
 
values.push(applyOp(val1, val2, op));
}
if(!ops.empty())
ops.pop();
}
else
{
while(!ops.empty() && precedence(ops.top())>= precedence(tokens[i])){
long long val2 = values.top();
values.pop();
 
long long val1 = values.top();
values.pop();
 
char op = ops.top();
ops.pop();
 
values.push(applyOp(val1, val2, op));
}
ops.push(tokens[i]);
}
}
while(!ops.empty()){
long long val2 = values.top();
values.pop();
 
long long val1 = values.top();
values.pop();
 
char op = ops.top();
ops.pop();
 
values.push(applyOp(val1, val2, op));
}
return values.top();
}
 
    void find(int target,string s1,int j,bool fl)
    {
        if(j==s1.length()-1)
        {
            if(evaluate(s1)==target)
            ans.push_back(s1);
            return;
        }
            string s2=s1,s3=s1,s4=s1;
            if(fl==false || s1[j]!='0')
            find(target,s1,j+1,false);
            s2.insert(j+1,"*");
            find(target,s2,j+2,true);
            s3.insert(j+1,"+");
            find(target,s3,j+2,true);
            s4.insert(j+1,"-");
            find(target,s4,j+2,true);
        
    }
  public:
    vector<string> addOperators(string S, int target) {
        find(target,S,0,false);
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends