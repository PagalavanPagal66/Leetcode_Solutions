class Solution {
private:
    std::unordered_map<string, int> skill2idx;

public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int target = std::pow(2, (int)req_skills.size())-1;
        for (int i=0; i<req_skills.size(); i++){
            skill2idx[req_skills[i]] = i;
        }
        return bfs(target, people);

    }

    int computeMask(vector<string>& skills){
        int mask = 0;
        for (string skill : skills){
            mask |= (1<<skill2idx[skill]);
        }
        return mask;
    }
    vector<int> bfs(int target, vector<vector<string>>& people){
        deque<pair<int, vector<int>>> q;
        vector<int> start;
        q.push_back(std::make_pair(0, start));
        std::unordered_set<int> seen;
        seen.insert(0);
        while (!q.empty()){
            auto curPair = q.front(); q.pop_front();
            int curMask = curPair.first;
            vector<int> curTeam = curPair.second;
            if (curMask==target){return curTeam;}
            for (int i=0; i<people.size(); i++){
                vector<int> nxtTeam = vector<int>(curTeam.begin(), curTeam.end());
                nxtTeam.push_back(i);
                int nxtMask = curMask | computeMask(people[i]);
                if (seen.count(nxtMask)==0){
                    seen.insert(nxtMask);
                    q.push_back(std::make_pair(nxtMask, nxtTeam));
                }
            }
        }
        return {};
    }
};