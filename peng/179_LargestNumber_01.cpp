// 179. Largest Number
// https://leetcode.com/problems/largest-number/

class Solution {
public:
    static bool myIsLarge(const string& a, const string& b) {
        if (a.size() > b.size()) {
            if (a.substr(0, b.size()) == b) {
                return myIsLarge(a.substr(b.size()), b);
            }
        }
        else if (a.size() < b.size()) {
            if (b.substr(0, a.size()) == a) {
                return myIsLarge(a, b.substr(a.size()));
            }
        }
        return a > b;
    }

    struct {
        bool operator()(int a, int b) const { return myIsLarge(std::to_string(a), std::to_string(b)); }
    } customLarge;


    string largestNumber(vector<int>& nums) {
        std::string ans;
        std::sort(nums.begin(), nums.end(), customLarge);
        for (auto e : nums) {
            ans += std::to_string(e);
        }
        // Handle special cases
        while (ans.size() > 0 && ans[0] == '0') {
            // drop leading zero
            ans = ans.substr(1);

        }
        if (ans.empty()) {
            ans = "0";
        }

        return ans;
    }
};
