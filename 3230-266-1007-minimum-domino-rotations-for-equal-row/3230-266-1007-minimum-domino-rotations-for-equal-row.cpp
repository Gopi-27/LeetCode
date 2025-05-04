class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int flag1 = 0;
        int flag2 = 0;
        int key1 = tops[0];
        int n = tops.size();
        int cnt1 = 0;
        int scnt1 = 0;
        for(int i = 0; i < n; i++){
            if(tops[i] != key1 && bottoms[i] == key1)cnt1++;
            else if(tops[i] != key1 && bottoms[i] != key1){
                flag1 = 1;
                break;
            }else if(tops[i] == key1 && bottoms[i] == key1)scnt1++;
        }
        int scnt2 = 0;
        int cnt2 = 0;
        int key2 = bottoms[0];
        for(int i = 0; i < n; i++){
            if(tops[i] == key2 && bottoms[i] != key2)cnt2++;
            else if(tops[i] != key2 && bottoms[i] != key2){
                flag2 = 1;
                break;
            }else if(tops[i] == key2 && bottoms[i] == key2)scnt2++; 
        }
        if(flag1 == 1 && flag2 == 1)return -1;
        if(flag1 == 1){
            return min(cnt2,n - cnt2 - scnt2);
        }
        if(flag2 == 1){
            return min(cnt1,n - cnt1 - scnt1);
        }
        return min(min(cnt2,n - cnt2 - scnt2),min(cnt1,n - cnt1 - scnt1));

    }
};