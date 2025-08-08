class SegmentTree{
    private :
        vector<int>SegTree;
    public :
        SegmentTree(int n){
            SegTree.resize(10 * n);
        }
        void BuildSegTree(vector<int>& A,int start,int end,int idx){
            if(start == end){
                SegTree[idx] = A[start];
                return;
            }
            int mid = (start + end) >> 1;
            BuildSegTree(A,start,mid,idx * 2 + 1);
            BuildSegTree(A,mid + 1,end,idx * 2 + 2);
            SegTree[idx] = max(SegTree[idx * 2 + 1],SegTree[idx * 2 + 2]);
            return;
        }
        int CanPlace(int fruits,int idx){
            if(SegTree[idx] < fruits)return 1;

            int lflag = CanPlace(fruits,idx * 2 + 1);

            if(lflag){
                int rflag = CanPlace(fruits,idx * 2 + 2);
                if(rflag){
                    SegTree[idx] = 0;
                    return 0;
                } 
            }
            SegTree[idx] = max(SegTree[idx * 2 + 1],SegTree[idx * 2 + 2]);
            return 0;
        }
        
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree s(n);
        s.BuildSegTree(baskets,0,n - 1,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += s.CanPlace(fruits[i],0);
        }
        
        return ans;
    }
};