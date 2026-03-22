class Solution {
public:
    bool Check(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] != target[i][j])return false;
        return true;
    }
    vector<vector<int>> Rotate90(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>>ans;
        for(int j = 0; j < n; j++){
            vector<int>temp;
            for(int i = n - 1; i >= 0; i--){
                temp.push_back(mat[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(Check(mat,target))return true;
        mat = Rotate90(mat);
        if(Check(mat,target))return true;
        mat = Rotate90(mat);
        if(Check(mat,target))return true;
        mat = Rotate90(mat);
        if(Check(mat,target))return true;
        return false;
    }
};