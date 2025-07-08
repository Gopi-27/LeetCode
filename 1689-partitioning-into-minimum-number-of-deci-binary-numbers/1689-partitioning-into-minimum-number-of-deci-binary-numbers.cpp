class Solution {
public:
    int minPartitions(string n) {
        char ans = n[0];
        for(int i = 1; n[i] != '\0'; i++)if(ans < n[i])ans = n[i];        
        return ans - '0';
    }
};