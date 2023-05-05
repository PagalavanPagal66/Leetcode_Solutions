class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int ans=0,maxi=0,count=0;
        int start=0,end=k-1;
        
        for(int i=start;i<=end;i++){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    count++;
                }
        }
        maxi=max(maxi,count);
        start++;
        end++;
        
        while(end<n){
            if(s[start-1]=='a' || s[start-1]=='e' || s[start-1]=='i' || s[start-1]=='o' || s[start-1]=='u'){
                    count--;
                }
             if(s[end]=='a' || s[end]=='e' || s[end]=='i' || s[end]=='o' || s[end]=='u'){
                    count++;
                }
            start++;
            end++;
            maxi=max(maxi,count);

        }
        return maxi;
    
    }
};