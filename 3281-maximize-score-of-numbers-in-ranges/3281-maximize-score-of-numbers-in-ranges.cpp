class Solution {
public:
    bool isValid(int key,vector<int>& start,int d,int n){
        int s = start[0];
        for(int i = 1; i < n; i++){
            if(0ll + s + key > start[i] + d)return false;
            if(0ll + s + key <= start[i])s = start[i];
            else s += key;            
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(),start.end());
        int low = 0;
        int high = start[n - 1] + d;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isValid(mid,start,d,n))low = mid + 1;
            else high = mid - 1;
        }
        return high;

    }
};