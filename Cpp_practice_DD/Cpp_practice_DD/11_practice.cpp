// 11 동적 할당과 객체 복사
// 11.1 동적 할당
// 11.1.1 변수 동적 할당하기
// ex11.1 메모리를 동적 할당 및 해제해보기
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a = new int(5);
//
//	cout << a << endl;
//	cout << *a << endl;
//	*a = 10;
//	cout << a << endl;
//	cout << *a << endl;
//
//	delete a;
//}


// 11.1.2 배열 동적 할당하기
// ex
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cout << "배열의 칸 수를 입력하시오 : ";
//	cin >> n;
//
//	// int* arr = new int[n];
//	int* arr = new int[n] {33, 33, 33}; // 동적 할당과 동시에 초기화 방법
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << endl;
//	}
//	delete[] arr;
//}


// 11.1.3 객체 동적 할당하기 (new 키워드 뒤에 객체의 생성자를 호출하면 된다.) (객체의 생성자는 new에서 실행되고, 소멸자는 delete에서 실행된다.)
// ex11.2 객체 동적 할당하기
//#include <iostream>
//using namespace std;
//
//class Vector2 {
//private:
//	float x, y;
//
//public:
//	Vector2() : x(0), y(0) {
//		cout << this << " : Vector2()" << endl;
//	}
//	Vector2(float x, float y) : x(x), y(y) {
//		cout << this << " : Vector2(float, float)" << endl;
//	}
//	~Vector2() {
//		cout << this << " : ~Vector2()" << endl;
//	}
//
//	float GetX() const { return x; }
//	float GetY() const { return y; }
//};
//
//int main() {
//	cout << "메인 시작" << endl;
//
//	// 정적 할당된 객체
//	Vector2 s1;
//	Vector2 s2(2, 3);
//
//	// 동적 할당된 객체
//	Vector2* d1 = new Vector2; // 생성자 실행
//	Vector2* d2 = new Vector2(4, 5);
//
//	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
//	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;
//
//	delete d1; // 소멸자 실행
//	delete d2; 
//
//	cout << "메인 끝!" << endl;
//}


// 11.2 깊은 복사(deep copy)와 얕은 복사(shallow copy)
// 얕은 복사(shallow copy)
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a = new int(3);
//	// int* b = a;
//	int* b;
//	b = a; // 참조만 복사되었다. // 실제 int를 담는 공간과 그 공간에 들어있는 값이 복사된 것이 아니라 주소값만 복사되었다. 
//	*a = 5;
//	cout << *a << endl;
//	cout << *b << endl;
//	delete a;
//	// delete b; // 메모리를 두 번 해제해서는 안된다.
//}


// 깊은 복사(deep copy)
// ex
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a = new int(3);
//	int* b = new int(*a); // b는 a가 가리키는 공간이 아닌 새로 만들어진 int 공간을 가리키고 있고, 그 공간에 단순히 a 공간에 들어있는 값이 복사된 것
//	*a = 5;
//	cout << *a << endl;
//	cout << *b << endl;
//	delete a;
//	delete b; // 이것은 깊은 복사이기 때문에 a와 b가 가리키는 메모리의 주소값이 서로 다르므로 둘을 다 해제시켜줘야한다.
//}


// 깊은 복사와 얕은 복사가 동시에 일어나는 상황
// ex
//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	A(int x, int *y) : x(x), y(y){}
//	int x;
//	int* y;
//};
//
//int main() {
//	A a(1, new int(2));
//	A b = a; // a에 있는 모든 멤버가 복사된다. 이 때, 멤버가 일반 변수든 포인터든 상관없이 거기 들어 있는 값이 그냥 복사되는 것이다. (첫번째 매개변수는 깊은 복사, 두번째 매개변수는 얕은 복사)
//	a.x = 3; 
//	*(a).y = 4; // *a.y = 4; 와 같은 표현이다. 
//	cout << b.x << endl;
//	cout << *(b).y << endl;
//	delete a.y;
//	// delete b.y; // A b =a; 과정에서 b의 멤버 변수 y에 a의 멤버 변수 y가 그대로 복사되었으므로(얕은 복사), 이 둘이 가리키는 주소값은 같다. 
//	// 따라서 메모리를 두 번 해제하려 하는 행위가 되는것이다.
//}


