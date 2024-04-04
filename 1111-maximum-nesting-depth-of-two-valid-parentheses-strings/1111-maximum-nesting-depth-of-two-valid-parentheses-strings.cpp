class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        stack<int>st;
        int ignore = 0;
        vector<int>ans(n,0);
        // for(int i=0;i<n;i++){
        //     if(seq[i] == '('){
        //         st.push(i);
        //     }
        //     else{
        //         if(ignore!=0){
        //             ans[i]=1;
        //             ignore++;
        //             continue;
        //         }
        //         int size = st.size();
        //         int ind = st.top();
        //         st.pop();
        //         if(ind == i-1)
        //         {    
        //             ans[ind]=1;
        //             ans[i]=1;
        //         }
        //     }
        // }
        int ocnt=0,ccnt=0;
        for(auto i:seq){
            if(i=='(')ocnt++;
        }
        int half = 0;
        int shalf= 0;
        int ind=0;
        for(auto i:seq){
            if(i=='('){
                half++;
            }
            ans[ind] = half%2;
            if(i==')'){
                half--;
            }
            ind++;
        }
        return ans;
    }
};