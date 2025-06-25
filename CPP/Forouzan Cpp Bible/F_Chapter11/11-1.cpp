/*
11-1 학생은 사람이다를 기반으로 Person 객체와 이를 상속하는 Student 객체를 만들고 사용하는 프로그램
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//person 클래스의 정의
class Person {

private:
    long identity;
public:
    void setId(long identity);
    long getId() const;
};

//setid 함수 정의
void Person::setId(long id) {
    identity = id;
    assert(identity >= 100000000 && identity <= 999999999);
}

//geid 함수 정의
long Person::getId() const {
    return identity;
}

//student 클래스 정의 
class Student : public Person {
private:
    double gpa;
public:
    void setGpa(double gpa);
    double getGpa() const;
};

//setGPa 함수 정의 
void Student::setGpa(double gp) {
    gpa = gp;
    assert(gpa >= 0 && gpa <= 4.3);
}

double Student::getGpa() const {
    return gpa;

}

//메인 함수 
int main(void) {

    Person person;
    person.setId(111111111L);
    cout << "Person 객체의 정보 입니다 \n ";
    cout << "고유 아이디 : " << person.getId();
    cout << endl << endl;

    //Student 클래스 인스턴스화 하고 사용
    Student student1;
    student1.setId(222222222L);
    student1.setGpa(3.6);
    cout << " 학생의 객체 정보 \n ";
    cout << "학생 학번 : " << student1.getId();
    cout << " 학생의 학점 : " << student1.getGpa();

    return 0;
}
