// 09 C++ 스타일 기본 문법
 
// 9.1 C++ 스타일 입출력
//// ex9.1 C++ 버전의 Hello, world! 프로그램
//#include <iostream>
//
//int main() {
//	std::cout << "Hello, world!" << std::endl;
//}


// ex9.2 cout으로 다양한 자료형의 값을 출력해보기
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


// ex9.3 정수 두 개를 입력받아 합 출력하기
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
// ex9.4 string 활용해보기
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string name;
//	string greeting;
//
//	cout << "이름 입력: ";
//	cin >> name;
//
//	greeting = "안녕하세요, " + name + " 님!";
//	cout << greeting << endl;
//	cout << name << "은 총 " << name.length() << "글자입니다." << endl;
//	cout << name << "의 첫 글자는 " << name[0] << "입니다." << endl;
//}


// 9.3 C++에서는 의미가 좀 다른 초기화
// int a(10); <- int a = 10;과 같다. 또한 C++에서는 (변수 선언 후 대입) 과 (변수의 초기화)가 의미상 차이가 있다.


// 9.4 래퍼런스와 r-value 참조

// 래퍼런스 변수

// int a(10);
// int &b = a; // 래퍼런스 변수 b가 생성되고, b는 a를 가리킨다.
// b = 15; // b를 통해 a의 값을 바꿀 수 있다.
// cout << b << endl; // a의 값이 출력된다.

// int a(10);
// int &b; // 에러 : 생성과 동시에 가리키는 변수를 적어야 한다.

// 래퍼런스 변수는 메모리상에 저장된 공간이 있는 값만 가리킬 수 있다.

// int a(10);
// int &b1 = a; // ok
// int &b2 = 5; // 에러 : 상수는 가리킬 수 없다.
// int &b3 = f(a); // 에러 : 함수의 리턴 값을 가리킬 수는 없다.
// int &b4 = a + 1; // 에러 : 식을 가리킬 수는 없다.

// 래퍼런스 변수는 일반 변수와 달리 대입 연산자를 사용했을 때 아무 값도 복사되지 않고 우변의 변수를 가리키는 역할만 한다.

// r-value 참조 (C++11에 추가된 기능)

// int a;
// a = 10; // 가능! a는 l-value(변수)

// int b[5];
// b[0] = 10; // 가능! b[0], b[1], ...은 l-value(배열의 칸)

// struct { int x; } c, d;
// c = d; // 가능! c는 l-value(구조체 변수)
// c.x = 10; // 가능! c.x는 l-value(구조체 변수의 멤버 변수)

// r-value는 (몇몇 예외를 제외하고) 메모리상에 존재하지 않으며 등호의 좌변에 올 수 없다.

// 10 = 15; // 불가능! 10은 r-value(상수)

// int b = 5;
// b + 1 = 10; // 불가능! b + 1은 r-value(식). 반면 당연히 b는 l-value이다.

// int c, d, e[10], f[10];
// &c = &d; // 불가능! &c는 r-value(주소값)
// e = f; // 불가능! e는 r-value(주소값; e는 &e[0]과 같은 말이므로)

// func() = 1; // 불가능! func()는 함수의 리턴 값

// 래퍼런스 변수는 메모리상에 저장된 공간이 있는 값만 가리킬 수 있다고 했으므로 r-value는 가리키지 못함.
// 이때, r-value를 가리키는 무엇인가를 만들고 싶다면, r-value 참조를 사용할 수 있다. (&& 을 사용한다.)

//int a = 10;
//int&& b = a + 1; // 가능!
//int&& c = func(); // 가능!


// 9.5 범위 기반 for문 (C++11에 새로 추가된 for문의 현대적인 버전)
// ex9.5 배열에서 범위 기반 for문 사용해보기
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

// ex9.6 범위 기반 for문을 사용하여 배열의 각 칸의 값 바꿔보기(?)
//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	for (int i : arr) {
//		i++; // arr의 각 칸에 들어있는 값을 1씩 증가시킨다.
//	}
//	for (int i : arr) {
//		cout << i << ' ';
//	}
//	cout << endl;
//} // 실패!

// ex9.7 범위 기반 for문을 사용하여 배열의 각 칸의 값 바꿔보기(래퍼런스 사용)
//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (int& i : arr) { // i를 래퍼런스로 선언하면...
//		i++; // arr의 각 칸을 바꿀 수 있다.
//	}
//	for (int i : arr) { // 여기서는 배열이 변경될 일이 없으므로 일반 변수로 선언
//		cout << i << ' ';
//	}
//	cout << endl;
//}

// 9.6 C++ 스타일 함수

