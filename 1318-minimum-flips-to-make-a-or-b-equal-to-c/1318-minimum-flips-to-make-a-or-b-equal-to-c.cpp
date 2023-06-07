class Solution {
public:
    int minFlips(int a, int b, int c) {
        int t=1;
        int res=0;
        for(int i=0;i<32;i++){
            int temp=t<<i;
            int ao=0,bo=0,co=0;
            if(a&temp)ao++;
            if(b&temp)bo++;
            if(c&temp)co++;
            if(co==0){
                if(ao==1){
                    res++;
                }
                if(bo==1){
                    res++;
                }
            }
            if(co==1){
                if(ao==0 && bo==0){
                    res++;
                }
            }
        }
        return res;
    }
};