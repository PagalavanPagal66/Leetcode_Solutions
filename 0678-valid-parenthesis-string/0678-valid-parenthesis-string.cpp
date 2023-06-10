class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> open,star;  
        for(int i = 0 ; i < n ; i++)      
        {
            
            if(s[i] == '(')        
                open.push(i);
            else if (s[i]=='*')  
                star.push(i);
            else                   
            {
                if(open.size())           
                    open.pop();
                else if(star.size())     
                    star.pop();
                else 
                {
                    return false ;             
                }
            }   
        }
        if(open.size()==0)           
            return true;
        while(open.size() && star.size())  {         
            int i = open.top();
            if( i > star.top())          
                return false;
            else
            {
                open.pop();          
                star.pop();
            }
        }
        if(open.size()==0)
            return true;
        return false;  
    }
};