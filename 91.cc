#include <stdio.h>
#include <string.h>

int numDecodings(char* s) {
	int len = strlen(s);
	if (len == 0 || s[0] == '0') {
		return 0;
	}
    int dp[len + 1];
    int i;
    dp[0] = 1;
    dp[1] = 1;
    for (i = 1; i < len; i++) {
    	if (s[i] == '0') {
    		if (s[i - 1] == '1' || s[i - 1] == '2') {
    			dp[i + 1] = dp[i - 1];
    			continue;
    		} else {
    			return 0;
    		}
    	}
    	if (s[i - 1] == '0') {
    		dp[i + 1] = dp[i];
    		continue;
    	}
    	if ((s[i - 1] - 48) * 10 + s[i] - 48 < 27) {
    		dp[i + 1] = dp[i] + dp[i - 1];
    	} else {
    		dp[i + 1] = dp[i];
    	}
    }
    for (i = 0; i <= len; i++) {
    	printf("%d\n", dp[i]);
    }
    return dp[len];
}

int main()
{
	printf("\n%d\n", numDecodings("100"));
	return 0;
}