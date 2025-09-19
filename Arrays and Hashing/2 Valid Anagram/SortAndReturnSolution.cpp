#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
   
public:
    static bool isAnagram(string s, string t) {
      if(s.size() != t.size()){
         return false;
      }
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());

      return s == t;
    }
};

int main(){

   //Input: s = "anagram", t = "nagaram"
   cout << Solution::isAnagram("anagram","nagaram") << '\n';

}