class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = (num / 2) + 1;
        while(low <= high){
            long long int mid = (low + high) >> 1;
            if(mid * mid == num)return true;
            else if(mid * mid > num)high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};