class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(),prop.end(),cmp); 
        int cnt=0;
        stack<pair<int,int>>st;
        int n=prop.size();
        for(int i=n-1;i>=0;i--){
            int curr = prop[i][1];
            int pairval = prop[i][0];
            if(st.empty()){
                st.push({curr,pairval});
            }
            else{
                while(!st.empty() && (st.top().first<=curr)){
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top().second > pairval)
                        cnt++;
                    //cout<<i<<" "<<prop[i][0]<<" "<<prop[i][1]<<" "<<st.top().first<<" "<<st.top().second<<endl;
                }
                st.push({curr,pairval});
            }
        }
        return cnt;
    }
};