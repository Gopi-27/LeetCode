long long coloredCells(int n) {
    // sum of first n odd natural numbers 
    // sum of first n-1 odd natural numbers
    // ex : if n=5 , ans = 1 3 5 7 9 7 5 3 1
    return pow(n,2)+pow(n-1,2);
}
