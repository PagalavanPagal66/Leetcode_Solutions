class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        mp.clear();
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string findTimestamp(vector<pair<int, string>>& arr, int t) {
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end) { 
            int mid = start + (end - start) / 2;
            if(arr[mid].first == t) {
                return arr[mid].second;
            } else if(arr[mid].first > t) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if(start<1){
            return "";
        }
        return arr[start - 1].second;
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        return findTimestamp(mp[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */