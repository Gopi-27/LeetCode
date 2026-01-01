class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            if(carry == 0)return digits;
            int dig = digits[i] + carry;
            digits[i] = dig % 10;
            carry = dig / 10;
        }
        if(carry > 0){
            int arr[] = new int[n + 1];
            arr[0] = carry;
            for(int i = 1; i <= n; i++)arr[i] = digits[i - 1];
            return arr;
        }
        return digits;
    }
}