//This solution is fficient: Time: O(n + m) Space: O(1) since we have at most 26 different characters.

// Time execution : 3 milliseconds acording to leetcode.
// Memory usage: 9.5 MB acording to leetcode.

#include <iostream> // needed to use input output operations
#include <unordered_map> // needed to use unordered map

using namespace std; // avoid write std:: every time

class Solution {
   
public:
    // static allows us to call the method without creating an instance of the Solution class, strings are pass by reference in order to not creates copies of the strings
    static bool isAnagram(string &s, string &t) {
      
      // if compare the size of the strings
      if (s.size() != t.size()) return false;

      // make 2 hash tables, for store the characters count of s ant t
      unordered_map<char, int> CheckS;
      unordered_map<char, int> CheckT;

      for (int i = 0; i < s.size(); i++)
      {
         // store every character from s and t and their frecuency of apear
         CheckS[s[i]]++;
         CheckT[t[i]]++;
      }

      // verify if CheckS and CheckT are equal, if they are equal means are anagrmas, otherwise they are not anagrams
      return CheckS == CheckT;
    }
};

int main(){

   string s1 = "anagram";
   string t1 = "nagaram";

   //Input: s = "anagram", t = "nagaram"
   cout << (Solution::isAnagram(s1,t1)?"They are Anagrams":"They are Not Anagrams") << '\n';

   //the strings are sorted because are pass by reference
   cout << s1 << '\n' << t1 << '\n';

   // return 0, because the main function especified an int retuning, besides indicates successful execution
   return 0;

}