class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;

        for(int i = 0; i < n - 1; i++){
            int req = heights[i + 1] - heights[i];
            if(req <= 0){
                continue;
            }else if(req <= bricks){
                pq.push(req);
                bricks -= req;
            }else{
                if(ladders <= 0)return i;
                ladders--;
                if(!pq.empty()){
                    int extra = pq.top();
                    if(extra <= req){
                        continue;
                    }
                    else {
                        pq.pop();
                        bricks += extra - req;
                        pq.push(req);
                    }
                }
            }
        }
        return n - 1;
    }
};