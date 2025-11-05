//Time Complexity: 0(n^2)  Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_set> // needed to use hash set

using namespace std; // needed to avoid write std:: every time

class Solution {
public:

    static bool isValidSudoku(vector<vector<char>>& board) {

      for (int row = 0; row < 9; row++) //Time: 0(n^2)
      {
         unordered_set<char> seen; //Space: 0(n)
         for (int j = 0; j < 9; j++)
         {
            if (board[row][j] != '.' && !seen.insert(board[row][j]).second)
            {
               return false;
            }
         }
      }

      for (int col = 0; col < 9; col++) //Time: 0(n^2)
      {
         unordered_set<char> seen; //Space: 0(n)
         for (int j = 0; j < 9; j++)
         {
            if (board[j][col] != '.' && !seen.insert(board[j][col]).second)
            {
               return false;
            }
         }
      }

      for (int box = 0; box < 9; box++) //Time: 0(n^2)
      {
         unordered_set<char> seen; //Space: 0(n)

         for (int j = 0; j < 3; j++)
         {  
            for (int k = 0; k < 3; k++)
            { 
               // (box/3)round the value to down, given is a integer division
               int row = (box / 3) * 3 + j;  // 0 0 0 3 3 3 6 6 6
               int col = (box % 3) * 3 + k;  // 0 3 6 0 3 6 0 3 6
                                             // 1 2 3 4 5 6 7 8 9

               if (board[row][col] != '.' && !seen.insert(board[row][col]).second)
               {
                  return false;
               }
            }
         }
      }
      return true;
    }
};

int main(){
   vector<vector<char>> board = {
    {'1','2','.','.','3','.','.','.','.'},
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','1','.','.','.','.','.','3'},
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