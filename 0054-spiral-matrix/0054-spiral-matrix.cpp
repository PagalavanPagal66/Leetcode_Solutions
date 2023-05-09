class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(); //number of rows
        int m=a[0].size(); //number of cols
        vector<int>v;
        int top=0,left=0,right=m-1,bottom=n-1;
        int ind=0;
        while(1){ 
            for(int i=left;i<=right;i++){
                v.push_back(a[top][i]);
            }
            top++;
            if(top>bottom){
                break;
            }
            for(int i=top;i<=bottom;i++){
                v.push_back(a[i][right]);
            }
            right--;
            if(right<left){
                break;
            }
            for(int i=right;i>=left;i--){
                v.push_back(a[bottom][i]);
            }
            bottom--;
            if(bottom<top){
                break;
            }
            for(int i=bottom;i>=top;i--){
                v.push_back(a[i][left]);
                ind++;
            }
            left++;
            if(left>right){
                break;
            }
        }
        return v;
    }
};