#include "0932_monotonic-array.h"

bool MonotonicArray::isMonotonic(std::vector<int>& A) {
  bool isMonotoneIncreasing = true;
  bool isMonotoneDecreasing = true;

  for (unsigned int i = 0; i < A.size() - 1; ++i) {
    if (A[i] > A[i + 1]) {
      isMonotoneIncreasing = false;
    } else if (A[i] < A[i + 1]) {
      isMonotoneDecreasing = false;
    }
  }

  return isMonotoneDecreasing || isMonotoneIncreasing;
}

void MonotonicArray::print_vector(std::vector<int>& A) {
  bool has_last = A.size() >= 1;
  std::vector<int>::iterator last;
  if (has_last) {
    last = A.end();
    --last;
  }

  std::cout << "[";
  for (auto i = A.cbegin(); i != A.cend(); ++i) {
    std::cout << *i;
    if (has_last && i != last) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

int MonotonicArray::test() {
  std::vector<int> A {0, 5, 7, 1};
  print_vector(A);
  std::cout << "Is the vector monotonic? "
      << isMonotonic(A) << std::endl;
  return 0;
}
