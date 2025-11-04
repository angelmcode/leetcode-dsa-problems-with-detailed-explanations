//Time Complexity: 0(n^2)  Space Complexity: O(n^2)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_set> // hash set
#include <unordered_map> // hash map
#include <map> // map: implemented as a balanced binary search tree
using namespace std; // needed to avoid write std:: every time

class Solution {
public:

    static bool isValidSudoku(vector<vector<char>>& board) {

      unordered_map<int, unordered_set<char>> row, col;
      map< pair<int, int>, unordered_set<char>> square;

      for (int r = 0; r < 9; r++)
      {
         for (int c = 0; c < 9; c++)
         {
            if (board[r][c] == '.') continue;

            pair<int, int> s = {r/3,c/3};

            if (row[r].count(board[r][c]) || col[c].count(board[r][c]) || square[s].count(board[r][c])){
               return false;
            }

            row[r].insert(board[r][c]);
            col[c].insert(board[r][c]);
            square[s].insert(board[r][c]);
         }  
      }
      return true;
   }
};

int main(){
   vector<vector<char>> board = {
    {'1','2','.','.','3','.','.','.','.'},  
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','.','.','.','.','.','.','3'},
    {'5','.','.','.','6','.','.','.','4'},
    {'.','.','.','8','.','3','.','.','5'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','.','.','.','.','.','2','.','.'},
    {'.','.','.','4','1','9','.','.','8'},
    {'.','.','.','.','8','.','.','7','9'}
   };

   bool result = Solution::isValidSudoku(board);

   cout << (result?"true":"false") << '\n';

   return 0;
}