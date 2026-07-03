class SegmentTree{
    vector<int>Seg;
public :
    SegmentTree(int n){
        Seg.resize(4 * n);
    }
    void Build(int idx,int s,int e,vector<int>& A){
        if(s == e){
            Seg[idx] = A[s];
            return ;
        }
        int mid = (s + e) >> 1;
        Build(idx * 2 + 1,s,mid,A);
        Build(idx * 2 + 2,mid + 1,e,A);
        Seg[idx] = max(Seg[idx * 2 + 1],Seg[idx * 2 + 2]);
    }
    int Query(int idx,int s,int e,int pos,int key){
        if(Seg[idx] < key)return INT_MAX;
        if(s == e)return s;
        int mid = (s + e) >> 1;
        if(pos <= mid){
            int l = Query(idx * 2 + 1,s,mid,pos,key);
            if(l != INT_MAX)return l;
        }
        return Query(idx * 2 + 2,mid + 1,e,pos,key);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree S(n);
        S.Build(0,0,n - 1,heights);
        vector<int>Ans;
        for(vector<int>& q : queries){
            int a = q[0];
            int b = q[1];
            if(a > b)swap(a,b);

            if(a == b)Ans.push_back(a);
            else if(heights[a] < heights[b])Ans.push_back(b);
            else {
               if(b == n - 1)Ans.push_back(-1);
               else{
                    int ans = S.Query(0,0,n - 1,b + 1,heights[a] + 1);
                    if(ans == INT_MAX)Ans.push_back(-1);
                    else Ans.push_back(ans); 
               }
            }
        }
        return Ans;
    }
};