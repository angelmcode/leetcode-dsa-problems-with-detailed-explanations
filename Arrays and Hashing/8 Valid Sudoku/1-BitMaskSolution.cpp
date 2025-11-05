//Time Complexity: 0(n^2)  Space Complexity: O(n)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:

    static bool isValidSudoku(vector<vector<char>>& board) {
      // Space: O(n)
      int row[9] = {0};
      int col[9] = {0};
      int square[9] = {0};

      for (int r = 0; r < 9; r++) //Time: 0(n^2)
      {
         for (int c = 0; c < 9; c++)
         {
            if (board[r][c] == '.') continue; 
            
            int s = ((r/3)*3 + (c/3));
            int value = board[r][c] - '1';

            if ((row[r] & (1 << value)) || (col[c] & (1 << value)) || (square[s] & (1 << value)))
            {
               return false;
            }

            row[r] |= (1<<value);
            col[c] |= (1<<value);
            square[s] |= (1<<value);
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