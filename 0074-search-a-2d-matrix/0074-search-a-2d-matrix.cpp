class Solution {
public:
    int GetRowBS(vector<vector<int>>& A,int low,int high,int target,int col){
        if(low > high)return -1;
        int mid = (low + high) >> 1;
        if(A[mid][0] <= target && A[mid][col] >= target){
            return mid;
        }else if(A[mid][0] > target){
           return GetRowBS(A,low,mid - 1,target,col);
        }else{
           return GetRowBS(A,mid + 1,high,target,col);
        }
        //not reach
        return -1;
    }
    bool ColBS(vector<vector<int>>& A,int row,int low,int high,int target){
        if(low > high)return false;
        int mid = (low + high) >> 1;
        if(A[row][mid] == target)return true;
        else if(A[row][mid] < target)return ColBS(A,row,mid + 1,high,target);
        else return ColBS(A,row,low,mid - 1,target);
        // not reach
        return false;
    }
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int row = GetRowBS(A,0,A.size() - 1,target,A[0].size() - 1);
        if(row == -1)return false;
        return ColBS(A,row,0,A[0].size() - 1,target);
    }
};