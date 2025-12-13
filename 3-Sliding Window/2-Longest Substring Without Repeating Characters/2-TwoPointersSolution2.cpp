// Time Complexity: O(n)  Space Complexity: O(n)
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
      if(s.empty()) return 0;
      int l = 0;
      int r = 0;
      int lSubString = 0;

      unordered_set<int> countS; // Space: O(n)
      while (r<s.size()) // Time: O(n)
      {
         if (countS.count(s[r]))
         {
            lSubString = max(lSubString, (int)countS.size());
            countS.erase(s[l]);
            l++;
         }  else {
            countS.insert(s[r]);
            r++;
         }
      }
      lSubString = max(lSubString, (int)countS.size());
      return lSubString;
    }
};

int main (){
   string s = "pwwkew";
   Solution r;
   cout << r.lengthOfLongestSubstring(s) << '\n';

   return 0;
}


