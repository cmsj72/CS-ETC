## C# 배열, 컬렉션(Collection)

- 자료구조는 데이터를 메모리에 저장하는 것, 데이터 양이 많을 때 목적에 맞는 자료구조를 사용하지 않으면 엄청난 비용(속도, 메모리 낭비)의 손실을 가져오거나 심지어 프로그램, 서버가 다운될 수도 있다.
- 목적에 따라 자료구조를 선택적으로 사용해 주어야 한다.



- Generic(제네릭) 타입과 Non-Generic 타입

  - Non-Generic : 박싱과 언박싱 과정에서 부하가 발생함(메모리 낭비와 속도 저하)

    ```c#
    Member2 member = new Member2();
    //Non-Generic Queue 생성
    Queue sendQ = new Queue();
    //큐에 넣을때는 object로 형변환이 됨
    //object로 형변환 되는것을 박싱(Boxing)이라고 함
    sendQ.Enqueue(member);//인자가 object타입 임
    
    for(int i = 0; i < sendQ.Count; i++){
    	//값을 큐에서 꺼내올때 원래의 타입으로 변환해야 함
    	//object에서 원래 타입으로 변환하는 것을 언박싱(Unboxing)이라고 함
    	Member2 getMember = (Member2)sendQ.Dequeue();//리턴값이 object 타입 임
    	SendMain(getMember.EmailAddress);
    }
    ```

  - Generic : 박싱과 언박싱이 발생하지 않음. 성능 면에서 훨씬 좋음

    ```c#
    Member2 member = new Member2();
    
    //Generic Queue 생성. 생성할 때 타입을 알려줌 <Member2>
    Queue<Member2> sendQ = new Queue<Member2>();
    
    //<Member2> 타입으로 생성했기 때문에 object로 박싱이 일어나지 않음
    sendQ.Enqueue(member);
    
    for(int i =0; i < sendQ.Count; i++){
    	//값을 큐에서 꺼내올 때 원래의 타입으로 형변환(언박싱) 하지 않아도 됨
    	Member2 getMember = sendQ.Dequeue();
    	SendMain(getMember.EmailAddress):
    }
    ```



| Generic 사용                   | Generic 미 사용      | Multi-Thread 동기화 옵션 사용                                | 용도                                                         |
| ------------------------------ | :------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| Dictionary<TKey,TValue>        | Hashtable            | ConcurrentDictionary\<TKey,TValue><br />ReadOnlyDictionary\<TKey,TValue><br />ImmutableDictionary\<TKey,TValue> | Key로 빠르게 데이터를 조회할 때 사용<br />Key와 Value로 데이터가 저장됨 |
| List\<T>                       | Array<br />ArrayList | ImmutableList\<T><br />ImmutableArray                        | 데이터가 저장된 순서(인덱스)를 빠르게 탐색함                 |
| Queue\<T>                      | Queue                | ConcurrentQueue\<T><br />ImmutableQueue\<T>                  | FIFO(선입 선출) 방식으로 항목 사용                           |
| Stack\<T>                      | Stack                | ConcurrentStack\<T><br />ImmutableStack\<T>                  | LIFO(후입 선출)방식으로 데이터 사용                          |
| SortedList\<TKey,TValue>       | SortedList           | ImmutableSortedDictionary<TKey,TValue><br />ImmutableSortedSet\<T> | 입력된 순서와 상관없이 Key 값으로 정렬됨                     |
| LinkedList\<T>                 | 지원 안함            | 지원 안함                                                    | 데이터 등록, 삭제가 빈번하게 일어날 때                       |
| ObservableCollection\<T>       | 지원 안함            | 지원 안함                                                    | 목록에 데이터를 넣거나 뺄 때 알람을 표시해줌                 |
| HashSet\<T><br />SortedSet\<T> | 지원 안함            | ImmutableHashSet\<T><br />ImmutableSortedSet\<T>             | 중복된 데이터를 저장하지 않을 때<br />(수학에서 집합 사용 시) |





출처 : https://blog.naver.com/tutorials_korea/221610337593
