class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>present(3,0);
        int n=s.length();
        int i=0,j=0;
        int count=0;
        while(j<n){
            present[s[j]-'a']++;
            while(present[0]>0 && present[1]>0 && present[2]>0){
                count+=n-j;
                present[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};