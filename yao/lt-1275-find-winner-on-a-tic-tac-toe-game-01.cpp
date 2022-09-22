class Solution {
public:

    bool linear(vector<vector<int>>& moves, std::array<int, 3>& m) {
        return ((moves[m[2]][1] - moves[m[1]][1]) * (moves[m[1]][0] - moves[m[0]][0]) == (moves[m[1]][1] - moves[m[0]][1]) * (moves[m[2]][0] - moves[m[1]][0]));
    }

    string tictactoe(vector<vector<int>>& moves) {

        int move_nums = moves.size();
        if (move_nums < 5) return "Pending";

        
        constexpr int len = 3;
        std::array<int, len> m = {0};
 
        // only need to check the last move
        m[0] = move_nums-1;         
        for (int i = move_nums-3; i >=((move_nums-1) & 0x1) +2; i-=2) {
            m[1] = i;
            for (int j = i - 2; j >= ((move_nums-1) & 0x1); j -= 2 ) {                
                m[2] = j;                
                if (linear(moves, m)) {
                    return ((move_nums & 0x1)? "A": "B");
                }
            }
        }

        if (move_nums == 9) return "Draw";
        return "Pending";
       
    }
};
