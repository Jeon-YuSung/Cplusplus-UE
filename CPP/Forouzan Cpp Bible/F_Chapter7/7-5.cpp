//객체를 만들고, 만들어진 객체의 수를 세는 프로그램 
#include <iostream>
using namespace std;


class Rectangle{

  private:
  double length;
  double height;
  static int count; // 정적 데이터 멤버 
  
public:
Rectangle(double length, double height);
Rectangle();
~Rectangle();
Rectangle(const Rectangle &rect);
static int getCount(); //정적 멤버 함수 
};

//정적 데이터 멤버 초기화
int Rectangle::count = 0;

//클래스 정의
//매개변수가 있는 생성자 
Rectangle::Rectangle(double length, double height) 
: length(length), height(height){
count++;
}
//기본 생성자 
Rectangle::Rectangle() : length(0.0), height(0.0){
  count++;
}
//복사 생성자 
Rectangle::Rectangle(const Rectangle &rect) : length(rect.length), height(rect.height)
{
  count++;
}
Rectangle::~Rectangle()
{
 count--; 
}
 //정적 멤버 함수 정의 
int Rectangle:: getCount(){
  return count; 
}

int main (void){
{
   Rectangle rect1(3.3, 1.4);
  Rectangle rect2(4.2, 1.6);
  Rectangle rect3;
  Rectangle rect4(rect1);
  Rectangle rect5(rect2);
  cout <<" 객체의 수 : " <<  rect5.getCount() <<endl;
}
  cout << "객체의 수 : " << Rectangle::getCount() << endl; 
  return 0;
}

/*
메인 함수에 { }를 추가해서 객체가 존재하는 영역을 지정함, 그렇기에 블록을 벗어나면 인스턴스가 모두 제거됨.
하지만 클래스 이름을 사용해서 정적 데이터 멤버에 접근하여 값을 확인할 수 있음. 블록 내부에서 5개의 인스턴스를 만들었으므로, 정적 데이터 멤버의 값을 확인하면 5가 나온다
하지만 블록을 벗어나면 모든 인스턴스가 삭제되어, 정적데이터 멤버의 값을 확인할 때 0이나옴. 
*/
