// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long int low = 1;
    long long int high = n;
    while(low <= high){
        long long int mid = (low + high) >> 1;
        if(isBadVersion(mid)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}