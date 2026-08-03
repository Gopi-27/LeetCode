class FenwickTree{
    vector<long long>Bit;
    int n;
public:
    FenwickTree(int n){
        Bit.resize(n + 2);
        this->n = n + 2;
    }
    void Update(int idx){
        while(idx < n){
            Bit[idx]++;
            idx += (idx) & (-idx);
        }
    }
    long long Query(int idx){
        long long ans = 0;
        while(idx > 0){
            ans += Bit[idx];
            idx -= (idx) & (-idx);
        }
        return ans;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long x = 0;
        long long y = 0;

        map<long long,int>CompressedVals;
        CompressedVals[0ll]++;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0)x++;
            else y++;
            CompressedVals[(y * a - x * b)]++;
        }  

        int cnt = 1;
        for(auto& b : CompressedVals)b.second = cnt++;

        FenwickTree F(cnt);
        long long ans = 0;
        x = 0ll;
        y = 0ll;
        F.Update(CompressedVals[0ll]);
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0)x++;
            else y++;

            ans += F.Query(CompressedVals[y * a - x * b]);

            F.Update(CompressedVals[y * a - x * b]);
        }
        return ans;   
    }
};