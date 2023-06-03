class Solution {
public:

    int helper(int head , map<int,vector<int>>&mp, vector<int>&time){
        int t=0;
        for(auto w:mp[head]){
            t=max(t,time[w]+helper(w,mp,time));
        }
        return t;
    }



    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int cur_time = informTime[headID];
        stack<int> work;
        int time= 0;
        map<int,vector<int>> mp;

        for(int i =0 ;i< n;i++){
            int w = manager[i];
            if(informTime[i])
                mp[w].push_back(i);
        }

        return cur_time+helper(headID,mp,informTime);
    }
};