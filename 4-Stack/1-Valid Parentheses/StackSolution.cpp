// Time Complexity: O(n)  Space Complexity: O(n)
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string& s) {
      if (s.size() % 2 == 1) return false;
      unordered_map<char, char>parenthesis({{'[',']'}, {'(',')'}, {'{','}'}}); //space O(1)
      stack<char> STK; // space O(n)
      for (int i = 0; i < s.size(); i++) // time O(n)
      {
         if (parenthesis.count(s[i]))
         {
            STK.push(s[i]);
         } else {
            if(STK.empty()) return false;
            if(parenthesis[STK.top()] != s[i]) return false;
            STK.pop();
         }
      }
      if(STK.size() != 0) return false; 
      return true;
    }
};


int main (){
   string s = "{}";
   Solution r;
   auto result = r.isValid(s);

   cout << result << '\n';

   return 0;
}