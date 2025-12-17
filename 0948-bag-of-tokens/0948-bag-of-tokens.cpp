class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int scr = 0;
        int i = 0;
        int j = tokens.size() - 1;
        while(i <= j){
            if(tokens[i] <= power){
                power -= tokens[i++];
                scr++;
            }else{
                if(scr && i != j){
                    power += tokens[j--];
                    scr--;
                }else{
                    return scr;
                }
            }
        }
        return scr;
    }
};