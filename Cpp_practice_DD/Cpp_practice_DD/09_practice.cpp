// 09 C++ ��Ÿ�� �⺻ ����
 
// 9.1 C++ ��Ÿ�� �����
//// ex9.1 C++ ������ Hello, world! ���α׷�
//#include <iostream>
//
//int main() {
//	std::cout << "Hello, world!" << std::endl;
//}


// ex9.2 cout���� �پ��� �ڷ����� ���� ����غ���
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 5;
//	double b = 3.141592;
//	char c = 'd';
//
//	cout << a << ' ' << b << ' ' << c << endl;
//}


// ex9.3 ���� �� ���� �Է¹޾� �� ����ϱ�
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a, b;
//
//	cin >> a >> b;
//	cout << a << " + " << b << " = " << a + b << endl;
//}


// 9.2 String
// ex9.4 string Ȱ���غ���
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string name;
//	string greeting;
//
//	cout << "�̸� �Է�: ";
//	cin >> name;
//
//	greeting = "�ȳ��ϼ���, " + name + " ��!";
//	cout << greeting << endl;
//	cout << name << "�� �� " << name.length() << "�����Դϴ�." << endl;
//	cout << name << "�� ù ���ڴ� " << name[0] << "�Դϴ�." << endl;
//}


// 9.3 C++������ �ǹ̰� �� �ٸ� �ʱ�ȭ
// int a(10); <- int a = 10;�� ����. ���� C++������ (���� ���� �� ����) �� (������ �ʱ�ȭ)�� �ǹ̻� ���̰� �ִ�.


// 9.4 ���۷����� r-value ����

// ���۷��� ����

// int a(10);
// int &b = a; // ���۷��� ���� b�� �����ǰ�, b�� a�� ����Ų��.
// b = 15; // b�� ���� a�� ���� �ٲ� �� �ִ�.
// cout << b << endl; // a�� ���� ��µȴ�.

// int a(10);
// int &b; // ���� : ������ ���ÿ� ����Ű�� ������ ����� �Ѵ�.

// ���۷��� ������ �޸𸮻� ����� ������ �ִ� ���� ����ų �� �ִ�.

// int a(10);
// int &b1 = a; // ok
// int &b2 = 5; // ���� : ����� ����ų �� ����.
// int &b3 = f(a); // ���� : �Լ��� ���� ���� ����ų ���� ����.
// int &b4 = a + 1; // ���� : ���� ����ų ���� ����.

// ���۷��� ������ �Ϲ� ������ �޸� ���� �����ڸ� ������� �� �ƹ� ���� ������� �ʰ� �캯�� ������ ����Ű�� ���Ҹ� �Ѵ�.

// r-value ���� (C++11�� �߰��� ���)

// int a;
// a = 10; // ����! a�� l-value(����)

// int b[5];
// b[0] = 10; // ����! b[0], b[1], ...�� l-value(�迭�� ĭ)

// struct { int x; } c, d;
// c = d; // ����! c�� l-value(����ü ����)
// c.x = 10; // ����! c.x�� l-value(����ü ������ ��� ����)

// r-value�� (��� ���ܸ� �����ϰ�) �޸𸮻� �������� ������ ��ȣ�� �º��� �� �� ����.

// 10 = 15; // �Ұ���! 10�� r-value(���)

// int b = 5;
// b + 1 = 10; // �Ұ���! b + 1�� r-value(��). �ݸ� �翬�� b�� l-value�̴�.

// int c, d, e[10], f[10];
// &c = &d; // �Ұ���! &c�� r-value(�ּҰ�)
// e = f; // �Ұ���! e�� r-value(�ּҰ�; e�� &e[0]�� ���� ���̹Ƿ�)

// func() = 1; // �Ұ���! func()�� �Լ��� ���� ��

// ���۷��� ������ �޸𸮻� ����� ������ �ִ� ���� ����ų �� �ִٰ� �����Ƿ� r-value�� ����Ű�� ����.
// �̶�, r-value�� ����Ű�� �����ΰ��� ����� �ʹٸ�, r-value ������ ����� �� �ִ�. (&& �� ����Ѵ�.)

//int a = 10;
//int&& b = a + 1; // ����!
//int&& c = func(); // ����!


// 9.5 ���� ��� for�� (C++11�� ���� �߰��� for���� �������� ����)
// ex9.5 �迭���� ���� ��� for�� ����غ���
//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (int i : arr) {
//		cout << i << ' ';
//	}
//	cout << endl;
//}

// ex9.6 ���� ��� for���� ����Ͽ� �迭�� �� ĭ�� �� �ٲ㺸��(?)
//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	for (int i : arr) {
//		i++; // arr�� �� ĭ�� ����ִ� ���� 1�� ������Ų��.
//	}
//	for (int i : arr) {
//		cout << i << ' ';
//	}
//	cout << endl;
//} // ����!

