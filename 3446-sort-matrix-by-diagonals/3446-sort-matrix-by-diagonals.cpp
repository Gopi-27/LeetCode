class Solution {
public:
    void Merge(vector<vector<int>>& A,pair<int,int>start,pair<int,int>mid,pair<int,int>end,bool flag){
        pair<int,int> i = start;
        pair<int,int> j = {mid.first + 1,mid.second + 1};
        vector<int>B;

        while(i.first <= mid.first && j.first <= end.first){
            if(flag){
                if(A[i.first][i.second] > A[j.first][j.second]){
                    B.push_back(A[i.first][i.second]);
                    i.first++;
                    i.second++;
                }else{
                    B.push_back(A[j.first][j.second]);
                    j.first++;
                    j.second++;
                } 
            }else{
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
    void MergeSort(vector<vector<int>>& A,pair<int,int>start,pair<int,int>end,bool flag){
        if(start.first >= end.first)return;
        pair<int,int>mid;
        mid.first = (start.first + end.first) >> 1;
        mid.second = (start.second + end.second) >> 1;
        MergeSort(A,start,mid,flag);
        MergeSort(A,{mid.first + 1,mid.second + 1},end,flag);
        Merge(A,start,mid,end,flag);
        return;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++){
            int count = n - i;
            MergeSort(grid,{i,0},{i + count - 1,count - 1},1);
        }
        for(int j = 1; j < n; j++){
            int count = n - j;
            MergeSort(grid,{0,j},{count - 1,j + count - 1},0);
        }
        return grid;
    }
};