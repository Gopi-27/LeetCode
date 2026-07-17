class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = apples.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            pq.push({i + days[i],apples[i]});
            while(!pq.empty() && pq.top().first <= i)pq.pop();
            if(!pq.empty()){
                pair<int,int> app = pq.top();pq.pop();
                cnt++;
                if(app.second > 1)pq.push({app.first,app.second - 1});
            }
        }
        int i = n;
        while(!pq.empty()){
            while(!pq.empty() && pq.top().first <= i)pq.pop();
            if(!pq.empty()){
                pair<int,int> app = pq.top();pq.pop();
                cnt++;
                if(app.second > 1)pq.push({app.first,app.second - 1});
            }
            i++;
        }
        return cnt;
    }
};