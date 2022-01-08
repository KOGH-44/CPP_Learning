// 10 객체와 클래스

// 10.1 네임스페이스(namespace)
// ex10.1 각 네임스페이스의 변수 및 함수 사용하기
//#include <iostream>	
//using namespace std;
//
//namespace doodle {
//	int n;
//	void set() {
//		n = 20;
//	}
//}
//namespace google {
//	int n;
//	void set() {
//		n = 30;
//	}
//}
//
//int main() { // main함수는 전역 네임스페이스에 속해있다.
//	doodle::set();
//	google::set();
//
//	cout << doodle::n << endl;
//	cout << google::n << endl;
//}


// ex10.2 서로 다른 네임스페이스의 변수 사용하기
//#include <iostream>
//using namespace std;
//
//namespace doodle {
//	int n;
//	void set() {
//		n = 20;
//	}
//}
//
//namespace google {
//	void set() {
//		doodle::n = 30;
//	}
//}
//
//int main() {
//	doodle::set();
//	cout << doodle::n << endl;
//
//	google::set();
//	cout << doodle::n << endl;
//}


// ex10.3 중첩 네임스페이스에서의 이름 검색
//#include <iostream>	
//using namespace std;
//
//namespace doodle {
//	int m, n;
//	void set();
//	namespace google {
//		int n;
//		void set();
//	}
//}
//
//void doodle::set() {
//	n = 20;
//}
//
//void doodle::google::set() {
//	m = 30;
//	n = 40;
//}
//
//int main() {
//	doodle::set();
//	doodle::google::set();
//
//	cout << doodle::m << endl;
//	cout << doodle::n << endl;
//	cout << doodle::google::n << endl;
//}


// ex10.4 using문 사용해보기
//#include <iostream>
//using namespace std;
//
//namespace doodle {
//	int n;
//	void set() {
//		n = 20;
//	}
//}
//
//int main() {
//	using namespace doodle;
//
//	set();
//	cout << n << endl;
//}


// ex10.4.1 using문의 문제점
//#include <iostream>
//using namespace std;
//
//int n;
//void set() {
//	n = 10;
//}
//namespace doodle {
//	int n;
//	void set() {
//		n = 20;
//	}
//}
//
//int main() {
//	using namespace doodle;
//	set(); // 에러! ::set과 doodle::set 사이가 모호하다.
//	cout << n << endl; // 마찬가지로 에러!
//}


// 10.2 클래스와 객체

// ex10.5 TV 클래스(구조체) 사용해보기 (encapsulation 캡슐화)
//#include <iostream> 
//using namespace std;
//
//struct TV {
//private:
//	bool powerOn;
//	int channel;
//	int volume;
//public:
//	void on() {
//		powerOn = true;
//	}
//	void off() {
//		powerOn = false;
//	}
//	void setChannel(int chn) {
//		if (chn >= 1 && chn <= 999) {
//			channel = chn;
//		}
//	}
//	int getChannel() {
//		return channel;
//	}
//	void setVolume(int vol) {
//		if (vol >= 0 && vol <= 100) {
//			volume = vol;
//		}
//	}
//	int getVolume() {
//		return volume;
//	}
//};
//
//int main() {
//	TV mytv;
//
//	mytv.on();
//	mytv.setChannel(10);
//	mytv.setVolume(50);
//	
//	cout << "현재 채널은 " << mytv.getChannel() << endl;
//	cout << "현재 볼륨은 " << mytv.getVolume() << endl;
//}


// 10.3 this 포인터

// ex10.6 this 포인터 사용해 보기
//#include <iostream>	
//using namespace std;
//
//class MyClass {
//public:
//	void PrintThis() {
//		cout << "나의 주소는 " << this << endl;
//	}
//	int x;
//};
//
//int main() {
//	MyClass a, b;
//	
//	cout << "객체 a의 주소는 " << &a << endl;
//	cout << "객체 b의 주소는 " << &b << endl;
//
//	a.PrintThis();
//	b.PrintThis();
//} // 멤버 변수는 각 객체마다 각각 메모리를 가지지만 멤버 함수(메서드)는 메모리에 일반적인 함수의 형태로 하나만 저장된다.
//// 이러한 메서드를 호출하면 어떤 객체가 호출한건지 알수 있도록 눈에 보이지 않는 매개변수를 통해 a, b의 주솟값이 비밀스럽게 넘어가게 되고, 이 매개변수가 this이다.


