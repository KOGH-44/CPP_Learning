// ���


// 12.1 ��� ����
// 12.1.1 ����� ����
// �ڽ� Ŭ������ �θ� Ŭ������ ���ԵǸ�, �θ� Ŭ������ ����� �ڽ� Ŭ������ ����� ���Եȴ�.
// �θ� Ŭ������ parent class, base class, superclass ��� �θ���, �ڽ� Ŭ������ child class, derived class, subclass ��� �θ���.
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


// 12.1.2 ��Ӱ� ���� ����
// ���� ������ / Ŭ���� �ܺο��� ���� / �ڽ� Ŭ�������� ���� / Ŭ���� ���ο��� ����
// public	  /     ����            /       ����         /        ����
// protected  /     �Ұ���          /       ����         /        ����
// private    /     �Ұ���          /       �Ұ���       /        ����
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
//		bProtected = 2; // OK. �θ� Ŭ������ protected ������� ���� ����
//		bPrivate = 3; // ����! �θ� Ŭ������ private ������� ���� �Ұ�
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // ����! protected ������� Ŭ���� �ܺο��� ���� �Ұ�
//	b.bPrivate = 13; // ����! private ������� �翬�� ���� �Ұ�
//}


// ��� ��� 
// ex (��� ��尡 public �� ���)
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
//		bProtected = 2; // OK. �θ� Ŭ������ protected ������� ���� ����
//		bPrivate = 3; // ����! �θ� Ŭ������ private ������� ���� �Ұ�
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // ����! protected ����� Ŭ���� �ܺο��� ���� �Ұ�
//	b.bPrivate = 13; // ����! private ������� �翬�� ���� �Ұ�
//	
//	d.bPublic = 111; 
//	d.bProtected = 112;
//	d.bPrivate = 113;
//}


// ex (��� ��尡 protected �� ���)
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
//		bProtected = 2; // OK. �θ� Ŭ������ protected ������� ���� ����
//		bPrivate = 3; // ����! �θ� Ŭ������ private ������� ���� �Ұ�
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // ����! protected ����� Ŭ���� �ܺο��� ���� �Ұ�
//	b.bPrivate = 13; // ����! private ������� �翬�� ���� �Ұ�
//
//	d.bPublic = 111; // ����! Base�� public ����� Derived���� protected ���!!
//	d.bProtected = 112; // ����! Base�� protected ����� Derived������ protected ���.
//	d.bPrivate = 113; // ����! ���ʺ��� Base�� private �����.
//}


// ex (��� ��尡 private �� ���)
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
//		bPrivate = 3; // ����! �θ� Ŭ������ private ������� ���� �Ұ�
//	}
//};
//
//class DerivedDerived : private Derived { // Base�� ���� Ŭ���� 
//public:
//	void DDFunc() {
//		bPublic = 1; // ����! �θ� Ŭ����(Derived)�� private ������� ���� �Ұ�
//		bProtected = 2; // ����! �θ� Ŭ������ private ������� ���� �Ұ�
//		bPrivate = 3; // ����! �θ� Ŭ������ private ������� ���� �Ұ�
//	}
//};
//
//int main() {
//	Base b;
//	Derived d;
//	DerivedDerived dd;
//
//	b.bPublic = 11; // OK.
//	b.bProtected = 12; // ����! protected ����� Ŭ���� �ܺο��� ���� �Ұ�
//	b.bPrivate = 13; // ����! private ������� �翬�� ���� �Ұ�
//
//	d.bPublic = 111; // ����! Base�� public ����� Derived���� private ���!!
//	d.bProtected = 112; // ����! Base�� protected ����� Derived���� private ���!!
//	d.bPrivate = 113; // ����! ���ʺ��� Base�� private �����.
//
//	dd.bPublic = 1111; // ����! ���ʺ��� Derived�� private �����.
//	dd.bProtected = 1112; // ����! ���ʺ��� Derived�� private �����.
//	dd.bPrivate = 1113; // ����! ���ʺ��� Derived�� private �����.
//}


//12.1.3 ��� ����
//ex12.1 Animal, Dog, Sparrow Ŭ���� ��� ����
//#include <iostream>	
//using namespace std;
//class Animal {
//public:
//	void Breathe() { cout << "���� ����." << endl; }	
//	int age;
//};
//
//class Dog : public Animal {
//public:
//	void Walk() { cout << "�ȴ´�." << endl; }	
//};
//
//class Sparrow : public Animal {
//public:
//	void Fly() { cout << "����." << endl; }
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


//12.2 ��� ���迡���� ����/�Ҹ���
//ex12.2 ������ ��� ���迡���� ������ ȣ��
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
//	Derived d; // Derived �����ڿ��� Ư���� ����� ���� ������ Base�� �⺻ �����ڰ� �ڵ����� ȣ���� �ȴ�.
//	// �׷��� ���� Base�� �⺻ �����ڰ� ���ٸ�(��, Base�� �����ڰ� �ϳ� �̻� ����Ǿ��µ� �� �� �Ű������� ���� �ʴ� �����ڰ� ���� ���...) ������ ������ �߻��Ѵ�.
//}

// �⺻ �����ڰ� ��� ������ ������ �߻��ϴ� ����
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
//	Derived() { // �׷��� ���� Base�� �⺻ �����ڰ� ���ٸ�(��, Base�� �����ڰ� �ϳ� �̻� ����Ǿ��µ� �� �� �Ű������� ���� �ʴ� �����ڰ� ���� ���...) ������ ������ �߻��Ѵ�.
//		cout << "Derived()" << endl;
//	}
//};

// �� ���� �ذ� ���
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
//	Derived() : Base(0) { // �ذ� ��� : ������ ���� Base�� ��� �����ڸ� ȣ�������� ���������Ѵ�.
//		cout << "Derived()" << endl;
//	}
//};
//
//int main() {
//	Base b(1);
//	Derived d;
//}


