class Solution {
public:
    void Merge(vector<vector<int>>&A,int start,int mid,int end,int k){
        int i = start;
        int j = mid + 1;
        vector<vector<int>>B;
        while(i <= mid && j <= end){
            if(A[i][k] < A[j][k]){
                B.push_back(A[j]);
                j++;
            }else{
                B.push_back(A[i]);
                i++;
            }
        }

        while(i <= mid)B.push_back(A[i++]);
        while(j <= end)B.push_back(A[j++]);

        j = 0;
        for(int i = start; i <= end; i++){
            A[i] = B[j++];
        }
        
        return;
        
    }
    void MergeSort(vector<vector<int>>& A,int start,int end,int k){
        if(start >= end)return;
        int mid = (start + end) >> 1;
        MergeSort(A,start,mid,k);
        MergeSort(A,mid + 1,end,k);
        Merge(A,start,mid,end,k);
        return;
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        MergeSort(score,0,score.size() - 1,k);
        return score;
    }
};