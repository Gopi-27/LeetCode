class FenwickTree{
    vector<int>Bit;
    int n;
public:
    FenwickTree(int n){
        Bit.resize(n + 1);
        this->n = n;
    }
    void Update(int idx,int val){
        while(idx <= n){
            Bit[idx] += val;
            idx += idx & (-idx);
        }
    }
    int Query(int idx){
        int ans = 0;
        while(idx > 0){
            ans += Bit[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }
};

class NumArray {
public:
    vector<int>A;
    FenwickTree *Fen;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        A = nums;
        Fen = new FenwickTree(n);
        for(int i = 0; i < n; i++)Fen->Update(i + 1,nums[i]);
    }
    
    void update(int index, int val) {
        Fen->Update(index + 1,val - A[index]);
        A[index] = val;
        return;
    }
    
    int sumRange(int left, int right) {
        return Fen->Query(right + 1) - Fen->Query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */