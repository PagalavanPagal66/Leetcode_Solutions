class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int ind=1;
        int top=0,bottom=n-1,left=0,right=n-1;
        vector<vector<int>> v(n, vector<int> (n));
        while(ind<=n*n){
            if(left>right){
                break;
            }
            for(int i=left;i<=right;i++){
                v[top][i]=ind;
                ind++;
            }
            top++;
            if(top>bottom){
                break;
            }
            for(int i=top;i<=bottom;i++){
                v[i][right]=ind;
                ind++;
            }
            right--;
            if(left>right){
                break;
            }
            for(int i=right;i>=left;i--){
                v[bottom][i]=ind;
                ind++;
            }
            bottom--;
            if(top>bottom){
                break;
            }
            for(int i=bottom;i>=top;i--){
                v[i][left]=ind;
                ind++;
            }
            left++;
        }
        return v;
    }
};