class SegmentTree{
    vector<pair<int,int>>Seg;
public:
    SegmentTree(int n){
        Seg.resize(4 * n);
    }
    void Build(int idx,int s,int e,vector<int>& A){
        if(s == e){
            Seg[idx] = {A[s],A[s]};
            return;
        }
        int mid = (s + e) >> 1;
        Build(idx * 2 + 1,s,mid,A);
        Build(idx * 2 + 2,mid + 1,e,A);
        Seg[idx].first = max(Seg[idx * 2 + 1].first,Seg[idx * 2 + 2].first);
        Seg[idx].second = min(Seg[idx * 2 + 1].second,Seg[idx * 2 + 2].second);
        return;
    }
    pair<int,int> Query(int idx,int s,int e,int ql,int qr){
        if(qr < s || e < ql)return {INT_MIN,INT_MAX};
        if(ql <= s && e <= qr)return Seg[idx];
        int mid = (s + e) >> 1;
        pair<int,int>l = Query(idx * 2 + 1,s,mid,ql,qr);
        pair<int,int>r = Query(idx * 2 + 2,mid + 1,e,ql,qr);
        return {max(l.first,r.first),min(l.second,r.second)};
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree Seg(n);
        Seg.Build(0,0,n - 1,nums);
        priority_queue<vector<int>>pq;
        for(int i = 0; i < n; i++){
            pair<int,int> p = Seg.Query(0,0,n - 1,i, n - 1);
            pq.push({p.first - p.second,i,n - 1});
        }
        long long ans = 0;
        while(k--){
            vector<int>temp = pq.top();pq.pop();
            ans += temp[0];
            if(temp[1] < temp[2]){
                pair<int,int> p = Seg.Query(0,0,n - 1,temp[1],temp[2] - 1);
                pq.push({p.first - p.second,temp[1],temp[2] - 1});
            }
        }
        return ans;
    }
};