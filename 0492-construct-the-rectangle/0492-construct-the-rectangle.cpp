class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>ans = {area,1};
        for(int i = 1; i * i <= area; i++){
            if(area % i == 0){
                ans = {area/i,i};
            }
        }
        return ans;
    }
};