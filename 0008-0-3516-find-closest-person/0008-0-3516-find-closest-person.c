int findClosest(int x, int y, int z) {
    int tper1 = abs(z - x);
    int tper2 = abs(z - y);
    if(tper1 < tper2)return 1;
    else if(tper1 > tper2)return 2;
    else return 0;

    
}