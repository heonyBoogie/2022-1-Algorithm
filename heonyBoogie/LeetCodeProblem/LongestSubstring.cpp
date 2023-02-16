#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        int max = 1;
        int startIndex = 0;
        int len = 1;
        for (int endIndex = 1; endIndex < s.length(); endIndex++)
        {
            for (int i = endIndex - 1; startIndex <= i; i--) {
                if (s[i] != s[endIndex]) {
                    if (i == startIndex) {
                        len++;
                        if (max < len) max = len;
                    }
                }
                else {
                    startIndex = i + 1;
                    len = endIndex - startIndex + 1;
                    break;

                }
            }
        }

        return max;
    }
};

int main()
{
    Solution solution = Solution();
    string testCase = "aabb";
    cout << solution.lengthOfLongestSubstring(testCase) << endl;
    return 0;
}