//ex12.3 ������/�Ҹ����� ���� ���� Ȯ���ϱ�
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
// �������� ȣ�� ����
// 1. �θ� Ŭ������ �����ڸ� ���� ȣ���Ѵ�.
// 2. Ŭ������ ��� ��� ������ �����ȴ�. (��, ��� �������� �����ڰ� ȣ��ȴ�.)
// 3. �������� ������ ����ȴ�.

// �Ҹ����� ȣ�� ����
// 1. �Ҹ����� ������ ����ȴ�.
// 2. Ŭ������ ��� ��� ������ �Ҹ�ȴ�. (��, ��� �������� �Ҹ��ڰ� ȣ��ȴ�.)
// 3. �θ� Ŭ������ �Ҹ��ڸ� �������� ȣ���Ѵ�.


//12.3 ����� �ʿ��� ����(1)
//ex12.4 TextMessage�� ImageMessage Ŭ���� �����
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "����";
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
//	Image* dogImage = new Image; // Image ��ü�� �̸� ����� �д�.
//	TextMessage* hello = new TextMessage(10, "�ε�", "�ȳ�"); 
//	// ����� �� ��ü�� �����͸� �������� �μ��� ���� �ִ´�.
//	ImageMessage* dog = new ImageMessage(30, "�ε�", dogImage);
//
//	cout << "���� �ð� : " << hello->GetSendTime() << endl;
//	cout << "���� ��� : " << hello->GetSendName() << endl;
//	cout << "  ����    : " << hello->GetText() << endl;
//	cout << endl;
//
//	cout << "���� �ð� : " << dog->GetSendTime() << endl;
//	cout << "���� ��� : " << dog->GetSendName() << endl;
//	cout << "  ����    : " << (string)*dog->GetImage() << endl; // ->, *, (string) ������ �����ڰ� ���ȴ�.
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//ex12.5 ����� ����� ���ĺ� �޽��� ����
//#include <iostream>	
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "����";
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
//private: // �ڽ� Ŭ���������� �� �����鿡 ������ ���� ����.
//	int sendTime;
//	string sendName;
//};
//
//class TextMessage : public Message {
//public:
//	TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) // �θ� Ŭ���� ������ ȣ��
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
//	ImageMessage(int sendTime, string sendName, Image* image) : Message(sendTime, sendName) // �θ� Ŭ���� ������ ȣ��
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
//	TextMessage* hello = new TextMessage(10, "�ε�", "�ȳ�");
//	ImageMessage* dog = new ImageMessage(20, "�ε�", dogImage);
//
//	cout << "���� �ð� : " << hello->GetSendTime() << endl;
//	cout << "���� ��� : " << hello->GetSendName() << endl;
//	cout << "   ����   : " << hello->GetText() << endl;
//	cout << endl;
//
//	cout << "���� �ð� : " << dog->GetSendTime() << endl;
//	cout << "���� ��� : " << dog->GetSendName() << endl;
//	cout << "   ����   : " << (string)*dog->GetImage() << endl;
//	cout << endl;
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//12.4 �������̵� (overriding �켱�ϴ�) 
//12.4.1 ��� �����ǿ� ���� ���ε�
//ex 12.6 �θ�� �ڽĿ� �̸��� ���� ��� ������ �ִ� ���
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int a = 10; // C++11 ���� ���� ��������, ��ü�� ������ �� a��� ����� 10���� �ʱ�ȭ�϶�� ���̴�.
//};
//
//class Derived : public Base {
//public:
//	int a = 20; // �ڽ� Ŭ������ ����� �θ� Ŭ������ ����� �̸��� ���ĵ� �ȴ�!
//	// �ڽ� Ŭ������ Derived���� Base�κ��� ��ӹ��� ��� a�� ������ ��� a, ���� �� ���� ������ �ִ�. �׷���, �̷��� �θ�� �ڽĿ� ���������� ����� ���� ���� �ڽĿ��� ����� ����� �θ𿡼� ����� ������� �켱������ �νĵȴ�.
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


// �ڽ� Ŭ�������� �θ� Ŭ������ �������� ����� �����ϰ� ���� ���
//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	int a = 10; // C++11 ���� ���� ��������, ��ü�� ������ �� a��� ����� 10���� �ʱ�ȭ�϶�� ���̴�.
//};
//
//class Derived : public Base {
//public:
//	int a = 20; // �ڽ� Ŭ������ ����� �θ� Ŭ������ ����� �̸��� ���ĵ� �ȴ�!
//	// �ڽ� Ŭ������ Derived���� Base�κ��� ��ӹ��� ��� a�� ������ ��� a, ���� �� ���� ������ �ִ�. �׷���, �̷��� �θ�� �ڽĿ� ���������� ����� ���� ���� �ڽĿ��� ����� ����� �θ𿡼� ����� ������� �켱������ �νĵȴ�.
//};
//
//int main() {
//	Base b;
//	Derived d;
//
//	cout << b.a << endl;
//	cout << d.Base::a << endl; // �ڽ� Ŭ�������� �θ� Ŭ������ �������� ����� ����
//	cout << d.Derived::a << endl;
//	cout << b.a << endl;
//}


//ex12.7 �θ�� �ڽĿ� �̸��� ���� ��� �޼��尡 �ִ� ���
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
//} // �ڽ� Ŭ�������� �θ� Ŭ������ �Ȱ��� �̸��� ����� �����ϴ� ���� ������(redefinition)�̶� �Ѵ�. �׸��� �̰��� �������̵��� �ƴϴ�.


