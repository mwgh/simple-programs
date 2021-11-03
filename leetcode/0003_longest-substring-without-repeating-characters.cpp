class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    map<char, int> currentIndex;
    for (int j = 0, i = 0; j < n; ++j) {
      if (currentIndex.find(s[j]) != currentIndex.end()) {
        i = max(currentIndex[s[j]], i);
      }
      ans = max(ans, j - i + 1);
      currentIndex[s[j]] = j + 1;
    }
    return ans;
  }
};
