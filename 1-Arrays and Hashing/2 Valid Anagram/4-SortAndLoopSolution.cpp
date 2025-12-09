//This solution is the lest fficient: Time: O(n log n + m log m) Space: O(1) if the stings are pass by reference O(n) if are pass by value.

// Time execution : 5 milliseconds acording to leetcode.
// Memory usage: 9.5 MB acording to leetcode.

#include <iostream> // needed to use input output operations
#include <algorithm> //need to use sort() function

using namespace std; // avoid write std:: every time

class Solution {
   
public:

    // static allows us to call the method without creating an instance of the Solution class, strings are pass by reference  
    static bool isAnagram(string &s, string &t) {

      // if comapare the size of the strings
      if(s.size() != t.size()){
         return false;
      }

      // if the strings have the same size are sort by the function sort() 
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());

      // this for loop would be abreviate with return s == t 
      for (int i = 0; i < s.size(); i++)
      {
         //compare every element of the strings to see if they are the same
         if (s[i] != t[i])
         {
            // return false if some element is no the same in both strings
            return false;
         }
         
      }
      // return true if every element is the same in both strings which mean the strings are anagrams
      return true;
    }
};

int main(){

   string s1 = "anagram";
   string t1 = "nagaram";
   //Input: s = "anagram", t = "nagaram"
   cout << (Solution::isAnagram(s1,t1)?"They are an Anagram":"They are Not an Anagram") << '\n';

   //the strings are sorted because are pass by reference
   cout << s1 << '\n' << t1 << '\n';

   // return 0, because the main function especified an int retuning, besides indicates successful execution
   return 0;

}