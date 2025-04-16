class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int>idx;
        int n = height.size();
        for(int i = 1; i < n; i++){
            if(height[i - 1] > threshold)idx.push_back(i);
        }
        return idx;
    }
};