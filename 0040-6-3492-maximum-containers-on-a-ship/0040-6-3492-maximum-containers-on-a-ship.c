int maxContainers(int n, int w, int maxWeight) {
    if((n * n * w) > maxWeight)return maxWeight/w;
    else return n * n;
}