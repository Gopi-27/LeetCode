class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int s1 = nums1.size();
        int s2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i < s1 && j < s2){
            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                int n = ans.size();
                if(n == 0)ans.push_back(nums1[i]);
                else {
                    if(ans[n - 1] != nums1[i])ans.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
        }
        return ans;

    }
};