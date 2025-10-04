int Min(int a, int b){
    if(a > b)return b;
    return a;
}
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int dis;
    int Ans = 0;
    while(left < right){
        int Area = (right - left) * Min(height[left],height[right]);
        if(Area > Ans)Ans = Area;
        if(height[left] > height[right])right--;
        else left++;
    }
    return Ans;
}