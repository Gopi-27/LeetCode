class Solution {
public:
    int minSensors(int n, int m, int k) {
        int val = (k + k) + 1;
        int rcnt = n / val;
        if(n % val != 0)rcnt++;
        int ccnt = m / val;
        if(m % val != 0)ccnt++;
        return rcnt * ccnt;
    }
};