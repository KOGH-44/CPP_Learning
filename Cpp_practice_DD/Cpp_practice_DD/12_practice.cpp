// 상속


// 12.1 상속 기초
// 12.1.1 상속의 개념
// 자식 클래스는 부모 클래스에 포함되며, 부모 클래스의 멤버는 자식 클래스의 멤버에 포함된다.
// 부모 클래스는 parent class, base class, superclass 라고 부르며, 자식 클래스는 child class, derived class, subclass 라고 부른다.
// ex
//#include <iostream>
//using namespace std;
//class Base {
//public:
//	void bFunc() {
//		cout << "Hello from base!" << endl;
//	}
//	int bNum;
//};
//
//class Derived : public Base {
//public:
//	void dFunc() {
//		cout << "Hello from derived!" << endl;
//	}
//	int dNum;
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bFunc();
//	b.bNum = 1;
//
//	d.bFunc();
//	d.bNum = 2;
//	d.dFunc();
//	d.dNum = 3;
//
//	cout << b.bNum << endl;
//	cout << d.bNum << endl;
//	cout << d.dNum << endl;
//}


// 12.1.2 상속과 접근 제어
// 접근 제어자 / 클래스 외부에서 접근 / 자식 클래스에서 접근 / 클래스 내부에서 접근
// public	  /     가능            /       가능         /        가능
// protected  /     불가능          /       가능         /        가능
// private    /     불가능          /       불가능       /        가능
// ex
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int bPublic;
//protected:
//	int bProtected;
//private:
//	int bPrivate;
//};
//
//class Derived : public Base {
//public:
//	void DFunc() {
//		bPublic = 1; // OK.
//		bProtected = 2; // OK. 부모 클래스의 protected 멤버에는 접근 가능
//		bPrivate = 3; // 에러! 부모 클래스의 private 멤버에는 접근 불가
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // 에러! protected 멤버에는 클래스 외부에서 접근 불가
//	b.bPrivate = 13; // 에러! private 멤버에도 당연히 접근 불가
//}


// 상속 모드 
// ex (상속 모드가 public 일 경우)
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int bPublic;
//protected:
//	int bProtected;
//private:
//	int bPrivate;
//};
//
//class Derived : public Base {
//public:
//	void DFunc() {
//		bPublic = 1; // OK.
//		bProtected = 2; // OK. 부모 클래스의 protected 멤버에도 접근 가능
//		bPrivate = 3; // 에러! 부모 클래스의 private 멤버에는 접근 불가
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // 에러! protected 멤버는 클래스 외부에서 접근 불가
//	b.bPrivate = 13; // 에러! private 멤버에도 당연히 접근 불가
//	
//	d.bPublic = 111; 
//	d.bProtected = 112;
//	d.bPrivate = 113;
//}


// ex (상속 모드가 protected 일 경우)
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int bPublic;
//protected:
//	int bProtected;
//private:
//	int bPrivate;
//};
//
//class Derived : protected Base {
//public:
//	void DFunc() {
//		bPublic = 1; // OK.
//		bProtected = 2; // OK. 부모 클래스의 protected 멤버에도 접근 가능
//		bPrivate = 3; // 에러! 부모 클래스의 private 멤버에는 접근 불가
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // 에러! protected 멤버는 클래스 외부에서 접근 불가
//	b.bPrivate = 13; // 에러! private 멤버에도 당연히 접근 불가
//
//	d.bPublic = 111; // 에러! Base의 public 멤버는 Derived에서 protected 취급!!
//	d.bProtected = 112; // 에러! Base의 protected 멤버는 Derived에서도 protected 취급.
//	d.bPrivate = 113; // 에러! 애초부터 Base의 private 멤버임.
//}


// ex (상속 모드가 private 일 경우)
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int bPublic;
//protected:
//	int bProtected;
//private:
//	int bPrivate;
//};
//
//class Derived : private Base {
//public:
//	void DFunc() {
//		bPublic = 1; // OK.
//		bProtected = 2; // OK. 
//		bPrivate = 3; // 에러! 부모 클래스의 private 멤버에는 접근 불가
//	}
//};
//
//class DerivedDerived : private Derived { // Base의 손자 클래스 
//public:
//	void DDFunc() {
//		bPublic = 1; // 에러! 부모 클래스(Derived)의 private 멤버에는 접근 불가
//		bProtected = 2; // 에러! 부모 클래스의 private 멤버에는 접근 불가
//		bPrivate = 3; // 에러! 부모 클래스의 private 멤버에는 접근 불가
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//	DerivedDerived dd;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // 에러! protected 멤버는 클래스 외부에서 접근 불가
//	b.bPrivate = 13; // 에러! private 멤버에도 당연히 접근 불가
//
//	d.bPublic = 111; // 에러! Base의 public 멤버는 Derived에서 private 취급!!
//	d.bProtected = 112; // 에러! Base의 protected 멤버는 Derived에서 private 취급!!
//	d.bPrivate = 113; // 에러! 애초부터 Base의 private 멤버임.
//
//	dd.bPublic = 1111; // 에러! 애초부터 Derived의 private 멤버임.
//	dd.bProtected = 1112; // 에러! 애초부터 Derived의 private 멤버임.
//	dd.bPrivate = 1113; // 에러! 애초부터 Derived의 private 멤버임.
//}


//12.1.3 상속 예제
//ex12.1 Animal, Dog, Sparrow 클래스 상속 예제
//#include <iostream>	
//using namespace std;
//class Animal {
//public:
//	void Breathe() { cout << "숨을 쉰다." << endl; }	
//	int age;
//};
//
//class Dog : public Animal {
//public:
//	void Walk() { cout << "걷는다." << endl; }	
//};
//
//class Sparrow : public Animal {
//public:
//	void Fly() { cout << "난다." << endl; }
//};
//
//int main() {
//	Dog d;
//	d.age = 7;
//	d.Breathe();
//	d.Walk();
//	cout << d.age << endl;
//
//	Sparrow s;
//	s.age = 2;
//	s.Breathe();
//	s.Fly();
//	cout << s.age << endl;
//}


