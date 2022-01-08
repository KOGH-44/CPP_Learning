// 10 ��ü�� Ŭ����

// 10.1 ���ӽ����̽�(namespace)
// ex10.1 �� ���ӽ����̽��� ���� �� �Լ� ����ϱ�
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
//int main() { // main�Լ��� ���� ���ӽ����̽��� �����ִ�.
//	doodle::set();
//	google::set();
//
//	cout << doodle::n << endl;
//	cout << google::n << endl;
//}


// ex10.2 ���� �ٸ� ���ӽ����̽��� ���� ����ϱ�
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


// ex10.3 ��ø ���ӽ����̽������� �̸� �˻�
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


// ex10.4 using�� ����غ���
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


// ex10.4.1 using���� ������
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
//	set(); // ����! ::set�� doodle::set ���̰� ��ȣ�ϴ�.
//	cout << n << endl; // ���������� ����!
//}


// 10.2 Ŭ������ ��ü

// ex10.5 TV Ŭ����(����ü) ����غ��� (encapsulation ĸ��ȭ)
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
//	cout << "���� ä���� " << mytv.getChannel() << endl;
//	cout << "���� ������ " << mytv.getVolume() << endl;
//}


// 10.3 this ������

// ex10.6 this ������ ����� ����
//#include <iostream>	
//using namespace std;
//
//class MyClass {
//public:
//	void PrintThis() {
//		cout << "���� �ּҴ� " << this << endl;
//	}
//	int x;
//};
//
//int main() {
//	MyClass a, b;
//	
//	cout << "��ü a�� �ּҴ� " << &a << endl;
//	cout << "��ü b�� �ּҴ� " << &b << endl;
//
//	a.PrintThis();
//	b.PrintThis();
//} // ��� ������ �� ��ü���� ���� �޸𸮸� �������� ��� �Լ�(�޼���)�� �޸𸮿� �Ϲ����� �Լ��� ���·� �ϳ��� ����ȴ�.
//// �̷��� �޼��带 ȣ���ϸ� � ��ü�� ȣ���Ѱ��� �˼� �ֵ��� ���� ������ �ʴ� �Ű������� ���� a, b�� �ּڰ��� ��н����� �Ѿ�� �ǰ�, �� �Ű������� this�̴�.


// 10.4 ��ü�� ������ �Ҹ� (������ constructor, �Ҹ��� destructor)
// ������ : �Լ� ������� �ٸ��� ���� Ÿ���� ���� �ʰ�, �������� �̸��� �� �����ڰ� ���Ե� Ŭ������ �̸��� ����.
// �Ҹ��� : ����ǥ�� �޸� �ȴ�.

// ex10.7 ���� ��ü�� �����ڿ� �Ҹ����� ȣ�� �ñ� �˾ƺ���
//#include <iostream>
//using namespace std;
//
//class MyClass {
//public:
//	MyClass() { // ������
//		cout << "�����ڰ� ȣ��Ǿ���!" << endl;
//	}
//	~MyClass() // �Ҹ���
//	{
//		cout << "�Ҹ��ڰ� ȣ��Ǿ���!" << endl;
//	}
//};
//
//// MyClass globalObj; // ���� ��ü
//
//void testLocalObj() {
//	cout << "=== testLocalObj �Լ� ���� ===" << endl;
//	MyClass localObj; // ���� ��ü
//	cout<<"=== testLocalObj �Լ� �� ===" << endl;
//}
//
//int main() {
//	cout << "=== main �Լ� ���� ===" << endl;
//	testLocalObj();
//	cout << "=== main �Լ� �� ===" << endl;
//}


