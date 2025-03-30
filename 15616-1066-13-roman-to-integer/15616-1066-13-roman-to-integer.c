int Value(char ch){
    if(ch == 'I')return 1;
    else if(ch == 'V')return 5;
    else if(ch == 'X')return 10;
    else if(ch == 'L')return 50;
    else if(ch == 'C')return 100;
    else if(ch == 'D')return 500;
    else return 1000;
}
int romanToInt(char* s) {
        int len = strlen(s);
        int ans = 0;
        ans = Value(s[len - 1]);
        for(int i = len - 2; i >= 0; i--){
            if(Value(s[i]) >= Value(s[i + 1]))ans += Value(s[i]);
            else ans -= Value(s[i]);
        }
        return ans;
}