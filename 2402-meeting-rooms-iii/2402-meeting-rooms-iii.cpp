class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>NoOfMeetings(n);
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        priority_queue<int,vector<int>,greater<int>>Room;
        for(int i = 0; i < n; i++)Room.push(i);
        for(vector<int>& m : meetings){
            int start = m[0];
            int end = m[1];
            
            while(!pq.empty() && pq.top().first <= start){
                Room.push(pq.top().second);
                pq.pop();
            } 

            if(Room.empty()){
                long long first_end = pq.top().first;
                int r = pq.top().second;
                pq.pop();
                long long wait = first_end - start;
                NoOfMeetings[r]++;
                pq.push({end + wait,r});
            }else{
                int r = Room.top();Room.pop();
                pq.push({end,r});
                NoOfMeetings[r]++;
            }

        }
        int maxi = 0;
        int idx  = 0;
        for(int i = 0; i < n; i++){
            if(maxi < NoOfMeetings[i]){
                maxi = NoOfMeetings[i];
                idx = i;
            }
        }
        return idx;
    }
};