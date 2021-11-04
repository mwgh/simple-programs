#include "0932_monotonic-array.h"
#include "0003_longest-substring-without-repeating-characters.h"

int main(void) {
  MonotonicArray* a = new MonotonicArray();
  int ret0 = a->test();
  if (ret0) {
    std::cerr << "Error with monotonic array" << std::endl;
    exit(1);
  }

  LongestSubstring* ls = new LongestSubstring();
  int ret1 = ls->test();
  if (ret1) {
    std::cerr << "Error with longest substring" << std::endl;
    exit(1);
  }
}
