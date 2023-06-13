### C++ algorithm 헤더

------

- sort

  - ```c++
    #include<algorithm>
    #include<iostream>
    using namespace std;
    
    int main(){    
        int a[10] =  { 9,3,5,4,1,10,8,6,7,2 };
        //	그냥 사용하면 오름차순 정렬
        sort(a, a + 10);
        //	내림차순 정렬
        sort(a, a+10, greater<int>());
        //	vector는 begin() 과 end()함수를 이용
    	for (int i = 0; i < 10; i++) {
    		cout << a[i] << " ";
    	}    
    }
    ```

- max_element, min_element

  - ```c++
    #include<algorithm>
    #include<iostream>
    #include<vector>
    using namespace std;
    
    int main(){    
        vector<int> a;
    	for (int i = 1; i <= 10; i++) {
    		a.push_back(i);
    	}
        //	주소값을 반환하기 때문에 *을 이용해 접근
        cout << *max_element(a.begin(), a.end()) << endl;
        cout << *min_element(a.begin(), a.end()) << endl;
    }
    ```

- unique

  - ```c++
    #include<algorithm>
    #include<iostream>
    #include<vector>
    using namespace std;
    
    int main(){    
        //	unique는 범위내에 연속적으로 존재하는 요소들을 삭제하고, 중복되지 않은 요소들을 
        //	앞에서부터 채운다.
        //	중복된 원소들을 모아둔 뒷부분의 첫번째 원소 주소를 리턴한다.
        //	배열의 크기를 바꿔주거나 하진 않기 때문에 쓰레기값(값을 덮으면서 작동하기 때문)이
        //	남는다.
        vector<int> arr = { 10,10,20,30,20,10,10 };
        unique(arr.begin(), arr.end());
        //	결과 : 10 20 30 20 10 10 10
        //	중복된 값이 남는다
        
        vector<int> arr2 = { 10,10,20,30,20,10,10 };
        //	중복 원소를 제거하기 위해서는 sort를 이용해 정렬한 후 unique를 사용하는 것이 좋다.
        sort(arr2.begin(), arr2.end());
        arr2.erase( unique(arr2.begin(), arr2.end()) , arr2.end());
        
    }
    ```

    

