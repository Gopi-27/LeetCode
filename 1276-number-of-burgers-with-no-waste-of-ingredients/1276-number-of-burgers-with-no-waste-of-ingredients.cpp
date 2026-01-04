class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices < 2 * cheeseSlices)return {};
        int small = cheeseSlices;
        tomatoSlices -= 2 * cheeseSlices;
        if(tomatoSlices > 2 * cheeseSlices || tomatoSlices % 2 == 1)return {};
        int jumbo = tomatoSlices/2;
        return {jumbo,small - jumbo};
    }
};