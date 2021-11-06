#include "0003_longest-substring-without-repeating-characters.h"
#include "0007_reverse-integer.h"
#include "0932_monotonic-array.h"

#include <iostream>

int main(void) {
  LongestSubstring* ls = new LongestSubstring();
  std::cout << "Testing longest substring:" << std::endl;
  int ret0 = ls->test();
  if (ret0) {
    std::cerr << "Error with longest substring" << std::endl;
    exit(1);
  }
  std::cout << std::endl;

  ReverseInteger* ri = new ReverseInteger();
  std::cout << "Testing reverse integer:" << std::endl;
  int ret1 = ri->test();
  if (ret1) {
    std::cerr << "Error with reverse integer" << std::endl;
    exit(1);
  }
  std::cout << std::endl;

  MonotonicArray* a = new MonotonicArray();
  std::cout << "Testing monotonic array:" << std::endl;
  int ret2 = a->test();
  if (ret2) {
    std::cerr << "Error with monotonic array" << std::endl;
    exit(1);
  }
}
