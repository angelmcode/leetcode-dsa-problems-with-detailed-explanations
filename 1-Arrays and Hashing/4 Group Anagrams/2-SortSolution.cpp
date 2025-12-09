// time complexity: O(n * k log k + k * n log n)  space complexity: O(n * k)

#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <algorithm> // needed to use sort fuction
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
        vector<vector<string>> result; // Space: O(1) initially, O(n*k) final
        vector<pair<string,int>> orderedStrs; // Space: O(n*k)

        for (int i = 0; i < strs.size(); i++)
        {
            orderedStrs.push_back({strs[i],i}); // Time: O(n*k), Space: O(n*k)
        }
      
        for (int i = 0; i < strs.size(); i++)
        {
            sort(orderedStrs[i].first.begin(),orderedStrs[i].first.end()); // Time: O(n*k log k)
        }

        sort(orderedStrs.begin(), orderedStrs.end()); // Time: O(n*k*log n), Space: O(n)

        int i = 0;
        while (i < strs.size())
        {
            vector<string> group; // Space: O(k*group_size)
            group.push_back(strs[orderedStrs[i].second]); // Time: O(k)

            while (i+1 < strs.size() && orderedStrs[i].first == orderedStrs[i+1].first)
            {
                group.push_back(strs[orderedStrs[i+1].second]); // Time: O(k)
                i++;
            }
            
            result.push_back(group);
            i++;
        }
      
        return result; // Space: O(n*k)
    }   
};


int main() {

   vector<string> strs {"a"};

   vector<vector<string>> result = Solution::groupAnagrams(strs);

   for (const auto &row : result) {
        std::cout << '[';
        for (int i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i + 1 < row.size()) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    return 0;
}