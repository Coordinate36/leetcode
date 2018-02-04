#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
}; */

/* class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;  
        if(n == 1) return x;  
        int t = n >> 1;
        if(n < 0) {  
            t = -t;  
            x = 1 / x;  
        } 
        double tmp = myPow(x, t);  
        if(n & 1) return tmp * tmp * x;
        return tmp * tmp;
    }
}; */

class Solution {
public:
    double myPow(double x, int n) {
        int m = n >= 0 ? n: -(n + 1);
        double res = 1;
        for (double tmp = x; m > 0; m >>= 1) {
            if (m & 1) {
                res *= tmp;
            }
            tmp *= tmp;
        }
        if (n < 0) {
            return 1 / (res * x);
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(34.00515, -3) << endl;
    return 0;
}