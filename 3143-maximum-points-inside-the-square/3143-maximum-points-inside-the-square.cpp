class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string stt) {
        map<int,vector<char>>m;
        for(int i=0;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];
            a=abs(a);
            b=abs(b);
            a=max(a,b);
            m[a].push_back(stt[i]);
        }
        int ans=0;
        set<char>s;
        for(auto it:m){
            auto &vec=it.second;
            for(int i=0;i<vec.size();i++){
                if(s.count(vec[i]))return ans;
                s.insert(vec[i]);
            }
            ans+=vec.size();
        }
        return ans;
    }
};