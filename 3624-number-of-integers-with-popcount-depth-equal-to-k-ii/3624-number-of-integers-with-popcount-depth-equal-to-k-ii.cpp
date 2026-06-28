class SegmentTree{
    vector<vector<int>>Seg;
public:
    SegmentTree(int n){
        Seg.resize(4 * n);
        for(int i = 0; i < 4 * n; i++)Seg[i].resize(6);
    }
    void Update(int idx,int s,int e,int p,int depth){
        if(s == e){
            Seg[idx] = {0,0,0,0,0,0};
            Seg[idx][depth] = 1;
            return;
        }
        int mid = (s + e) >> 1;
        if(p <= mid)Update(idx * 2 + 1,s,mid,p,depth);
        else Update(idx * 2 + 2,mid + 1,e,p,depth);
        for(int i = 0; i < 6; i++){
            Seg[idx][i] = Seg[idx * 2 + 1][i] + Seg[idx * 2 + 2][i];
        }
        return;
    }
    int Query(int idx,int s,int e,int ql,int qr,int k){
        if(qr < s || e < ql)return 0;
        if(ql <= s && e <= qr)return Seg[idx][k];
        int mid = (s + e) >> 1;
        return Query(idx * 2 + 1,s,mid,ql,qr,k) + Query(idx * 2 + 2,mid + 1,e,ql,qr,k);
    }
};
class Solution {
public:
    int PopCntDepth(long long x){
        if(x == 1)return 0;
        int nx = 0;
        while(x > 0){
            if(x & 1)nx++;
            x >>= 1;
        }
        return 1 + PopCntDepth(nx);
    }
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        // cout << PopCntDepth(7);
        SegmentTree Seg(n);
        for(int i = 0; i < n; i++)Seg.Update(0,0,n - 1,i,PopCntDepth(nums[i]));
        vector<int>Ans;
        for(vector<long long>& q : queries){
            if(q[0] == 1){
                Ans.push_back(Seg.Query(0,0,n - 1,q[1],q[2],q[3]));
            }else{
                Seg.Update(0,0, n - 1,q[1],PopCntDepth(q[2]));
            }
        }
        return Ans;
    }
};