class Solution {
    public int[] Fact(int n){
        int ans[] = new int[2];
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                ans[0] = i;
                ans[1] = n/i;
            }
        }
        return ans;
    }
    public int[] closestDivisors(int num) {
        int ans1[] = Fact(num + 1);
        int ans2[] = Fact(num + 2);
        if(ans1[1] - ans1[0] <= ans2[1] - ans2[0])return ans1;
        return ans2;
    }   
}