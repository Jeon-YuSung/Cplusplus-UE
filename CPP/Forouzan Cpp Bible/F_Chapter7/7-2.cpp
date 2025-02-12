#include <iostream>
using namespace std;

class Circle {
  private:
    double radius;
  public:
  Circle(double radius); //파라매터 있는 생성자
  Circle(); //기본 생성자
  ~Circle(); // 소멸자 
Circle(const Circle &circle); //복사 생성자
void setRadius(double radius); //설정자
//접근자
doulbe getRadius() const;
doulbe getArea() const;
double getPerimeter() const; 

};

Circle::Circle(double rds)
:radius(rds)
{
  cout << " 매개변수가 있는 생성자가 호출되었습니다 " << endl;
}


Circle::Circle()
: rdaius(0.0)
{
  cout << "기본 생성자가 호출 되었습니다 " << endl; 
}

//복사 생성자 정의
Circle::Circle(const Circle &circle)
: rdaius(circle.radius)
{
  cout << "복사 생성자가 호출 되었습니다 " << endl; 
}


//소멸자 정의
Circle::~Circle()
{
  cout << "소멸자가 호출 되었습니다 " << radius << endl; 
}
//setRadius정의 
void Circle::setRadius(double value)
{
  radius = value;
}

//getRadius 정의
double Circle::getRadius() cosnt 
{
  return radius;
}
//getArea정의 
doulbe getArea() const
{
  const double PI = 3.141592;
  return (PI * radius * radius);
}

//getPerimeter 
double getPerimeter()
{
  const double PI = 3.141592;
  return (PI * radius * 2);
}

int main (void){
  Circle circle1(5.3);
  cout << "반지름 : " << circle1.getRadius() << endl;
  cout << "넓이 : " << circle1.getArea() << endl;
  cout << "둘레 : " << circle1.getPerimeter() << endl << endl;
  
  Circle circle2(circle1);
  cout << "반지름 : " << circle2.getRadius() << endl;
  cout << "넓이 : " << circle2.getArea() << endl;
  cout << "둘레 : " << circle2.getPerimeter() << endl << endl;
  
  Circle circle3;
  cout << "반지름 : " << circle3.getRadius() << endl;
  cout << "넓이 : " << circle3.getArea() << endl;
  cout << "둘레 : " << circle3.getPerimeter() << endl << endl;
  
  return 0;
}
