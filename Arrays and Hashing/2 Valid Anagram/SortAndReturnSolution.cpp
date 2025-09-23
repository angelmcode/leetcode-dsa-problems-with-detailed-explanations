//This solution is the lest fficient: Time: O(n log n + m log m) Space: O(1) if the stings are pass by reference O(n) if are pass by value.

// Time execution : 4 milliseconds acording to leetcode.
// Memory usage: 9.7 MB acording to leetcode.

#include <iostream> // needed to use input output operations
#include <algorithm> //need to use sort() function

using namespace std; // avoid write std:: every time

class Solution {
   
public:
   // static allows us to call the method without creating an instance of the Solution class, strings are pass by reference  
    static bool isAnagram(string &s, string &t) {

      // if compare the size of the strings
      if(s.size() != t.size()){
         return false;
      }
       // if the strings have the same size are sort by the function sort() 
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());
      
      //true or false are returned depend is the expresion s == t is true or false
      return s == t;
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