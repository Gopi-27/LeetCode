class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
     unordered_map<string,int>mpp;
      int n = paths.size();
      for(int i = 0; i < n; i++){
            mpp[paths[i][0]]++;
            mpp[paths[i][1]]++;
      }
      for(int i = 0; i < n; i++){
        if(mpp[paths[i][1]] == 1)return paths[i][1];
      }
      return "";
    }
};