class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];
        int n = tri.size();
        bool xflag = 0;
        bool yflag = 0;
        bool zflag = 0;
        for(int i = 0; i < n; i++){
            if(tri[i][0] <= x && tri[i][1] <= y && tri[i][2] <= z){
                if(tri[i][0] == x)xflag = 1;
                if(tri[i][1] == y)yflag = 1;
                if(tri[i][2] == z)zflag = 1;
            }
        }
        return xflag && yflag && zflag;
        

    }
};