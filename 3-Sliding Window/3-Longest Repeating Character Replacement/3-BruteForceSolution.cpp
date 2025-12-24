// Time Complexity: O(n^2)  Space Complexity: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      int result = 0;

      for (int i = 0; i < s.size(); i++) // Time: O(n^2)
      {
        unordered_map<char, int> count; // Space: O(n)
        int maxf = 0;
        for (int j = i; j < s.size(); j++)
        {
          count[s[j]]++;
          maxf = max(maxf, count[s[j]]);

          if ((j-i+1)-maxf <= k)
          {
            result = max(result, j-i+1);
          }
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