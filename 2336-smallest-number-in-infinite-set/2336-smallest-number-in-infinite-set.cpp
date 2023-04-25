class SmallestInfiniteSet {
    int current;
    set<int>s;
public:
    SmallestInfiniteSet() {
        current=1;
    }
    
    int popSmallest() {
        
        int ans;
        if(!s.empty())
        {
            ans=*s.begin();
            s.erase(*s.begin());
        }
        else
        {
            ans=current;
            current++;
        }
        return ans;
    }
    
    void addBack(int num) {
        
        if(current<=num || s.find(num)!=s.end())
            return;
        s.insert(num);
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */