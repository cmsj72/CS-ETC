#include<iostream>
#include<vector>
#include<algorithm>
//pair Ŭ������ utility�� ����
//utility�� algorithm, vector���� ���ԵǾ� �ִ�.
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main() {

	//	pair<type1, type2> p : pair Ŭ������ ��ü p�� ����
	pair<int, int> p1;

	//	p.first : p�� ù��° ���ڸ� ��ȯ
	//	p.second : p�� �ι�° ���ڸ� ��ȯ
	p1.first = 1;
	p1.second = 2;

	//	make_pair(��1, ��2) : ��1, ��2�� �ѽ����� �ϴ� pair�� ���� ��ȯ
	pair<int, double> p2;
	p2 = make_pair(1, 2.1);

	//	pair�� vector�� �Բ� ���� ���
	vector<pair<int, int>> arr;

	// �� vector�� ���� ����
	typedef pair<int, int> p;
	vector<p> arr2;
	
	//	pair ��ü�� ��� �񱳸� �� �� �ִ�.
	//	pair ��ü ���� ��� �񱳸� �����ϴ� ���,
	//	���� ���� ù��° ���� ���ϰ�, ù��° ���� ������ �ι�° ���� ���ؼ� �Ǵ�
	pair<int, int> a, b;
	a = make_pair(2, 4);
	b = make_pair(1, 5);
	a > b ? cout << "ù��°" : cout << "�ι�°";
	cout << endl;

	a = make_pair(2, 7);
	b = make_pair(2, 10);
	a > b ? cout << "ù��°" : cout << "�ι�°";
	cout << endl;

	cout << endl;
	//	���� ����
	vector<pair<int, int>> example;
	example.push_back(make_pair(1, 1));
	example.push_back(make_pair(3, 2));
	example.push_back(make_pair(2, 3));
	example.push_back(make_pair(4, 4));

	//	������
	for (auto p : example) {
		cout << p.first << " " << p.second << endl;
	}

	sort(example.begin(), example.end(), compare);

	// ������
	for (auto p : example) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}