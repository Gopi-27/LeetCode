class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mpp;
        for(auto b : arr)mpp[b]++;
        for(auto b : arr){
            if(mpp[b] == 1){
                k--;
                if(k == 0)return b;
            }
        }
        return "";
    }
};