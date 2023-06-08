class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n = p.size();
        stack<double> st;
        vector<pair<int, int>> cars;
        for(int i=0; i<n; i++){
            cars.push_back({p[i], s[i]});
        }
        sort(cars.begin(), cars.end());

        for(int i=n-1; i>=0; i--){
            double timetaken = (target-cars[i].first)/(double)cars[i].second;
            bool fl = true;
            if(st.size() >= 1 && st.top() >= timetaken){
                fl = false;
            }
            if(fl)st.push(timetaken);
        }
        return st.size();
    }
};