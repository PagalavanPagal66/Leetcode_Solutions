class Solution {
public:
    int Histogram(vector<int>& heights){
        stack<pair<int,int>>s;
        vector<int>left;
        vector<int>right;
        int ans=0;
        int n=heights.size();
        
        for(int i=n-1;i >= 0;i--){
            while(!s.empty() && s.top().first > heights[i]){
                s.pop();
            }
            if(s.empty()){
                right.push_back(n);
            }
            else right.push_back(s.top().second);
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i=0;i < heights.size();i++){
            while(!s.empty() && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        for(int i=0;i < n;i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,heights[i]*width);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=INT_MIN;
        vector<int>height(matrix[0].size(),0);
        for(int i=0;i < matrix.size();i++){
            for(int j=0;j < height.size();j++){
                if(matrix[i][j] == '1'){
                    height[j]+=1;

                }
                else height[j]=0;
            }
            ans=max(ans,Histogram(height));
        }
        return ans;
    }
};