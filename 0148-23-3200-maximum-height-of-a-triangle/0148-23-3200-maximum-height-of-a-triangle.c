int maxHeightOfTriangle(int red, int blue) {
    int tred=red;
    int tblue=blue;
    // starting with blue
    int cnt1=0;
    int i=1;
    while(1){
        if(i%2!=0){
            if((blue-i)>=0){
                blue-=i;
                cnt1++;
            }else break;
        }else{
            if((red-i)>=0){
                red-=i;
                cnt1++;
            }else break;
        }
        i++;
    }
    //startin with red;
    int cnt2=0;
    i=1;
    while(1){
        if(i%2!=0){
            if((tred-i)>=0){
                tred-=i;
                cnt2++;
            }else break;
        }else{
            if((tblue-i)>=0){
                tblue-=i;
                cnt2++;
            }else break;
        }
        i++;
    }
    if(cnt1>cnt2){
        return cnt1;
    }else{
        return cnt2;
    }
}