// ���� ���ε� (Static binding)
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
//	void bFunc() { // ������
//		cout << "Derived::bFunc()" << endl;
//	}
//	void dFunc() {
//		cout << "Derived::dFunc()" << endl;
//	}
//};
//
//int main() {
//	Derived d;
//	Base* b = &d; // �θ� Ŭ������ �����Ͱ� �ڽ� Ŭ������ ����ų �� �ִ�. (�θ�� �ڽ��� �����ϹǷ� ������迡 ���� �����ϴ� �����ϸ� �ȴ�.)
//	// b->dFunc(); // ������ ����Ű�� �ڽ� Ŭ������ ����� �ҷ� �� ���� ����. 
//	
//	Derived* dd = new Derived;
//	Base* bb = dd; // dd�� ����ִ� �ּҰ��� bb���� ���Ƿ�, ������ ���� �Ҵ���(Derived* dd = new Derived;) �� ��ü�� �Ȱ��� ����Ű��� ��
//
//	bb->bFunc(); // ����Ե�, �������� �޼��尡 �ƴ� Base�� ���� ���ǵǾ� �ִ� �޼��尡 ����... ������ ������ �������, bb��� �����͸� ���� �ҷ��� �� �ִ� ����� ������ Base�� ����� ������ �Ͽ���. ���� Base���� ���ǵ� �Լ��� ����� �� �ۿ� ����.
//	// �׸��� �̷��� ������ ���� ���ε�(Static binding)�̶� �ϸ� "����"�� ������ Ÿ�ӿ� �����ȴٴ� ��, "���ε�"�� �޼��� ȣ���� �Ͼ�� �� ���� ������ �޼��� �� � �޼��带 ���������� �����ϴ� ���� ���Ѵ�.
//	dd->bFunc();
//	dd->Derived::bFunc();
//	dd->Base::bFunc(); 
//	delete dd; // dd�� bb�� ����Ű�� �ִ� ��ü�� ���� ��ü�̹Ƿ� �� ���� �����ؾ� ��
//}


//12.4.2 ���� �Լ� (Virtual function), �������̵��� ���� ���ε�
// ���� ���ε� (Dynamic binding) : �������� �ƴ� ��Ÿ�ӿ�, �� ���α׷� ���� ���߿� �޼��带 ���ε��ϴ� ����̴�.
// ���� ���ε��� ���� ��� ����� ���� ����
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
//	void Use() { // ������
//		cout << "Sword::Use()" << endl;
//		swing();
//	}
//
//private:
//	void swing() { // �� �Լ����� Į ���⸦ ������� �� �Ͼ�� �ϵ��� ó��
//		cout << "Swing sword!" << endl;
//	}
//};
//
//class Magic : public Weapon {
//public:
//	// Weapon(power) : �θ� Ŭ���� ������ ȣ��, manaCost(manaCost) : ��� �ʱ�ȭ ���
//	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
//		cout << "Magic(int, int)" << endl;
//	}
//	void Use() { // ������
//		cout << "Magic::Use()" << endl;
//		cast();
//	}
//
//private:
//	void cast() { // �� �Լ����� ���� ���⸦ ������� �� �Ͼ�� �ϵ��� ó��
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
//	Weapon* currentWeapon; // ���� ���⸦ ����Ű�� ������
//	currentWeapon = &mySword;
//	currentWeapon->Use(); // ���� ���ε����� ���Ͽ�, �츮�� �Ϸ��� �ǵ��ʹ� �ٸ��� �θ� Ŭ������ �޼��带 ȣ���ϰ� ��. => �̸� ���� �Լ��� ���� ���ε����� �ذ� ����! �׸��� �̸� �������̵��̶� Ī�Ѵ�. 
//}


// ���� �Լ�
//ex12.8 ���� �Լ� ����ϱ�
//#include <iostream>
//using namespace std;
//
//class Weapon {
//public:
//	Weapon(int power) : power(power) {
//		cout << "Weapon(int)" << endl;
//	}
//
//	virtual void Use() { // ���� �Լ�!! 
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
//	void Use() { // �������̵� : �θ��� ���� �Լ��� �������ϴ� �� (���� �Լ��� ���ε��� ���ؼ��� �����Ϸ��� �Ű� ���� �ʱ� �����̴�.)
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
//	void Use() { // �������̵�
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
//	currentWeapon->Use(); // ���� �Լ��� ������ ������ �ð����� ��� �޼��带 ���ε����� �������� �ʰ�, ���� ���߿� �� �����Ͱ� ���� ����Ű�� �ִ� ��ü�� Ÿ���� �˾Ƴ�(RTTI : Run Time Type Identification/Information �� ���Ͽ�) �� Ÿ�Կ��� �������̵��� �Լ��� �����Ѵٸ�
//	// �ٷ� �� �Լ��� �����Ѵ�. ���ε��� ��Ÿ�ӿ� �Ͼ���Ƿ� �̰��� ���� ���ε��̶�� �θ���. ��, �ڽ� Ŭ�������� ���ʺ��� �������̵��� ���� �ʾҴٸ�, �̷� ��쿡�� �θ� Ŭ������ �Լ��� ���� �Լ��� �ϴ��� �׳� ����ȴ�.
//	// �� ������ �������� ������ �ִ�. (Polymorphism)
//}


//12.4.3 ���� �Ҹ���
// Bingsoo* p = new PatBingsoo; (Bingsoo�� PatBingsoo�� �θ� Ŭ�����̴�.)
// delete p;
// �� �ڵ忡�� �Ҹ��ڴ� Bingsoo�� �Ҹ��ڸ� ȣ��ȴ�. ������ �����Ҷ��� ��ü�� ���� Ÿ���� ��Ȯ�� �� �� ����, ���� ���ε��� �Ͼ�� �����̴�.
// ���� ���� �Լ��� �ϳ��� ���Ե� Ŭ������� ���� �׻� �Ҹ��ڵ� �������� ������ �Ѵ�.
//#include <iostream>
//using namespace std;
//
//class Bingsoo {
//public:
//	Bingsoo() { cout << "Bingsoo()" << endl; }	
//	virtual ~Bingsoo() // ���� �Ҹ��� ����� ���
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


