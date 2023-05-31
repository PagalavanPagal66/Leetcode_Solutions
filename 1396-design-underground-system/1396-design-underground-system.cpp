class UndergroundSystem {
private:
    unordered_map<int,string> in;
    unordered_map<int,int> tIn;
    multimap<pair<string,string>, int> time;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]=stationName;
        tIn[id]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        time.insert({{in[id],stationName},t-tIn[id]});
    }
    
    double getAverageTime(string startStation, string endStation) {
        int totTime=0;
        int n=0;
        for(auto i:time){
            if(i.first.first==startStation && i.first.second==endStation)
            {
                totTime+=i.second;
                n++;
            }
        }
        return (double)totTime/n;
    }
};


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */