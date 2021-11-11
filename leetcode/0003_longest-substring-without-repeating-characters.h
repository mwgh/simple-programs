#pragma once
#include "leetcode-solution.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

class LongestSubstringWithoutRepeatingCharacters: public LeetcodeSolution {
public:
  int lengthOfLongestSubstring(std::string s);

  virtual int test(void);
};
