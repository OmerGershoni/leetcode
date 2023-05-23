// https://leetcode.com/problems/valid-anagram/

#include <vector>

#define NUM_OF_LETTERS 26

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLettersCount[NUM_OF_LETTERS] = { 0 };
        int tLettersCount[NUM_OF_LETTERS] = { 0 };

        if (s.size() != t.size())
        {
            return false;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            ++sLettersCount[s[i] - 'a'];
            ++tLettersCount[t[i] - 'a'];
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (sLettersCount[i] != tLettersCount[i])
            {
                return false;
            }
        }

        return true;
    }
};
