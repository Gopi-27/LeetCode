class FrequencyTracker {
public:
    vector<int>Ele,Frr;
    FrequencyTracker() {
        Ele.resize(1e5 + 1);
        Frr.resize(1e5 + 1e5 + 1);
    }
    void add(int number) {
        Frr[Ele[number]]--;
        Ele[number]++;
        Frr[Ele[number]]++;
    }
    
    void deleteOne(int number) {
        if(!Ele[number])return;
        Frr[Ele[number]]--;
        Ele[number]--;
        Frr[Ele[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return Frr[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */