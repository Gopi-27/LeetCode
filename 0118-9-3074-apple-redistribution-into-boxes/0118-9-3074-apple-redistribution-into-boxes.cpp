class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int tot_app = 0;
        for(int b : apple) tot_app += b;
        int cnt = 0;
        int n = capacity.size();
        int req_cap = 0;
        for(int i = n - 1; i >= 0; i--){
            req_cap += capacity[i];
            cnt++;
            if( req_cap >= tot_app )break;
        }
        return cnt;
    }
};