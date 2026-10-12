class TopVotedCandidate {
    vector<int>Per,Times,Winner;
    int n;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        n = persons.size();
        Per = persons;
        Times = times;
        Winner.resize(n);
        vector<int>Freq(n);
        int maxVotes = 0;
        int win = -1;
        for(int i = 0; i < n; i++){
            Freq[Per[i]]++;
            if(Freq[Per[i]] >= maxVotes){
                maxVotes = Freq[Per[i]];
                win = Per[i];
            }
            Winner[i] = win;
        }
    }
    
    int q(int t) {
        int idx = lower_bound(Times.begin(),Times.end(),t) - Times.begin();
        if(idx >= n || Times[idx] > t)idx--;
        return Winner[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */