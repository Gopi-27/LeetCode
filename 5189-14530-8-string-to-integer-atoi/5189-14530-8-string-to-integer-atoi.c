int myAtoi(char* s) {
    long long int num = 0;
    int idx = 0;
    int sign = 1;
    while( s[idx] != '\0' && s[idx] == ' ')idx++;
    if(s[idx] == '-' || s[idx] == '+' || (s[idx] >= '0' && s[idx] <= '9')){
        if(s[idx] == '-'){
            sign = -1;
            idx++;
        }else if(s[idx] == '+'){
            sign = 1;
            idx++;
        }
        while(s[idx] != '\0' && s[idx] >= '0' && s[idx] <= '9'){
            if( ( (num * 10) + (s[idx] - '0') ) <= (pow(2,31) - 1) ){
                num = (num * 10) + (s[idx] - '0');
            }
            else {
                if(sign == 1)return pow(2,31) - 1;
                else return -pow(2,31);
            }
            idx++;
        }
        return sign * num;


    }else {
        return num;
    } 



}