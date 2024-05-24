class Solution {
public:
    int numTrees(int n) {
        long double x=2*n;
        long double y=n;
        long double z=1;
        for(int i=0;i<n;i++){
            z=z*(x/y);
            //cout<<x<<" "<<y<<" "<<z<<endl;
            x--;
            y--;
        }
        z=z/(n+1);
        cout<<z;
        return round(z);
    }
};