// ex10.8 ���� ��ü�� �����ڿ� �Ҹ����� ȣ�� �ñ� �˾ƺ���
//#include <iostream>
//using namespace std;
//
//class MyClass {
//public:
//	MyClass() { // ������
//		cout << "�����ڰ� ȣ��Ǿ���!" << endl;
//	}
//	~MyClass() // �Ҹ���
//	{
//		cout << "�Ҹ��ڰ� ȣ��Ǿ���!" << endl;
//	}
//};
//
//MyClass globalObj; // ���� ��ü
//
//void testLocalObj() {
//	cout << "=== testLocalObj �Լ� ���� ===" << endl;
//	MyClass localObj; // ���� ��ü
//	cout << "=== testLocalObj �Լ� �� ===" << endl;
//}
//
//int main() {
//	cout << "=== main �Լ� ���� ===" << endl;
//	testLocalObj();
//	cout << "=== main �Լ� �� ===" << endl;
//} 


// ex10.9 ���Ҽ��� �����ϴ� ��ü���� ������ �����ε��ϱ�
//#include <iostream>
//using namespace std;
//
//class Complex {
//public:
//	Complex() {
//		real = 0;
//		imag = 0;
//	} // Ŭ������ �����ڰ� �ϳ��� ����� �Ǹ�, �Ϲ������� �����Ǵ� ����Ʈ(�⺻) �����ڴ� ������� �ȴ�. �̰� �� ���������� ����Ʈ(�⺻) �����ڰ� �ϴ� ������ �Ѵ�.
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
//	Complex c1; // Complex() ȣ��
//	Complex c2 = Complex(2, 3); // Complex(double, double) ȣ��
//	Complex c3(4, 5); // Complex(double, double) ȣ��
//
//	cout << "c1 = " << c1.GetReal() << ", " << c1.GetImag() << endl;
//	cout << "c2 = " << c2.GetReal() << ", " << c2.GetImag() << endl;
//	cout << "c3 = " << c3.GetReal() << ", " << c3.GetImag() << endl;
//}


// ����Ʈ �ʱ�ȭ ��� (list-initialization)
 //Complex c4 = {2, 3};
 //Complex c5 = Complex{2, 3};
 //Complex c6{2, 3};


 // 10.5 �������� �پ��� ����
 // ex10.10 �����ڿ� ����Ʈ �Ű����� ����ϱ�
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
//	Complex c1; // real_, imag_�� �ش��ϴ� �μ��� �����Ƿ� ����Ʈ ������ �ʱ�ȭ
//	Complex c2 = Complex(2, 3); 
//	Complex c3(4, 5);
//
//	cout << "c1 = " << c1.getReal() << ", " << c1.getImag() << endl;
//	cout << "c2 = " << c2.getReal() << ", " << c2.getImag() << endl;
//	cout << "c3 = " << c3.getReal() << ", " << c3.getImag() << endl;
//}


// Time Ŭ���� ����� (������ ���� Ȱ��)
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
//	cout << t0.h << " ��, " << t0.m << " ��, " << t0.s << " ��" << endl;
//	cout << t1.h << " ��, " << t1.m << " ��, " << t1.s << " ��" << endl;
//	cout << t2.h << " ��, " << t2.m << " ��, " << t2.s << " ��" << endl;
//	cout << t3.h << " ��, " << t3.m << " ��, " << t3.s << " ��" << endl;
//}


// ���� ��� (Static Member) ����� ��ü �Ҽ��� �ƴ϶� Ŭ���� �Ҽ����� ����� ������ ���� (��ü�� ����ٰ� ���� ������ ����, ��ü�� ������ �ʾҴٰ� �Ȼ���°͵� �ƴ�)
// 10.6.1 ���� ��� �޼���
// ex10.11 ���� ���� Ŭ�������� �� ���� ���� ���� ��� �޼��带 ����� ����ϱ�
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


// 10.6.2 ���� ��� ���� (���� ��� ������ ���� ��� ������ private�� �־ �ʱ�ȭ�� ����������, ������ �Ұ����ϴ�.) (���� ��� ������ ���� ������ �ʱ�ȭ ������Ѵ�.)
// ex10.12 ���� ��� ������ ����Ͽ� ��ü�� �Ϸù�ȣ �ű��
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
//int Color::idCounter = 1; // ���� �������� ���� ��� ���� �ʱ�ȭ
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


