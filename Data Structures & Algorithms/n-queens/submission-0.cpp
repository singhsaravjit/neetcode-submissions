class Solution {
public:
    vector<string> board;
    vector<bool> col, posdiag, negdiag;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {

        col.resize(n,false);
        posdiag.resize(2*n, false);
        negdiag.resize(2*n, false);
        board.resize(n, string(n,'.'));

        backtrack(0,n);
        return res;
        
    }

    void backtrack(int r, int n){

        if(r == n){
            res.push_back(board);
            return;
        }
        for(int c=0;c< n;c++){
            if(col[c] || posdiag[r+c] || negdiag[r-c+n]){
                continue;
            }
            col[c]=true;
            posdiag[r+c]=true;

            negdiag[r-c+n]=true;
            board[r][c]='Q';
            backtrack(r+1,n);
            col[c] = false;
            posdiag[r + c] = false;
            negdiag[r - c + n] = false;
            board[r][c] = '.';
        }




    }
};
