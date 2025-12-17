class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int>A = {a,b,c};
        sort(A.begin(),A.end());
        int maxi = A[2];
        int diff = max(0,A[0] + A[1] - A[2]);
        int val = min(min(A[0],A[1]),diff/2);
        return A[0] + A[1] - diff + val;
    }
};