// 10.4 객체의 생성과 소멸 (생성자 constructor, 소멸자 destructor)
// 생성자 : 함수 선언과는 다르게 리턴 타입을 적지 않고, 생성자의 이름은 그 생성자가 포함된 클래스의 이름과 같다.
// 소멸자 : 물결표를 달면 된다.

// ex10.7 지역 객체의 생성자와 소멸자의 호출 시기 알아보기
//#include <iostream>
//using namespace std;
//
//class MyClass {
//public:
//	MyClass() { // 생성자
//		cout << "생성자가 호출되었다!" << endl;
//	}
//	~MyClass() // 소멸자
//	{
//		cout << "소멸자가 호출되었다!" << endl;
//	}
//};
//
//// MyClass globalObj; // 전역 객체
//
//void testLocalObj() {
//	cout << "=== testLocalObj 함수 시작 ===" << endl;
//	MyClass localObj; // 지역 객체
//	cout<<"=== testLocalObj 함수 끝 ===" << endl;
//}
//
//int main() {
//	cout << "=== main 함수 시작 ===" << endl;
//	testLocalObj();
//	cout << "=== main 함수 끝 ===" << endl;
//}


// ex10.8 지역 객체의 생성자와 소멸자의 호출 시기 알아보기
//#include <iostream>
//using namespace std;
//
//class MyClass {
//public:
//	MyClass() { // 생성자
//		cout << "생성자가 호출되었다!" << endl;
//	}
//	~MyClass() // 소멸자
//	{
//		cout << "소멸자가 호출되었다!" << endl;
//	}
//};
//
//MyClass globalObj; // 전역 객체
//
//void testLocalObj() {
//	cout << "=== testLocalObj 함수 시작 ===" << endl;
//	MyClass localObj; // 지역 객체
//	cout << "=== testLocalObj 함수 끝 ===" << endl;
//}
//
//int main() {
//	cout << "=== main 함수 시작 ===" << endl;
//	testLocalObj();
//	cout << "=== main 함수 끝 ===" << endl;
//} 


// ex10.9 복소수를 저장하는 객체에서 생성자 오버로딩하기
//#include <iostream>
//using namespace std;
//
//class Complex {
//public:
//	Complex() {
//		real = 0;
//		imag = 0;
//	} // 클래스에 생성자가 하나라도 생기게 되면, 암묵적으로 생성되던 디폴트(기본) 생성자는 사라지게 된다. 이게 이 예제에서는 디폴트(기본) 생성자가 하던 역할을 한다.
//	Complex(double real_, double imag_) {
//		real = real_;
//		imag = imag_;
//	} 
//	double GetReal() {
//		return real;
//	}
//	double SetReal(double real_) {
//		real = real_;
//	}
//	double GetImag() {
//		return imag;
//	}
//	double SetImag(double imag_) {
//		imag = imag_;
//	}
//private:
//	double real;
//	double imag;
//};
//
//int main() {
//	Complex c1; // Complex() 호출
//	Complex c2 = Complex(2, 3); // Complex(double, double) 호출
//	Complex c3(4, 5); // Complex(double, double) 호출
//
//	cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
//	cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
//	cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
//}


// 리스트 초기화 방법 (list-initialization)
 //Complex c4 = {2, 3};
 //Complex c5 = Complex{2, 3};
 //Complex c6{2, 3};


 // 10.5 생성자의 다양한 사용법
 // ex10.10 생성자에 디폴트 매개변수 사용하기
//#include <iostream>
//using namespace std;
//
//class Complex {
//public:
//	Complex(double real_ = 0, double imag_ = 0) {
//		real = real_;
//		imag = imag_;
//	}
//
//	double getReal() {
//		return real;
//	}
//	void setReal(double real_) {
//		real = real_;
//	}
//	double getImag() {
//		return imag;
//	}
//	void setImag(double imag_) {
//		imag = imag_;
//	}
//private:
//	double real;
//	double imag;
//};
//
//int main() {
//	Complex c1; // real_, imag_에 해당하는 인수가 없으므로 디폴트 값으로 초기화
//	Complex c2 = Complex(2, 3); 
//	Complex c3(4, 5);
//
//	cout << "c1 = " << c1.getReal() << ", " << c1.getImag() << endl;
//	cout << "c2 = " << c2.getReal() << ", " << c2.getImag() << endl;
//	cout << "c3 = " << c3.getReal() << ", " << c3.getImag() << endl;
//}


