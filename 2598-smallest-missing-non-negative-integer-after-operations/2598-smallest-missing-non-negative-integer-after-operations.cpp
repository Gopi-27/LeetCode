class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>freq(value);
        int n = nums.size();
        for(int i = 0; i < n; i++)freq[((nums[i] % value) + value) % value]++;

        int ele;
        int min_ele_freq = INT_MAX;

        for(int i = 0; i < value; i++){
            if(!freq[i])return i;
            if(freq[i] <= min_ele_freq){
                min_ele_freq = freq[i];
                ele = i;
            }
        }
        
        int ans = (min_ele_freq - 1) * value + ele + 1;
        for(int i = ele + 1; i < value; i++){
            freq[i] = freq[i] - min_ele_freq;
            if(freq[i] == 0)return ans;
            else ans++;
        }
        for(int i = 0; i <= ele; i++){
            if(ele == 0 && i == 0)continue;// got by wrong sub
            freq[i] = freq[i] - min_ele_freq;
            if(freq[i] == 0)return ans;
            else ans++;
        }

        return ans;        
    }
};