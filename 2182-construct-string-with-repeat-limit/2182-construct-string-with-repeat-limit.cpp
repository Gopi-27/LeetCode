class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26);
        for(char &c : s)
            freq[c - 'a']++;
        deque<pair<int,int>>dq;
        for(int i = 0; i < 26; i++){
            if(freq[i])dq.push_back({i,freq[i]});
        }
        string ans = "";
        while(!dq.empty()){
            pair<int,int>p = dq.back();dq.pop_back();
            int mini = min(p.second,repeatLimit);
            for(int i = 0; i < mini; i++){
                ans += 'a' + p.first;
            }

            if(p.second > repeatLimit){
                if(!dq.empty()){
                    pair<int,int>l = dq.back();dq.pop_back();
                    ans += 'a' + l.first;
                    l.second--;
                    if(l.second)dq.push_back(l);  
                    dq.push_back({p.first,p.second - repeatLimit});
                }
                
            }
        }
        return ans;
    }
};