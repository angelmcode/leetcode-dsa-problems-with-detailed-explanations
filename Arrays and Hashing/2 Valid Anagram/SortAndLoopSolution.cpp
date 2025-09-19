//This solution is the lest fficient: Time: O(n log n + m log m) Space: O(1).

// Input of 100,000 elements:
// Time execution : 5 milliseconds acording to leetcode.
// Memory usage: 9.5 MB acording to leetcode.

#include <iostream> // needed to use input output operations
#include <algorithm> //need to use sort() function

using namespace std; // avoid write std:: every time

class Solution {
   
public:
    static bool isAnagram(string s, string t) {
      if(s.size() != t.size()){
         return false;
      }
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());

      for (int i = 0; i < s.size(); i++)
      {
         if (s[i] != t[i])
         {
            return false;
         }
         
      }
      return true;
    }
};

int main(){

   //Input: s = "anagram", t = "nagaram"
   cout << (Solution::isAnagram("anagram","nagaram")?"Is an Anagram":"Is Not an Anagram") << '\n';

   // return 0, because the main function especified an int retuning, besides indicates successful execution
   return 0;

}