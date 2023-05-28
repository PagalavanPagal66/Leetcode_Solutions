class Solution {
public:
    int n;
    map<pair<int, int>, int> mem;

    int rec(int i, int j, vector<int> &cuts){
        if(mem.find({i, j}) != mem.end()) return mem[{i, j}];
        
        bool flag = false;
        for(int k = 0; k<cuts.size(); k++){
            if(cuts[k] <= i) continue;
            if(cuts[k] >= j) break;
            if(!flag){ 
                mem[{i, j}] = j-i + rec(i, cuts[k], cuts)+rec(cuts[k], j, cuts);
            } else {
                mem[{i, j}] = min(mem[{i, j}], j-i + rec(i, cuts[k], cuts)+rec(cuts[k], j, cuts));
            } 
            flag = true;
        }

        if(!flag) return 0;
        return mem[{i, j}];
    }

    int minCost(int z, vector<int>& cuts) {
        n = z;
        sort(cuts.begin(), cuts.end());

        return rec(0, n, cuts);
    }
};