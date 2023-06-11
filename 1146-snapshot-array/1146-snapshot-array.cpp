class SnapshotArray {
public:
    unordered_map < int , map<int,int> > mp;
    int snapCnt;
    SnapshotArray(int length) {
        for(int i=0 ; i<length ; i++){
            map <int, int> m; m[0] = 0;
            mp[i] = m;
        }
        snapCnt = 0;
    }
    void set(int index, int val) {   
        mp[index][snapCnt] = val;
    }
    int snap() {
        return snapCnt++;
    }
    int get(int index, int snap_id) {   
        auto it = mp[index].upper_bound(snap_id); 

        it--; 
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */