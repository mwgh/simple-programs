class Solution {
public:
    bool isMonotonic(vector<int>& A) {
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
};
