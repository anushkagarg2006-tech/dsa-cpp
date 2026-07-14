class Solution {
public:
    vector<string> ans;

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return ans;
        backtrack(num, target, 0, "", 0, 0);
        return ans;
    }

    void backtrack(const string& num, int target, int index, string path, long currentVal, long prevNum) {
        // Base Case: If we have reached the end of the string, check if it evaluates to the target
        if (index == num.length()) {
            if (currentVal == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            // Corner Case: Skip numbers with leading zeros (e.g., "05")
            if (i > index && num[index] == '0') {
                break;
            }

            string part = num.substr(index, i - index + 1);
            long customNum = stol(part);

            // If it's the first number in our expression, we don't prepend any operator
            if (index == 0) {
                backtrack(num, target, i + 1, part, customNum, customNum);
            } else {
                // Scenario 1: Addition '+'
                backtrack(num, target, i + 1, path + "+" + part, currentVal + customNum, customNum);

                // Scenario 2: Subtraction '-'
                backtrack(num, target, i + 1, path + "-" + part, currentVal - customNum, -customNum);

                // Scenario 3: Multiplication '*'
                // We revert the previous operation and apply the multiplication precedence rules
                backtrack(num, target, i + 1, path + "*" + part, currentVal - prevNum + (prevNum * customNum), prevNum * customNum);
            }
        }
    }
};