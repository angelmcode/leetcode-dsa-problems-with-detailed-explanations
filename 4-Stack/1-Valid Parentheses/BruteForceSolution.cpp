// Time Complexity: O(n^2)  Space Complexity: O(1)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      while (s.find("{}") != string::npos || s.find("[]") != string::npos || s.find("()") != string::npos )
      {
         if (s.find("{}") != string::npos)
         {
            s.erase(s.find("{}"),2);
            continue;
         }

         if (s.find("[]") != string::npos)
         {
            s.erase(s.find("[]"),2);
            continue;
         }

         if (s.find("()") != string::npos)
         {
            s.erase(s.find("()"),2);
            continue;
         }
      }
      return s.empty();
    }
};


int main (){
   string s = "{}";
   Solution r;
   auto result = r.isValid(s);

   cout << result << '\n';

   return 0;
}