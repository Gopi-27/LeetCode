char slowestKey(int* releaseTimes, int releaseTimesSize, char* keysPressed) {
        int max = releaseTimes[0];
        char chmax = keysPressed[0];
        for(int i = 1; i < releaseTimesSize; i++){
            if((releaseTimes[i] - releaseTimes[i - 1]) > max){
                max = releaseTimes[i] - releaseTimes[i - 1];
                chmax = keysPressed[i];
            }else if ((releaseTimes[i] - releaseTimes[i - 1]) == max){
                if(keysPressed[i] > chmax)chmax = keysPressed[i];
            }
        }
        return chmax;
}