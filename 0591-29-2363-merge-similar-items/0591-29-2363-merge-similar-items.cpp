class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items2.begin(),items2.end());
        sort(items1.begin(),items1.end());
        int l1 = items1.size();
        int l2 = items2.size();
        vector<vector<int>> Ans;
        int i = 0;
        int j = 0;
        while(i < l1 && j < l2){
            if(items1[i][0] < items2[j][0]){
                Ans.push_back(items1[i]);
                i++;
            }else if(items1[i][0] > items2[j][0]){
                Ans.push_back(items2[j]);
                j++;
            }else{
                items1[i][1] += items2[j][1];
                Ans.push_back(items1[i]);
                i++;
                j++;
                
            }
        }
        while(i < l1){
            Ans.push_back(items1[i++]);
        }
        while(j < l2){
            Ans.push_back(items2[j++]);
        }
        return Ans;
    }
};