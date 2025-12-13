// Time Complexity: O(n^2)  Space Complexity: O(n)
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int size = s.size();

      int longestSubString = 0;
      for (int i = 0; i < size; i++) // Time: O(n^2)
      {
         unordered_set<char> countS; // Space: O(n)
         for (int j = i; j < size; j++)
         {
            if (countS.count(s[j]))
            {
               break;
            }
            countS.insert(s[j]);
         }
         int substring = countS.size();
         longestSubString = max(longestSubString, substring);
      }
      return longestSubString;
    }
};

int main (){
   string s = "aab";
   Solution r;
   cout << r.lengthOfLongestSubstring(s) << '\n';

   return 0;
}