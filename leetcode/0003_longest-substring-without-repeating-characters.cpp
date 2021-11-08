#include "0003_longest-substring-without-repeating-characters.h"

int LongestSubstring::lengthOfLongestSubstring(std::string s) {
  int n = s.size();
  int ans = 0;
  std::map<char, int> currentIndex;
  for (int j = 0, i = 0; j < n; ++j) {
    if (currentIndex.find(s[j]) != currentIndex.end()) {
      i = std::max(currentIndex[s[j]], i);
    }
    ans = std::max(ans, j - i + 1);
    currentIndex[s[j]] = j + 1;
  }
  return ans;
}

int LongestSubstring::test(void) {
  std::string hello = "hello abcdefg";
  std::cout << "The length of the longest substring without repeating "
      "characters in the string '"
      << hello << "' is "
      << (new LongestSubstring())->lengthOfLongestSubstring(hello)
      << "." << std::endl;
  return 0;
}
