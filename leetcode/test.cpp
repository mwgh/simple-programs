#include "test.h"
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::vector<LeetcodeSolution*> sols = {
    new LongestSubstringWithoutRepeatingCharacters(),
    new ReverseInteger(),
    new MonotonicArray()
  };
  std::vector<std::string> testNames = {
    "longest substring without repeating characters",
    "reverse integer",
    "monotonic array"
  };

  for (unsigned int i = 0; i < sols.size(); ++i) {
    std::cout << "Testing " << testNames[i] << ":" << std::endl;
    int ret = sols[i]->test();
    if (ret) {
      std::cerr << "Error with " << testNames[i] << std::endl;
      exit(1);
    }

    if (i != sols.size() - 1)  std::cout << std::endl;
  }

  for (LeetcodeSolution* sol : sols) {
    delete sol;
  }
  return 0;
}
