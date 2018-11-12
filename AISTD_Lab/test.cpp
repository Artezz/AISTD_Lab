#include "stdafx.h"
bool is_equal(int arr[], size_t size11, size_t size12, int ** arr2, size_t size21, size_t size22) {
	bool flag = 0;
	if (size11 != size21 || size12 != size22) return false;
	for(size_t i = 0; i< size11; i++)
		for (size_t k = 0; k < size12; k++) {
			if (arr[i*size12+k] != arr2[i][k])
				return false;
		}
	return true;
}