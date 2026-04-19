class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = n - 1;
        int ans = 0;
        for(int j = m - 1; j >= 0; j--){
            while(i > 0 && nums1[i - 1] <= nums2[j])i--;
            if(i <= j && nums1[i] <= nums2[j])ans = max(ans,j - i);
        }
        return ans;
    }
};