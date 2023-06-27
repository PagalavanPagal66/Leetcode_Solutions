class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;   // there is no string, how to form a substring
        unordered_map<char,int> m;   //matching character with integers
        int i=0;  //left border
        int j=0; // right border
        int ans=INT_MIN;  // taking the minimal value among the integer
        while(j<s.length())   // for (j = 0 ; j < n ; j++)
        {
            m[s[j]]++;        // marking the j th indexed character as seen
            if(m.size()==j-i+1)  //comparing the map size -> unique elements is equal to the number of characters in that string . So  no where repeatation occurs.
            {
                ans = max(ans,j-i+1);
                // ans = max(ans,mp.size());
            }
            else if(m.size()<j-i+1)   // map size is lesser than the characters count in that substring. Somewhere repeatation occurs. Whenever repeatation occurs the map will go to the same character to map twice. so this change occurs. 
            {
                while(m.size()<j-i+1)  // untill the repeatation is happening we are reducing the left border 
                {
                    m[s[i]]--; // we have to reduce the count of the characters outside the leftborder    
                    if(m[s[i]]==0)  // we have no characters
                    {
                        m.erase(s[i]); // we are totally removing that character key pair from that map
                    }
                    i++;   //moving the left border towards the right 
                }
            }
            j++; 
        }
        return ans;
    }
};