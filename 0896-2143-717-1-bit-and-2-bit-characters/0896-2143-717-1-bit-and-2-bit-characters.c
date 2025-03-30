bool isOneBitCharacter(int* bits, int bitsSize) {
    int idx = 0;
    while(idx < bitsSize - 1){
        if(bits[idx] == 0){
            idx++;
        }else{
            idx += 2;
        }
    }
    if(idx == bitsSize - 1)return true;
    else return false;
}