// Time 클래스 만들기 (생성자 위임 활용)
//#include <iostream>
//using namespace std;
//
//class Time {
//public:
//	int h, m, s;
//
//	Time() : h(0), m(0), s(0) {
//	}
//	Time(int s) : Time()  {
//		this->s = s;
//	}
//	Time(int m, int s) : Time(s) {
//		this->m = m;
//	}
//	Time(int h, int m, int s) : Time(m, s) {
//		(*this).h = h;
//	} 
//};
//
//int main() {
//	Time t0;
//	Time t1(11);
//	Time t2(21, 44);
//	Time t3(4, 22, 15);
//
//	cout << t0.h << " 시, " << t0.m << " 분, " << t0.s << " 초" << endl;
//	cout << t1.h << " 시, " << t1.m << " 분, " << t1.s << " 초" << endl;
//	cout << t2.h << " 시, " << t2.m << " 분, " << t2.s << " 초" << endl;
//	cout << t3.h << " 시, " << t3.m << " 분, " << t3.s << " 초" << endl;
//}


// 정적 멤버 (Static Member) 멤버를 객체 소속이 아니라 클래스 소속으로 만들어 버리는 개념 (객체를 만든다고 따로 생기지 않음, 객체를 만들지 않았다고 안생기는것도 아님)
// 10.6.1 정적 멤버 메서드
// ex10.11 색깔 저장 클래스에서 두 색을 섞는 정적 멤버 메서드를 만들고 사용하기
//#include <iostream>	
//using namespace std;
//
//class Color {
//public:
//	Color() : r(0), g(0), b(0) {}
//	Color(float r, float g, float b) : r(r), g(g), b(b) {}
//	
//	float getR() { return r; }
//	float getG() { return g; }
//	float getB() { return b; }
//
//	static Color MixColors(Color a, Color b) {
//		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
//	}
//
//private:
//	float r;
//	float g;
//	float b;
//
//};
//
//int main() {
//	Color red = Color(1, 0, 0);
//	Color blue = Color(0, 0, 1);
//	Color purple = Color::MixColors(red, blue);
//
//	cout << red.getR() << ", " << red.getG() << ", " << red.getB() << endl;
//	cout << blue.getR() << ", " << blue.getG() << ", " << blue.getB() << endl;
//	cout << purple.getR() << ", " << purple.getG() << ", " << purple.getB() << endl;
//}


// 10.6.2 정적 멤버 변수 (정적 멤버 변수는 정적 멤버 변수가 private에 있어도 초기화는 가능하지만, 대입은 불가능하다.) (정적 멤버 변수는 전역 범위에 초기화 해줘야한다.)
// ex10.12 정적 멤버 변수를 사용하여 객체에 일련번호 매기기
//#include <iostream>	
//using namespace std;
//
//class Color {
//public:
//	Color() : r(0), g(0), b(0), id(idCounter++) {}
//	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}
//	
//	int GetId() { return id; }
//	float GetR() { return r; }
//	float GetG() { return g; }
//	float GetB() { return b; }
//
//	static Color MixColor(Color a, Color b) {
//		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
//	}
//
//private:
//	static int idCounter;
//	float r, g, b;
//	int id;
//};
//
//int Color::idCounter = 1; // 전역 범위에서 정적 멤버 변수 초기화
//
//int main() {
//	Color red = Color(1, 0, 0);
//	Color blue = Color(0, 0, 1);
//	Color purple = Color::MixColor(red, blue);
//
//	cout << red.GetId() << endl;
//	cout << blue.GetId() << endl;
//	cout << purple.GetId() << endl;
//}


// 10.7 상수형 메서드 (객체를 변화시키지 않는 메서드를 만들 때 사용) (객체를 상수형으로 선언하면 상수형 메서드만 호출 가능하다!)
// ex
//#include <iostream>
//using namespace std;
//
//class Account {
//public:
//	Account() : money(0) {}
//	Account(int money) : money(money) {}
//
//	void Deposit(const int d) {
//		// d = 2000;
//		money += d;
//		cout << d << "원을 예금했다!" << endl;
//	}
//	void Draw(const int d) {
//		// d = money;
//		if (money - d >= 0) {
//			money -= d;
//			cout << d << "원을 인출했다!" << endl;
//		}
//	}
//	int GetMoney() const {
//		// money++;
//		return money;
//	}
//
//private:
//	int money;
//};
//
//int main() {
//	Account myAccount(50000);
//	cout << myAccount.GetMoney() << endl;
//	myAccount.Draw(4000);
//
//	const Account other(120000);
//	cout << other.GetMoney() << endl;
//	other.Draw(4000); // 객체를 상수형으로 선언하였기에, 상수 메서드가 아닌 메서드를 사용 불가능하다.
//}


