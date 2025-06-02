class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>mystack;
        int n = nums2.size();
        unordered_map<int,int>mpp;
        for(int i = n - 1; i >= 0; i--){
            while(!mystack.empty() && mystack.top() < nums2[i])mystack.pop();
            if(!mystack.empty())mpp[nums2[i]] = mystack.top();
            else mpp[nums2[i]] = -1;

            mystack.push(nums2[i]);
        }
        int m = nums1.size();
        for(int i = 0; i < m; i++){
            nums1[i] = mpp[nums1[i]];
        }
        return nums1;
    }
};