class Solution {
public:
    int addDigits(int num) {
        int n=0;
        while(num>0){
            n+=num%10;
            num/=10;
        }
        if(n<10){
            return n;
        }
        else{
            return addDigits(n);
        }
    }
};