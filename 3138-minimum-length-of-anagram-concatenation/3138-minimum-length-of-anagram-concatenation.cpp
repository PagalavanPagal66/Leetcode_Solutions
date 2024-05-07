class Solution {
public:
    bool isval(string& s,int len){
        set<string>st;
        for(int i=0;i<s.size();i+=len){
            string temp = "";
            int ctr=0;
            while(ctr<len){
                temp+=s[i+ctr];
                ctr++;
            }
            sort(temp.begin(),temp.end());
            st.insert(temp);
          //  cout<<temp<<" "<<len<<endl;
            if(st.size()>1){
                return false;
            }
        }
        if(st.size()>1){
                return false;
         }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=1;i<n;i++){
            if(n%i == 0 && isval(s,i)){
                return i;
            }
        }
        return n;
    }
};