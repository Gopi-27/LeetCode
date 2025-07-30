class Solution {
public:
    int minOperations(int n) {
       int h = n / 2;
       return (n % 2 == 0)?(h * h):(h * (h + 1));
    }
};