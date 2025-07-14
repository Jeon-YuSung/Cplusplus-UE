## Chapter 17. 재귀

  재귀와 반복의 개념을 비교
  
-----------------------------------------------------

  - #### 반복과 재귀
    
      - 반복
        
          반복을 사용한 코드는 반복을 종료하기 위한 조건이 존재, 또한 코드에서 함수를 한번만 호출

```cpp

  void line(int n){
    while(n >=1){
      cout << "*";
      n--;
      }
    return;
}


int sum(int n){
  int result = 0;
    while(n>=0){
    result += n;
    n--;
    }
  return result;
}

int sum (int n){
  if(n <= 0){
    return 0;
}
  return sum(n-1) + n;
}

```
  
  - 재귀
         
  자기 자신을 호출로 함수를 N-1번 호출함 <br> 
  **재귀에서 제네럴 케이스는 어떤 처리를 하는 함수 호출을 의미하고, 베이스 케이스는 반복을 종료하기 위한 함수 호출을 의미**

```cpp
  void line(int n){
    if(n<1){
      return;  
    }
  cout << "*";
  line(n-1);
}

  int sum(int n){
    if(n<=0){
      return 0;
}
  return sum(n-1) + n;
}

int factorial(int n){
  if(n <=1) {
    return 1;
}
return factorial(n-1) * n;

}
```


[17-1. 재귀를 사용해서 합계와 팩토리얼 구하기]() <br>
[17-2. GCD를 구하는 함수 구현]() <br>
[17-3. 피보나치 수열 구하기]() <br>
[17-4. 재귀적으로 문자열 반전하기]() <br>
[17-5. 재귀를 사용한 isPalindrome 함수]() <br>
[17-6. quickSort Program]() <br>
[17-7. 재귀를 사용한 이진 탐색]() <br>
[17-8. 하노이 타워]()
