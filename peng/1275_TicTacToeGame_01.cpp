// 1275. Find Winner on a Tic Tac Toe Game
// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

class Solution {
public:
    class ttt {
    public:
        void reset () { data = 0; }
        void add (const int& move) { data += (1 << move); }
        bool isWon() const {
            return ((data & 0x0007) == 0x0007) || // 0, 1, 2
                   ((data & 0x0049) == 0x0049) || // 0, 3, 6
                   ((data & 0x0111) == 0x0111) || // 0, 4, 8
                   ((data & 0x0092) == 0x0092) || // 1, 4, 7
                   ((data & 0x0124) == 0x0124) || // 2, 5, 8
                   ((data & 0x0054) == 0x0054) || // 2, 4, 6
                   ((data & 0x0038) == 0x0038) || // 3, 4, 5
                   ((data & 0x01C0) == 0x01C0);   // 6, 7, 8
        }
    private:
        uint16_t data {0};
    };

    string tictactoe(vector<vector<int>>& moves) {
        string ans = "Pending";
        const auto& n = moves.size();
        if (n == 9) { ans = "Draw"; }
        if (n >= 5) {
            ttt t;
            for (int i = n - 1; i >= 0; i -= 2) {
                t.add(moves[i][0] * 3 + moves[i][1]);
            }
            if (t.isWon()) { return ((n & 0x01) ? "A" : "B"); }
        }
        return ans;
    }
};
