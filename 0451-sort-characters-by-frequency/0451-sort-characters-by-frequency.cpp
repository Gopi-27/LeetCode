class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(char& ch: s)mpp[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto& b : mpp)pq.push({b.second,b.first});
        string ans = "";
        while(!pq.empty()){
            pair<int,char> curr = pq.top();pq.pop();
            for(int i = 0; i < curr.first; i++)ans += curr.second;
        }
        return ans;
    }
};