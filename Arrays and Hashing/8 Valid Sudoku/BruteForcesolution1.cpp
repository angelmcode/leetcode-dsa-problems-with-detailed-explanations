//Time Complexity: 0(n^2)  Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_set> // needed to use hash set

using namespace std; // needed to avoid write std:: every time

class Solution {
public:

    static bool isValidSudoku(vector<vector<char>>& board) {

      for (int i = 0; i < 9; i++)
      {
         unordered_set<char> seen;
         for (int j = 0; j < 9; j++)
         {
            if (board[i][j] != '.' && !seen.insert(board[i][j]).second)
            {
               return false;
            }
         }
      }

      for (int i = 0; i < 9; i++)
      {
         unordered_set<char> seen;
         for (int j = 0; j < 9; j++)
         {
            if (board[j][i] != '.' && !seen.insert(board[j][i]).second)
            {
               return false;
            }
         }
      }

      int kstart = 0;
      int kend = 3;
      int jstart = 0;
      int jend = 3;

      for (int i = 0; i < 9; i++)
      {
         unordered_set<char> seen;
         if (i==3)
         {
            jstart=3;
            jend=6;
            kstart=0;
            kend=3;
         } else if (i==6)
         {
            jstart=6;
            jend=9;
            kstart=0;
            kend=3;
         }

         for (int j = jstart; j < jend; j++)
         {
            for (int k = kstart; k < kend; k++)
            {
               if (board[j][k] != '.' && !seen.insert(board[j][k]).second)
               {
                  return false;
               }
            }
         }
         kstart = kend;
         kend = kend + 3;
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