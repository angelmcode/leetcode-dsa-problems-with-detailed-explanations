// Time Complexity: O(n)  Space Complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.size() > s2.size()) return false;

      vector<int> s1Count(26,0); // space: O(1)
      vector<int> s2Count(26,0); // space: O(1)

      for (int i = 0; i < s1.size(); i++) // time: O(n)
      {
         s1Count[s1[i] - 'a']++;
         s2Count[s2[i] - 'a']++;
      }

      int matches = 0;
      for (int i = 0; i < 26; i++) // time: O(n)
      {
         if (s1Count[i] == s2Count[i])
         {
            matches++;
         }
      }

      int l=0;
      for (int r = s1.size(); r < s2.size(); r++) // time: O(n)
      {
         if (matches == 26)
         {
            return true;
         }
         
         int index = s2[r] - 'a';
         s2Count[index]++;
         if (s1Count[index] == s2Count[index])
         {
            matches++;
         } else if (s1Count[index] + 1 == s2Count[index]){
            matches--;
         }

         index = s2[l] - 'a';
         s2Count[index]--;
         if (s1Count[index] == s2Count[index])
         {
            matches++;
         } else if (s1Count[index] - 1 == s2Count[index]){
            matches--;
         }
         l++;
      }
      return matches == 26;
    }
};

int main (){
   string s1 = "abc", s2 = "lecabee";
   Solution r;
   cout << r.checkInclusion(s1,s2) << '\n';

   return 0;
}