  int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0;
         
        for (int i : nums) {         
            x1 = (x1 ^ i) & ~x2;
            x2 = (x2 ^ i) & ~x1;
        }

        return x1;  
    }
