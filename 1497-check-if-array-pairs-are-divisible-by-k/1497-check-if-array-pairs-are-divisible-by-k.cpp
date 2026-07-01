class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>Rem(k);
        for(int& val : arr)Rem[((val % k) + k ) % k]++;
        if(Rem[0] % 2)return false;
        for(int i = 1; i <= k/2; i++)if(Rem[i] != Rem[k - i])return false;
        return true;
    }
};