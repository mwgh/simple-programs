#pragma once
#include "leetcode-solution.h"
#include <iostream>
#include <limits>

class ReverseInteger: public LeetcodeSolution {
public:
  ReverseInteger() {}
  virtual ~ReverseInteger() {}
  int reverse(int x);
  virtual int test();
};
