class SegmentTree{
    vector<int>Ones;
    vector<int>Zeros;
    vector<int>Lazy;
public:
    SegmentTree(int n){
        Ones.resize(4 * n);
        Zeros.resize(4 * n);
        Lazy.resize(4 * n);
    }
    void Build(int idx,int s,int e,vector<int>& A){
        if(s == e){
            if(A[s])Ones[idx]++;
            else Zeros[idx]++;
            return;
        }
        int mid = (s + e) >> 1;
        Build(idx * 2 + 1,s,mid,A);
        Build(idx * 2 + 2,mid + 1,e,A);

        Ones[idx] = Ones[idx * 2 + 1] + Ones[idx * 2 + 2];
        Zeros[idx] = Zeros[idx * 2 + 1] + Zeros[idx * 2 + 2];
        return;
    }
    void Apply(int idx,int s,int e,int flag){
        if(flag % 2 == 0)return;
        swap(Ones[idx],Zeros[idx]);
        if(s == e)return;
        Lazy[idx * 2 + 1] = (Lazy[idx * 2 + 1] + 1) % 2;
        Lazy[idx * 2 + 2] = (Lazy[idx * 2 + 2] + 1) % 2;
    }
    // l r -> flip;
    void Update(int idx,int s,int e,int ql,int qr){
        if(Lazy[idx])Apply(idx,s,e,Lazy[idx]);
        Lazy[idx] = 0;
        if(qr < s || e < ql)return;
        if(ql <= s && e <= qr){
            Apply(idx,s,e,1);
            return;
        }
        int mid = (s + e) >> 1;
        Update(idx * 2 + 1,s,mid,ql,qr);
        Update(idx * 2 + 2,mid + 1,e,ql,qr);

        Ones[idx] = Ones[idx * 2 + 1] + Ones[idx * 2 + 2];
        Zeros[idx] = Zeros[idx * 2 + 1] + Zeros[idx * 2 + 2];
    }
    int Query(){
        return Ones[0];
    }

};
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        SegmentTree S(n);
        S.Build(0,0,n - 1,nums1);
        long long sum = 0;
        for(int i = 0; i < n; i++)sum += nums2[i];
        vector<long long>Ans;
        for(vector<int>& q : queries){
            if(q[0] == 1){
                S.Update(0,0,n - 1,q[1],q[2]);
            }else if(q[0] == 2){
                // cout << S.Query() << endl;
                sum += 1ll * S.Query() * q[1];
                // cout << sum << endl;
            }else{
                Ans.push_back(sum);
            }
        }
        return Ans;
    }
};
// => 1,1
//          (3,0);
//          0 2 
//         /   \ 
//     (2,0)   (1,0)
//     0 1       2 
//     / \
//  (1,0)(1,0)
//   0     1       
