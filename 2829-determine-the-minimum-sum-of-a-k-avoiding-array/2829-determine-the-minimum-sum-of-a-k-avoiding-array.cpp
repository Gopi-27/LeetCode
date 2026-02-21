class Solution {
public:
    int minimumSum(int n, int k) {
        int cnt = k/2;
        if(n <= cnt)return (n * (n + 1))/2;
        int rem = n - cnt;
        int last = k + rem - 1;
        return ((cnt * (cnt + 1))/2) + ((last * (last + 1))/2) - (k * (k - 1))/2;
    }
};