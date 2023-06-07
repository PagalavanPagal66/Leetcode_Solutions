class Solution {
public:
    long int evalRPN(vector<string>& tokens) {
        stack<long int> stack;

        for(auto curr:tokens){
          if(curr=="+"){
            long int x = stack.top(); stack.pop();
            long int y = stack.top(); stack.pop();
            stack.push(x+y);
          }
          else if(curr=="-"){
            long int x = stack.top(); stack.pop();
            long int y = stack.top(); stack.pop();
            stack.push(y-x);
          }
          else if(curr=="*"){
            long int x = stack.top(); stack.pop();
            long int y = stack.top(); stack.pop();
            stack.push(x*y);
          }
          else if(curr=="/"){
            long int x = stack.top(); stack.pop();
            long int y = stack.top(); stack.pop();
            stack.push(y/x);
          }
          else{
            stack.push(stoi(curr));
          }
        }
        return stack.top();
    }
};