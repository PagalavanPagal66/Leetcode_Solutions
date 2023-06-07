class Solution {
public:
    bool isValid(string s) {
    stack<char> stack;
    for(int i=0; i< s.size() ; i++)
    {
        if(stack.size()>0)
        {
            if((stack.top()=='(' && s[i]==')') || (stack.top()=='[' && s[i]==']') || (stack.top()=='{' && s[i]=='}'))
            {
                stack.pop();  //this is pair existing condition
                continue;
            }
        }
        stack.push(s[i]); //is pair exist this statement should not be executed
    } 
    if(stack.empty()) 
        return true;
    return false;
}
};