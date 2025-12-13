// Time Complexity: O(n)  Space Complexity: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> map; // Space: O(n)

      int l = 0;
      int result = 0;

      for (int r = 0; r < s.size(); r++) // Time: O(n)
      {
         if (map.count(s[r]))
         {
            l= max(map[s[r]]+1, l);
         }
         map[s[r]] = r;
         result = max(result, r-l+1);
      }
      return result;
    }
};

int main (){
   string s = "abba";
   Solution r;
   cout << r.lengthOfLongestSubstring(s) << '\n';

   return 0;
}


