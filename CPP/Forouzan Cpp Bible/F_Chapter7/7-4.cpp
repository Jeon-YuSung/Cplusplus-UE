//Rectangle 클래스 사용하기. 
#include <iostream>
#include <cassert>

using namespace std;

// Ractangle 클래스 정의 ( 데이터 멤버와 멤버 함수 선언)
class Ractangle{
// 데이터 멤버 선언
  private:
double length;
double height;

public:
Rectangle(double length, double height);//생성자
Rectangle(const Rectangle &rect); //복사 생성자
~Rectangle(); //소멸자
// 접근자 멤버 선언
void print() const;
double getArea() const;
double getPerimeter() const;
};

//생성자, 소멸자, 접근자 인스턴스 멤버 함수의 정의 
Rectangle(double len, double hgt) : length(len), height(hgt){
  if((length <= 0.0) || (height <= 0.0))
  {
    cout << " Rectangle  객체를 생성할 수 없습니다. " << endl; 
    assert(false);
  }
}

//복사 생성자 
Rectangle::Rectangle(const Rectangle &rect) : length(rect.length), height(rect.height)
{ 
}

//소멸자 
Rectangle::~Rectangle()
{
  
}
//접근자 멤버 함수 
void Rectangle::print() const
{
  cout << " 사각형의 넓이 : " << length << ", 높이 : " << height << endl;
}

double Rectangle::getArea() const
{
  return(length*height);
}

double Rectangle::getPerimeter() const
{
  return(2 * ( length + height));
}

// 3개의 객체를 인스턴스화 하고 활용
int main (void){

  // 3개의 객체를 인스턴스화 
  Rectangle rect1(3.0, 4.2);
  Rectangle rect2(5.1, 10.2);
  Rectangle rect3(rect2);

  // 1번째 객체의 멤버함수 호출
  cout << "사각형1 : " << rect1.print() << endl;
  cout << "넓이 : " << rect1.getArea() << endl;
  cout << "둘레 : " << rect1.getPerimeter() << endl << endl;

  // 2번째 객체의 멤버함수 호출
  cout << "사각형2 : " << rect2.print() << endl;
  cout << "넓이 : " << rect2.getArea() << endl;
  cout << "둘레 : " << rect2.getPerimeter() << endl << endl;

    // 1번째 객체의 멤버함수 호출
  cout << "사각형3 : " << rect3.print() << endl;
  cout << "넓이 : " << rect3.getArea() << endl;
  cout << "둘레 : " << rect3.getPerimeter() << endl << endl;
  
  return 0;
}