// 10.8 메서드 선언과 정의 분리하기
// ex10.13 생성자와 메서드의 선언과 정의 분리하기
//#include <iostream>	
//using namespace std;
//
//class Vector2 {
//public:
//	Vector2();
//	Vector2(float x, float y);
//	float GetX() const;
//	float GetY() const;
//
//private:
//	float x, y;
//};
//
//int main() {
//	Vector2 a(2, 3);
//	cout << "a = (" << a.GetX() << ", " << a.GetY() << ")" << endl;
//}
//
//Vector2::Vector2() : x(0), y(0) {}
//Vector2::Vector2(float x, float y) : x(x), y(y) {}
//float Vector2::GetX() const {
//	return x;
//}
//float Vector2::GetY() const {
//	return y;
//}


// 10.9 연산자 오버로딩
// ex10.14 다양한 형태의 함수를 사용하여 객체끼리 연산해보기
//#include <iostream>
//using namespace std;
//
//// 클래스 정의
//
//class Vector2 {
//public:
//	Vector2();
//	Vector2(float x, float y);
//	float GetX() const;
//	float GetY() const;
//	static Vector2 Sum(Vector2 a, Vector2 b); // 정적 메서드 선언
//	Vector2 Add(Vector2 other); // 일반 메서드 선언
//
//private:
//	float x, y;
//};
//
//Vector2 Sum(Vector2 a, Vector2 b); // 전역 함수 선언
//
//// 메인 함수
//
//int main() {
//	Vector2 a(2, 3), b(5, 6);
//	Vector2 c1 = Sum(a, b); // 전역 함수 호출
//	Vector2 c2 = Vector2::Sum(a, b); // 정적 메서드 호출
//	Vector2 c3 = a.Add(b); // 일반 메서드 호출
//
//	cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
//	cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;
//	cout << "c3 = (" << c3.GetX() << ", " << c3.GetY() << ")" << endl;
//}
//
//// 함수 정의
//
//Vector2::Vector2() : x(0), y(0) {}
//Vector2::Vector2(float x, float y) : x(x), y(y) {}
//float Vector2::GetX() const { return x; }
//float Vector2::GetY() const { return y; }
//
//// 정적 메서드 정의
//// Tip: 정적 메서드의 정의에서는 static 키워드를 붙일 필요가 없다.
//Vector2 Vector2::Sum(Vector2 a, Vector2 b) {
//	return Vector2(a.x + b.x, a.y + b.y);
//}
//// 일반 메서드 정의
//Vector2 Vector2::Add(Vector2 other) {
//	return Vector2(x + other.x, y + other.y);
//}
//// 전역 함수 정의
//Vector2 Sum(Vector2 a, Vector2 b) {
//	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
//}


// 위 예제 연습
//#include <iostream>
//using namespace std;
//
//class Vector2 {
//private:
//	float x, y;
//
//public:
//	Vector2();
//	Vector2(float x, float y);
//	float GetX() const;
//	float GetY() const;
//
//	static Vector2 Sum(Vector2 a, Vector2 b); // 정적 메서드 선언
//	Vector2 Add(Vector2 other); // 일반 메서드 선언
//};
//
//Vector2 Sum(Vector2 a, Vector2 b); // 전역 함수 선언
//
//int main() {
//	Vector2 a(4, 5), b(5, 11);
//	Vector2 c1 = Vector2::Sum(a, b);
//	Vector2 c2 = a.Add(b);
//	Vector2 c3 = Sum(a, b);
//
//	cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
//	cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;
//	cout << "c3 = (" << c3.GetX() << ", " << c3.GetY() << ")" << endl;
//}
//
//Vector2::Vector2() : x(0), y(0) {}
//Vector2::Vector2(float x, float y) : x(x), y(y) {}
//float Vector2::GetX() const { return x; }
//float Vector2::GetY() const { return y; }
//
//Vector2 Vector2::Sum(Vector2 a, Vector2 b) {
//	return Vector2(a.x + b.x, a.y + b.y);
//}
//Vector2 Vector2::Add(Vector2 other) {
//	return Vector2(x + other.x, y + other.y);
//}
//Vector2 Sum(Vector2 a, Vector2 b) {
//	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
//}


