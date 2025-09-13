class Solution {
public:
    int maxFreqSum(string s) {
        int frr[26] = {0};
        for(int i = 0; s[i] != '\0'; i++){
            frr[s[i] - 'a']++;
        }
        int vmax = 0;
        int cmax = 0;
        for(int i = 0; i < 26; i++){
            if(i == 'a' - 'a' || i == 'e' - 'a' || i == 'i' - 'a' || i == 'o' - 'a' || i == 'u' - 'a'){
                if(frr[i] > vmax)vmax = frr[i];
            }else{
                if(frr[i] > cmax)cmax = frr[i];
            }
        }
        return vmax + cmax;
    }
};