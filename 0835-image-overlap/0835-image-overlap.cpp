class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int p = i,r = 0; p < n; p++,r++){
                    for(int q = j,c = 0; q < n; q++,c++){
                        if(img2[p][q] && img2[p][q] == img1[r][c])cnt++;
                    }
                }
                ans = max(ans,cnt);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int p = i,r = n - 1; p >= 0; p--,r--){
                    for(int q = j,c = n - 1; q >= 0; q--,c--){
                        if(img2[p][q] && img2[p][q] == img1[r][c])cnt++;
                    }
                }
                ans = max(ans,cnt);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int p = i,r = n - 1; p >= 0; p--,r--){
                    for(int q = j,c = 0; q < n; q++,c++){
                        if(img2[p][q] && img2[p][q] == img1[r][c])cnt++;
                    }
                }
                ans = max(ans,cnt);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0;
                for(int p = i,r = 0; p < n; p++,r++){
                    for(int q = j,c = n - 1; q >= 0; q--,c--){
                        if(img2[p][q] && img2[p][q] == img1[r][c])cnt++;
                    }
                }
                ans = max(ans,cnt);
            }
        }

        return ans;
    }
};