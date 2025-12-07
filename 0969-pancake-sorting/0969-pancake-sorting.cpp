class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        for(int key = n; key >= 1; key--){
            for(int i = 0; i < n; i++){
                if(arr[i] == key){
                    ans.push_back(i + 1);
                    for(int k = 0; k <= i/2; k++)swap(arr[k],arr[i - k]);
                    ans.push_back(key);
                    for(int k = 0; k < key/2; k++)swap(arr[k],arr[key - k - 1]);
                    break;
                }
            }
        }
        return ans;
    }
};