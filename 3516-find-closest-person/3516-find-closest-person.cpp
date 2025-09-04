class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xtime = abs(x - z);
        int ytime = abs(y - z);
        return (xtime == ytime)? 0 : (xtime > ytime) ? 2 : 1;
    }
};