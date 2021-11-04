#include "0932_monotonic-array.h"

bool MonotonicArray::isMonotonic(std::vector<int>& A) {
  bool isMonotoneIncreasing = true;
  bool isMonotoneDecreasing = true;

  for (int i = 0; i < A.size() - 1; i++) {
    if (A[i] > A[i + 1]) {
      isMonotoneIncreasing = false;
    } else if (A[i] < A[i + 1]) {
      isMonotoneDecreasing = false;
    }
  }

  return isMonotoneDecreasing || isMonotoneIncreasing;
}

void MonotonicArray::print_vector(std::vector<int>& A) {
  std::cout << "[";
  for (int i = 0; i < A.size(); ++i) {
    std::cout << A[i];
    if (i != A.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

int MonotonicArray::test(void) {
  std::vector<int> A {0, -1, -20, -25};
  print_vector(A);
  std::cout << "Is the vector monotonic? " 
      << isMonotonic(A) << std::endl;
  return 0;
}
