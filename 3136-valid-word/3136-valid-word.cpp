class Solution {
public:
    bool isnum(char i){
        if(i=='0' || i=='1' || i=='2' || i=='3' || i=='4' || i=='5' || i=='6'
          || i=='7'|| i=='8'|| i=='9'){
            return true;
        }
        return false;
    }
    bool isValid(string word) {
        int l=word.size();
        if(l<3){
            return false;
        }
        int v=0,v1=0;
        for(auto i:word){
            if(isnum(i)){
                continue;
            }
            if(i=='a' || i=='e' || i=='o' || i=='u' || i=='i'){
                v++;
            }            
            else if(i=='A' || i=='E' || i=='I' || i=='O' || i=='U'){
                v++;
            }
            else if((i>='a' && i<='z')||(i>='A' && i<='Z')){
                v1++;
            }
            else{
                return false;
            }
        }
        if(v && v1){
            return true;
        }
        return false;
    }
};