int GetDay(char* str){
    int month = (str[0] - '0') * 10 + (str[1] - '0');
    int day = (str[3] - '0') * 10 + (str[4] - '0');
    int arr[] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
    return arr[month] + day;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int As = GetDay(arriveAlice);
    int Ae = GetDay(leaveAlice);
    int Bs = GetDay(arriveBob);
    int Be = GetDay(leaveBob);
    if(Be < As || Bs > Ae)return 0;
    if(Be <= Ae){
        if(Bs < As)return Be - As + 1;
        return Be - Bs + 1;
    }
    if(Bs < As){
        return Ae - As + 1;
    }
    return Ae - Bs + 1;

}