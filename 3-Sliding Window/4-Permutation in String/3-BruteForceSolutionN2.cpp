// Time Complexity: O(n^2)  Space Complexity: O(1)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<char, int> count; // Space: O(1)
        for (char &c : s1) // Time: O(n)
        {
         count[c]++;
        }

        int l=0, r=s1.size()-1;
        while (r<s2.size()) // Time: O(n^2)
        {
         unordered_map<char, int> countW; // Space: O(1)
         for (int i = l; i <= r; i++)
         {
            countW[s2[i]]++;
         }
         if (count == countW)
         {
            return true;
         }else {
            l++;
            r++;
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