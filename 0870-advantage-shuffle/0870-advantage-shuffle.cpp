class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>st;
        int n = nums1.size();
        for(int i = 0; i < n; i++)st.insert(nums1[i]);
        
        for(int i = 0; i < n; i++){
            auto it = st.upper_bound(nums2[i]);
            if(it == st.end())nums1[i] = -1;
            else {
                nums1[i] = *it;
                st.erase(it);
            }
        }
        for(int i = 0; i < n; i++){
            cout << nums1[i] << " ";
            if(nums1[i] == -1){
                nums1[i] = *(st.begin());
                st.erase(st.begin());
            }
        }
        return nums1;
    }
};

// [0, 1, 2, 2, 4]

    // 2  4  1  2  0
// [1, 3, 0, 0, 2]