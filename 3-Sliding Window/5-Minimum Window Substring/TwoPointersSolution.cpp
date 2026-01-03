// Time Complexity: O(n + m)  Space Complexity: O(m)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
      if(t.empty()) return "";

      unordered_map<char, int> target, window; //space: O(m)

      for (char &c : t)
      {
        target[c]++;
      }
      
      int need = target.size();
      int have = 0;

      int l = 0;
      int shortest = s.size()+1;
      pair<int, int> result;
      for (int r = 0; r < s.size(); r++) //time: O(n + m)
      {
        window[s[r]]++;

        if (target.count(s[r]) && target[s[r]] == window[s[r]])
        {
          have++;
        }

        while (need == have)
        {
          if ((r-l+1) < shortest)
          {
            shortest = r-l+1;
            result = {l, r};
          }

          window[s[l]]--;
          if (target.count(s[l]) && target[s[l]] > window[s[l]])
          {
            have--;
          }
          
          l++;
        }
      }
      return shortest == s.size()+1 ? "" : s.substr(result.first, shortest);
    }
};

int main (){
   string s = "OUZODYXAZV", t = "XYZ";
   Solution r;
   cout << r.minWindow(s,t) << '\n';

   return 0;
}