class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int frr[10] = {0};
        for(int i = 0; secret[i] != '\0'; i++)frr[secret[i] - '0']++;
        for(int i = 0; secret[i] != '\0'; i++){
            if(secret[i] == guess[i]){
                bulls++;
                frr[guess[i] - '0']--;
            }
            
        }
        for(int i = 0; secret[i] != '\0'; i++){
            if(secret[i] != guess[i] && frr[guess[i] - '0'] > 0){
                cows++;
                frr[guess[i] - '0']--;
            }
        }
        string Ans = "";
        if(bulls == 0)Ans += '0';
        while(bulls > 0){
            char ch = (bulls % 10) + '0';
            Ans = ch + Ans;
            bulls /= 10;
        }
        Ans += 'A';
        string Bns = "";
        if(cows == 0)Bns += '0';
        while(cows > 0){
            char ch = (cows % 10) + '0';
            Bns = ch + Bns;
            cows /= 10;
        }
        Bns += 'B';
        return Ans + Bns;
    }
};