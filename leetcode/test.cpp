#include "0003_longest-substring-without-repeating-characters.h"
#include "0007_reverse-integer.h"
#include "0932_monotonic-array.h"

int main(void) {
  LongestSubstring* ls = new LongestSubstring();
  int ret0 = ls->test();
  if (ret0) {
    std::cerr << "Error with longest substring" << std::endl;
    exit(1);
  }

  ReverseInteger* ri = new ReverseInteger();
  int ret1 = ri->test();
  if (ret1) {
    std::cerr << "Error with reverse integer" << std::endl;
    exit(1);
  }

  MonotonicArray* a = new MonotonicArray();
  int ret2 = a->test();
  if (ret2) {
    std::cerr << "Error with monotonic array" << std::endl;
    exit(1);
  }
}
