class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long )m * k > bloomDay.size()) {
            return -1;
        }
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        while (s < e) {
            int mi = s + (e - s) / 2;
            int flowerbloom = 0;
            int totalflower = 0;
            for (int i : bloomDay) {

                if (i <= mi) {
                    flowerbloom++;
                } else {
                    flowerbloom = 0;
                }
                if (flowerbloom == k) {
                    totalflower++;
                    flowerbloom = 0;
                }
            }
            if (totalflower >= m) {
                e = mi;
            } else {
                s = mi + 1;
            }
        }
        return s;
    }
};