// ex10.15 덧셈, 뺄셈 연산자 오버로딩해보기
//#include <iostream>	
//using namespace std;
//
//class Vector2 {
//private:
//	float x, y;
//	
//public:
//	Vector2();
//	Vector2(float x, float y);
//	float GetX() const;
//	float GetY() const;
//	Vector2 operator+(const Vector2 ohter) const;
//	Vector2 operator-(const Vector2 other) const;
//};
//
//int main() {
//	Vector2 a(2, 3), b(5, 6);
//	Vector2 c1 = a + b;
//	Vector2 c2 = a - b;
//	cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
//	cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;	
//}
//
//Vector2::Vector2() : x(0), y(0) {}
//Vector2::Vector2(float x, float y) : x(x), y(y) {}
//float Vector2::GetX() const { return x; }
//float Vector2::GetY() const { return y; }
//
//Vector2 Vector2::operator+(const Vector2 other) const {
//	return Vector2(x + other.x, y + other.y);
//}
//Vector2 Vector2::operator-(const Vector2 other) const {
//	return Vector2(x - other.x, y - other.y);
//}


// ex10.16 곱셈 연산자 오버로딩해보기
//#include <iostream>
//using namespace std;
//
//class Vector2 {
//private:
//	float x, y;
//
//public:
//	Vector2();
//	Vector2(float, float);
//	float GetX() const;
//	float GetY() const;
//	Vector2 operator+(const Vector2 other) const;
//	Vector2 operator-(const Vector2 other) const;
//	Vector2 operator*(const float k) const; // 벡터 * 실수
//	float operator*(const Vector2 other) const; // 벡터 * 벡터 (내적)
//};
//
//Vector2 operator*(const float k, const Vector2 v); // 실수 * 벡터
//
//int main() {
//	Vector2 a(2, 3), b(5, 6);
//	Vector2 c1 = a * 3.1;
//	Vector2 c2 = 3.1 * a;
//	float c3 = a * b;
//	cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
//	cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;	
//	cout << "c3 = " << c3 << endl;
//}
//
//Vector2::Vector2() : x(0), y(0) {}
//Vector2::Vector2(float x, float y) : x(x), y(y) {}
//float Vector2::GetX() const { return x; }
//float Vector2::GetY() const { return y; }
//
//Vector2 Vector2::operator+(const Vector2 other) const {
//	return Vector2(x + other.x, y + other.y);
//}
//Vector2 Vector2::operator-(const Vector2 other) const {
//	return Vector2(x - other.x, y - other.y);
//}
//Vector2 Vector2::operator*(const float k) const {
//	return Vector2(x * k, y * k);
//}
//float Vector2::operator*(const Vector2 other) const {
//	return x * other.x + y * other.y;
//}
//Vector2 operator*(const float k, const Vector2 v) {
//	return Vector2(k * v.GetX(), k * v.GetY());
//}


// 종합문제
// 1번 
//#include <iostream>
//using namespace std;
//
//int n = 0;
//namespace A {
//	int n = 0;
//	namespace B {
//		void set() { n = 10; }	
//		int n = 0;
//	}
//}
//namespace C {
//	void set();
//	int n = 0;
//}
//void C::set() { n = 20; }
//
//int main() {
//	using namespace A::B;
//
//	set();
//	C::set();
//
//	cout << ::n << endl; // 0
//	cout << A::n << endl; // 10
//	cout << A::B::n << endl; // 0
//	cout << C::n << endl; // 20
//}


// 2번
//#include <iostream>
//using namespace std;
//
//class GameWindow {
//public:
//	GameWindow();
//	GameWindow(const int, const int);
//
//	int GetWidth() const;
//	int GetHeight() const;
//
//	void ResizeWindow(const int, const int);
//
//private:
//	int width;
//	int height;
//};
//
//GameWindow::GameWindow() : width(800), height(600) {}
//GameWindow::GameWindow(const int w, const int h) {
//	ResizeWindow(w, h);
//}
//
//int GameWindow::GetWidth() const {
//	return width;
//}
//int GameWindow::GetHeight() const {
//	return height;
//}
//void GameWindow::ResizeWindow(const int w, const int h) {
//	if (w < 800) width = 800;
//	else width = w;
//	if (h < 600) height = 600;
//	else height = h;
//}
//
//int main() {
//	GameWindow mainWindow;
//	mainWindow.ResizeWindow(1366, 768);
//	cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;
//}


// 3번
#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass() : num(cnt++), ch('\0') {}

	void Check(MyClass* ptr) {
		if (ptr + num == this) {
			cout << num << endl;
		}
	}
	static int cnt;

private:
	int num;
	char ch;
};

int MyClass::cnt = 0;

int main() {
	MyClass obj[5];

	cout << "Test #1 : " << endl;
	for (int i = 0; i < 5; i++) {
		obj[i].Check(obj);
	}
	
	cout << "Test #2 : " << endl;
	for (MyClass& i : obj) {
		i.Check(obj);
	}

	cout << "cnt = " << MyClass::cnt << endl;
}
