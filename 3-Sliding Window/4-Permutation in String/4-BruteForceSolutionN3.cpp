// Time Complexity: O(n^3 log n)  Space Complexity: O(n)
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end()); // Time: O(n log n)

        for (int i = 0; i < s2.size(); i++) // Time: O(n^3 log n)
        {
         for (int j = i; j < s2.size(); j++)
         {
            string copy = s2.substr(i,j-i+1); // Space: O(n)
            sort(copy.begin(), copy.end()); // Time: O(n log n)

            if (copy == s1) // Time: O(n)
            {
               return true;
            }
         }
        }
        return false;
    }
};

int main (){
   string s1 = "abc", s2 = "lecabee";
   Solution r;
   cout << r.checkInclusion(s1,s2) << '\n';

   return 0;
}