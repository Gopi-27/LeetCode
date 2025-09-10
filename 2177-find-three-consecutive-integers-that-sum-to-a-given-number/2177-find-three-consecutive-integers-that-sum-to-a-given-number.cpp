class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long quo = num / 3;
        int rem = num % 3;
        if(rem > 0)return {};
        return {quo - 1,quo,quo + 1};
    }
};