class FenwickTree{
    vector<long long>Bit;
    int n;
public : 
    FenwickTree(){
        n = 1e5 + 1;
        Bit.resize(1e5 + 1);
    }
    void Update(int idx,int val){
        while(idx <= n){
            Bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    long long Query(int idx){
        long long ans = 0;
        while(idx > 0){
            ans += Bit[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }
};
class Solution {
public:
    int numTeams(vector<int>& rating) {
        FenwickTree l;
        FenwickTree r;
        int n = rating.size();
        for(int i = 0; i < n; i++)r.Update(rating[i],1);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            r.Update(rating[i],-1);
            ans += l.Query(rating[i] - 1) * (n - i - 1 - r.Query(rating[i]));
            ans += (i - l.Query(rating[i])) * r.Query(rating[i] - 1);
            l.Update(rating[i],1);
        }
        return ans;
    }
};