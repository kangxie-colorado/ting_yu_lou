// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        if (temperatures.size() < 2) {
            return ans;
        }

        int  d = 0;     // Distance
        bool f = false; // found
        for (int i = temperatures.size() - 2; i >= 0; i--) {
            d = 1;
            f = true;
            while (temperatures[i] >= temperatures[i + d]) {
                if (ans[i + d] == 0) {
                    f = false;
                    break;
                }
                d += ans[i + d];
                if ((i + d + 1) > temperatures.size()) {
                    // Not found, or end of the array
                    f = false;
                    break;
                }
            }
            if (f) {
                ans[i] = d;
            }
        }
        return ans;
    }
};

