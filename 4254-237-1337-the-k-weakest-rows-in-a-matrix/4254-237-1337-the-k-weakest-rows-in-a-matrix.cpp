class Solution {
public:
    int SolCnt(vector<int>& Arr,int n){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Arr[mid] == 1)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0; i < m; i++){
             pq.push({SolCnt(mat[i],n),i});
        }
        vector<int>Ans;
        while(k--){
           Ans.push_back((pq.top().second));
           pq.pop();
        }
        return Ans;

        
    }
};