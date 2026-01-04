class Solution {
public:
    int IsFourDivisors(int n){
        int sum = 1 + n;
        int cnt = 2;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                cnt++;
                if(i != n/i)cnt++;

                sum += i;
                sum += n/i;
            }

            if(cnt > 4)return 0;
        }
        if(cnt < 4)return 0;
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int& n : nums){
            int sum = IsFourDivisors(n);
            cout << sum << endl;
            ans += sum;
        }
        return ans;
    }
};