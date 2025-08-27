class Solution {
public:
    void Merge(vector<vector<int>>& A,pair<int,int>start,pair<int,int>mid,pair<int,int>end){
        pair<int,int> i = start;
        pair<int,int> j = {mid.first + 1,mid.second + 1};
        vector<int>B;
        while(i.first <= mid.first && j.first <= end.first){
            if(A[i.first][i.second] < A[j.first][j.second]){
                B.push_back(A[i.first][i.second]);
                i.first++;
                i.second++;
            }else{
                B.push_back(A[j.first][j.second]);
                j.first++;
                j.second++;
            }
        }
        while(i.first <= mid.first){
            B.push_back(A[i.first][i.second]);
            i.first++;
            i.second++;
        }

        while(j.first <= end.first){
            B.push_back(A[j.first][j.second]);
            j.first++;
            j.second++;
        }
        int k = 0;
        int col = start.second;
        for(int row = start.first; row <= end.first; row++){
            A[row][col++] = B[k++];
        }
        return;
    }
    void MergeSort(vector<vector<int>>& A,pair<int,int>start,pair<int,int>end){
        if(start.first >= end.first)return;
        pair<int,int>mid;
        mid.first = (start.first + end.first) >> 1;
        mid.second = (start.second + end.second) >> 1;
        MergeSort(A,start,mid);
        MergeSort(A,{mid.first + 1,mid.second + 1},end);
        Merge(A,start,mid,end);
        return;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i = 0; i < row; i++){
            int count = min(row - i,col);
            MergeSort(mat,{i,0},{i + count - 1, count - 1});
        }
        for(int j = 1; j < col; j++){
            int count = min(row,col - j);
            MergeSort(mat,{0,j},{count - 1,j + count - 1});
        }
        return mat;
    }
};