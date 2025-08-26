class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int MaxArea;
        double Maxhypo = 0;
        int n = dimensions.size();
        for(int i = 0; i < n; i++){
            double hypo = sqrt(dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
            if(hypo > Maxhypo){
                Maxhypo = hypo;
                MaxArea = dimensions[i][0] * dimensions[i][1];
            }else if(hypo == Maxhypo){
                MaxArea = max(MaxArea,dimensions[i][0] * dimensions[i][1]);
            }            
        }
        return MaxArea;
    }
};