// ex9.7 ���� ��� for���� ����Ͽ� �迭�� �� ĭ�� �� �ٲ㺸��(���۷��� ���)
//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (int& i : arr) { // i�� ���۷����� �����ϸ�...
//		i++; // arr�� �� ĭ�� �ٲ� �� �ִ�.
//	}
//	for (int i : arr) { // ���⼭�� �迭�� ����� ���� �����Ƿ� �Ϲ� ������ ����
//		cout << i << ' ';
//	}
//	cout << endl;
//}

// 9.6 C++ ��Ÿ�� �Լ�

// 9.6.1 �Լ� �����ε� (Overloading)
// ex9.8 swap �Լ� �����ε� �غ���
//#include <iostream>
//using namespace std;
//
//void swap(int& a, int& b) { // int�� �����ϴ� �Լ�
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void swap(double& a, double& b) { // double�� �����ϴ� �Լ�
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void swap(char& a, char& b) { // char�� �����ϴ� �Լ�
//	char tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//	int a = 10, b = 20;
//	double da = 12.34, db = 56.78;
//	char ca = 'A', cb = 'B';
//
//	swap(a, b); // swap(int &a, int &b) ȣ��
//	swap(da, db); // swap(double &da, double &db) ȣ��
//	swap(ca, cb); // swap(char &ca, char &cb) ȣ��
//
//	cout << a << " " << b << endl;
//	cout << da << " " << db << endl;
//	cout << ca << " " << cb << endl;
//}

// ���� ���� �����ε� ����
// void f(int a) / void f(double a) // �Ű����� �ڷ����� �ٸ���.
// void g(int a, int b) / void g(int a, double b) // �� ��° �Ű������� �ڷ����� �ٸ���.
// void h(int a) / void h(int a, int b) // �Ű������� ������ �ƿ� �ٸ���.
// void k(int a, double b) / void k(double a, int b) // ������ ������ ������ �ٸ���.

// ���� ���� �����ε� �Ұ���
// void f(int a) / void f(int b) // �Ű������� �̸��� �޶� �ڷ����� ����.
// void g(int a) / int g(int a) // ���� Ÿ���� �޶� �Ű������� �ڷ����� ������ �ȵȴ�.

// ex9.9 �����ε��� ���� �ۼ��� ������ ȹ�� Ƚ��
//#include <iostream>
//using namespace std;
//
//int inventory[8] = { 0 };
//int score = 0;
//
//// �������� �� �� �ֿ��� ��
//void getItem(int itemId) {
//	inventory[itemId]++;
//}
//// �������� ���� �� �ֿ��� �� (cnt : ������ ����)
//void getItem(int itemId, int cnt) {
//	inventory[itemId] += cnt;
//}
//// �������� ���� �� �ݰ�, ������ ����� �� (sc : ���� ����)
//void getItem(int itemId, int cnt, int sc) {
//	inventory[itemId] += cnt;
//	score += sc;
//}
//
//int main() {
//	getItem(6, 5); // 6�� �������� 5�� ����
//	getItem(3); // 3�� �������� �ϳ� ����
//	getItem(5, 4, 7000); // 5�� �������� 4�� ��� 7000���� ����
//
//	//  �����ϰ� �ִ� ������ ���� ���
//	for (int i : inventory) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "���� : " << score << endl;
//}


// 9.6.2 ����Ʈ �Ű����� (�Ű������� � �⺻���� ���� �ϴ� ���) (�� ���� �μ����� ���ʴ�� ������ �� �ִ�.)
// ex9.10 ����Ʈ �Ű����� ����غ���
//#include <iostream>
//using namespace std;
//
//void f(int a = 1) {
//	cout << a << endl;
//}
//
//int main() {
//	f(123); // a�� 123�� ����.
//	f(); // a�� �⺻���� 1�� ����.
//}


// ex9.11  ����Ʈ �Ű������� ����� ���ĺ� ������ ����
//#include <iostream>
//using namespace std;
//
//int inventory[8] = { 0 };
//int score = 0;
//
//void getItem(int itemId, int cnt = 1, int sc = 0) {
//	inventory[itemId] += cnt; // cnt�� ������ ���, ������ ������ 1�� ����
//	score += sc; // sc�� ������ ���, score�� ��ȭ ����
//}
//
//int main() {
//	getItem(6, 5); // 6�� �������� 5�� ����
//	getItem(3); // 3�� �������� �ϳ� ����
//	getItem(5, 4, 7000); // 5�� �������� 4�� ��� 7000���� ����
//
//	// �����ϰ� �ִ� ������ ���� ���
//	for (int i : inventory) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "���� : " << score << endl;
//}


// ���չ���
// 1��
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string name;
//	int score;
//
//	cout << "�̸� �Է� : ";
//	cin >> name;
//
//	cout << "���� �Է� : ";
//	cin >> score;
//
//	cout << name << " ���� ������ " << score << "���Դϴ�." << endl;
//}


// 2��
//#include <iostream>
//using namespace std;
//
//int main() {
//	char str[] = "Hello, world!";
//	cout << str << endl;
//	cout << *str << endl;
//}


// 3��
#include <iostream>
using namespace std;

int main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };

	for (int(&row)[3] : arr) { // int 3ĭ¥�� �迭�� ����Ű�� ���۷���
		for (int &num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}