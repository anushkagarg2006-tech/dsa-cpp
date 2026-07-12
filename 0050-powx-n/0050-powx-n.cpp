class Solution {
private:
    double binaryPow(double x, long long n) {
        if (n == 0)
            return 1.0;

        double half = binaryPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        }

        else {
            return x * half * half;
        }
    }

public:
    double myPow(double x, int n) {
        long long nn = n;

        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }

        return binaryPow(x, nn);
    }
};