//12.2 상속 관계에서의 생성/소멸자
//ex12.2 간단한 상속 관계에서의 생성자 호출
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	Base() {
//		cout << "Base()" << endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	Derived() {
//		cout << "Derived()" << endl;
//	}
//};
//
//int main() {
//	Derived d; // Derived 생성자에서 특별한 언급을 하지 않으면 Base의 기본 생성자가 자동으로 호출이 된다.
//	// 그런데 만약 Base에 기본 생성자가 없다면(즉, Base에 생성자가 하나 이상 선언되었는데 그 중 매개변수를 받지 않는 생성자가 없을 경우...) 컴파일 에러가 발생한다.
//}

// 기본 생성자가 없어서 컴파일 에러가 발생하는 예시
//#include <iostream>	
//using namespace std;
//
//class Base {
//public:
//	Base(int a) {
//		cout << "Base(int)" << endl;
//	}
//};
//
//class Derived : public Base {  
//public:
//	Derived() { // 그런데 만약 Base에 기본 생성자가 없다면(즉, Base에 생성자가 하나 이상 선언되었는데 그 중 매개변수를 받지 않는 생성자가 없을 경우...) 컴파일 에러가 발생한다.
//		cout << "Derived()" << endl;
//	}
//};

// 위 에러 해결 방법
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	Base(int a) {
//		cout << "Base(int)" << endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	Derived() : Base(0) { // 해결 방법 : 다음과 같이 Base의 어느 생성자를 호출할지를 명시해줘야한다.
//		cout << "Derived()" << endl;
//	}
//};
//
//int main() {
//	Base b(1);
//	Derived d;
//}


//ex12.3 생성자/소멸자의 실행 순서 확인하기
//#include <iostream>
//using namespace std;
//
//class Ice {
//public:
//	Ice() { cout << "Ice()" << endl; }
//	~Ice() { cout << "~Ice()" << endl; }
//};
//
//class Pat {
//public:
//	Pat() { cout << "Pat()" << endl; }
//	~Pat() { cout << "~Pat()" << endl; }
//};
//
//class Bingsoo {
//public:
//	Bingsoo() { cout << "Bingsoo()" << endl; }
//	~Bingsoo() { cout << "~Bingsoo()" << endl; }
//	
//private:
//	Ice ice;
//};
//
//class PatBingsoo : public Bingsoo {
//public:
//	PatBingsoo() { cout << "PatBingsoo()" << endl; }
//	~PatBingsoo() { cout << "~PatBingsoo()" << endl; }
//
//private:
//	Pat pat;
//};
//
//int main() {
//	cout << "===== 1 =====" << endl;
//	PatBingsoo* p = new PatBingsoo;
//	cout << "===== 2 =====" << endl;
//	delete p;
//	cout << "===== 3 =====" << endl;
//}
// 생성자의 호출 순서
// 1. 부모 클래스의 생성자를 먼저 호출한다.
// 2. 클래스의 모든 멤버 변수가 생성된다. (즉, 멤버 변수들의 생성자가 호출된다.)
// 3. 생성자의 본문이 실행된다.

// 소멸자의 호출 순서
// 1. 소멸자의 본문이 실행된다.
// 2. 클래스의 모든 멤버 변수가 소멸된다. (즉, 멤버 변수들의 소멸자가 호출된다.)
// 3. 부모 클래스의 소멸자를 마지막에 호출한다.


//12.3 상속이 필요한 이유(1)
//ex12.4 TextMessage와 ImageMessage 클래스 만들기
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "사진";
//	}
//};
//
//class TextMessage {
//public:
//	TextMessage(int sendTime, string sendName, string text) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//		this->text = text;
//	}
//
//	int GetSendTime() const { return sendTime; }
//	string GetSendName() const { return sendName; }
//	string GetText() const { return text; }
//
//private:
//	int sendTime;
//	string sendName;
//	string text;
//};
//
//class ImageMessage {
//public:
//	ImageMessage(int sendTime, string sendName, Image* image) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//		this->image = image;
//	}
//
//	int GetSendTime() const { return sendTime; }
//	string GetSendName() const { return sendName; }
//	Image* GetImage() const { return image; }
//
//private:
//	int sendTime;
//	string sendName;
//	Image* image;
//};
//
//int main() {
//	Image* dogImage = new Image; // Image 객체를 미리 만들어 둔다.
//	TextMessage* hello = new TextMessage(10, "두들", "안녕"); 
//	// 만들어 둔 객체의 포인터를 생성자의 인수로 집어 넣는다.
//	ImageMessage* dog = new ImageMessage(30, "두들", dogImage);
//
//	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
//	cout << "보낸 사람 : " << hello->GetSendName() << endl;
//	cout << "  내용    : " << hello->GetText() << endl;
//	cout << endl;
//
//	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
//	cout << "보낸 사람 : " << dog->GetSendName() << endl;
//	cout << "  내용    : " << (string)*dog->GetImage() << endl; // ->, *, (string) 순으로 연산자가 계산된다.
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//ex12.5 상속을 사용해 고쳐본 메신저 예제
//#include <iostream>	
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "사진";
//	}
//};
//
//class Message {
//public:
//	Message(int sendTime, string sendName) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//	}
//
//	int GetSendTime() const { return sendTime; }
//	string GetSendName() const { return sendName; }
//
//private: // 자식 클래스에서는 이 변수들에 접근할 일이 없다.
//	int sendTime;
//	string sendName;
//};
//
//class TextMessage : public Message {
//public:
//	TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) // 부모 클래스 생성자 호출
//	{
//		this->text = text;
//	}
//
//	string GetText() const { return text; }
//
//private:
//	string text;
//};
//
//class ImageMessage : public Message {
//public:
//	ImageMessage(int sendTime, string sendName, Image* image) : Message(sendTime, sendName) // 부모 클래스 생성자 호출
//	{
//		this->image = image;
//	}
//
//	Image* GetImage() const { return image; }
//
//private:
//	Image* image;
//};
//
//int main() {
//	Image* dogImage = new Image;
//	TextMessage* hello = new TextMessage(10, "두들", "안녕");
//	ImageMessage* dog = new ImageMessage(20, "두들", dogImage);
//
//	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
//	cout << "보낸 사람 : " << hello->GetSendName() << endl;
//	cout << "   내용   : " << hello->GetText() << endl;
//	cout << endl;
//
//	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
//	cout << "보낸 사람 : " << dog->GetSendName() << endl;
//	cout << "   내용   : " << (string)*dog->GetImage() << endl;
//	cout << endl;
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//12.4 오버라이딩 (overriding 우선하다) 
//12.4.1 멤버 재정의와 정적 바인딩
//ex 12.6 부모와 자식에 이름이 같은 멤버 변수가 있는 경우
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int a = 10; // C++11 부터 허용된 문법으로, 객체가 생성될 때 a라는 멤버를 10으로 초기화하라는 뜻이다.
//};
//
//class Derived : public Base {
//public:
//	int a = 20; // 자식 클래스의 멤버가 부모 클래스의 멤버와 이름이 겹쳐도 된다!
//	// 자식 클래스인 Derived에는 Base로부터 상속받은 멤버 a와 고유의 멤버 a, 각각 두 개가 별개로 있다. 그런데, 이렇게 부모와 자식에 동명이인의 멤버가 있을 때는 자식에서 선언된 멤버가 부모에서 선언된 멤버보다 우선적으로 인식된다.
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	cout << b.a << endl;
//	cout << d.a << endl;
//	cout << b.a << endl;
//}


// 자식 클래스에서 부모 클래스의 동명이인 멤버에 접근하고 싶을 경우
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int a = 10; // C++11 부터 허용된 문법으로, 객체가 생성될 때 a라는 멤버를 10으로 초기화하라는 뜻이다.
//};
//
//class Derived : public Base {
//public:
//	int a = 20; // 자식 클래스의 멤버가 부모 클래스의 멤버와 이름이 겹쳐도 된다!
//	// 자식 클래스인 Derived에는 Base로부터 상속받은 멤버 a와 고유의 멤버 a, 각각 두 개가 별개로 있다. 그런데, 이렇게 부모와 자식에 동명이인의 멤버가 있을 때는 자식에서 선언된 멤버가 부모에서 선언된 멤버보다 우선적으로 인식된다.
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	cout << b.a << endl;
//	cout << d.Base::a << endl; // 자식 클래스에서 부모 클래스의 동명이인 멤버에 접근
//	cout << d.Derived::a << endl;
//	cout << b.a << endl;
//}


//ex12.7 부모와 자식에 이름이 같은 멤버 메서드가 있는 경우
//#include <iostream>	
//using namespace std;
//
//class Base {
//public:
//	void Print() {
//		cout << "From Base!" << endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	void Print() {
//		cout << "From Derived!" << endl;
//	}
//};
//
//int main() {
//	Derived d;
//
//	d.Print();
//	d.Base::Print();
//	d.Derived::Print();
//} // 자식 클래스에서 부모 클래스와 똑같은 이름의 멤버를 정의하는 것을 재정의(redefinition)이라 한다. 그리고 이것은 오버라이딩이 아니다.


// 정적 바인딩 (Static binding)
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	void bFunc() {
//		cout << "Base::bFunc()" << endl;
//	}
//};
//
//class Derived  : public Base {
//public:
//	void bFunc() { // 재정의
//		cout << "Derived::bFunc()" << endl;
//	}
//	void dFunc() {
//		cout << "Derived::dFunc()" << endl;
//	}
//};
//
//int main() {
//	Derived d;
//	Base* b = &d; // 부모 클래스의 포인터가 자식 클래스를 가리킬 수 있다. (부모는 자식을 포함하므로 상관관계에 따라 가능하다 생각하면 된다.)
//	// b->dFunc(); // 하지만 가리키는 자식 클래스의 멤버를 불러 올 수는 없다. 
//	
//	Derived* dd = new Derived;
//	Base* bb = dd; // dd에 들어있는 주소값이 bb에도 들어가므로, 위에서 동적 할당한(Derived* dd = new Derived;) 그 객체를 똑같이 가리키라는 뜻
//
//	bb->bFunc(); // 놀랍게도, 재정의한 메서드가 아닌 Base에 원래 정의되어 있던 메서드가 실행... 하지만 위에서 배웠듯이, bb라는 포인터를 통해 불러올 수 있는 멤버는 오로지 Base에 선언된 멤버라고 하였다. 따라서 Base에서 정의된 함수가 실행될 수 밖에 없다.
//	// 그리고 이러한 현상을 정적 바인딩(Static binding)이라 하며 "정적"은 컴파일 타임에 결정된다는 뜻, "바인딩"은 메서드 호출이 일어났을 때 여러 가능한 메서드 중 어떤 메서드를 실행할지를 결정하는 일을 뜻한다.
//	dd->bFunc();
//	dd->Derived::bFunc();
//	dd->Base::bFunc(); 
//	delete dd; // dd와 bb가 가리키고 있는 객체는 같은 객체이므로 한 번만 삭제해야 함
//}


//12.4.2 가상 함수 (Virtual function), 오버라이딩과 동적 바인딩
// 동적 바인딩 (Dynamic binding) : 컴파일이 아닌 런타임에, 즉 프로그램 실행 도중에 메서드를 바인딩하는 방법이다.
// 동적 바인딩이 없을 경우 생기는 문제 예시
//#include <iostream>
//using namespace std;
//
//class Weapon {
//public:
//	Weapon(int power) : power(power) {
//		cout << "Weapon(int)" << endl;
//	}
//	void Use() {
//		cout << "Weapon::Use()" << endl;
//	}
//
//protected:
//	int power;
//};
//
//class Sword : public Weapon {
//public:
//	Sword(int power) : Weapon(power) {
//		cout << "Sword(int)" << endl;
//	}
//	void Use() { // 재정의
//		cout << "Sword::Use()" << endl;
//		swing();
//	}
//
//private:
//	void swing() { // 이 함수에서 칼 무기를 사용했을 때 일어나는 일들을 처리
//		cout << "Swing sword!" << endl;
//	}
//};
//
//class Magic : public Weapon {
//public:
//	// Weapon(power) : 부모 클래스 생성자 호출, manaCost(manaCost) : 멤버 초기화 목록
//	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
//		cout << "Magic(int, int)" << endl;
//	}
//	void Use() { // 재정의
//		cout << "Magic::Use()" << endl;
//		cast();
//	}
//
//private:
//	void cast() { // 이 함수에서 마법 무기를 사용했을 때 일어나는 일들을 처리
//		cout << "Cast magic!" << endl;
//	}
//
//	int manaCost;
//};
//
//int main() {
//	Sword mySword(10);
//	Magic myMagic(15, 7);
//
//	mySword.Use();
//	myMagic.Use();
//
//	Weapon* currentWeapon; // 현재 무기를 가리키는 포인터
//	currentWeapon = &mySword;
//	currentWeapon->Use(); // 정적 바인딩으로 인하여, 우리가 하려는 의도와는 다르게 부모 클래스의 메서드를 호출하게 됨. => 이를 가상 함수와 동적 바인딩으로 해결 가능! 그리고 이를 오버라이딩이라 칭한다. 
//}


// 가상 함수
//ex12.8 가상 함수 사용하기
//#include <iostream>
//using namespace std;
//
//class Weapon {
//public:
//	Weapon(int power) : power(power) {
//		cout << "Weapon(int)" << endl;
//	}
//
//	virtual void Use() { // 가상 함수!! 
//		cout << "Weapon::Use()" << endl;
//	}
//
//protected:
//	int power;
//};
//
//class Sword : public Weapon {
//public:
//	Sword(int power) : Weapon(power) {
//		cout << "Sword(int)" << endl;
//	}
//
//	void Use() { // 오버라이딩 : 부모의 가상 함수를 재정의하는 것 (가상 함수의 바인딩에 대해서는 컴파일러가 신경 쓰지 않기 때문이다.)
//		cout << "Sword::Use()" << endl;
//		swing();
//	}
//
//private:
//	void swing() {
//		cout << "Swing sword!" << endl;
//	}
//};
//
//class Magic : public Weapon {
//public:
//	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
//		cout << "Magic(int, int)" << endl;
//	}
//	
//	void Use() { // 오버라이딩
//		cout << "Magic::Use()" << endl;
//		cast();
//	}
//
//private:
//	void cast() {
//		cout << "Cast magic!" << endl;
//	}
//
//	int manaCost;
//};
//
//int main() {
//	Sword mySword(10);
//	Magic myMagic(15, 11);
//
//	Weapon* currentWeapon;
//
//	currentWeapon = &mySword;
//	currentWeapon->Use(); // 가상 함수가 나오면 컴파일 시간에는 어느 메서드를 바인딩할지 결정하지 않고, 실행 도중에 그 포인터가 실제 가리키고 있는 객체의 타입을 알아내(RTTI : Run Time Type Identification/Information 을 통하여) 그 타입에서 오버라이딩된 함수가 존재한다면
//	// 바로 그 함수를 실행한다. 바인딩이 런타임에 일어났으므로 이것을 동적 바인딩이라고 부른다. 또, 자식 클래스에서 애초부터 오버라이딩을 하지 않았다면, 이런 경우에는 부모 클래스의 함수가 가상 함수라 하더라도 그냥 실행된다.
//	// 이 개념은 다형성과 관련이 있다. (Polymorphism)
//}


//12.4.3 가상 소멸자
// Bingsoo* p = new PatBingsoo; (Bingsoo는 PatBingsoo의 부모 클래스이다.)
// delete p;
// 위 코드에서 소멸자는 Bingsoo의 소멸자만 호출된다. 이유는 해제할때는 객체의 실제 타입을 정확히 알 수 없고, 정적 바인딩이 일어나기 때문이다.
// 따라서 가상 함수가 하나라도 포함된 클래스라면 거의 항상 소멸자도 가상으로 만들어야 한다.
//#include <iostream>
//using namespace std;
//
//class Bingsoo {
//public:
//	Bingsoo() { cout << "Bingsoo()" << endl; }	
//	virtual ~Bingsoo() // 가상 소멸자 만드는 방법
//	{
//		cout << "~Bingsoo()" << endl;
//	}
//};
//
//class PatBingsoo : public Bingsoo {
//public:
//	PatBingsoo() { cout << "PatBingsoo()" << endl; }
//	~PatBingsoo()
//	{
//		cout << "~PatBingsoo()" << endl;
//	}
//};
//
//int main() {
//	Bingsoo* p = new PatBingsoo;
//	delete p;
//}


//12.5 상속이 필요한 이유(2)
//ex12.9 가상 함수를 활용하여 간단하게 바꾼 메신저 예제
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "사진";
//	}
//};
//
//class Message {
//private:
//	int sendTime;
//	string sendName;
//
//public:
//	Message(int sendTime, string sendName) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//	}
//	virtual ~Message() {} // 가상 소멸자
//
//	int GetSendTime() const { return sendTime; }
//	string GetSendName() const { return sendName; }
//	virtual string GetContent() const { return ""; }
//};
//
//class TextMessage : public Message {
//public:
//	TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) {
//		this->text = text;
//	}
//
//	string GetContent() const { return text; } // 오버라이딩
//
//private:
//	string text;
//};
//
//class ImageMessage : public Message {
//public:
//	ImageMessage(int sendTime, string sendName, Image* image) : Message(sendTime, sendName) {
//		this->image = image;
//	}
//
//	string GetContent() const { return (string)*image; } // 오버라이딩
//
//private:
//	Image* image;
//};
//
//void printMessage(Message* m) {
//	cout << "보낸 시간 : " << m->GetSendTime() << endl;
//	cout << "보낸 사람 : " << m->GetSendName() << endl;
//	cout << "   내용   : " << m->GetContent() << endl; // 가상 함수이므로 동적 바인딩이 일어난다.
//
//	cout << endl;
//}
//
//int main() {
//	Image* dogImage = new Image;
//	TextMessage* hello = new TextMessage(10, "두들", "안녕");
//	ImageMessage* dog = new ImageMessage(20, "두들", dogImage);
//
//	printMessage(hello);
//	printMessage(dog);
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//ex12.9 가상 함수를 활용하여 간단하게 바꾼 메신저 예제 (call-by-reference로 바꾼 예제)
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "사진";
//	}
//};
//
//class Message {
//private:
//	int sendTime;
//	string sendName;
//
//public:
//	Message(int sendTime, string sendName) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//	}
//	virtual ~Message() {} // 가상 소멸자
//
//	int GetSendTime() const { return sendTime; }
//	string GetSendName() const { return sendName; }
//	virtual string GetContent() const { return ""; }
//};
//
//class TextMessage : public Message {
//public:
//	TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) {
//		this->text = text;
//	}
//
//	string GetContent() const { return text; } // 오버라이딩
//
//private:
//	string text;
//};
//
//class ImageMessage : public Message {
//public:
//	ImageMessage(int sendTime, string sendName, Image* image) : Message(sendTime, sendName) {
//		this->image = image;
//	}
//
//	string GetContent() const { return (string)*image; } // 오버라이딩
//
//private:
//	Image* image;
//};
//
//void printMessage(const Message& m) { // call-by-reference
//	cout << "보낸 시간 : " << m.GetSendTime() << endl;
//	cout << "보낸 사람 : " << m.GetSendName() << endl;
//	cout << "   내용   : " << m.GetContent() << endl; // 가상 함수이므로 동적 바인딩이 일어난다.
//
//	cout << endl;
//}
//
//int main() {
//	Image* dogImage = new Image;
//	TextMessage* hello = new TextMessage(10, "두들", "안녕");
//	ImageMessage* dog = new ImageMessage(20, "두들", dogImage);
//
//	printMessage(*hello);
//	printMessage(*dog);
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//ex12.10 여러 메시지 타입을 한 번에 담을 수 있는 Message "포인터 배열" 만들기
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "사진";
//	}
//};
//
//class Message {
//private:
//	int sendTime;
//	string sendName;
//
//public:
//	Message(int sendTime, string sendName) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//	}
//	virtual ~Message() {} // 가상 소멸자
//
//	int GetSendTime() const { return sendTime; }
//	string GetSendName() const { return sendName; }
//	virtual string GetContent() const { return ""; }
//};
//
//class TextMessage : public Message {
//public:
//	TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) {
//		this->text = text;
//	}
//
//	string GetContent() const { return text; } // 오버라이딩
//
//private:
//	string text;
//};
//
//class ImageMessage : public Message {
//public:
//	ImageMessage(int sendTime, string sendName, Image* image) : Message(sendTime, sendName) {
//		this->image = image;
//	}
//
//	string GetContent() const { return (string)*image; } // 오버라이딩
//
//private:
//	Image* image;
//};
//
//void printMessage(const Message& m) { // call-by-reference
//	cout << "보낸 시간 : " << m.GetSendTime() << endl;
//	cout << "보낸 사람 : " << m.GetSendName() << endl;
//	cout << "   내용   : " << m.GetContent() << endl; // 가상 함수이므로 동적 바인딩이 일어난다.
//
//	cout << endl;
//}
//
//int main() {
//	Image* dogImage = new Image;
//	Message* messages[] = { // 포인터 배열 만들기
//		new TextMessage(10, "두들", "안녕"),
//		new ImageMessage(20, "두들", dogImage),
//		new TextMessage(30, "두들", "잘가")
//	}; 
//
//	// 범위 기반 for문
//	for (Message* m : messages) {
//		printMessage(*m); // printMessage 함수가 call-by-reference 이므로 포인터를 역참조한 값을 보내줘야한다.
//	}
//
//	// 배열의 각 칸마다 동적 할당된 객체를 가리키고 있으므로 각각 해제한다.
//	for (Message* m : messages) {
//		delete m;
//	}
//
//	delete dogImage;
//}


// 위 예제 연습
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "사진을 보냈습니다.";
//	}
//};
//
//class Message {
//private:
//	int sendTime;
//	string sendName;
//	
//public:
//	Message(int sendTime, string sendName) {
//		this->sendTime = sendTime;
//		this->sendName = sendName;
//	}
//	virtual ~Message() {}
//
//	int getSendTime() const { return sendTime; }
//	string getSendName() const { return sendName; }
//	virtual string getMessage() const { return ""; }
//};
//
//class TextMessage : public Message {
//public:
//	TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName), text(text) {}
//
//	string getMessage() const { return text; }
//
//private:
//	string text;
//};
//
//class ImageMessage : public Message {
//public:
//	ImageMessage(int sendTime, string sendName, Image* imageAddress) : Message(sendTime, sendName) {
//		image = imageAddress;
//	}
//
//	string getMessage() const { return (string)*image; }
//
//private:
//	Image* image;
//};
//
//void printMessage(Message& m) {
//	cout << "보낸 시각 : " << m.getSendTime() << endl;
//	cout << "보낸 사람 : " << m.getSendName() << endl;
//	cout << "   내용   : " << m.getMessage() << endl;
//	cout << endl;
//}
//
//int main() {
//	Image* cat = new Image;
//	Message* messages[] = {
//		new TextMessage(1121, "메시", "안녕!"),
//		new ImageMessage(1242, "사비", cat),
//		new TextMessage(1806, "이니에스타", "잘가!")
//	};
//
//	for (Message* m : messages) {
//		printMessage(*m);
//	}
//
//	for (Message* m : messages) {
//		delete m;
//	}
//	delete cat;
//}

//12.6 순수 가상 함수(Pure virtual function)와 추상 클래스 (Abstract class)
// 순수 가상 함수에는 함수의 실체가 없다. (함수 본문이 없다.)
// 순수 가상 함수가 하나라도 있는 클래스를 추상 클래스라고 한다. (추상 클래스를 가지고 인스턴스(객체)를 만들 수 없다.)
// 어떤 부모 클래스가 그 자체로는 쓸모가 없고 자식 클래스들을 가리키는 용도로만 사용될 경우 추상 클래스로 만들면 유리하다.
//ex12.11
//#include <iostream>
//using namespace std;
//
//const double PI = 3.141592653589793;
//
//class Shape { // 추상 클래스 (클래스 안에 순수 가상 함수가 하나라도 있으므로)
//public:
//	virtual ~Shape() {}
//	virtual double GetArea() const = 0; // 순수 가상 함수
//	virtual void Resize(double factor) = NULL; // 순수 가상 함수 (0 or NULL을 사용하여 순수 가상 함수를 만든다.)
//};
//
//class Circle : public Shape {
//public:
//	Circle(double r) : r(r) {}
//	
//	double GetArea() const { // 오버라이딩
//		return PI * r * r;
//	}
//	void Resize(double factor) { // 오버라이딩
//		r *= factor;
//	}
//
//private:
//	double r;
//};
//
//class Rectangle : public Shape {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//
//	double GetArea() const { // 오버라이딩
//		return a * b;
//	}
//	void Resize(double factor) { // 오버라이딩
//		a *= factor;
//		b *= factor;
//	}
//private:
//	double a, b;
//};
//
//int main() {
//	// Shape를 가리키는 포인터 배열을 통해 두 종류의 도형을 배열에 한꺼번에 담을 수 있다.
//	Shape* shapes[] = {
//		new Circle(1),
//		new Rectangle(1,2)
//	};
//
//	for (Shape* s : shapes) {
//		s->Resize(2); // 각 도형을 2배씩 확대한다.
//	}
//
//	for (Shape* s : shapes) {
//		cout << s->GetArea() << endl; // 각 도형의 넓이를 출력한다.
//	}
//
//	for (Shape* s : shapes) {
//		delete s;
//	}
//}


// 위 예제 연습
//#include <iostream>
//using namespace std;
//
//const double PI = 3.14159265;
//
//class Shape {
//public:
//	virtual ~Shape() {}
//	virtual double getArea() = 0;
//	virtual void Resize(double factor) = NULL;
//};
//
//class Circle : public Shape {
//private:
//	double r;
//
//public:
//	Circle(double r) : r(r) {}
//
//	double getArea() {
//		return r * r * PI;
//	}
//	void Resize(double factor) {
//		r *= factor;
//	}
//};
//
//
//class Rectangle : public Shape {
//private:
//	double a, b;
//
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//
//	double getArea() {
//		return a * b;
//	}
//	void Resize(double factor) {
//		a *= factor;
//		b *= factor;
//	}
//};
//
//int main() {
//	Shape* shapes[] = {
//		new Circle(2),
//		new Circle(3),
//		new Rectangle(2, 3)
//	};
//
//	for (Shape* s : shapes) {
//		cout << s->getArea() << endl;
//	}
//
//	for (Shape* s : shapes) {
//		s->Resize(2.0);
//	}
//
//	for (Shape* s : shapes) {
//		cout << s->getArea() << endl;
//	}
//
//	for (Shape* s : shapes) {
//		delete s;
//	}
//}


//12.7 상속 관계에서의 형변환 
//12.7.1 업캐스팅(Upcasting) : 자식 클래스 타입에 대한 참조(포인터 또는 래퍼런스)를 부모 타입에 대한 것으로 형변환하는 것 
// ex) Base* b = new Derived; // 좌변은 Base*이고 우변은 Derived* 이므로 등호 양변의 타입이 다를 때는 기본적으로 대입 연산이 불가능 함. 하지만 에러가 나지 않는 이유는 Derived*에서 Base*로 묵시적 형변환이 일어났기 때문이다.
// 모든 업캐스팅은 묵시적으로 일어날 수 있다.

// 래퍼런스에서의 업캐스팅 예시1
// ex
// Derived d;
// Base& b = d; // 업캐스팅 발생

// 래퍼런스에서의 업캐스팅 예시2 (call-by-reference)
//void f(Base& b) {
//
//}
//int main() {
//	Derived d;
//	f(d);
//} 

// 업캐스팅이 아닌 경우 ( 컴파일 오류 발생)
//Derived d;
//Base b = d; // 에러! 이건 업캐스팅이 아니다.


//ex12.12 배열에서 업캐스팅을 잘못 이용한 사례
//#include <iostream>
//using namespace std;
//
//struct Animal { // 8바이트
//	float x = 1;
//	float y = 2;
//};
//
//struct FlyingAnimal : public Animal { // 12바이트
//	double z = 3;
//};
//
//const void printAnimals(Animal* a, int n) { // Animal* a 는 Animal a[] 와 같은 표현이다.
//	for (int i = 0; i < n; i++) {
//		cout << "(" << (a+i)->x << ", " << a[i].y << ")" << endl; // a[i] 는 *(a+i)와 같은 표현이다.
//	} // 여기서는 a가 Animal 포인터이기 때문에 a가 가리키는 주소값이 100이라면 a+1이 가리키는 주소값은 8바이트 건너뛴 108이다. 
//	// 하지만 배열에 실제로 들어 있는 객체는 12바이트짜리 FlyingAnimal 타입 객체들인데, 그 배열을 Animal* 로 받아버리는 바람에 배열 한 칸이 마치 8바이트짜리인 것처럼 잘못 인식되어버린 것이다.
//}
//
//int main() {
//	FlyingAnimal* arr = new FlyingAnimal[5];
//
//	printAnimals(arr, 5);
//	delete[] arr;
//}


//ex12.13 배열에서 업캐스팅을 제대로 사용한 사례
//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//	float x_pos = 1;
//	float y_pos = 2;
//	virtual ~Animal() {}
//};
//
//class FlyingAnimal : public Animal {
//public:
//	float z_pos = 3;
//};
//
//void printAnimals(Animal** a, int n) {
//	for (int i = 0; i < n; i++) {
//		cout << "(" << a[i]->x_pos << ", " << a[i]->y_pos << ")" << endl;
//	}
//}
//
//int main() {
//	Animal** arr = new Animal*[10]; // Animal* 타입을 10개 담을 수 있는 배열(즉, 포인터 배열)을 만들고 그 배열의 0번째 주소값을 리턴하겠다.
//	for (int i = 0; i < 10; i++) {
//		arr[i] = new FlyingAnimal;
//	}
//	printAnimals(arr, 10);
//
//	for (int i = 0; i < 10; i++) {
//		delete arr[i]; // 각 칸마다 할당된 객체가 있으므로 각 칸마다 해제한다.
//	}
//	delete[] arr; // 포인터 배열을 삭제한다.
//}


//12.7.2 다운캐스팅 (Downcasting) : 부모 클래스 타입에 대한 참조(포인터 또는 래퍼런스)를 자식 타입에 대한 것으로 형변환하는 것
// 다운 캐스팅은 묵시적으로 일어날 수 없다!
// 따라서 다운 캐스팅은 C언어에서 배운 강제 형변환(Drv1* d1 = (Drv1*)b;)을 하던지, C++에서 등장하는 static_cast 나 dynamic_cast를 해야한다.
//ex12.14 간단한 다운캐스팅
//#include <iostream>	
//using namespace std;
//
//struct Base {
//	int a = 1;
//	virtual ~Base() {}
//};
//
//struct Drv1 : Base { // 구조체는 상속 모드를 생략하면 public이 상속 모드가 된다.
//	float x = 3.14;
//};
//
//struct Drv2 : Base {
//	int y = 3;
//};
//
//int main() {
//	Base* b = new Drv1; // 업캐스팅 발생
//	//Drv1* d = (Drv1*)b; // 강제 형변환 // 다운캐스팅 발생
//	Drv1* d = static_cast<Drv1*>(b); // 다운캐스팅 발생
//	cout << d->x << endl;
//	delete b;
//}


//ex12.15 다운캐스팅을 잘못 이용한 사례
//#include <iostream>
//using namespace std;
//
//struct Base {
//	int a = 1;
//	virtual ~Base() {}
//};
//
//struct Derived1 : Base {
//	void f() {
//		cout << "Derived1::f()" << endl;
//		cout << x << endl;
//	}
//	float x = 3.14;
//};
//
//struct Derived2 : Base {
//	void f() {
//		cout << "Derived2::f()" << endl;
//		cout << y << endl;
//	}
//	int y = 3;
//};
//
//int main() {
//	Base* b = new Derived1;
//	Derived1* d1 = static_cast<Derived1*>(b); // 올바른 다운캐스팅
//	Derived2* d2 = static_cast<Derived2*>(b); // 잘못된 다운캐스팅 (하지만 컴파일러는 이 객체의 자식이 맞는지만 파악하고 맞다면 그대로 진행시킨다.)
//
//	d1->f();
//	d2->f(); // d2는 다운캐스팅으로 받은 객체를 Derived2로 해석함 -> 치명적 오류 발생
//
//	delete b;
//}


//12.7.3 RTTI와 dynamic_cast (주의! static_cast와 dynamic_cast는 형변환의 방향이 아닌 방식을 말하는 단어이다. 둘 다, 업캐스팅과 다운캐스팅이 가능하다는 것이다. 두 캐스팅을 사용할 경우에 형변환이 일어나는 방법이 다른 것이다.)
// 동적으로 프로그램 실행 도중에 캐스팅을 하겠다는 뜻! 즉, dynamic_cast에서는 런타임에 들어가서 올바른 캐스팅인지 아닌지를 직접 검사하고, 올바른 경우에만 성공적으로 캐스팅한다.
// 이 모든 검사가 런타임에 일어나기 때문에 객체의 실제 타입에 대한 정보를 얻어올 수 있다!
// dynamic_cast는 다형적 클래스(Polymorphic class)끼리만 가능하다. (다형적 클래스란 가상 소멸자 또는 가상 함수가 하나라도 있는 클래스를 말한다.)
// 다형적 클래스에서 가상 함수를 통해 동적 바인딩을 실현할 수 있는 이유는 가상 함수가 RTTI(런타임에 타입에 대한 정보를 가져올 수 있는 기능)라는 메커니즘에 의해 작동하기 때문이다.
// 중요! dynamic_cast는 캐스팅하려고 하는 타입과 실제 타입이 맞아떨어진다면 성공적으로 형변환이 되고, 아니라면 형변환의 결과로 NULL 포인터를 돌려준다.
////ex12.16 dynamic_cast를 사용해서 직사각형일 때만 대각선의 길이 출력하기
//#include <iostream>
//#include <math.h>
//using namespace std;
//
//const double PI = 3.141592;
//
//class Shape { // 다형적 클래스 
//public:
//	virtual ~Shape(){}
//	virtual double GetArea() const = 0;
//	virtual void Resize(double factor) = 0;
//};
//
//class Circle : public Shape {
//public:
//	Circle(double r) : r(r) {}
//	double GetArea() const {
//		return r * r * PI;
//	}
//	void Resize(double factor) {
//		r *= factor;
//	}
//
//private:
//	double r;
//};
//
//class Rectangle : public Shape {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//	double GetArea() const {
//		return a * b;
//	}
//	void Resize(double factor) {
//		a *= factor;
//		b *= factor;
//	}
//	double GetDiag() const {
//		return sqrt(a * a + b * b);
//	}
//
//private:
//	double a, b;
//};
//
//int main() {
//	Shape* shapes[] = {
//		new Rectangle(1,2),
//		new Circle(3),
//		new Rectangle(4,1),
//		new Rectangle(11,2)
//	};
//
//	for (int i = 0; i < 4; i++) {
//		cout << "도형의 넓이 : " << shapes[i]->GetArea() << endl;
//		Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]);
//		if (r != NULL) { // 성공적으로 형변환이 되었다면
//			cout << "대각선의 길이 : " << r->GetDiag() << endl;
//		}
//	}
//
//	for (int i = 0; i < 4; i++) {
//		delete shapes[i];
//	}
//} // 매우 유용한 기능이지만 dynamic_cast는 프로그램 성능 차원에서는 별로 좋지 않다!


// 중요! 가상 함수를 오버라이딩한 함수는 virtual을 생략하여도 가상 함수가 된다. (즉, 가상함수를 오버라이딩 한 함수도 가상함수다.)


//// 12.8 객체지향 프로그래밍의 4대 원리(원칙, 특성, 특징)
// 1. 캡슐화 (Encapsulation)
//What : 데이터(멤버 변수)와 기능(멤버 메서드)을 하나의 단위로 묶어 놓음
//	     데이터를 보이지 않게 가리고, 데이터에 접근하기 위한 메서드만을 노출 (데이터 은닉, Data hiding)
//When : 언제든!
//Why  : 클래스 사용자 : 클래스 내부 구조 이해 x, 사용법만 알면 사용 가능, 데이터를 실수로 잘못 바꾸는 것을 방지
//How  : 클래스 안에 멤버 변수, 멤버 메서드 선언 / 접근 제어
//
// 2. 상속성 (Inheritance)
//What : 부모 클래스의 멤버를 재사용해서 자식 클래스에서도 사용할 수 있음
//When : 부모 클래스에서 할 수 있는 일을 자식 클래스에서 할 수 있음 (리스코프 치환 원칙)
//       자식 클래스는 부모 클래스의 일종이다. (A is a B. (A가 B의 일종이다.))
//Why  : 코드 재사용
//How  : 상속!
//
// 3. 다형성 (Polymorphism)
//What : 동적 다형성 : 한 클래스가 그로부터 파생된 다양한 형태를 지닐 수 있음
//       정적 다형성 : 함수 오버로딩, 템플릿
//When : 자식 클래스의 메서드 구현이 부모 클래스와 다를 때
//Why  : 자식 클래스에서 하고 싶은 일들이 부모 클래스에서와 다를 수 있음
//How  : 오버라이딩, 가상 함수 (RTTI, 다형적 클래스)
//
// 4. 추상화 (Abstraction) (클래스 간 추상화)
//What : 부모 클래스 : 클래스가 구현해야 할 기능만을 명시 (순수 가상 함수)
//       자식 클래스 : 실제 구현
//When : [자식 클래스]는 [부모 클래스]할 수 있어야 한다. (A is able to B. (A는 B할 수 있다.))
//Why  : "자동차" : 운전대, 페달, 기어 변속기 (추상 클래스)
//       각 부품의 작동 원리는 자동차 종류마다 다름
//How  : 추상 클래스 (순수 가상 함수)


//12.9 객체지향 프로그래밍의 문제점
//12.9.1 다중 상속과 다이아몬드 문제
// 다중 상속 : 한 클래스가 여러 클래스로부터 상속을 받는 경우, 즉 한 클래스가 여러 부모를 두는 경우를 말한다.
//ex12.17 다중 상속 예제
//#include <iostream>
//using namespace std;
//
//struct Mom {
//	int a = 1;
//};
//
//struct Dad {
//	int b = 2;
//};
//
//struct Child : Mom, Dad { // Mom과 Dad라는 두 클래스로부터 상속
//	int c = 3;
//};
//
//int main() {
//	Child ch;
//
//	cout << ch.a << endl;
//	cout << ch.b << endl;
//	cout << ch.c << endl;
//}


// 문제가 되는 다중 상속 예시
//#include <iostream>
//using namespace std;
//
//struct Person {
//	int a;
//};
//
//struct Mom : Person {
//	Mom() {
//		a = 1;
//	}
//};
//
//struct Dad : Person {
//	Dad() {
//		a = 2;
//	}
//};
//
//struct Child : Mom, Dad { 
//	int c;
//};
//
//int main() {
//	Child ch; // ch에는 a가 2개가 있음
//	cout << ch.a << endl; // 모호한 문제가 발생
//	cout << ch.c << endl;
//}


// 위 문제를 해결하는 방법
//#include <iostream>
//using namespace std;
//
//struct Person {
//	int a;
//};
//
//struct Mom : Person {
//	Mom() {
//		a = 1;
//	}
//};
//
//struct Dad : Person {
//	Dad() {
//		a = 2;
//	}
//};
//
//struct Child : Mom, Dad {
//	int c;
//};
//
//int main() {
//	Child ch;
//
//	cout << ch.Mom::a << endl; 
//	cout << ch.Dad::a << endl;
//	cout << ch.c << endl;
//}


// 문제가 되는 다중 상속 예시 2
//#include <iostream>
//using namespace std;
//
//struct Person {
//	virtual ~Person() {}
//	
//	int age; // 나이
//	void Eat() {
//		cout << "먹는다..." << endl;
//	}
//};
//
//struct Student : Person {
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//};
//
//struct Worker : Person {
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//};
//
//struct Researcher : Student, Worker {
//
//};
//
//int main() {
//	Researcher r;
//	//r.age = 30; // 에러!!!
//	r.Student::age = 30;
//	r.Worker::age = 30; // 이 행위를 하는것도 이상함.
//
//	//r.Eat(); // 에러!!!
//	r.Student::Eat();
//	r.Worker::Eat(); // 이 행위를 하는것도 이상함.
//
//	Person* p = new Researcher;
//	p->Eat(); // 불가능!!! Person에는 Eat() 메서드가 하나만 있지만 Researcher에는 Eat() 메서드가 두개이므로...
//} // 이런 이유로 Java, C# 같은 언어에서는 다중 상속을 특수한 경우를 제외하고는 막아버렸다.


// 위와 같은 다중 상속의 문제점을 해결하는 방법 : 가상 상속! (Student, Worker 클래스의 중간 상속 단계(이들 클래스들도 Person 클래스로부터 당연히 상속을 받음)를 거치지 않고 Person 클래스로 부터 직접 상속 받아오게 하는 방법)
//ex12.18 가상 상속 사용하기 (구조체 버전)
//#include <iostream>
//using namespace std;
//
//struct Person {
//	int age; // 나이
//	virtual ~Person() {} // 다형적 클래스로 만들어주기 위한 가상 소멸자
//	void Eat() {
//		cout << "먹는다..." << endl;
//	}
//};
//
//struct Student : virtual Person { // 가상 상속
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//};
//
//struct Worker : virtual Person { // 가상 상속
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//};
//
//struct Researcher : public Student, Worker{
//
//};
//
//int main() {
//	Researcher r;
//	r.age = 20;
//
//	cout << r.age << endl;
//	cout << r.Student::age << endl;
//	cout << r.Worker::age << endl;
//	cout << r.Person::age << endl;
//
//	r.Eat();
//}


//ex12.18 가상 상속 사용하기 (클래스 버전)
//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	int age; // 나이
//	virtual ~Person() {} // 다형적 클래스로 만들어주기 위한 가상 소멸자
//	void Eat() {
//		cout << "먹는다..." << endl;
//	}
//};
//
//class Student : virtual public Person { // 가상 상속
//public:
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//};
//
//class Worker : virtual public Person { // 가상 상속
//public:
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//};
//
//class Researcher : public Student, Worker{
//public:
//};
//
//int main() {
//	Researcher r;
//	r.age = 20;
//
//	cout << r.age << endl;
//	cout << r.Student::age << endl;
//	cout << r.Worker::age << endl;
//	cout << r.Person::age << endl;
//
//	r.Eat();
//
//	Person* p = new Researcher;
//	p->age = 25;
//	cout << p->age << endl;
//	p->Eat();
//	delete p;
//}


// 가상 상속의 문제점 (Student 와 Researcher에서 모두 Eat() 함수 오버라이딩해야 하는 상황이 벌어진다면...?)
//#include <iostream>
//using namespace std;
//
//struct Person {
//	int age;
//	virtual ~Person() {}	
//	virtual void Eat() { // 가상 함수
//		cout << "먹는다..." << endl;
//	}
//};
//
//struct Student : virtual Person {
//	void Eat() { // 오버라이딩
//		cout << "냠냠..." << endl;
//	}
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//};
//
//struct Worker : virtual Person {
//	void Eat() { // 오버라이딩
//		cout << "쩝쩝..." << endl;
//	}
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//};
//
//struct Researcher : Student, Worker {
//
//}; // 상속이 불가능하다.


// 이러한 문제들을 해결하기 위해서는 다음과 같은 약속을 해야한다 : "다중 상속은 인터페이스로부터만 받는다."
// 인터페이스 (Interface) : 멤버 변수는 없고, 모든 메서드가 순수 가상 함수인 클래스를 인터페이스라 한다. (순수 가상 함수가 하나라도 존재하는 클래스를 뜻하는 추상 클래스와 혼동하지 말자.)
// 통상적으로 인터페이스는 클래스 이름앞에 I를 붙인다.
//#include <iostream>
//using namespace std;
//
//struct IPerson {
//	virtual ~IPerson() {}
//	virtual void Eat() = 0;
//};
//
//struct IStudent : virtual IPerson {
//	virtual void Study() = 0;
//};
//
//struct IWorker : virtual IPerson {
//	virtual void Work() = 0;
//};
//
//struct Researcher : IStudent, IWorker {
//	void Eat() { // 구현
//		cout << "먹는다..." << endl;
//	}
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//};
//
//int main() {
//	Researcher r;
//	r.Eat();
//	r.Study();
//	r.Work();
//
//	IPerson* p = new Researcher;
//	IStudent* s = new Researcher;
//	IWorker* w = new Researcher;
//	
//	p->Eat();
//	
//	s->Eat();
//	s->Study();
//	w->Eat();
//	w->Work();
//	
//	delete p;
//	delete s;
//	delete w;
//}


// 위 해결법의 문제점(age 변수가 인터페이스의 특성상 없는 문제점)을 해결 하는 방법
//ex12.19 인터페이스와 다중 상속
//#include <iostream>
//using namespace std;
//
//class IPerson {
//public:
//	virtual ~IPerson() {}
//	virtual void Eat() = 0;
//	virtual void SetAge(int age) = 0;
//	virtual int GetAge() = 0;
//};
//
//class IStudent : public virtual IPerson {
//public:
//	virtual void Study() = 0;
//};
//
//class IWorker : public virtual IPerson {
//public:
//	virtual void Work() = 0;
//};
//
//class Researcher : public IStudent, public IWorker {
//public:
//	void Eat() {
//		cout << "먹는다..." << endl;
//
//	}
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//	void SetAge(int age) { this->age = age; }
//	int GetAge() { return age; }
//	
//private:
//	int age;
//};
//
//int main() {
//	Researcher r;
//	r.SetAge(25);
//	cout << r.GetAge() << endl;
//
//	IPerson* p = new Researcher;
//	p->SetAge(27);
//	cout << p->GetAge() << endl;
//
//	IStudent* s = new Researcher;
//	s->SetAge(30);
//	cout << s->GetAge() << endl;
//
//	IWorker* w = new Researcher;
//	w->SetAge(33);
//	cout << w->GetAge() << endl;
//
//	delete p;
//	delete s;
//	delete w;
//} // 이와 같이 다중 상속은 겉보기에는 좋은 기능 같지만, 잘못 사용했다가는 이렇게 코드를 복잡하게 만드는 원인이 되기도 한다. 그러므로 다중 상속은 안 하는것이 최선이고, 정말 필요하다고 생각될 때도 신중히 처리해야 한다.


//12.9.2 정사각형과 직사각형 문제 (원-타원 문제라고도 한다.)
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//
//private:
//	double a, b;
//};
//
//class Square : public Rectangle {
//public:
//	Square(double a) : Rectangle(a, a) {}
//}; // 이 방법은 double이 8바이트 이므로 Square(5)와 같이 호출되었다면 Rectangle(5, 5)가 호출되니깐 double 2개를 사용하게 되고, 결국 8바이트를 낭비하게 된다.
//// 또 한, Resize 함수를 사용하게 될 경우 더 큰 문제가 발생하게 된다.

// 위 예시에서 Resize 함수를 사용할 시 발생하는 문제 
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//	void ResizeX(double factor) { a *= factor; }
//	void ResizeY(double factor) { b *= factor; }
//	double GetX() { return a; } // 이렇게 부모 클래스에서 public으로 Get 함수를 만들어 줄 경우, 상속 받은 자식 클래스에서 이 함수를 통해 부모 클래스의 private 멤버에 접근 가능하게 해준다. 
//	double GetY() { return b; }
//
//private:
//	double a, b;
//};
//
//class Square : public Rectangle {
//public:
//	Square(double a) : Rectangle(a, a) {}
//};
//
//int main() {
//	Square MySquare(4);
//	MySquare.ResizeX(2); // <- 이 함수를 사용하게 되므로서 더 이상 정사각형이 아니다!!!
//	cout << MySquare.GetX() << endl;
//	cout << MySquare.GetY() << endl;
//
//	Rectangle* r = new Square(5);
//	r->ResizeX(2);
//	r->ResizeY(3);
//	cout << r->GetX() << endl; 
//	cout << r->GetY() << endl;
//}


// 위 문제에 관한 객체지향 프로그래밍에는 어긋나지만 매우 C++적인 해결책 : 메서드 삭제 (C++11 이후부터만 가능하다.)
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//	void ResizeX(double  factor) { a *= factor; }
//	void ResizeY(double factor) { b *= factor; }
//
//private:
//	double a, b;
//};
//
//class Square : public Rectangle {
//public:
//	Square(double a) : Rectangle(a, a) {}
//	void ResizeX(double factor) = delete; // 함수 삭제! (C++11 이후)
//	void ResizeY(double factor) = delete; // 함수 삭제! (C++11 이후)
//	void ResizeXY(double factor) {
//		Rectangle::ResizeX(factor); // X축 길이 변환
//		Rectangle::ResizeY(factor); // Y축 길이 변환
//	}
//};
//
//int main() {
//	Square mySquare(5);
//	//mySquare.ResizeX(2); // 에러!
//	mySquare.ResizeXY(2); // OK
//
//	// 하지만 다형성을 사용하면 이러한 함수 삭제를 무색하게 해버린다.
//	Rectangle* r = new Square(5);
//	r->ResizeX(2); // 가능!!! 결국 이는 완벽한 해결책이 못 됨
//}


// 또 다른 해결책 : 두 클래스를 Immutable(불변)으로 고쳐주기 
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//	Rectangle ResizeX(double factor) const { return Rectangle(factor * a, b); } // 클래스가 Immutable로 변경 불가이므로 함수를 통하여 새로운 Rectangle 객체를 만들어주고 반환한다. 
//	Rectangle ResizeY(double factor) const { return Rectangle(a, factor * b); }
//private:
//	const double a, b; // 클래스를 Immutable로 만들어 주는 것!
//};
//
//class Square : public Rectangle {
//public:
//	Square(double a) : Rectangle(a, a) {}
//};
//
//int main() {
//	Square mySquare(5);
//	Rectangle resized = mySquare.ResizeX(3); // mySquare는 변하지 않는다!
//}


//// 또 다른 해결책 : 상식을 부정하고 상속 관계를 거꾸로 만들어버리기
//#include <iostream>
//using namespace std;
//
//class Square {
//public:
//	Square(double a) : a(a) {}
//
//private:
//	double a;
//};
//
//class Rectangle : public Square {
//public:
//	Rectangle(double a, double b) : Square(a), b(b) {}
//	
//private: 
//	double b;
//}; // 이 해결책은 그럴싸해 보이지만, is-a 관계를 위반하기 때문에 클래스를 사용하는 사람 입장에서는 논리적으로 헛갈릴 수 있으므로 그리 현명한 선택은 아니다.
// 이 외에도 다양한 해결책이 제시되었지만 깔끔하게 해결할 수 있는 방법은 존재하지 않는다. 그냥 객체지향 프로그래밍의 한계로 받아들이고, 상황에 맞게 그나마 깔끔한 방식을 골라 설계하는 것이 최선이다.


// 종합문제
// 1번
//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	virtual int f() { return x; }
//	virtual ~A() {}
//private:
//	int x = 10;
//};
//
//class B : public A {
//public:
//	int f() { return x; } // virtual int f() { return x; } 와 같은 표현이 된다.
//	virtual int g() { return A::f(); }
//private:
//	int x = 20;
//};
//
//class C : public B {
//public:
//	int f() { return x; }
//	int g() { return B::f(); }
//	virtual int h() { return B::g(); }
//private:
//	int x = 30;
//};
//
//int main() {
//	A* a = new B; // 변수 a의 실제 타입은 A*이므로 형변환 없이는 A클래스에는 없지만 B 클래스에 있는 멤버에 접근 불가하다.
//	A* b = new C;
//	B* c = new C;
//	C* d = new C;
//
//	cout << a->f() << endl;
//	cout << static_cast<B*>(a)->g() << endl; // 다운캐스팅 필요 (어떤 타입을 가리키는지 명확히 알 수 있으므로 dynamic_cast를 써도 되지만 느리다.)
//	cout << b->f() << endl;
//	if (C* t = dynamic_cast<C*>(b)) { // 다운 캐스팅 필요
//		cout << t->g() << endl;
//	}
//	cout << c->f() << endl;
//	cout << c->g() << endl;
//	cout << d->g() << endl;
//	cout << d->h() << endl;
//
//	delete a;
//	delete b;
//	delete c;
//	delete d;
//}


// 2번 (dynamic_cast를 사용하지 않고 사각형일 경우 대각선의 길이도 출력해라)
//#include <iostream>
//#include <string>
//#include <math.h>
//using namespace std;
//
//const double PI = 3.14159265;
//
//class Shape {
//public:
//	virtual ~Shape() {}
//
//	virtual double GetArea() const = NULL;
//	virtual void Resize(double factor) = 0;
//	virtual string GetInfo() const {
//		return "도형의 넓이 : " + to_string(GetArea());
//	}
//};
//
//class Circle : public Shape {
//private:
//	double r;
//
//public:
//	Circle(double r) : r(r) {}
//	
//	double GetArea() const {
//		return r * r * PI;
//	}
//	void Resize(double factor) {
//		r *= factor;
//	}
//};
//
//class Rectangle : public Shape {
//private:
//	double a, b;
//
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//
//	double GetArea() const {
//		return a * b;
//	}
//	void Resize(double factor) {
//		a *= factor;
//		b *= factor;
//	}
//	double GetDiag() const {
//		return sqrt(a * a + b * b);
//	}
//	string GetInfo() const {
//		return Shape::GetInfo() + "\n대각선의 길이 : " + to_string(GetDiag());
//	}
//};
//
//int main() {
//	Shape* shapes[] = {
//		new Circle(1),
//		new Rectangle(1,1),
//		new Rectangle(2,3),
//		new Circle(2)
//	};
//
//	for (Shape* s : shapes) {
//		cout << s->GetInfo() << endl;
//	}
//
//	for (Shape* s : shapes) {
//		delete s;
//	}
//}


// 3번 (상속과 가상 함수를 사용해 중복되는 코드를 줄여보라.)
// 제시된 원래 코드
//#include <iostream>
//#include <stdio.h>
//#include <string>
//using namespace std;
//
//enum LogLevels {
//	DEBUG,
//	INFO,
//	WARNING,
//	ERROR,
//	FATAL
//};
//
//const char* const LEVEL_HEADINGS[] = {
//	"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
//};
//
//class FileLogger {
//public:
//	FileLogger(int minLevel, const string& fileName) : minLevel(minLevel) {
//		logFile = fopen(fileName.c_str(), "a");
//	}
//	~FileLogger()
//	{
//		fclose(logFile);
//	}
//	
//	void Log(const string& s, int level) {
//		if (level >= minLevel)
//			fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
//	}
//	int GetMinLevel() const { return minLevel; }
//
//private:
//	int minLevel;
//	FILE* logFile;
//};
//
//class ConsoleLogger {
//public:
//	ConsoleLogger(int minLevel) : minLevel(minLevel) {}
//
//	void Log(const string& s, int level) {
//		if (level >= minLevel)
//			printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
//	}
//	int GetMinLevel() const { return minLevel; }
//
//private:
//	int minLevel;
//};
//
//int main() {
//	ConsoleLogger c(LogLevels::WARNING);
//	c.Log("abc", LogLevels::ERROR);
//	c.Log("def", LogLevels::INFO);
//	c.Log("ghi", LogLevels::WARNING);
//
//	FileLogger f(LogLevels::DEBUG, "log.txt");
//	f.Log("abc", LogLevels::ERROR);
//	f.Log("def", LogLevels::INFO);
//	f.Log("ghi", LogLevels::WARNING);
//}

// 정답
//#include <iostream>
//#include <stdio.h>	
//#include <string>
//using namespace std;
//
//enum LogLevels {
//	DEBUG,
//	INFO,
//	WARNING,
//	ERROR,
//	FATAL
//};
//
//const char* const LEVEL_HEADINGS[] = {
//	"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
//};
//
//class Logger {
//public:
//	Logger(int minLevel) : minLevel(minLevel) {}
//	virtual ~Logger() {}
//
//	void Log(const string& s, int level) {
//		if (level >= minLevel) doLogJob(s, level);
//	}
//	int GetMinLevel() const { return minLevel; }
//
//protected:
//	virtual void doLogJob(const string& s, int level) = 0;
//
//private:
//	int minLevel;
//};
//
//class FileLogger : public Logger {
//public:
//	FileLogger(int minLevel, const string& fileName) : Logger(minLevel) {
//		logFile = fopen(fileName.c_str(), "a");
//	}
//	~FileLogger() {
//		fclose(logFile);
//	}
//
//protected:
//	void doLogJob(const string& s, int level) {
//		fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
//	}
//
//private:
//	FILE* logFile;
//};
//
//class ConsoleLogger : public Logger {
//public:
//	ConsoleLogger(int minLevel) : Logger(minLevel) {}
//
//protected:
//	void doLogJob(const string& s, int level) {
//		printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
//	}
//};
//
//int main() {
//	ConsoleLogger c(LogLevels::WARNING);
//	c.Log("abc", LogLevels::ERROR);
//	c.Log("def", LogLevels::INFO);
//	c.Log("ghi", LogLevels::WARNING);
//
//	FileLogger f(LogLevels::DEBUG, "log.txt");
//	f.Log("abc", LogLevels::ERROR);
//	f.Log("def", LogLevels::INFO);
//	f.Log("ghi", LogLevels::WARNING);
//}


// 문제 3-1
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

enum LogLevels {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	FATAL
};

const char* const LEVEL_HEADINGS[] = {
	"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
};

class Logger {
public:
	Logger(int minLevel) : minLevel(minLevel){}
	virtual ~Logger() {}

	void Log(const string& s, int level) {
		if (level >= minLevel) doLogJob(s, level);
	}
	int GetMinLevel() const { return minLevel; }

protected:
	int minLevel;

	virtual void doLogJob(const string& s, int level) = 0;
};

class FileLogger : public Logger {
public:
	FileLogger(int minLevel, const string& fileName) : Logger(minLevel) {
		logFile = fopen(fileName.c_str(), "a");
	}
	~FileLogger()
	{
		fclose(logFile);
	}

protected:
	void doLogJob(const string& s, int level) {
		fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
	}

private:
	FILE* logFile;
};

class ConsoleLogger : public Logger {
public:
	ConsoleLogger(int minLevel) : Logger(minLevel) {}

protected:
	void doLogJob(const string& s, int level) {
		printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
	}
};

void testLogger(Logger& logger) {
	logger.Log("abc", LogLevels::ERROR);
	logger.Log("def", LogLevels::INFO);
	logger.Log("ghi", LogLevels::WARNING);

}

int main() {
	ConsoleLogger c(LogLevels::WARNING);
	testLogger(c);

	FileLogger f(LogLevels::DEBUG, "log.txt");
	testLogger(f);
}