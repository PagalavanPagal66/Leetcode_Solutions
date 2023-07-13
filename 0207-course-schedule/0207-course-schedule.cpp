class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<int>adj[numCourses];
        for(auto i:pr){
            adj[i[0]].push_back(i[1]);
        }
        vector<int>inor(numCourses,0);
        for(auto i:adj){
            for(auto j:i){
                inor[j]++;
            }
        }
        int flag=0;
        queue<int>q;
        int ind=0;
        for(auto i:inor){
            if(i==0){
                q.push(ind);
            }
            ind++;
        }
        while(!q.empty()){
                int temp=q.front();
                q.pop();
                 flag++;
                for(auto i:adj[temp]){
                    inor[i]--;
                    if(inor[i]==0){
                     
                        q.push(i);
                    }
            }
        }
        cout<<flag;
        return flag==numCourses;
    }
};