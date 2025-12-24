// Time Complexity: O(n)  Space Complexity: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char, int> count; // Space: O(n)
      int result = 0;

      int l=0;
      int maxf = 0;
      for (int r = 0; r < s.size(); r++) // Time: O(n)
      {
        count[s[r]]++;
        maxf = max(maxf, count[s[r]]);
        while ((r-l+1) - maxf > k)
        {
          count[s[l]]--;
          l++;
        }
        result = max(result, r-l+1);
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