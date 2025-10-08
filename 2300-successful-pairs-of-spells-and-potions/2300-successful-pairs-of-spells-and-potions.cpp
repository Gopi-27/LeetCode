class Solution {
public:
    int GetIdx(vector<int>& A,long long key){
        int low = 0;
        int high = A.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(A[mid] >= key)high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int p = potions.size();

        vector<int>Ans(n);

        for(int i = 0; i < n; i++){
            long long  key = success/spells[i];

            if(success % spells[i])key++;
            int idx = GetIdx(potions,key);
            Ans[i] = p - idx; 
        }
        return Ans;
    }
};