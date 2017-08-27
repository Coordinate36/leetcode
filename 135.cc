int max(int a, int b) {
	if(a > b) {
		return a;
	}
	else {
		return b;
	}
}

int candy(int* ratings, int ratingsSize) {
    int num[ratingsSize];
    memset(num, 1, sizeof(num));
    int i;
    int sum = 0;
    for(i = 0; i < ratingsSize; i++) {
    	if(ratings[i + 1] > ratings[i]) {
    		num[i + 1] = num[i] + 1;
    	}
    }
    for(i = ratingsSize - 1; i; i--) {
    	if(ratings[i - 1] > ratings[i]) {
    		num[i - 1] = max(num[i] + 1, num[i - 1]);
    	}
    }
    for(i = 0; i < ratingsSize; i++) {
    	sum += num[i];
    }
    return sum;
}