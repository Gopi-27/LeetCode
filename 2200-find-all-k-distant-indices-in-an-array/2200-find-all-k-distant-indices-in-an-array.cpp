class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // ultimate aim is to reduce time complexcity
        vector<int>Ans;
        int n = nums.size();
        int i = 0;
        int idx = -1;// index to Add
        while(i < n){
            if(nums[i] == key){
                if(idx < i - k) idx = i - k; // starting point
                if(idx < 0) idx = 0;            
                int flag = 1; // to check  will loop break at middle
                while(idx < n && idx <= i + k){
                    if(idx != i && nums[idx] == key ){
                        i = idx;
                        flag = 0;
                        break;
                    } 
                    Ans.push_back(idx++);
                }
                // if the loop is not broke at middle, we can directly go to end;
                if(flag)i += k;
            }else i++;
        }
        return Ans;
    }
};