//12.5 ����� �ʿ��� ����(2)
//ex12.9 ���� �Լ��� Ȱ���Ͽ� �����ϰ� �ٲ� �޽��� ����
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "����";
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
//	virtual ~Message() {} // ���� �Ҹ���
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
//	string GetContent() const { return text; } // �������̵�
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
//	string GetContent() const { return (string)*image; } // �������̵�
//
//private:
//	Image* image;
//};
//
//void printMessage(Message* m) {
//	cout << "���� �ð� : " << m->GetSendTime() << endl;
//	cout << "���� ��� : " << m->GetSendName() << endl;
//	cout << "   ����   : " << m->GetContent() << endl; // ���� �Լ��̹Ƿ� ���� ���ε��� �Ͼ��.
//
//	cout << endl;
//}
//
//int main() {
//	Image* dogImage = new Image;
//	TextMessage* hello = new TextMessage(10, "�ε�", "�ȳ�");
//	ImageMessage* dog = new ImageMessage(20, "�ε�", dogImage);
//
//	printMessage(hello);
//	printMessage(dog);
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//ex12.9 ���� �Լ��� Ȱ���Ͽ� �����ϰ� �ٲ� �޽��� ���� (call-by-reference�� �ٲ� ����)
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "����";
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
//	virtual ~Message() {} // ���� �Ҹ���
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
//	string GetContent() const { return text; } // �������̵�
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
//	string GetContent() const { return (string)*image; } // �������̵�
//
//private:
//	Image* image;
//};
//
//void printMessage(const Message& m) { // call-by-reference
//	cout << "���� �ð� : " << m.GetSendTime() << endl;
//	cout << "���� ��� : " << m.GetSendName() << endl;
//	cout << "   ����   : " << m.GetContent() << endl; // ���� �Լ��̹Ƿ� ���� ���ε��� �Ͼ��.
//
//	cout << endl;
//}
//
//int main() {
//	Image* dogImage = new Image;
//	TextMessage* hello = new TextMessage(10, "�ε�", "�ȳ�");
//	ImageMessage* dog = new ImageMessage(20, "�ε�", dogImage);
//
//	printMessage(*hello);
//	printMessage(*dog);
//
//	delete dogImage;
//	delete hello;
//	delete dog;
//}


//ex12.10 ���� �޽��� Ÿ���� �� ���� ���� �� �ִ� Message "������ �迭" �����
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "����";
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
//	virtual ~Message() {} // ���� �Ҹ���
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
//	string GetContent() const { return text; } // �������̵�
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
//	string GetContent() const { return (string)*image; } // �������̵�
//
//private:
//	Image* image;
//};
//
//void printMessage(const Message& m) { // call-by-reference
//	cout << "���� �ð� : " << m.GetSendTime() << endl;
//	cout << "���� ��� : " << m.GetSendName() << endl;
//	cout << "   ����   : " << m.GetContent() << endl; // ���� �Լ��̹Ƿ� ���� ���ε��� �Ͼ��.
//
//	cout << endl;
//}
//
//int main() {
//	Image* dogImage = new Image;
//	Message* messages[] = { // ������ �迭 �����
//		new TextMessage(10, "�ε�", "�ȳ�"),
//		new ImageMessage(20, "�ε�", dogImage),
//		new TextMessage(30, "�ε�", "�߰�")
//	}; 
//
//	// ���� ��� for��
//	for (Message* m : messages) {
//		printMessage(*m); // printMessage �Լ��� call-by-reference �̹Ƿ� �����͸� �������� ���� ��������Ѵ�.
//	}
//
//	// �迭�� �� ĭ���� ���� �Ҵ�� ��ü�� ����Ű�� �����Ƿ� ���� �����Ѵ�.
//	for (Message* m : messages) {
//		delete m;
//	}
//
//	delete dogImage;
//}


