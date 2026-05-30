class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>clr;
        map<int,int>ball;
        vector<int>ans;
        for(vector<int>& q : queries){
            int x = q[0];
            int y = q[1];
            if(ball.count(x)){
                clr[ball[x]]--;
                if(!clr[ball[x]])clr.erase(ball[x]);
                ball[x] = y;
                clr[y]++;
            }else{
                ball[x] = y;
                clr[y]++;
            }
            ans.push_back(clr.size());
        }
        return ans;
    }
};