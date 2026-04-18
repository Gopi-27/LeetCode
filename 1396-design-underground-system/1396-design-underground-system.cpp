class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>login;
    unordered_map<string,pair<double,int>>avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        login[id] = {stationName,t};
        return;
    }
    
    void checkOut(int id, string stationName, int t) {
        string src_dest = login[id].first + "-->" + stationName;
        avg[src_dest].first += t - login[id].second;
        avg[src_dest].second++;
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string src_dest = startStation + "-->" + endStation;
        return avg[src_dest].first/avg[src_dest].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */