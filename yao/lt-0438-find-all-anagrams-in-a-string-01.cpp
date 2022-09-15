  vector<int> findAnagrams(string& s, string& p) {
        int ls = s.length();
        int lp = p.length();
        if (ls < lp) return {};
        
        vector<int> p_cs(26, 0);
        vector<int> subs_cs(26, 0);

        vector<int> ret;
        int sum_p {0};
        for (int i = 0; i < lp; i++) {
            sum_p += p[i];
            p_cs[p[i]-'a'] += 1;
        }

        int sum_subs {0};
        for (int i = 0; i < lp; i++) {
            sum_subs += s[i];
            subs_cs[s[i]-'a'] += 1;
        }

        if (sum_subs == sum_p && p_cs == subs_cs) {
            ret.push_back(0);
        }

        for (int i = lp; i < ls; i++) {
            sum_subs = sum_subs - s[i-lp] + s[i];
            subs_cs[s[i-lp]-'a'] -= 1;
            subs_cs[s[i]-'a'] += 1;

            if ((sum_subs == sum_p) && 
                ((ret.size()>0 && ret.back()==i-lp && s[i-lp] == s[i]) || p_cs == subs_cs)) {
                ret.push_back(i-lp+1);
            }
        }
        return ret;        
    }
