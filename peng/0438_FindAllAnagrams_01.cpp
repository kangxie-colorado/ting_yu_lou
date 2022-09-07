// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    class CAnagram {
    private:
        int tab[26] = {0};
    public:
        void add(const char& c) { tab[c - 'a']++; }
        void del(const char& c) { tab[c - 'a']--; }
        bool equal(const CAnagram& v) {
            for (int i = 0; i < 26; i++) {
                if (tab[i] != v.tab[i]) { return false; }
            }
            return true;
        }
    };

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        const int m = s.size();
        const int n = p.size();
        if (m < n) { return ans;}

        CAnagram target, t1;
        for (int i = 0; i < n; i++) {
            target.add(p[i]);
            t1.add(s[i]);
        }
        if (t1.equal(target)) {
            ans.push_back(0);
        }
        for (int i = n; i < m; i++) {
            t1.add(s[i]);
            t1.del(s[i - n]);
            if (t1.equal(target)) {
                ans.push_back(i + 1 - n);
            }
        }
        return ans;
    }
};