// 10.7 ����� �޼��� (��ü�� ��ȭ��Ű�� �ʴ� �޼��带 ���� �� ���) (��ü�� ��������� �����ϸ� ����� �޼��常 ȣ�� �����ϴ�!)
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
//		cout << d << "���� �����ߴ�!" << endl;
//	}
//	void Draw(const int d) {
//		// d = money;
//		if (money - d >= 0) {
//			money -= d;
//			cout << d << "���� �����ߴ�!" << endl;
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
//	other.Draw(4000); // ��ü�� ��������� �����Ͽ��⿡, ��� �޼��尡 �ƴ� �޼��带 ��� �Ұ����ϴ�.
//}


// 10.8 �޼��� ����� ���� �и��ϱ�
// ex10.13 �����ڿ� �޼����� ����� ���� �и��ϱ�
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


// 10.9 ������ �����ε�
// ex10.14 �پ��� ������ �Լ��� ����Ͽ� ��ü���� �����غ���
//#include <iostream>
//using namespace std;
//
//// Ŭ���� ����
//
//class Vector2 {
//public:
//	Vector2();
//	Vector2(float x, float y);
//	float GetX() const;
//	float GetY() const;
//	static Vector2 Sum(Vector2 a, Vector2 b); // ���� �޼��� ����
//	Vector2 Add(Vector2 other); // �Ϲ� �޼��� ����
//
//private:
//	float x, y;
//};
//
//Vector2 Sum(Vector2 a, Vector2 b); // ���� �Լ� ����
//
//// ���� �Լ�
//
//int main() {
//	Vector2 a(2, 3), b(5, 6);
//	Vector2 c1 = Sum(a, b); // ���� �Լ� ȣ��
//	Vector2 c2 = Vector2::Sum(a, b); // ���� �޼��� ȣ��
//	Vector2 c3 = a.Add(b); // �Ϲ� �޼��� ȣ��
//
//	cout << "c1 = (" << c1.GetX() << ", " << c1.GetY() << ")" << endl;
//	cout << "c2 = (" << c2.GetX() << ", " << c2.GetY() << ")" << endl;
//	cout << "c3 = (" << c3.GetX() << ", " << c3.GetY() << ")" << endl;
//}
//
//// �Լ� ����
//
//Vector2::Vector2() : x(0), y(0) {}
//Vector2::Vector2(float x, float y) : x(x), y(y) {}
//float Vector2::GetX() const { return x; }
//float Vector2::GetY() const { return y; }
//
//// ���� �޼��� ����
//// Tip: ���� �޼����� ���ǿ����� static Ű���带 ���� �ʿ䰡 ����.
//Vector2 Vector2::Sum(Vector2 a, Vector2 b) {
//	return Vector2(a.x + b.x, a.y + b.y);
//}
//// �Ϲ� �޼��� ����
//Vector2 Vector2::Add(Vector2 other) {
//	return Vector2(x + other.x, y + other.y);
//}
//// ���� �Լ� ����
//Vector2 Sum(Vector2 a, Vector2 b) {
//	return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
//}


// �� ���� ����
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
//	static Vector2 Sum(Vector2 a, Vector2 b); // ���� �޼��� ����
//	Vector2 Add(Vector2 other); // �Ϲ� �޼��� ����
//};
//
//Vector2 Sum(Vector2 a, Vector2 b); // ���� �Լ� ����
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


// ex10.15 ����, ���� ������ �����ε��غ���
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


// ex10.16 ���� ������ �����ε��غ���
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
//	Vector2 operator*(const float k) const; // ���� * �Ǽ�
//	float operator*(const Vector2 other) const; // ���� * ���� (����)
//};
//
//Vector2 operator*(const float k, const Vector2 v); // �Ǽ� * ����
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


// ���չ���
// 1�� 
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


// 2��
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


// 3��
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
