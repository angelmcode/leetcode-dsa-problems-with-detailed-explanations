// Time Complexity: O(n*m)  Space Complexity: O(m)
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      int result = 0;

      unordered_set<char> charac(s.begin(), s.end());//Space: O(m)

      for (char c : charac) // Time: O(n*m)
      {
        int count = 0; 
        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
          if (s[r] == c)
          {
            count++;
          } 
          while ((r-l+1) - count > k)
          {
            if (s[l] == c)
            {
              count--;
            }
            l++;
          }

          result = max(result, r-l+1);
        }
      }
      return result;
    }
};

int main (){
   string s = "AABBB";
   int k = 2;
   Solution r;
   cout << r.characterReplacement(s,k) << '\n';

   return 0;
}