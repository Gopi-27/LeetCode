int maxDistance(int* colors, int colorsSize) {
    int idx;
    for(int i = colorsSize - 1; i > 0; i--){
        if(colors[i] != colors[0]){
            idx = i;
            break;
        }
    }
    for(int i = 0; i < colorsSize; i++){
        if(colors[i] != colors[colorsSize - 1]){
            if(idx < (colorsSize - 1 - i)){
                idx = colorsSize - 1 - i;
            }
            break;
        }
    }
    return idx;
}