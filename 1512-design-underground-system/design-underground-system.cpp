class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> m;
    unordered_map<int, pair<string, int>> check;
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        check[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto startStation = check[id];
        if (m.find(startStation.first + "," + stationName) != m.end()) {
            auto val = m[startStation.first + "," + stationName];
            m[startStation.first + "," + stationName] = {
                t - startStation.second + val.first, val.second + 1};
        } else {
            m.insert({startStation.first + "," + stationName,
                      {t - startStation.second, 1}});
        }
        check.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        auto val = m[startStation + "," + endStation];
        return val.first / (val.second * 1.0);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */