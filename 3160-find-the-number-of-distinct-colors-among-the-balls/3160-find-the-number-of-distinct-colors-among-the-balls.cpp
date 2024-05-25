class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp,mp2;
        vector<int>ans;
        int d=0;
        for(auto &i:queries){
            if(mp.find(i[0])!=mp.end()){
                mp2[mp[i[0]]]--;
                if(mp2[mp[i[0]]]==0)d--;
            }
            mp[i[0]]=i[1],mp2[i[1]]++;
            if(mp2[i[1]]==1)d++;
            ans.push_back(d);
        }
        return ans;
    }
};