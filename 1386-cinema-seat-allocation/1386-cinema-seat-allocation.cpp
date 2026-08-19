class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int m = reservedSeats.size();
        int ans = 0;
        int prevRow = 0;
        int i = 0;
        while(i < m){
            int mask = 0;
            ans += (reservedSeats[i][0] - prevRow - 1) << 1;
            prevRow = reservedSeats[i][0];
            while(i < m && reservedSeats[i][0] == prevRow){
                mask |= 1 << reservedSeats[i][1];
                i++;
            }
            
            if(!((mask >> 2) & 1) && !((mask >> 3) & 1) && !((mask >> 4) & 1) && !((mask >> 5) & 1))ans++,mask |= (1 << 6) - (1 << 2);
            
            if(!((mask >> 4) & 1) && !((mask >> 5) & 1) && !((mask >> 6) & 1) && !((mask >> 7) & 1))ans++,mask |= (1 << 7) - (1 << 4);

            if(!((mask >> 6) & 1) && !((mask >> 7) & 1) && !((mask >> 8) & 1) && !((mask >> 9) & 1))ans++,mask |= (1 << 9) - (1 << 6);
        }
        ans += (n - prevRow) << 1;
        return ans;
    }
};