## Lvalue와 Rvalue

1. Lvalue : 단일 표현식 이후에도 없어지지 않고 지속되는 객체(ex : const 타입을 포함한 모든 변수)
2. Rvalue : 표현식이 종료된 이후에는 더 이상 존재하지 않는 임시적인 값(ex : 상수, 임시 객체)

```c++
#include<iostream>
#include<string>
using namespace std;

int main(){
	int x = 3;
    const int y = x;
    int z = x + y;
    int* p = &x;
    
    cout << string("one");
    
    ++x;
    x++;
}
```

- 3 , x + y, &x, string("one"), x++ 는 모두 Rvalue 이다. x, y, z, p 등의 이름을 가지는 변수는 모두 Lvalue 이지만 상수값 3, 임시 객체 string("one") 은 표현식이 종료되면 더 이상 참조할 수 없는 값이기 때문에 Rvalue이다.
  x + y, &x 와 같은 표현식도 마찬가지로 종료되면 더 이상 참조할 수 없기 때문에 Rvalue 이다.
  ++x와 x++ 는 둘 모두 다 증가된 값을 리턴하지만 ++x 는 증가된 x 자신을 리턴 하기 때문에 Lvalue인 반면에 x++은 증가된 복사본을 리턴 하기 때문에 Rvalue 이다. Lvalue와 Rvalue를 좀 더 간단하게 구분하는 방법은 
  표현식에 주소 연산자 &을 붙여보는 것이다. & 연산자는 Lvalue를 요구하기 때문에 표현식이 Rvalue라면 컴파일 오류가 나게 된다.

- ```c++
  &(++x);
  &(x++);	//	error C2102:'&' requires l-value
  ```

- Rvalue 참조자 &&

  - C++에서 int& a = b; 형태로 사용하였던 참조자(Reference)는 Lvalue 참조자 이다. C++11 표준에서는 Lvalue 참조자 이외에도 Ravlue를 참조할 수 있는 Rvalue 참조자가 추가되었다.

    ```c++
    int rvalue(){
    	return 10;
    }
    
    int main(){
    	int lvalue = 10;
    	
    	int& a = lvalue;
    	int& b = rvalue();
        // error C2440: 'initializing' : cannot convert from 'int' to 'int &'
    	
    	int&& c = lvalue;
        // error C2440: 'initializing' : cannot convert from 'int' to 'int &&'
    	int&& d = rvalue();
    }
    ```





출처 : https://effort4137.tistory.com/entry/Lvalue-Rvalue
