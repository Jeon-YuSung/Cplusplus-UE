#include "array.h"

int main(void) {


	Array arr(3);
	arr[0] = 22.31; 
	arr[1] = 77.42;
	arr[2] = 65.24;

	for (int i = 0; i < 3; i++) {
	
		cout << "arr[" << i << "] = " << arr[i] << "\n";
	}

	return 0;
} 
