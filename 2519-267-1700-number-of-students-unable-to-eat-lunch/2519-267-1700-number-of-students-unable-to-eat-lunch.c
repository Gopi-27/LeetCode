int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int zcnt = 0;
    int ocnt = 0;
    for(int i = 0; i < studentsSize; i++){
        if(students[i] == 1)ocnt++;
        else zcnt++;
    }
    for(int i = 0; i < sandwichesSize; i++){
        if(sandwiches[i] == 0){
            if(zcnt > 0)zcnt--;
            else return ocnt + zcnt;
        }else{
            if(ocnt > 0)ocnt--;
            else return ocnt + zcnt;
        }
    }
    return zcnt + ocnt;

}