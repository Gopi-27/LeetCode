class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>>ans = new ArrayList<>();
        int n = arr.length;
        Arrays.sort(arr);
        int mini = Integer.MAX_VALUE;
        for(int i = 1; i < n; i++)mini = Math.min(mini,arr[i] - arr[i - 1]);
        for(int i = 1; i < n; i++){
            if((arr[i] - arr[i - 1] )== mini){
                List<Integer>l = new ArrayList<>();
                l.add(arr[i - 1]);
                l.add(arr[i]);
                ans.add(l);
            }
        }
        return ans;
    }
}