// 9.6.1 함수 오버로딩 (Overloading)
// ex9.8 swap 함수 오버로딩 해보기
//#include <iostream>
//using namespace std;
//
//void swap(int& a, int& b) { // int를 스왑하는 함수
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void swap(double& a, double& b) { // double을 스왑하는 함수
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void swap(char& a, char& b) { // char를 스왑하는 함수
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
//	swap(a, b); // swap(int &a, int &b) 호출
//	swap(da, db); // swap(double &da, double &db) 호출
//	swap(ca, cb); // swap(char &ca, char &cb) 호출
//
//	cout << a << " " << b << endl;
//	cout << da << " " << db << endl;
//	cout << ca << " " << cb << endl;
//}

// 다음 쌍은 오버로딩 가능
// void f(int a) / void f(double a) // 매개변수 자료형이 다르다.
// void g(int a, int b) / void g(int a, double b) // 두 번째 매개변수의 자료형이 다르다.
// void h(int a) / void h(int a, int b) // 매개변수의 개수가 아예 다르다.
// void k(int a, double b) / void k(double a, int b) // 종류는 같지만 순서가 다르다.

// 다음 쌍은 오버로딩 불가능
// void f(int a) / void f(int b) // 매개변수의 이름은 달라도 자료형이 같다.
// void g(int a) / int g(int a) // 리턴 타입이 달라도 매개변수의 자료형이 같으면 안된다.

// ex9.9 오버로딩을 통해 작성한 아이템 획득 횟수
//#include <iostream>
//using namespace std;
//
//int inventory[8] = { 0 };
//int score = 0;
//
//// 아이템을 한 개 주웠을 때
//void getItem(int itemId) {
//	inventory[itemId]++;
//}
//// 아이템을 여러 개 주웠을 때 (cnt : 아이템 개수)
//void getItem(int itemId, int cnt) {
//	inventory[itemId] += cnt;
//}
//// 아이템을 여러 개 줍고, 점수도 얻었을 때 (sc : 얻은 점수)
//void getItem(int itemId, int cnt, int sc) {
//	inventory[itemId] += cnt;
//	score += sc;
//}
//
//int main() {
//	getItem(6, 5); // 6번 아이템을 5개 얻음
//	getItem(3); // 3번 아이템을 하나 얻음
//	getItem(5, 4, 7000); // 5번 아이템을 4개 얻고 7000점을 얻음
//
//	//  보유하고 있는 아이템 개수 출력
//	for (int i : inventory) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "점수 : " << score << endl;
//}


// 9.6.2 디폴트 매개변수 (매개변수가 어떤 기본값을 갖게 하는 기능) (맨 뒤의 인수부터 차례대로 생략할 수 있다.)
// ex9.10 디폴트 매개변수 사용해보기
//#include <iostream>
//using namespace std;
//
//void f(int a = 1) {
//	cout << a << endl;
//}
//
//int main() {
//	f(123); // a에 123이 들어간다.
//	f(); // a에 기본값인 1이 들어간다.
//}


// ex9.11  디폴트 매개변수를 사용해 고쳐본 아이템 예제
//#include <iostream>
//using namespace std;
//
//int inventory[8] = { 0 };
//int score = 0;
//
//void getItem(int itemId, int cnt = 1, int sc = 0) {
//	inventory[itemId] += cnt; // cnt가 생략된 경우, 아이템 개수는 1만 증가
//	score += sc; // sc가 생략된 경우, score는 변화 없음
//}
//
//int main() {
//	getItem(6, 5); // 6번 아이템을 5개 얻음
//	getItem(3); // 3번 아이템을 하나 얻음
//	getItem(5, 4, 7000); // 5번 아이템을 4개 얻고 7000점을 얻음
//
//	// 보유하고 있는 아이템 개수 출력
//	for (int i : inventory) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "점수 : " << score << endl;
//}


// 종합문제
// 1번
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string name;
//	int score;
//
//	cout << "이름 입력 : ";
//	cin >> name;
//
//	cout << "정수 입력 : ";
//	cin >> score;
//
//	cout << name << " 님의 점수는 " << score << "점입니다." << endl;
//}


// 2번
//#include <iostream>
//using namespace std;
//
//int main() {
//	char str[] = "Hello, world!";
//	cout << str << endl;
//	cout << *str << endl;
//}


// 3번
#include <iostream>
using namespace std;

int main() {
	int arr[2][3] = { {1,2,3},{4,5,6} };

	for (int(&row)[3] : arr) { // int 3칸짜리 배열을 가리키는 래퍼런스
		for (int &num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
}