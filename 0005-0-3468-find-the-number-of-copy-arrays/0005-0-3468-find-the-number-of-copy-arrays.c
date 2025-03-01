int Max(int a, int b){
    if(a>b)return a;
    else return b;
}
int Min(int a,int b){
    if(a>b)return b;
    else return a;
}
int No_Of_Com(int org1,int org2,int *dup1,int *dup2){
    if(*dup1<org1 && *dup2<org1){
        *dup1=0;
        *dup2=0;
        return 0;
    }
    else if(*dup1>org2 && *dup2>org2){
        *dup1=0;
        *dup2=0;
        return 0;
    }
    else{
        *dup1=Max(org1,*dup1);
        *dup2=Min(org2,*dup2);
        return Min(org2,*dup2)-Max(org1,*dup1)+1;
    }
}
int countArrays(int* original, int originalSize, int** bounds, int boundsSize, int* boundsColSize) {
    int vals[originalSize];
    vals[0]=bounds[0][1]-bounds[0][0]+1;
    int ans=vals[0];
    for(int i=1; i<originalSize; i++){
        int dif=original[i]-original[i-1];
        vals[i]=No_Of_Com(bounds[i-1][0]+dif,bounds[i-1][1]+dif,&bounds[i][0],&bounds[i][1]);
        if(ans>vals[i])ans=vals[i];
    }

    return ans;
}