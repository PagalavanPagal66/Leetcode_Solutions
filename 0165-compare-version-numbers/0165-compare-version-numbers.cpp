class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i =0;
        int j =0;
        bool flag1 = false;
        bool flag2 = false;
        string s1 ="";
        string s2 ="";
        while(i<version1.size() || j<version2.size()){
            s1 = "";
            s2 = "";
            if(version1[i]=='.'){
                i++;
            }
            while(i<version1.size() && (version1[i]=='0')){
                i++;
            }
            if(version1[i]!='.'){
                while(i<version1.size() && version1[i]!='.'){
                    s1+=version1[i];
                    i++;
                }
            }
            if(version2[j]=='.'){
                j++;
            }
            while(j<version2.size() && (version2[j]=='0')){
                j++;
            }
            if(version2[j]!='.'){
                while(j<version2.size() && version2[j]!='.'){
                    s2+=version2[j];
                    j++;
                }
            }

            if(s1.size()!=s2.size()){
                if(s1.size()>s2.size()){
                    return 1;
                }
                else{
                    return -1;
                }
            }

            for(int k=0;k<s1.size();k++){
                if(s1[k]>s2[k]){
                    return 1;
                }
                else if(s1[k]<s2[k]){
                    return -1;
                }
            }

        }
       return 0;
   
    }
};