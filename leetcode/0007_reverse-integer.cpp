class Solution {
public:
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      int rem = x % 10;
      x /= 10;
      bool willOverflow = (res > std::numeric_limits<int>::max()/10)
          || (res == std::numeric_limits<int>::max()/10 && rem > 7);
      bool willUnderflow = (res < std::numeric_limits<int>::min()/10)
          || (res == std::numeric_limits<int>::min()/10 && rem < -8);
      if (willOverflow || willUnderflow) {
        return 0;
      }
      res = res * 10 + rem;
    }
    return res;
  }
};
