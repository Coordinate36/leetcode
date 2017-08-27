int min(int a, int b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int i = 0, j = 0;
    int size = triangleRowSize * (triangleRowSize + 1) / 2;
    int dp[size];
    dp[0] = triangle[0][0];
    for (i = 1; i < triangleRowSize; i++) {
    	int pre_size = i * (i - 1) / 2;
    	int cur_size = i * (i + 1) / 2;
    	dp[cur_size] = dp[pre_size] + triangle[i][0];
    	dp[cur_size + i] = dp[pre_size + i - 1] + triangle[i][i];
    	for (j = 1; j < i; j++) {
    		dp[cur_size + j] = min(dp[pre_size + j - 1] + triangle[i][j], dp[pre_size + j] + triangle[i][j]);
    	}
    }
    int last_size = triangleRowSize * (triangleRowSize - 1) / 2;
    int min_d = dp[last_size];
    for (i = last_size + 1; i < size; i++) {
    	if (dp[i] < min_d) {
    		min_d = dp[i];
    	}
    }
    return min_d;
}