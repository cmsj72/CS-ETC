#include<iostream>
#include<vector>
#include<algorithm>
//pair 클래스는 utility에 존재
//utility는 algorithm, vector에도 포함되어 있다.
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main() {

	//	pair<type1, type2> p : pair 클래스의 객체 p를 생성
	pair<int, int> p1;

	//	p.first : p의 첫번째 인자를 반환
	//	p.second : p의 두번째 인자를 반환
	p1.first = 1;
	p1.second = 2;

	//	make_pair(값1, 값2) : 값1, 값2를 한쌍으로 하는 pair를 만들어서 반환
	pair<int, double> p2;
	p2 = make_pair(1, 2.1);

	//	pair는 vector와 함께 많이 사용
	vector<pair<int, int>> arr;

	// 위 vector와 같은 형태
	typedef pair<int, int> p;
	vector<p> arr2;
	
	//	pair 객체의 대소 비교를 할 수 있다.
	//	pair 객체 간의 대소 비교를 진행하는 경우,
	//	제일 먼저 첫번째 값을 비교하고, 첫번째 값이 같으면 두번째 값을 통해서 판단
	pair<int, int> a, b;
	a = make_pair(2, 4);
	b = make_pair(1, 5);
	a > b ? cout << "첫번째" : cout << "두번째";
	cout << endl;

	a = make_pair(2, 7);
	b = make_pair(2, 10);
	a > b ? cout << "첫번째" : cout << "두번째";
	cout << endl;

	cout << endl;
	//	정렬 예제
	vector<pair<int, int>> example;
	example.push_back(make_pair(1, 1));
	example.push_back(make_pair(3, 2));
	example.push_back(make_pair(2, 3));
	example.push_back(make_pair(4, 4));

	//	정렬전
	for (auto p : example) {
		cout << p.first << " " << p.second << endl;
	}

	sort(example.begin(), example.end(), compare);

	// 정렬후
	for (auto p : example) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}