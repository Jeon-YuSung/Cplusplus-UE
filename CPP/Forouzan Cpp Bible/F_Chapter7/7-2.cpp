#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double rds); // 매개변수 있는 생성자
    Circle(); // 기본 생성자
    ~Circle(); // 소멸자
    Circle(const Circle &circle); // 복사 생성자

    void setRadius(double radius); // 설정자 (Setter)

    // 접근자 (Getter)
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
};

// 매개변수 있는 생성자 정의
Circle::Circle(double rds)
    : radius(rds) {
    cout << "매개변수가 있는 생성자가 호출되었습니다." << endl;
}

// 기본 생성자 정의
Circle::Circle()
    : radius(0.0) {
    cout << "기본 생성자가 호출되었습니다." << endl;
}

// 복사 생성자 정의 (오타 수정)
Circle::Circle(const Circle &circle)
    : radius(circle.radius) {
    cout << "복사 생성자가 호출되었습니다." << endl;
}

// 소멸자 정의
Circle::~Circle() {
    cout << "소멸자가 호출되었습니다. 반지름: " << radius << endl;
}

// setRadius 정의
void Circle::setRadius(double value) {
    radius = value;
}

// getRadius 정의 (오타 수정)
double Circle::getRadius() const {
    return radius;
}

// getArea 정의 (오타 및 클래스 멤버 함수로 지정)
double Circle::getArea() const {
    const double PI = 3.141592;
    return (PI * radius * radius);
}

// getPerimeter 정의 (클래스 멤버 함수로 지정 및 const 추가)
double Circle::getPerimeter() const {
    const double PI = 3.141592;
    return (PI * radius * 2);
}

int main() {
    Circle circle1(5.3);
    cout << "반지름: " << circle1.getRadius() << endl;
    cout << "넓이: " << circle1.getArea() << endl;
    cout << "둘레: " << circle1.getPerimeter() << endl << endl;

    Circle circle2(circle1);
    cout << "반지름: " << circle2.getRadius() << endl;
    cout << "넓이: " << circle2.getArea() << endl;
    cout << "둘레: " << circle2.getPerimeter() << endl << endl;

    Circle circle3;
    cout << "반지름: " << circle3.getRadius() << endl;
    cout << "넓이: " << circle3.getArea() << endl;
    cout << "둘레: " << circle3.getPerimeter() << endl << endl;

    return 0;
}