// �� ���� ����
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Image {
//public:
//	operator string() {
//		return "������ ���½��ϴ�.";
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
//	cout << "���� �ð� : " << m.getSendTime() << endl;
//	cout << "���� ��� : " << m.getSendName() << endl;
//	cout << "   ����   : " << m.getMessage() << endl;
//	cout << endl;
//}
//
//int main() {
//	Image* cat = new Image;
//	Message* messages[] = {
//		new TextMessage(1121, "�޽�", "�ȳ�!"),
//		new ImageMessage(1242, "���", cat),
//		new TextMessage(1806, "�̴Ͽ���Ÿ", "�߰�!")
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

//12.6 ���� ���� �Լ�(Pure virtual function)�� �߻� Ŭ���� (Abstract class)
// ���� ���� �Լ����� �Լ��� ��ü�� ����. (�Լ� ������ ����.)
// ���� ���� �Լ��� �ϳ��� �ִ� Ŭ������ �߻� Ŭ������� �Ѵ�. (�߻� Ŭ������ ������ �ν��Ͻ�(��ü)�� ���� �� ����.)
// � �θ� Ŭ������ �� ��ü�δ� ���� ���� �ڽ� Ŭ�������� ����Ű�� �뵵�θ� ���� ��� �߻� Ŭ������ ����� �����ϴ�.
//ex12.11
//#include <iostream>
//using namespace std;
//
//const double PI = 3.141592653589793;
//
//class Shape { // �߻� Ŭ���� (Ŭ���� �ȿ� ���� ���� �Լ��� �ϳ��� �����Ƿ�)
//public:
//	virtual ~Shape() {}
//	virtual double GetArea() const = 0; // ���� ���� �Լ�
//	virtual void Resize(double factor) = NULL; // ���� ���� �Լ� (0 or NULL�� ����Ͽ� ���� ���� �Լ��� �����.)
//};
//
//class Circle : public Shape {
//public:
//	Circle(double r) : r(r) {}
//	
//	double GetArea() const { // �������̵�
//		return PI * r * r;
//	}
//	void Resize(double factor) { // �������̵�
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
//	double GetArea() const { // �������̵�
//		return a * b;
//	}
//	void Resize(double factor) { // �������̵�
//		a *= factor;
//		b *= factor;
//	}
//private:
//	double a, b;
//};
//
//int main() {
//	// Shape�� ����Ű�� ������ �迭�� ���� �� ������ ������ �迭�� �Ѳ����� ���� �� �ִ�.
//	Shape* shapes[] = {
//		new Circle(1),
//		new Rectangle(1,2)
//	};
//
//	for (Shape* s : shapes) {
//		s->Resize(2); // �� ������ 2�辿 Ȯ���Ѵ�.
//	}
//
//	for (Shape* s : shapes) {
//		cout << s->GetArea() << endl; // �� ������ ���̸� ����Ѵ�.
//	}
//
//	for (Shape* s : shapes) {
//		delete s;
//	}
//}


// �� ���� ����
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


//12.7 ��� ���迡���� ����ȯ 
//12.7.1 ��ĳ����(Upcasting) : �ڽ� Ŭ���� Ÿ�Կ� ���� ����(������ �Ǵ� ���۷���)�� �θ� Ÿ�Կ� ���� ������ ����ȯ�ϴ� �� 
// ex) Base* b = new Derived; // �º��� Base*�̰� �캯�� Derived* �̹Ƿ� ��ȣ �纯�� Ÿ���� �ٸ� ���� �⺻������ ���� ������ �Ұ��� ��. ������ ������ ���� �ʴ� ������ Derived*���� Base*�� ������ ����ȯ�� �Ͼ�� �����̴�.
// ��� ��ĳ������ ���������� �Ͼ �� �ִ�.

// ���۷��������� ��ĳ���� ����1
// ex
// Derived d;
// Base& b = d; // ��ĳ���� �߻�

// ���۷��������� ��ĳ���� ����2 (call-by-reference)
//void f(Base& b) {
//
//}
//int main() {
//	Derived d;
//	f(d);
//} 

// ��ĳ������ �ƴ� ��� ( ������ ���� �߻�)
//Derived d;
//Base b = d; // ����! �̰� ��ĳ������ �ƴϴ�.


//ex12.12 �迭���� ��ĳ������ �߸� �̿��� ���
//#include <iostream>
//using namespace std;
//
//struct Animal { // 8����Ʈ
//	float x = 1;
//	float y = 2;
//};
//
//struct FlyingAnimal : public Animal { // 12����Ʈ
//	double z = 3;
//};
//
//const void printAnimals(Animal* a, int n) { // Animal* a �� Animal a[] �� ���� ǥ���̴�.
//	for (int i = 0; i < n; i++) {
//		cout << "(" << (a+i)->x << ", " << a[i].y << ")" << endl; // a[i] �� *(a+i)�� ���� ǥ���̴�.
//	} // ���⼭�� a�� Animal �������̱� ������ a�� ����Ű�� �ּҰ��� 100�̶�� a+1�� ����Ű�� �ּҰ��� 8����Ʈ �ǳʶ� 108�̴�. 
//	// ������ �迭�� ������ ��� �ִ� ��ü�� 12����Ʈ¥�� FlyingAnimal Ÿ�� ��ü���ε�, �� �迭�� Animal* �� �޾ƹ����� �ٶ��� �迭 �� ĭ�� ��ġ 8����Ʈ¥���� ��ó�� �߸� �νĵǾ���� ���̴�.
//}
//
//int main() {
//	FlyingAnimal* arr = new FlyingAnimal[5];
//
//	printAnimals(arr, 5);
//	delete[] arr;
//}


//ex12.13 �迭���� ��ĳ������ ����� ����� ���
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
//	Animal** arr = new Animal*[10]; // Animal* Ÿ���� 10�� ���� �� �ִ� �迭(��, ������ �迭)�� ����� �� �迭�� 0��° �ּҰ��� �����ϰڴ�.
//	for (int i = 0; i < 10; i++) {
//		arr[i] = new FlyingAnimal;
//	}
//	printAnimals(arr, 10);
//
//	for (int i = 0; i < 10; i++) {
//		delete arr[i]; // �� ĭ���� �Ҵ�� ��ü�� �����Ƿ� �� ĭ���� �����Ѵ�.
//	}
//	delete[] arr; // ������ �迭�� �����Ѵ�.
//}


//12.7.2 �ٿ�ĳ���� (Downcasting) : �θ� Ŭ���� Ÿ�Կ� ���� ����(������ �Ǵ� ���۷���)�� �ڽ� Ÿ�Կ� ���� ������ ����ȯ�ϴ� ��
// �ٿ� ĳ������ ���������� �Ͼ �� ����!
// ���� �ٿ� ĳ������ C���� ��� ���� ����ȯ(Drv1* d1 = (Drv1*)b;)�� �ϴ���, C++���� �����ϴ� static_cast �� dynamic_cast�� �ؾ��Ѵ�.
//ex12.14 ������ �ٿ�ĳ����
//#include <iostream>	
//using namespace std;
//
//struct Base {
//	int a = 1;
//	virtual ~Base() {}
//};
//
//struct Drv1 : Base { // ����ü�� ��� ��带 �����ϸ� public�� ��� ��尡 �ȴ�.
//	float x = 3.14;
//};
//
//struct Drv2 : Base {
//	int y = 3;
//};
//
//int main() {
//	Base* b = new Drv1; // ��ĳ���� �߻�
//	//Drv1* d = (Drv1*)b; // ���� ����ȯ // �ٿ�ĳ���� �߻�
//	Drv1* d = static_cast<Drv1*>(b); // �ٿ�ĳ���� �߻�
//	cout << d->x << endl;
//	delete b;
//}


//ex12.15 �ٿ�ĳ������ �߸� �̿��� ���
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
//	Derived1* d1 = static_cast<Derived1*>(b); // �ùٸ� �ٿ�ĳ����
//	Derived2* d2 = static_cast<Derived2*>(b); // �߸��� �ٿ�ĳ���� (������ �����Ϸ��� �� ��ü�� �ڽ��� �´����� �ľ��ϰ� �´ٸ� �״�� �����Ų��.)
//
//	d1->f();
//	d2->f(); // d2�� �ٿ�ĳ�������� ���� ��ü�� Derived2�� �ؼ��� -> ġ���� ���� �߻�
//
//	delete b;
//}


//12.7.3 RTTI�� dynamic_cast (����! static_cast�� dynamic_cast�� ����ȯ�� ������ �ƴ� ����� ���ϴ� �ܾ��̴�. �� ��, ��ĳ���ð� �ٿ�ĳ������ �����ϴٴ� ���̴�. �� ĳ������ ����� ��쿡 ����ȯ�� �Ͼ�� ����� �ٸ� ���̴�.)
// �������� ���α׷� ���� ���߿� ĳ������ �ϰڴٴ� ��! ��, dynamic_cast������ ��Ÿ�ӿ� ���� �ùٸ� ĳ�������� �ƴ����� ���� �˻��ϰ�, �ùٸ� ��쿡�� ���������� ĳ�����Ѵ�.
// �� ��� �˻簡 ��Ÿ�ӿ� �Ͼ�� ������ ��ü�� ���� Ÿ�Կ� ���� ������ ���� �� �ִ�!
// dynamic_cast�� ������ Ŭ����(Polymorphic class)������ �����ϴ�. (������ Ŭ������ ���� �Ҹ��� �Ǵ� ���� �Լ��� �ϳ��� �ִ� Ŭ������ ���Ѵ�.)
// ������ Ŭ�������� ���� �Լ��� ���� ���� ���ε��� ������ �� �ִ� ������ ���� �Լ��� RTTI(��Ÿ�ӿ� Ÿ�Կ� ���� ������ ������ �� �ִ� ���)��� ��Ŀ���� ���� �۵��ϱ� �����̴�.
// �߿�! dynamic_cast�� ĳ�����Ϸ��� �ϴ� Ÿ�԰� ���� Ÿ���� �¾ƶ������ٸ� ���������� ����ȯ�� �ǰ�, �ƴ϶�� ����ȯ�� ����� NULL �����͸� �����ش�.
////ex12.16 dynamic_cast�� ����ؼ� ���簢���� ���� �밢���� ���� ����ϱ�
//#include <iostream>
//#include <math.h>
//using namespace std;
//
//const double PI = 3.141592;
//
//class Shape { // ������ Ŭ���� 
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
//		cout << "������ ���� : " << shapes[i]->GetArea() << endl;
//		Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]);
//		if (r != NULL) { // ���������� ����ȯ�� �Ǿ��ٸ�
//			cout << "�밢���� ���� : " << r->GetDiag() << endl;
//		}
//	}
//
//	for (int i = 0; i < 4; i++) {
//		delete shapes[i];
//	}
//} // �ſ� ������ ��������� dynamic_cast�� ���α׷� ���� ���������� ���� ���� �ʴ�!


// �߿�! ���� �Լ��� �������̵��� �Լ��� virtual�� �����Ͽ��� ���� �Լ��� �ȴ�. (��, �����Լ��� �������̵� �� �Լ��� �����Լ���.)


//// 12.8 ��ü���� ���α׷����� 4�� ����(��Ģ, Ư��, Ư¡)
// 1. ĸ��ȭ (Encapsulation)
//What : ������(��� ����)�� ���(��� �޼���)�� �ϳ��� ������ ���� ����
//	     �����͸� ������ �ʰ� ������, �����Ϳ� �����ϱ� ���� �޼��常�� ���� (������ ����, Data hiding)
//When : ������!
//Why  : Ŭ���� ����� : Ŭ���� ���� ���� ���� x, ������ �˸� ��� ����, �����͸� �Ǽ��� �߸� �ٲٴ� ���� ����
//How  : Ŭ���� �ȿ� ��� ����, ��� �޼��� ���� / ���� ����
//
// 2. ��Ӽ� (Inheritance)
//What : �θ� Ŭ������ ����� �����ؼ� �ڽ� Ŭ���������� ����� �� ����
//When : �θ� Ŭ�������� �� �� �ִ� ���� �ڽ� Ŭ�������� �� �� ���� (�������� ġȯ ��Ģ)
//       �ڽ� Ŭ������ �θ� Ŭ������ �����̴�. (A is a B. (A�� B�� �����̴�.))
//Why  : �ڵ� ����
//How  : ���!
//
// 3. ������ (Polymorphism)
//What : ���� ������ : �� Ŭ������ �׷κ��� �Ļ��� �پ��� ���¸� ���� �� ����
//       ���� ������ : �Լ� �����ε�, ���ø�
//When : �ڽ� Ŭ������ �޼��� ������ �θ� Ŭ������ �ٸ� ��
//Why  : �ڽ� Ŭ�������� �ϰ� ���� �ϵ��� �θ� Ŭ���������� �ٸ� �� ����
//How  : �������̵�, ���� �Լ� (RTTI, ������ Ŭ����)
//
// 4. �߻�ȭ (Abstraction) (Ŭ���� �� �߻�ȭ)
//What : �θ� Ŭ���� : Ŭ������ �����ؾ� �� ��ɸ��� ��� (���� ���� �Լ�)
//       �ڽ� Ŭ���� : ���� ����
//When : [�ڽ� Ŭ����]�� [�θ� Ŭ����]�� �� �־�� �Ѵ�. (A is able to B. (A�� B�� �� �ִ�.))
//Why  : "�ڵ���" : ������, ���, ��� ���ӱ� (�߻� Ŭ����)
//       �� ��ǰ�� �۵� ������ �ڵ��� �������� �ٸ�
//How  : �߻� Ŭ���� (���� ���� �Լ�)


//12.9 ��ü���� ���α׷����� ������
//12.9.1 ���� ��Ӱ� ���̾Ƹ�� ����
// ���� ��� : �� Ŭ������ ���� Ŭ�����κ��� ����� �޴� ���, �� �� Ŭ������ ���� �θ� �δ� ��츦 ���Ѵ�.
//ex12.17 ���� ��� ����
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
//struct Child : Mom, Dad { // Mom�� Dad��� �� Ŭ�����κ��� ���
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


// ������ �Ǵ� ���� ��� ����
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
//	Child ch; // ch���� a�� 2���� ����
//	cout << ch.a << endl; // ��ȣ�� ������ �߻�
//	cout << ch.c << endl;
//}


// �� ������ �ذ��ϴ� ���
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


// ������ �Ǵ� ���� ��� ���� 2
//#include <iostream>
//using namespace std;
//
//struct Person {
//	virtual ~Person() {}
//	
//	int age; // ����
//	void Eat() {
//		cout << "�Դ´�..." << endl;
//	}
//};
//
//struct Student : Person {
//	void Study() {
//		cout << "�����Ѵ�..." << endl;
//	}
//};
//
//struct Worker : Person {
//	void Work() {
//		cout << "���Ѵ�..." << endl;
//	}
//};
//
//struct Researcher : Student, Worker {
//
//};
//
//int main() {
//	Researcher r;
//	//r.age = 30; // ����!!!
//	r.Student::age = 30;
//	r.Worker::age = 30; // �� ������ �ϴ°͵� �̻���.
//
//	//r.Eat(); // ����!!!
//	r.Student::Eat();
//	r.Worker::Eat(); // �� ������ �ϴ°͵� �̻���.
//
//	Person* p = new Researcher;
//	p->Eat(); // �Ұ���!!! Person���� Eat() �޼��尡 �ϳ��� ������ Researcher���� Eat() �޼��尡 �ΰ��̹Ƿ�...
//} // �̷� ������ Java, C# ���� ������ ���� ����� Ư���� ��츦 �����ϰ�� ���ƹ��ȴ�.


// ���� ���� ���� ����� �������� �ذ��ϴ� ��� : ���� ���! (Student, Worker Ŭ������ �߰� ��� �ܰ�(�̵� Ŭ�����鵵 Person Ŭ�����κ��� �翬�� ����� ����)�� ��ġ�� �ʰ� Person Ŭ������ ���� ���� ��� �޾ƿ��� �ϴ� ���)
//ex12.18 ���� ��� ����ϱ� (����ü ����)
//#include <iostream>
//using namespace std;
//
//struct Person {
//	int age; // ����
//	virtual ~Person() {} // ������ Ŭ������ ������ֱ� ���� ���� �Ҹ���
//	void Eat() {
//		cout << "�Դ´�..." << endl;
//	}
//};
//
//struct Student : virtual Person { // ���� ���
//	void Study() {
//		cout << "�����Ѵ�..." << endl;
//	}
//};
//
//struct Worker : virtual Person { // ���� ���
//	void Work() {
//		cout << "���Ѵ�..." << endl;
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


//ex12.18 ���� ��� ����ϱ� (Ŭ���� ����)
//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	int age; // ����
//	virtual ~Person() {} // ������ Ŭ������ ������ֱ� ���� ���� �Ҹ���
//	void Eat() {
//		cout << "�Դ´�..." << endl;
//	}
//};
//
//class Student : virtual public Person { // ���� ���
//public:
//	void Study() {
//		cout << "�����Ѵ�..." << endl;
//	}
//};
//
//class Worker : virtual public Person { // ���� ���
//public:
//	void Work() {
//		cout << "���Ѵ�..." << endl;
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


// ���� ����� ������ (Student �� Researcher���� ��� Eat() �Լ� �������̵��ؾ� �ϴ� ��Ȳ�� �������ٸ�...?)
//#include <iostream>
//using namespace std;
//
//struct Person {
//	int age;
//	virtual ~Person() {}	
//	virtual void Eat() { // ���� �Լ�
//		cout << "�Դ´�..." << endl;
//	}
//};
//
//struct Student : virtual Person {
//	void Eat() { // �������̵�
//		cout << "�ȳ�..." << endl;
//	}
//	void Study() {
//		cout << "�����Ѵ�..." << endl;
//	}
//};
//
//struct Worker : virtual Person {
//	void Eat() { // �������̵�
//		cout << "����..." << endl;
//	}
//	void Work() {
//		cout << "���Ѵ�..." << endl;
//	}
//};
//
//struct Researcher : Student, Worker {
//
//}; // ����� �Ұ����ϴ�.


// �̷��� �������� �ذ��ϱ� ���ؼ��� ������ ���� ����� �ؾ��Ѵ� : "���� ����� �������̽��κ��͸� �޴´�."
// �������̽� (Interface) : ��� ������ ����, ��� �޼��尡 ���� ���� �Լ��� Ŭ������ �������̽��� �Ѵ�. (���� ���� �Լ��� �ϳ��� �����ϴ� Ŭ������ ���ϴ� �߻� Ŭ������ ȥ������ ����.)
// ��������� �������̽��� Ŭ���� �̸��տ� I�� ���δ�.
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
//	void Eat() { // ����
//		cout << "�Դ´�..." << endl;
//	}
//	void Study() {
//		cout << "�����Ѵ�..." << endl;
//	}
//	void Work() {
//		cout << "���Ѵ�..." << endl;
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


// �� �ذ���� ������(age ������ �������̽��� Ư���� ���� ������)�� �ذ� �ϴ� ���
//ex12.19 �������̽��� ���� ���
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
//		cout << "�Դ´�..." << endl;
//
//	}
//	void Study() {
//		cout << "�����Ѵ�..." << endl;
//	}
//	void Work() {
//		cout << "���Ѵ�..." << endl;
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
//} // �̿� ���� ���� ����� �Ѻ��⿡�� ���� ��� ������, �߸� ����ߴٰ��� �̷��� �ڵ带 �����ϰ� ����� ������ �Ǳ⵵ �Ѵ�. �׷��Ƿ� ���� ����� �� �ϴ°��� �ּ��̰�, ���� �ʿ��ϴٰ� ������ ���� ������ ó���ؾ� �Ѵ�.


//12.9.2 ���簢���� ���簢�� ���� (��-Ÿ�� ������� �Ѵ�.)
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
//}; // �� ����� double�� 8����Ʈ �̹Ƿ� Square(5)�� ���� ȣ��Ǿ��ٸ� Rectangle(5, 5)�� ȣ��Ǵϱ� double 2���� ����ϰ� �ǰ�, �ᱹ 8����Ʈ�� �����ϰ� �ȴ�.
//// �� ��, Resize �Լ��� ����ϰ� �� ��� �� ū ������ �߻��ϰ� �ȴ�.

// �� ���ÿ��� Resize �Լ��� ����� �� �߻��ϴ� ���� 
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//	void ResizeX(double factor) { a *= factor; }
//	void ResizeY(double factor) { b *= factor; }
//	double GetX() { return a; } // �̷��� �θ� Ŭ�������� public���� Get �Լ��� ����� �� ���, ��� ���� �ڽ� Ŭ�������� �� �Լ��� ���� �θ� Ŭ������ private ����� ���� �����ϰ� ���ش�. 
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
//	MySquare.ResizeX(2); // <- �� �Լ��� ����ϰ� �ǹǷμ� �� �̻� ���簢���� �ƴϴ�!!!
//	cout << MySquare.GetX() << endl;
//	cout << MySquare.GetY() << endl;
//
//	Rectangle* r = new Square(5);
//	r->ResizeX(2);
//	r->ResizeY(3);
//	cout << r->GetX() << endl; 
//	cout << r->GetY() << endl;
//}


// �� ������ ���� ��ü���� ���α׷��ֿ��� ��߳����� �ſ� C++���� �ذ�å : �޼��� ���� (C++11 ���ĺ��͸� �����ϴ�.)
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
//	void ResizeX(double factor) = delete; // �Լ� ����! (C++11 ����)
//	void ResizeY(double factor) = delete; // �Լ� ����! (C++11 ����)
//	void ResizeXY(double factor) {
//		Rectangle::ResizeX(factor); // X�� ���� ��ȯ
//		Rectangle::ResizeY(factor); // Y�� ���� ��ȯ
//	}
//};
//
//int main() {
//	Square mySquare(5);
//	//mySquare.ResizeX(2); // ����!
//	mySquare.ResizeXY(2); // OK
//
//	// ������ �������� ����ϸ� �̷��� �Լ� ������ �����ϰ� �ع�����.
//	Rectangle* r = new Square(5);
//	r->ResizeX(2); // ����!!! �ᱹ �̴� �Ϻ��� �ذ�å�� �� ��
//}


// �� �ٸ� �ذ�å : �� Ŭ������ Immutable(�Һ�)���� �����ֱ� 
//#include <iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(double a, double b) : a(a), b(b) {}
//	Rectangle ResizeX(double factor) const { return Rectangle(factor * a, b); } // Ŭ������ Immutable�� ���� �Ұ��̹Ƿ� �Լ��� ���Ͽ� ���ο� Rectangle ��ü�� ������ְ� ��ȯ�Ѵ�. 
//	Rectangle ResizeY(double factor) const { return Rectangle(a, factor * b); }
//private:
//	const double a, b; // Ŭ������ Immutable�� ����� �ִ� ��!
//};
//
//class Square : public Rectangle {
//public:
//	Square(double a) : Rectangle(a, a) {}
//};
//
//int main() {
//	Square mySquare(5);
//	Rectangle resized = mySquare.ResizeX(3); // mySquare�� ������ �ʴ´�!
//}


//// �� �ٸ� �ذ�å : ����� �����ϰ� ��� ���踦 �Ųٷ� ����������
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
//}; // �� �ذ�å�� �׷����� ��������, is-a ���踦 �����ϱ� ������ Ŭ������ ����ϴ� ��� ���忡���� �������� �갥�� �� �����Ƿ� �׸� ������ ������ �ƴϴ�.
// �� �ܿ��� �پ��� �ذ�å�� ���õǾ����� ����ϰ� �ذ��� �� �ִ� ����� �������� �ʴ´�. �׳� ��ü���� ���α׷����� �Ѱ�� �޾Ƶ��̰�, ��Ȳ�� �°� �׳��� ����� ����� ��� �����ϴ� ���� �ּ��̴�.


// ���չ���
// 1��
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
//	int f() { return x; } // virtual int f() { return x; } �� ���� ǥ���� �ȴ�.
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
//	A* a = new B; // ���� a�� ���� Ÿ���� A*�̹Ƿ� ����ȯ ���̴� AŬ�������� ������ B Ŭ������ �ִ� ����� ���� �Ұ��ϴ�.
//	A* b = new C;
//	B* c = new C;
//	C* d = new C;
//
//	cout << a->f() << endl;
//	cout << static_cast<B*>(a)->g() << endl; // �ٿ�ĳ���� �ʿ� (� Ÿ���� ����Ű���� ��Ȯ�� �� �� �����Ƿ� dynamic_cast�� �ᵵ ������ ������.)
//	cout << b->f() << endl;
//	if (C* t = dynamic_cast<C*>(b)) { // �ٿ� ĳ���� �ʿ�
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


// 2�� (dynamic_cast�� ������� �ʰ� �簢���� ��� �밢���� ���̵� ����ض�)
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
//		return "������ ���� : " + to_string(GetArea());
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
//		return Shape::GetInfo() + "\n�밢���� ���� : " + to_string(GetDiag());
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


// 3�� (��Ӱ� ���� �Լ��� ����� �ߺ��Ǵ� �ڵ带 �ٿ�����.)
// ���õ� ���� �ڵ�
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

// ����
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


// ���� 3-1
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