class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

    bool find(vector<vector<char>>& board, int i, int j,
              int indx, string &word, int n, int m) {

        if (indx == word.length())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m ||
            board[i][j] == '$' || board[i][j] != word[indx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto &dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (find(board, ni, nj, indx + 1, word, n, m)) {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    find(board, i, j, 0, word, n, m))
                    return true;
            }
        }

        return false;
    }
};