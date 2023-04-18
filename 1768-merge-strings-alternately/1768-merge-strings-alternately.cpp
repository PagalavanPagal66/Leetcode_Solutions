class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string temp="";
        int i=0,j=0;
        while(i<w1.length() && j<w2.length()){
            temp+=w1[i++];
            temp+=w2[j++];
        }
        while(i<w1.length())temp+=w1[i++];
        while(j<w2.length())temp+=w2[j++];
        return temp;
    }
};