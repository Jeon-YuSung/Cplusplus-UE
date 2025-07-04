//15-8(11) fun클래스를 사용하는 애플리케이션 파일 
#include "fun.cpp"

int main(void)
{
//서로 다른 자료형으로 클래스의 인스턴스 생성
	Fun<int> Fun1(23);
	Fun<double> Fun2(22.12);
	Fun<char> Fun3('A');
	Fun<string> Fun4("Hello");

	// 각 클래스 값 출력 
	cout << " Fun1 : " << Fun1.get() << endl;
	cout << " Fun2 : " << Fun2.get() << endl;
	cout << " Fun3 : " << Fun3.get() << endl;
	cout << " Fun4 : " << Fun4.get() << endl;

	//값 설정
	Fun1.set(42);
	Fun3.set('C');
	
	//호출 후의 값 
	cout << " SET 함수 호출 후의 Fun1 : " << Fun1.get() << endl;
	cout << " SET 함수 호출 후의 Fun3 : " << Fun3.get() << endl;
}
