int Min(int a, int b){
    if(a > b)return b;
    return a;
}

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){   
    if(start < destination){
        int forward = 0;
        for(int i = start; i < destination; i++)forward += distance[i];
        int backward = 0;
        for(int i = 0; i < start; i++)backward += distance[i];
        for(int i = destination; i < distanceSize; i++)backward += distance[i];
        return Min(backward,forward);
    }else{
        int forward = 0;
        for(int i = start; i < distanceSize; i++)forward += distance[i];
        for(int i = 0; i < destination; i++)forward += distance[i];
        int backward = 0;
        for(int i = destination; i < start; i++)backward += distance[i];
        return Min(backward,forward);
    }       
        
}