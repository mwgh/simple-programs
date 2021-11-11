#pragma once
#include "leetcode-solution.h"
#include <vector>
#include <iostream>

class MonotonicArray: public LeetcodeSolution {
public:
  bool isMonotonic(std::vector<int>& A);

  void print_vector(std::vector<int>& A);

  virtual int test(void);
};
