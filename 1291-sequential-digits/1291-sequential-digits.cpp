class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>Ans;
        for(int i = 1; i < 10; i++){
            long long num = i;
            for(int j = i + 1; j < 10; j++){
                num = (num * 10) + j;
                if(num >= low && num <= high)Ans.push_back(num);
                if(num > high)break;
            }
        }
        sort(Ans.begin(),Ans.end());
        return Ans;
    }
};