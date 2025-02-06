//클래스를 사용하는 프로그램. 

#include <iostream>
using namespace std;

//클래스의 정의, 데이터 멤버와 멤버 함수르 선언; 
class Circle{

private: 
  double radius;
public:
  double getRadius() const;
  double getArea() const;
  double getPerimeter() const;
  void setRadius(double value);
};

//멤버 함수 정의 
double Circle::getRadious() const{
return radius;
}
double Circle::getArea() const{
  const double PI = 3.14;
  return (PI * radius * radius);
}
double Circle::getPerimeter() const{
    const double PI = 3.14;
  return (PI * radius * 2);
}
void Circle::setRadius(double value){

radius = value;  
}

//애플리케이션 부분, 클래스를 인스턴스화 해서 객체를 만들고 사용 
int main (void){

  cout << "서클 1: " << endl;
  Circle circle1;
  circle1.setRadius(10.0);
  cout<< "반지름 길이 : " << circle1.getRadius() << endl;
  cout<< "원의 넓이 : " << circle1.getArea() << endl;
  cout<< "원의 둘레 : " << circle1.getPerimeter() << endl << endl; 

  cout << "서클 2: " << endl;
  Circle circle2;
  circle1.setRadius(30.0);
  cout<< "반지름 길이 : " << circle2.getRadius() << endl;
  cout<< "원의 넓이 : " << circle2.getArea() << endl;
  cout<< "원의 둘레 : " << circle2.getPerimeter() << endl;
  
  return 0;
}
