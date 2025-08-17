// 1장 연습문제1 동적 크기 배열 구현하기 
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

template<typename T>
class dynamicArray {

private:
    T* data;
    size_t n;

public:
    //생성자 선언
    dynamicArray(int n) {
        this->n = n;
        data = new T[n];
    } 
    //복사 생성자 선언
    dynamicArray(const dynamicArray<T>& other) {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++) {
            data[i] = other[i];
        }
    }
    // 직접 접근하기위한 []연산자와 at함수 정의
    T& operator[](int index){
        return data[index];
    }

    const T& operator[](int index) const {

        return data[index];

    }

    T& at(int index) {
    
        if (index < n) {
            return data[index];
        }
        throw "Index out of range";
    }

    //배열 크기를 반환하는 size 멤버함수
    size_t size() const {
        return n;
    }
    //소멸자 선언
    ~dynamicArray() {
        delete[] data; //메모리 누수 방지
    }

    // 동적배열 원소를 순회할 때 사용할 반복자 관련 함수 정의
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n;  }

    //두 배열을 하나로 합치는 +연산자 함수 정의, friend로 선언
    friend dynamicArray<T> operator+(const dynamicArray<T>& arr1, dynamicArray<T>& arr2) {
        dynamicArray<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    //배열에 저장된 몬든 데이터를 문자열로 반환하는 멤버 함수 작성 
    std::string to_string(const std::string& sep = ",")  {
        if (n == 0) {
            return " ";
        }
        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++) {
            os << sep << data[i];
        }
        return os.str();
    }

};

//구조체를 이용하여 학생을 정의 
struct student {
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
    return (os << "[" << s.name << "," << s.standard << "]");
}

//메인 함수 
int main(void) {
    
    int nStudents;
    std::cout << "1반의 학생수 를 입력하세요 : ";
    std::cin >> nStudents;

    dynamicArray<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++) {
        std::string name;
        int standard;
        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요. :";
        std::cin >> name >> standard;
        class1[i] = student(name, standard);
    }
    //배열 크기보다 큰 인덱스의 학생에 접근
    try {
        // 주석 해제시, 프로그램이 비정상 종료함.
        //class1[nStudents] = student{ "John", 8 }; //예상 할 수 없는 동작
        class1.at(nStudents) = student{ "John", 8 }; // 예외 발생 
    }
    catch (...) {
        std::cout << "예외 발생" << std::endl;
    }

    //deep copy
    auto class2 = class1;
    std::cout << "1반을 복사해서 2반을 생성 \n";
    std::cout << class2.to_string() << std::endl;

    //2학급을합쳐서 새로운 큰 학급을 생성
    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐서 3반 생성 : " << class3.to_string() << std::endl;
    return 0;
}
