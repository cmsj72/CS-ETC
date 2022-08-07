## 유니티 코루틴(Coroutine)과 서브 루틴

- 우리가 어떤 작업을 처리하기 위애 필요함 **함수(Function)를 호출**하면, 그 **함수는 자신의 역할을 모두 수행한 이후 자신을 호출했던 메인 루틴(Main Routine)속 코드의 다음 위치로 돌아가서** 프로그램의 흐름이 이어지게 된다. 만약 서브 루틴이 반환하는(Return) 값이 있다면, 메인 루틴은 이 값을 사용할 수도 있다. 이것을 일반적으로 **서브 루틴(Sub Routine)**이라 표현한다.

  ```c++
  string Name();
  int main(){
  	//메인루틴
  	cout << "Hello World" << endl; 
  	cout << "My Name is " << Name() << endl;
  }
  
  string Name(){
  	//서브루틴
  	string name = "윤찬호";
  	return name
  }
  ```

- 서브 루틴이 메인 투린에 **종속**된 상태로 호출을 받는 입장이라 한다면, 코루틴(Coroutine)은 **코루틴을 호출한 메인 루틴과 함께 실행되는 구조**이다. 따라서 메인 루틴과 **대등한 관계**라 할 수  있다.

- 형식

  - 함수의 반환 타입으로 반드시 열거형 인터페이스인 **IEnumerator**를 사용해야 하고, **yield return 구문이 적어도 한번 이상은 사용**되어야 한다.

    ```c#
    IEnumerator TestCo(){
    	//수행할 작업
    	yield return null;
    }
    ```

  - **yield는 함수의 코드가 실행한 결과를 반환**한다. 코루틴이 함수에 정의된 작업을 실행하다가 yield return 구문을 만나면, yield return 구문으로 지정한 명령을 실행시키고, **코루틴을 호출했던 루틴으로 잠시 제어의 권한을 넘겨**주면서 코루틴의 실행이 일시적으로 중지되는 것이다. 위 코드에서 yielr return null이 지정한 "null"은 1프레임을 코루틴의 호출자에게 양보하고 대기하라는 뜻이다. 만약 예를 들어 3초동안 대기했다가 다음 작업을 실행하려면, yield return 구문을 아래와 같이 지정할 수 있다.

    ```c#
    yield return WaitForSeconds(3.0f);
    ```

    3초가 지나면 프로그램의 제어 권한은 코루틴 함수에서 yield return으로 중단되었던 코드의 위치로 복귀하여 코루틴 함수의 작업을 계속 이어간다. yield 구문으로 반환되는 값이 코루틴 함수가 다시 실행(재개)되는 시점을 지정하는 것이다. 이것이 바로 서브루틴과 코루틴의 결정적인 차이이다. 서브 루틴은 호출될 때마다 코드의 첫 부분부터 다시 실행하지만, 코루틴은 중단되었던 코드의 다음 위치부터 실행 된다. 

    함수가 시작되는 위치를 진업지점(Entry Point)라고 한다. 진입 지점이 1개인 서브 루틴에 비해서, 코루틴은 진입 지점을 여러개 정의할 수 있다. 아래는 코루틴에서 사용하는 반환 타입의 목록이다.(코루틴이 코루틴의 호출자에게 양보하는 조건이라고 생각하면 된다)

    |           구문            |                  기능                   |
    | :-----------------------: | :-------------------------------------: |
    |           null            |          다음 프레임까지 대기           |
    | new WaitForSeconds(float) |           지정한 초만큼 대기            |
    | new WaitForFixedUpdate()  | 다음 물리 프레임까지 대기(Fixed Update) |
    |  new WaitForEndOfFrame()  |   모든 렌더링 작업이 끝날 때까지 대기   |
    |  StartCoRoutine(string)   |     다른 코루틴이 끝날  때까지 대기     |
    |      new WWW(string)      |     웹 통신 작업이 끝날 때까지 대기     |
    |    new AsyncOperation     |     비동기 작업이 끝날 때까지 대기-     |

  - 코루틴은 StartCoroutine 함수의 매개변수로 함수를 전달하여 호출할 수 있고, 코루틴 함수의 이름을 문자열 형식으로 전달할 수도 있다. 하지만 코루틴 함수의 이름을 문자열 형식으로 전달하면, 간편하게 사용할 수는 있겠지만, 실제 메소드를 찾아내는 과정(연산)이 필요하기 때문에 성능이 저하될 수 있다.

    ```c#
    //함수를 전달하여 호출
    StartCoroutine(TestCo());
    //함수의 이름을 문자열 형식으로 전달하여 호출
    StartCoroutine("TestCo");
    ```

    코루틴의 매개변수가 1개 있을 경우에는 아래와 같이 호출할 수도 있다.(매개변수가 1개일 경우에만 가능)

    ```c#
    StartCoroutine("TestCo",2.0f);
    ```

  - 예제코드

    ```c#
    void Start(){
        StartCoroutine(TestCo());
        TestSub();
    }
    IEnumerator TestCo(){
        Debug.Log("[co] 1");
        yield return new WaitForSeconds(1);
        Debug.Log("[co] 2");
        Debug.Log("[co] 3");
    }
    public void TestSub(){
        for(int i = 0; i < 3; i++){
            Debug.Log("[sub] " + i);
        }
    }
    //코루틴이 yield return 구문을 통해 1프레임을 대기하는 동안 프로그램의 제어 권한이 코루틴의 호출자인 Start함수로 돌아왔다. 그래서 서브 루틴이 실행되어 작업을 모두 처리한 후, 다시 제어 권한이 코루틴으로 넘어가서 yield return으로 중단된 그 이후의 나머지 작업을 실행한 것을 확인할 수 있다.
    ```

  - 코루틴은 하나의 프로세스를 여러 루틴들이 시간을 나눠서 사용하는 방식이다. 그러나 스레드(Thread)는 동시에 여러 프로세스가 여러 작업을 진행하는 것이다. 코루틴을 통해 개발자는 여러 프레임에 걸쳐 일어나는 동작들을 덜 복잡하게 설계(Modeling)할 수 있다.



출처 : https://m.blog.naver.com/pxkey/221296053953