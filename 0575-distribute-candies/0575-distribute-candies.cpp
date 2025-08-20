class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st;
        int n = candyType.size();
        for(int i = 0; i < n; i++){
            st.insert(candyType[i]);
        }
        int len = st.size();
        return len >= (n/2) ? (n/2) : len;
    }
};