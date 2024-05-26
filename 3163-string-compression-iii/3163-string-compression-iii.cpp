class Solution {
public:
    string compressedString(string word) {
        int ctr=1,ind=1;
        string ans="";
        char temp = word[0];
        word+='!';
        int n=word.size();
        while(ind!=n){
            if(word[ind]==temp){
                if(ctr<9){
                    ctr++;
                    ind++;
                    continue;
                }
            }
            ans+=to_string(ctr);
            ans+=temp;
            temp=word[ind];
            ind++;
            ctr=1;
        }
        return ans;
    }
};