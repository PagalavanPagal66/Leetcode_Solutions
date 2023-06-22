class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        mp.clear();
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value}); // mp[key] is a vector ->since we mapped a string (key) to a value(vector) 
    }
    string findTimestamp(vector<pair<int, string>>& arr, int t) {
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end) { 
            int mid = start + (end - start) / 2;
            if(arr[mid].first == t) { // that person found
                return arr[mid].second;   
            }
            else if(arr[mid].first > t) { 
                // the mid we got is greater than the time we search... so he must be already in that class
                end = mid - 1;
                //choosing the first half of the time period
            }
            else {
                //he is still not came ... so he must be in the second half
                start = mid + 1;
            }
        }
        if(start<1){
            return ""; // the classroom opens at 1. But we dont find him after that ... So there is no chance of that person in that class already
        }
        return arr[start - 1].second; // there is no found of that needed person so we have to find the just previous person
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return ""; // no valid classroom in that clg
        }
        else{
            return findTimestamp(mp[key], timestamp); 
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */