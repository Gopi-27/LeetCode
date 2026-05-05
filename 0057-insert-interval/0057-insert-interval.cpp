class Solution {
public:
    bool Intersect(vector<int>& org,vector<int>newInterval){
        if(org[1] >= newInterval[0] && org[1] <= newInterval[1])return true;
        if(newInterval[1] >= org[0] && newInterval[1] <= org[1])return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>Ans;
        bool flag = 0;
        for(vector<int>& org : intervals){
            if(Intersect(org,newInterval)){
                newInterval[0] = min(newInterval[0],org[0]);
                newInterval[1] = max(newInterval[1],org[1]);
            }else if(org[1] < newInterval[0])Ans.push_back(org);
            else{
                if(flag)Ans.push_back(org);
                else{
                    Ans.push_back(newInterval);
                    flag = 1;
                    Ans.push_back(org);
                }
            }
        }
        if(!flag)Ans.push_back(newInterval);
        return Ans;
    }
};