#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

char *longestPalindrome(char *s) {
    int len = strlen(s);
    int resLeft = 0, resRight = 0;
    if (len <= 1){
    	return s;
    }
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i < len; i++){
    	dp[i][i] = 1;
    	if(s[i] == s[i - 1]){
    		dp[i - 1][i] = 1;
    		resLeft = i - 1;
    		resRight = i;
    	}
    }
    for(int l = 3; l <= len; l++){
    	for(int i = 0; i <= len - l; i++){
    		if(s[i] == s[i + l - 1] && dp[i + 1][i + l - 2]){
    			dp[i][i + l - 1] = true;
    			if(resRight - resLeft + 1 < l){
    				resLeft = i;
    				resRight = i + l - 1;
    			}
    		}
    	}
    }
    int l = resRight - resLeft + 1;
    char *result = (char *)malloc(l + 1);
    for(int i = 0; i < l; i++){
    	result[i] = s[resLeft + i];
    }
    result[l] = 0;
    return result;
}

int main()
{
	char *s = "abbd";
	printf("%s\n", longestPalindrome(s));
	return 0;
}