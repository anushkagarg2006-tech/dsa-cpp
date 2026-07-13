class Solution {
public:
    int MOD = 1337;

    // Same fast power jo humne pehle kiya tha
    long long helper(long long base, long long expo) {
        base = base % MOD;
        long long ans = 1;
        while (expo > 0) {
            if (expo % 2 == 0) {
                base = (base * base) % MOD;
                expo = expo / 2;
            } else {
                ans = (ans * base) % MOD;
                expo -= 1;
            }
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        long long result = 1;
        for (int i = 0; i < b.size(); i++) {
            int digit = b[i];
            // result ko power 10 kardo, fir naye digit ka a^digit multiply karo
            result = (helper(result, 10) * helper(a, digit)) % MOD;
        }
        return (int)result;
    }
};