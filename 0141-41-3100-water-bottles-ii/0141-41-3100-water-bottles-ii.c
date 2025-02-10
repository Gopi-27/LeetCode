int maxBottlesDrunk(int numBottles, int numExchange) {
    	int totcnt=numBottles;
	int rem=0;
	while(numBottles>=numExchange){
		
		totcnt++;
		
		numBottles=1+numBottles-(numExchange);
		numExchange++;
		
	}
	return totcnt;



}