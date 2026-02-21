class Solution {
    public int[] numberOfPairs(int[] nums) {
        int Freq[] = new int[101];
        for(int b : nums){
            Freq[b]++;
        }
        int ans[] = new int[2];
        for(int b : Freq){
            ans[0] += b/2;
            ans[1] += b % 2;
        }
        return ans;
    }
}