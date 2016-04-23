// Source: https://leetcode.com/problems/valid-sudoku/
// Date: 2016-04-23
/********************************************************************************** 
* 
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* 
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
* 
* A partially filled sudoku which is valid.
* 
* Note:
* > A valid Sudoku board (partially filled) is not necessarily solvable. 
*   Only the filled cells need to be validated.
* 
*               
**********************************************************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int sub_box[3][3][9] = {0};
        for (int r=0; r<board.size(); r++){
            for (int c=0; c<board[0].size(); c++){
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0' - 1;
                    if (row[r][num] || col[c][num] || sub_box[r/3][c/3][num]){
                        return false;
                    }
                    row[r][num] = 1;
                    col[c][num] = 1;
                    sub_box[r/3][c/3][num] = 1;
                }
            }
        }
        return true;
    }
};


class Solution {
    public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, sub_box[9][9] = {false};
        for (int r=0; r<board.size(); r++){
            for (int c=0; c<board[0].size(); c++){
                if (board[r][c] != '.'){
                    int num = board[r][c] - '0' - 1;      // get the number index, -1 due to the index is 0-8
                    if (row[r][num] || col[c][num] || sub_box[r/3*3+c/3][num]){
                        return false;
                    }
                    row[r][num] = true;
                    col[c][num] = true;
                    sub_box[r/3*3+c/3][num] = true;
                }
            }
        }
        return true;
    }
};
