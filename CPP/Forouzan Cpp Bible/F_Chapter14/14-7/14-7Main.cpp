//14-7 function-try 블록 예시 - 애플리케이션 
#include "Integer.h"

int main(void) {

	for (int i = 0; i < 1000000; i++) {
		try {
			Integer integer(i);
			cout << integer.getValue();
			cout << endl;
		}
		catch(...){
			cout << "예외 발생 \n";
		}
	}

	return 0;
} 
