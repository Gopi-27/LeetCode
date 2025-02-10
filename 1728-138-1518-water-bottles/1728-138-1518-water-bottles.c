int numWaterBottles(int numBottles, int numExchange) {
    int totcnt=numBottles;
	int rem=0;
	while(numBottles>=numExchange){
		
		totcnt+=((numBottles)/numExchange);
		rem=((numBottles)%numExchange);
		numBottles=((numBottles)/numExchange)+rem;
		
	}
	return totcnt;

}