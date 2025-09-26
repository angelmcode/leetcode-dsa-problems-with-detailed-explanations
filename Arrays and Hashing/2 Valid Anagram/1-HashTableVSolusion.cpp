//This solution is fficient: Time: O(n + m) Space: O(1) since we have at most 26 different characters.

// Time execution : 0 milliseconds acording to leetcode.
// Memory usage: 9.5 MB acording to leetcode.

#include <iostream> // needed to use input output operations
#include <vector> // needed to use vector (dynamic array)
#include <algorithm> //need to use sort() function

using namespace std; // avoid write std:: every time

class Solution {
   
public:
    // static allows us to call the method without creating an instance of the Solution class, strings are pass by reference in order to not creates copies of the strings
    static bool isAnagram(string &s, string &t) {

      // if compare the size of the strings
      if(s.size() != t.size()) return false;
      
      // a dynamic array is set with 26 element initializes with 0
      vector<int> count(26,0);

      for (int i = 0; i < s.size(); i++)
      {
       //every time that an letter is encounter add 1 to the corresponding index in the vector
       count[s[i] - 'a']++;

       //every time that an letter is encounter subtract 1 to the corresponding index in the vector
       count[t[i] - 'a']--;
      }
      
      // this for loop review all the vector, index by index
      for (auto c : count)
      {
         // if encounters a element diferent to 0 means that the strings are not anagrams
         if (c != 0) return false;
      }

      // if the strings have the same size and all the elements in the array are 0, return true that means the strings are anagrams
      return true;
      
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