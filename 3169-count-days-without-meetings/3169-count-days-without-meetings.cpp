class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int taken = meetings[0][1]-meetings[0][0]+1;
        int pastend = meetings[0][1]+1;
        for(int i=1;i<meetings.size();i++){
            //cout<<taken<<" ";
            taken+=max(0,(min(days,meetings[i][1])+1-max(pastend,meetings[i][0])));
            pastend = max(pastend,meetings[i][1]+1);
        }
        return days - taken;
    }
};