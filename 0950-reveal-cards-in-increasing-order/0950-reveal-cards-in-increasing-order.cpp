class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
     queue<int>Q;
     int n = deck.size();
     for(int i = 0; i < n; i++)Q.push(i);
     vector<int>ans(n);
     int i = 0;
     sort(deck.begin(),deck.end());
     while(!Q.empty()){
        ans[Q.front()] = deck[i++];
        Q.pop();
        Q.push(Q.front());
        Q.pop();
     }   
     return ans;
    }
};