// 11.3 복사 생성자와 복사 대입 연산자
// 11.3.1 String 클래스 만들기
// ex11.3 String 클래스 만들어보기
//#include <iostream>
//#include <string.h> 
//using namespace std;
//
//class String {
//private:
//	char* strData;
//	int len;
//
//public:
//	String() {
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) {
//		len = strlen(str);
//		strData = new char[len + 1]; // NULL 문자가 추가되어야 하기때문에...
//		strcpy(strData, str); // 깊은 복사를 하기 위해...
//	}
//	~String()
//	{
//		if (strData) {
//			delete[] strData;
//		}
//	}
//
//	 const char* GetStrData() const { // const char*가 아닌 char*를 리턴타입으로 설정하면 빈 문자열을 리턴할때 오류가 발생할 수 있다.
//		if (strData) return strData;
//		return ""; // 빈 문자열 리턴
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//int main() {
//	String s1;
//	String s2("Hello Welcome!");
//
//	cout << s1.GetLen() << endl;
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetLen() << endl;
//	cout << s2.GetStrData() << endl;
//}


// 11.3.2 복사 생성자 오버로딩 (copy constructor overloading)
//#include <iostream>
//#include <string.h> 
//using namespace std;
//
//class String {
//private:
//	char* strData;
//	int len;
//
//public:
//	String() {
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) {
//		len = strlen(str);
//		strData = new char[len + 1]; // NULL 문자가 추가되어야 하기때문에...
//		strcpy(strData, str);
//	}
//	~String()
//	{
//		if (strData) {
//			delete[] strData;
//		}
//	}
//
//	const char* GetStrData() const { // const char*가 아닌 char*를 리턴타입으로 설정하면 빈 문자열을 리턴할때 오류가 발생할 수 있다.
//		if (strData) return strData;
//		return ""; // 빈 문자열 리턴
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//int main() {
//	String s1("Hello");
//	String s2 = s1; // 객체를 복사하면 객체의 멤버중에 포인터가 있을 경우 얕은 복사가 일어난다. (그리고 이와 같은 행위를 할때 복사 생성자가 실행된다.)
//	// String s2(s1); // 그리고 이와 같은 행위를 할때 복사 생성자가 실행된다. (객체를 선언하는 동시에 어떤 다른 객체의 값으로 초기화하는 경우 <= 복사 생성)
//	// 복사 생성자를 특별히 만들어 놓지 않은 상태에서 복사 생성을 할 경우, 얕은 복사가 일어난다. // 실행시 런타임 오류가 나는 이유는 얕은 복사로 인하여 메모리 해제를 두 번 하였기 때문이다.
//	// 복사 생성자 정의 방법 : String(String &rhs) {} 
//	cout << s1.GetLen() << endl;
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetLen() << endl;
//	cout << s2.GetStrData() << endl;
//}


// ex11.4 String 클래스에 복사 생성자 추가하기
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class String {
//private:
//	char* strData;
//	int len;
//
//public:
//	String() {
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) {
//		len = strlen(str);
//		strData = new char[len + 1];
//		strcpy(strData, str); // 깊은 복사
//	}
//	String(const String& rhs) { // 복사 생성자 정의, 매개변수로는 String에 대한 래퍼런스를 받는다.
//		len = rhs.len;
//		strData = new char[len + 1];
//		strcpy(strData, rhs.strData); // 깊은 복사
//	}
//	~String()
//	{
//		if (strData != NULL) {
//			delete[] strData;
//		}
//	}
//
//
//	const char* GetStrData() const {
//		if (strData != NULL)  return strData;
//		return "";
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//int main() {
//	String s1("Hello");
//	String s2 = s1; // String s2(s1); 과 같은 말. 복사 생성자가 호출된다.
//
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetStrData() << endl;
//} // 에러가 발생하지 않는다. 각 복사 생성자의 정의에 따라, 각 객체에서 메모리를 각자 할당하고, 각자 할당한 메모리를 각자 해제했기 떄문이다.


// 11.3.3 복사 대입 연산자 오버로딩 (copy assignment operator overloading (String& operator=(const String& rhs)) (전역 함수가 아니라, 클래스 안에 정의해야한다.)
// ex11.5 String 클래스에 복사 대입 연산자 추가하기
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class String {
//private:
//	char* strData;
//	int len;
//
//public:
//	String() {
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) {
//		len = strlen(str);
//		strData = new char[len + 1];
//		strcpy(strData, str);
//	}
//	String(const String& rhs) { 
//		len = rhs.len;
//		strData = new char[len + 1];
//		strcpy(strData, rhs.strData); 
//	}
//	String& operator=(const String& rhs) { // 복사 대입 연산자 오버로딩 (생성자는 생성할때 딱 한번 일어난다)
//		if (this != &rhs) { // 본인이 본인에게 대입한 경우를 처리하기 위하여
//			delete[] strData; // 기존에 있던 String 객체의 strData를 지워주지 않으면 메모리 누수(memory leak)이 발생한다.
//			len = rhs.len;
//			strData = new char[len + 1];
//			strcpy(strData, rhs.strData);
//		}
//		return *this; // 대입 연산자는 리턴값이 있다. (다중 대입의 경우를 위하여)
//	}
//
//	const char* GetStrData() const {
//		if (strData)return strData;
//		return "";
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//
//int main() {
//	String s1("Hello world");
//	String s2 = s1; // 복사 생성자 실행 String s2(s1); 과 같은 표현이므로 복사 생성자가 실행된다.
//	String s3;
//	String s4("Hi"); 
//	s3 = s1; // 복사 대입 연산자 실행
//	s4 = s1; // 복사 대입 연산자 실행
//	s4 = s4; // 복사 대입 연산자 실행
//	String s5;
//	String s6;
//	s6 = s5 = s4; // 복사 대입 연산자 실행
//
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetStrData() << endl;
//	cout << s3.GetStrData() << endl;
//	cout << s4.GetStrData() << endl;
//}


// 11.4 이동 시맨틱(move semantic) : 복사 이후에 바로 사라지는 객체에 대해서는 의도적으로 얕은 복사를 해 데이터를 복사하지 않고 "이동"만 시키도록 하는 문법
// ex11.6 이동 생성자와 이동 대입 연산자를 구현하지 않았을 때의 작동
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class String {
//public:
//	String() {
//		cout << "String() : " << this << endl;
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) {
//		cout << "String(const char*) : " << this << endl;
//		len = strlen(str);
//		alloc(len);
//		strcpy(strData, str);
//	}
//	String(const String& rhs) {
//		cout << "String(const String&) : " << this << endl;
//		len = rhs.len;
//		alloc(len);
//		strcpy(strData, rhs.strData);
//	}
//	~String()
//	{
//		cout << "~String() : " << this << endl;
//		release();
//		strData = NULL;
//	}
//
//	String& operator=(const String& rhs) {
//		cout << "String& operator=(const String&) : " << this << endl;
//		if (this != &rhs) {
//			release();
//			len = rhs.len;
//			alloc(len);
//			strcpy(strData, rhs.strData);
//		}
//		return *this;
//	}
//
//	char* GetStrData() const {
//		return strData;
//	}
//	int GetLen() const {
//		return len;
//	}
//
//private:
//	char * strData;
//	int len;
//
//	void alloc(int len) {
//		strData = new char[len + 1];
//		cout << "strData 할당됨 : " << (void*)strData << endl; // (void*)로 형태에는 관심 없이 주소값만 보겠다는 뜻
//	}
//	void release() {
//		if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
//		delete[] strData;
//	}
//};
//
//String GetName() {
//	cout << "===== 2 =====" << endl;
//	String res("Doodle");
//	cout << "===== 3 =====" << endl;
//	return res;
//}
//
//int main() {
//	String a;
//	cout << "===== 1 =====" << endl;
//	a = GetName();
//	cout << "===== 4 =====" << endl;
//}


// 11.5.2 이동 생성자 및 이동 대입 연산자 오버로딩 (이동 시맨틱 구현)
// 객체가 리턴되는 순간에 원래는 복사 생성자/복사 대입 연산자가 호출되던 것이 이동 생성자/이동 대입 연산자를 정의해놓으면 이동 생성자와 이동 대입 연산자가 호출되도록 바뀐다.
// 이동 생성자가 해야하는 역할은 얕은 복사이다!
// 이동 대입 연산자 오버로딩의 경우 복사 대입 연산자 오버로딩과는 다르게, 자기 자신에 대입하는 경우는 절대 벌어지지 않는다. (이동이 일어나고 있다는 것은 우변이 대입 연산 이후에 사라진다는 뜻이므로...)
// ex11.7 이동 생성자와 이동 대입 연산자 구현하기
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class String {
//private:
//	char* strData;
//	int len;
//
//	void alloc(int len) {
//		strData = new char[len + 1];
//		cout << "strData 할당됨 : " << (void*)strData << endl;
//	}
//	void release() {
//		if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
//		delete[] strData;
//	}
//
//public:
//	String() { // 매개변수가 없을 때의 생성자
//		cout << "String() : " << this << endl;
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) { // 매개변수가 있을 때의 생성자
//		cout << "String(const char*) : " << this << endl;
//		len = strlen(str);
//		alloc(len);
//		strcpy(strData, str);
//	}
//	String(const String& rhs) { // 복사 생성자
//		cout << "String(const String&) : " << this << endl;
//		len = rhs.len;
//		alloc(len);
//		strcpy(strData, rhs.strData);
//	}
//	// 이동 생성자
//	String(String&& rhs) { // 매개변수로 r-value를 받아야하므로 우측값 참조 래퍼런스를 사용한다.
//		cout << "String(String&&) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL; // 매개변수로 들어오는 우측값이 소멸되기 전에 해제시켜줘야한다.
//	}
//	~String() // 소멸자
//	{
//		cout << "~String() : " << this << endl;
//		release();
//		strData = NULL;
//	}
//	String& operator=(const String& rhs) { // 복사 대입 연산자 오버로딩
//		cout << "String& operator=(const String&) : " << this << endl;
//		if (this != &rhs) {
//			release();
//			len = rhs.len;
//			alloc(len);
//			strcpy(strData, rhs.strData);
//		}
//		return *this;
//	}
//	// 이동 대입 연산자 오버로딩
//	String& operator=(String&& rhs) {
//		cout << "String& operator=(String&& rhs) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL; // 매개변수로 들어오는 우측값이 소멸되기 전에 해제시켜줘야한다.
//		return *this;
//	}
//	
//	 char* GetStrData() const {
//		return strData;
//	}
//	 int GetLen() const {
//		return len;
//	}
//};
//
//String getName() {
//	cout << "===== 2 =====" << endl;
//	String res("Doodle");
//	cout << "===== 3 =====" << endl;
//	return res;
//}
//
//int main() {
//	String a;
//	cout << "===== 1 =====" << endl;
//	a = getName();
//	cout << "===== 4 =====" << endl;
//} // 결과를 확인해보면, 복사 생성 한번과 및 복사 대입 한번이 줄어들어서 총 2번의 복사가 줄어들었다. 이로써, 성능의 향상을 기대할 수 있다.


// 위 예제 연습
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class String {
//private:
//	int len;
//	char* strData;
//
//	void alloc(int len) {
//		strData = new char[len + 1];
//		cout << "strData 할당됨 : " << (void*)strData << endl;
//	}
//	void release() {
//		if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
//		delete[] strData;
//	}
//
//public:
//	String() { // 생성자1
//		cout << "String() : " << this << endl;
//		len = 0;
//		strData = NULL;
//	}
//	String(const char* str) { // 생성자2
//		cout << "String(const char*) : " << this << endl;
//		len = strlen(str);
//		alloc(len);
//		strcpy(strData, str);
//	}
//	String(const String& rhs) { // 복사 생성자
//		cout << "String(const String&) : " << this << endl;
//		len = rhs.len;
//		alloc(len);
//		strcpy(strData, rhs.strData);
//	}
//	String(String&& rhs) { // 이동 생성자
//		cout << "String(String&& rhs) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL;
//	}
//	~String() // 소멸자
//	{
//		cout << "~String() : " << this << endl;
//		release();
//		strData = NULL;
//	}
//
//	String& operator=(const String& rhs) { // 복사 대입 연산자 오버로딩
//		if (this != &rhs) {
//			cout << "String& operator=(const String&) : " << endl;
//			release();
//			len = rhs.len;
//			alloc(len);
//			strcpy(strData, rhs.strData);
//		}
//		return *this;
//	}
//	String& operator=(String&& rhs) { // 이동 대입 연산자 오버로딩
//		cout << "String& operator=(String&&) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL;
//		return *this;
//	}
//
//	char* GetStrData() const {
//		return strData;
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//String GetName() {
//	cout << "======2========" << endl;
//	String res = String("DDDD");
//	cout << "======3========" << endl;
//	return res;
//}
//
//int main() {
//	String a;
//	cout << "======1========" << endl;
//	a = GetName();
//	cout << "======4========" << endl;
//}


// 위 예제 연습 2
//#include <iostream>	
//#include <string.h>
//using namespace std;
//
//class String {
//private:
//	int len;
//	char* strData;
//
//	void alloc(int len) {
//		strData = new char[len + 1];
//		cout << "strData 할당됨 : " << (void*)strData << endl;
//	}
//	void release() {
//		if (strData) cout << "strData 해제됨 : " << (void*)strData << endl;
//		delete[] strData;
//	}
//
//public:
//	String() {
//		cout << "String() : " << this << endl;
//		len = 0;
//		strData = NULL;
//	}
//	String(const char* str) {
//		cout << "String(const char*) : " << this << endl;
//		len = strlen(str);
//		alloc(len);
//		strcpy(strData, str);
//	}
//	String(const String& rhs) {
//		cout << "String(const String&) : " << this << endl;
//		len = rhs.len;
//		alloc(len);
//		strcpy(strData, rhs.strData);
//	}
//	String(String&& rhs) {
//		cout << "String(String&&) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL;
//	}
//	~String()
//	{
//		cout << "~String() : " << this << endl;
//		release();
//	}
//
//	String& operator=(const String& rhs) {
//		cout << "String& operator=(const String&) : " << this << endl;
//		if (this != &rhs) {
//			release();
//			len = rhs.len;
//			alloc(len);
//			strcpy(strData, rhs.strData);
//		}
//		return *this;
//	}
//	String& operator=(String&& rhs) {
//		cout << "String& operator=(String&&) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL;
//		return *this;
//	}
//
//	char* GetStrData() const {
//		return strData;
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//String getName() {
//	cout << "===== 2 =====" << endl;
//	String res("Hi Hello Welcome!");
//	cout << "===== 3 =====" << endl;
//	return res;
//}
//
//int main() {
//	String a;
//	cout << "===== 1 =====" << endl;
//	a = getName();
//	cout << "===== 4 =====" << endl;
//}


// 11.6 묵시적 형변환 (implicit conversion) / 명시적 형변환 (explicit conversion)
// 11.6.2 형변환 생성자 오버로딩
// ex11.8 형변환 생성자를 만들고 사용하기
//#include <iostream>
//#include <string>
//using namespace std;
//
//class item {
//private:
//	int num;
//	string name;
//
//public:
//	item() { cout << "item()" << endl; }
//	item(int num) : num(num) { cout << "item(int)" << endl; }
//	item(string name) : name(name) { cout << "item(string)" << endl; }
//	item(int num, string name) : num(num), name(name) { cout << "item(int, string)" << endl; }
//};
//
//int main() {
//	cout << "===== a =====" << endl;
//	item a1 = item(1);
//	item a2(2);
//	item a3 = (item)3; // 명시적 형변환 (이때의 생성자를 (형)변환 생성자라 한다.)
//	item a4 = 4; // 묵시적 형변환
//	item a5, a6, a7;
//	a5 = item(5);  // 이동 대입 
//	a6 = 6; // 묵시적 형변환
//	a7 = (item)7; // 명시적 형변환 (이때의 생성자를 (형)변환 생성자라 한다.) // (형)변환 생성자(conversion constructor) : 우변의 타입을 좌변으로 변환하려 할때
//	
//	cout << "===== b =====" << endl;
//	
//	item b1 = item("stone");
//	item b2("stone");
//	item b3 = (item)"stone"; // 명시적 형변환 (이때의 생성자를 (형)변환 생성자라 한다.)
//	item b4 = string("stone"); // 묵시적 형변환
//	item b5, b6, b7;
//	b5 = item("stone");  // 이동 대입 
//	b6 = string("stone"); // 묵시적 형변환
//	b7 = (item)"stone"; // 명시적 형변환 (이때의 생성자를 (형)변환 생성자라 한다.) // (형)변환 생성자(conversion constructor) : 우변의 타입을 좌변으로 변환하려 할때
//
//	cout << "===== c =====" << endl;
//	item c1 = item(1, "stone");
//	item c2(2, "dirt");
//	// item c3 = (item){ 3, "wood" }; // 중괄호 안의 내용물을 명시적으로 형변환하는 문법은 존재하지 않음
//	item c4 = { 3, "wood" }; //묵시적 형변환, (형)변환 생성자 호출
//	item c5, c6;
//	c5 = item(4, "grass");
//	c6 = { 5, "water" }; // (형)변환 생성자 호출
//}


// 11.6.3 형변환 연산자 오버로딩
// ex11.9 형변환 연산자 오버로딩
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Item {
//private:
//	int num;
//	string name;
//
//public:
//	Item(){}
//	Item(int num) : num(num) {}
//	Item(string name) : name(name) {}
//	Item(int num, string name) : num(num), name(name) {}
//
//	operator int() const { // 형변환 연산자 오버로딩의 경우 매개변수는 없으므로 생략하고, 리턴타입도 생략해준다.
//		cout << "Item::operator int()" << endl;
//		return num;
//	}
//	operator string() const {
//		cout << "Item::operator string()" << endl;
//		return name;
//	}
//};
//
//int main() {
//	Item i1(1, "Stone");
//	int inum = i1; // 암시적 형변환 연산자 실행
//	string iname = i1; // 암시적 형변환 연산자 실행
//
//	cout << inum << endl;
//	cout << iname << endl;
//
//	Item i2(2, "Grass");
//	int i2num = (int)i2; // 명시적 형변환 연산자 실행
//	string i2name = (string)i2; // 명시적 형변환 연산자 실행
//
//	cout << i2num << endl;
//	cout << i2name << endl;
//}


// 11.6.4 explicit 키워드 (명시적 형변환만을 가능하게 하는 키워드)
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Item {
//private:
//	int num;
//	string name;
//public:
//	Item(){}
//	explicit Item(int num) : num(num) {}
//	explicit Item(string name) : name(name) {}
//	explicit Item(int num, string name) : num(num), name(name) {}
//};
//
//int main() {
//	Item i0;
//	//Item i1 = 1; // 에러! explicit 키워드로 인하여, 묵시적 형변환은 할 수 없다!
//	Item i2(2); // OK, 이건 형변환이 아니고 생성자만 호출한 것이다.
//	Item i3 = (Item)3; // OK, 3을 명시적으로 Item으로 형변환했다.
//	// Item i4 = { 2,"Dirt" }; // 에러! explicit 키워드로 인하여, 묵시적 형변환은 할 수 없다!
//	Item i5(2, "Dirt"); // OK
//}

// C++11부터는 형변환 연산자 앞에도 마찬가지로 explicit 키워드를 붙일 수 있다.
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Item {
//private:
//	int num;
//	string name;
//public:
//	Item(){}
//	explicit Item(int num) : num(num) {}
//	explicit Item(string name) : name(name) {}
//	explicit Item(int num, string name) : num(num), name(name) {}
//
//	explicit operator int() const { return num; }	
//	explicit operator string() const { return name; }
//};
//
//int main() {
//	Item i2(2);
//	Item i3 = (Item)3;
//	Item i5(2, "Dirt");
//
//	// int a = i5; // 에러! 묵시적 형변환은 할 수 없다.
//	int b = (int)i5; // OK. 명시적 형변환이다.
//}


// 종합문제
// 1번
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 10, b = 20, c = 30;
//	int* p = &a;
//	int& r = b;
//	int** pp = &p; // p라는 포인터를 가리키는 더블 포인터 pp
//	int* (&rp) = p; // p라는 포인터를 가리키는 래퍼런스 변수 rp (51강) (int* <- 가리켜야하는것의 타입)
//
//	r = c / *p;
//	rp = &c;
//	**pp = 40;
//	*p = 50;
//	*pp = &a;
//	*rp = 60;
//
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << *p << endl;
//	cout << r << endl;
//	cout << **pp << endl;
//	cout << *rp << endl;
//}


// 2번
#include <iostream>	
using namespace std;

struct Point {
	int x, y;
};

class Polygon {
private:
	int nPoints; // 꼭지점의 개수
	Point* points; // 꼭지점의 좌표
public:
	Polygon() {
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point* points) : nPoints(nPoints) {
		this->points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			this->points[i] = points[i]; // 포인터를 배열처럼 접근
		}
	}
	// 복사 생성자 구현
	Polygon(const Polygon& rhs) {
		nPoints = rhs.nPoints;
		points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			points[i] = rhs.points[i];
		}
	}
	// 이동 생성자 구현
	Polygon(Polygon&& rhs) {
			nPoints = rhs.nPoints;
			points = rhs.points;
			rhs.points = NULL;
	}

	~Polygon()
	{
		delete[] points;
	}

	// 복사 대입 연산자 구현
	Polygon& operator=(const Polygon& rhs) {
		if (this != &rhs) {
			nPoints = rhs.nPoints;
			delete[] points;
			points = new Point[nPoints];
			for (int i = 0; i < nPoints; i++) {
				points[i] = rhs.points[i];
			}
		}
		return *this;
	}

	// 이동 대입 연산자 구현
	Polygon& operator=(Polygon&& rhs) {
		nPoints = rhs.nPoints;
		points = rhs.points;
		rhs.points = NULL;
		return *this;
	}

	int GetNPoints() const {
		return nPoints;
	}

	Point* GetPoints() const {
		if (nPoints == 0) return NULL;
		return points;
	}
};

Polygon getSquare() {
	Point points[4] = { {0,0}, {1,0},{1,1},{0,1} };
	Polygon p(4, points);
	return p;
}

int main() {
	Polygon a;
	a = getSquare(); // 얕은 객체 복사 2회 (임시 객체 생성때 이동 생성자 -> 그 후 이동 대입 연산으로 총 2번)
	Polygon b = a; // 깊은 객체 복사 1회 (복사 생성자로 총 1번)
	Polygon c;
	c = a; // 깊은 객체 복사 1회 (복사 대입 연산자로 총 1번)

	int nPoints = c.GetNPoints();
	Point* points = c.GetPoints();
	for (int i = 0; i < nPoints; i++) {
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
}