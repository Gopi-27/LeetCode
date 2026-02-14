class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        map<int,int>mpp;
        for(vector<int>& p : people)mpp[p[0]]++;
        int n = people.size();
        for(int i = n - 1; i >= 0; i--){
            int h = people[i][0];
            int rfp = people[i][1];
            mpp[h]--;
            int move = rfp - mpp[h];
            int j = i;
            while(move--){
                swap(people[j],people[j + 1]);
                j++;
            }
        }
        return people;
    }
};