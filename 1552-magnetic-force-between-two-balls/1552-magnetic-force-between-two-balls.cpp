class Solution {
public:
    int GetNxtIdx(vector<int>& P,int key,int start){
        int low = start;
        int high = P.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(P[mid] < key)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    bool Valid(vector<int>& P,int key,int m){
        int n = P.size();
        int cnt = 1;
        int idx = 0;
        while(cnt < m && idx < n){
            idx = GetNxtIdx(P,P[idx] + key,idx + 1);
            if(idx < n)cnt++;
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n - 1] - position[0];
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Valid(position,mid,m))low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};