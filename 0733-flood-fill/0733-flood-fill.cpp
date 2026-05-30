class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        if(x == color)return image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>>Q;
        Q.push({sr,sc});
        while(!Q.empty()){
            int r = Q.front().first;
            int c = Q.front().second;Q.pop();
            image[r][c] = color;
            //left
            if(c - 1 >= 0 && image[r][c - 1] == x)Q.push({r,c - 1});
            //right
            if(c + 1 < m && image[r][c + 1] == x)Q.push({r,c + 1});
            // top
            if(r - 1 >= 0 && image[r - 1][c] == x)Q.push({r - 1,c});
            // bottom
            if(r + 1 < n && image[r + 1][c] == x)Q.push({r + 1,c});
        }
        return image;
    }
};