class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int,int> count;
        for (int card : hand) count[card]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& [val, freq] : count) {
            minHeap.push(val);
        }

        while (!minHeap.empty()) {
            int smallest = minHeap.top();

            if (count[smallest] == 0) {
                minHeap.pop();
                continue;
            }

            for (int c = smallest; c < smallest + groupSize; c++) {
                if (count[c] == 0) return false;
                count[c]--;
            }
        }

        return true;
    }
};