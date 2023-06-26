class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;  
        unordered_map<char,int> m;   
        int i=0,j=0,ans=INT_MIN; 
        while(j<s.length())   
        {
            m[s[j]]++;  
            if(m.size()==j-i+1)  
            {
                ans = max(ans,j-i+1); 
            }
            else if(m.size()<j-i+1)   
            {
                while(m.size()<j-i+1)  
                {
                    m[s[i]]--;   
                    if(m[s[i]]==0)  
                    {
                        m.erase(s[i]);
                    }
                    i++;   
                }
            }
             j++; 
        }
        return ans;
    }
};