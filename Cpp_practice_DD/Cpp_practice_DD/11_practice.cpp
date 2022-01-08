// 11 ���� �Ҵ�� ��ü ����
// 11.1 ���� �Ҵ�
// 11.1.1 ���� ���� �Ҵ��ϱ�
// ex11.1 �޸𸮸� ���� �Ҵ� �� �����غ���
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


// 11.1.2 �迭 ���� �Ҵ��ϱ�
// ex
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cout << "�迭�� ĭ ���� �Է��Ͻÿ� : ";
//	cin >> n;
//
//	// int* arr = new int[n];
//	int* arr = new int[n] {33, 33, 33}; // ���� �Ҵ�� ���ÿ� �ʱ�ȭ ���
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << endl;
//	}
//	delete[] arr;
//}


// 11.1.3 ��ü ���� �Ҵ��ϱ� (new Ű���� �ڿ� ��ü�� �����ڸ� ȣ���ϸ� �ȴ�.) (��ü�� �����ڴ� new���� ����ǰ�, �Ҹ��ڴ� delete���� ����ȴ�.)
// ex11.2 ��ü ���� �Ҵ��ϱ�
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
//	cout << "���� ����" << endl;
//
//	// ���� �Ҵ�� ��ü
//	Vector2 s1;
//	Vector2 s2(2, 3);
//
//	// ���� �Ҵ�� ��ü
//	Vector2* d1 = new Vector2; // ������ ����
//	Vector2* d2 = new Vector2(4, 5);
//
//	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
//	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;
//
//	delete d1; // �Ҹ��� ����
//	delete d2; 
//
//	cout << "���� ��!" << endl;
//}


// 11.2 ���� ����(deep copy)�� ���� ����(shallow copy)
// ���� ����(shallow copy)
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a = new int(3);
//	// int* b = a;
//	int* b;
//	b = a; // ������ ����Ǿ���. // ���� int�� ��� ������ �� ������ ����ִ� ���� ����� ���� �ƴ϶� �ּҰ��� ����Ǿ���. 
//	*a = 5;
//	cout << *a << endl;
//	cout << *b << endl;
//	delete a;
//	// delete b; // �޸𸮸� �� �� �����ؼ��� �ȵȴ�.
//}


// ���� ����(deep copy)
// ex
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a = new int(3);
//	int* b = new int(*a); // b�� a�� ����Ű�� ������ �ƴ� ���� ������� int ������ ����Ű�� �ְ�, �� ������ �ܼ��� a ������ ����ִ� ���� ����� ��
//	*a = 5;
//	cout << *a << endl;
//	cout << *b << endl;
//	delete a;
//	delete b; // �̰��� ���� �����̱� ������ a�� b�� ����Ű�� �޸��� �ּҰ��� ���� �ٸ��Ƿ� ���� �� ������������Ѵ�.
//}


// ���� ����� ���� ���簡 ���ÿ� �Ͼ�� ��Ȳ
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
//	A b = a; // a�� �ִ� ��� ����� ����ȴ�. �� ��, ����� �Ϲ� ������ �����͵� ������� �ű� ��� �ִ� ���� �׳� ����Ǵ� ���̴�. (ù��° �Ű������� ���� ����, �ι�° �Ű������� ���� ����)
//	a.x = 3; 
//	*(a).y = 4; // *a.y = 4; �� ���� ǥ���̴�. 
//	cout << b.x << endl;
//	cout << *(b).y << endl;
//	delete a.y;
//	// delete b.y; // A b =a; �������� b�� ��� ���� y�� a�� ��� ���� y�� �״�� ����Ǿ����Ƿ�(���� ����), �� ���� ����Ű�� �ּҰ��� ����. 
//	// ���� �޸𸮸� �� �� �����Ϸ� �ϴ� ������ �Ǵ°��̴�.
//}


// 11.3 ���� �����ڿ� ���� ���� ������
// 11.3.1 String Ŭ���� �����
// ex11.3 String Ŭ���� ������
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
//		strData = new char[len + 1]; // NULL ���ڰ� �߰��Ǿ�� �ϱ⶧����...
//		strcpy(strData, str); // ���� ���縦 �ϱ� ����...
//	}
//	~String()
//	{
//		if (strData) {
//			delete[] strData;
//		}
//	}
//
//	 const char* GetStrData() const { // const char*�� �ƴ� char*�� ����Ÿ������ �����ϸ� �� ���ڿ��� �����Ҷ� ������ �߻��� �� �ִ�.
//		if (strData) return strData;
//		return ""; // �� ���ڿ� ����
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


// 11.3.2 ���� ������ �����ε� (copy constructor overloading)
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
//		strData = new char[len + 1]; // NULL ���ڰ� �߰��Ǿ�� �ϱ⶧����...
//		strcpy(strData, str);
//	}
//	~String()
//	{
//		if (strData) {
//			delete[] strData;
//		}
//	}
//
//	const char* GetStrData() const { // const char*�� �ƴ� char*�� ����Ÿ������ �����ϸ� �� ���ڿ��� �����Ҷ� ������ �߻��� �� �ִ�.
//		if (strData) return strData;
//		return ""; // �� ���ڿ� ����
//	}
//	int GetLen() const {
//		return len;
//	}
//};
//
//int main() {
//	String s1("Hello");
//	String s2 = s1; // ��ü�� �����ϸ� ��ü�� ����߿� �����Ͱ� ���� ��� ���� ���簡 �Ͼ��. (�׸��� �̿� ���� ������ �Ҷ� ���� �����ڰ� ����ȴ�.)
//	// String s2(s1); // �׸��� �̿� ���� ������ �Ҷ� ���� �����ڰ� ����ȴ�. (��ü�� �����ϴ� ���ÿ� � �ٸ� ��ü�� ������ �ʱ�ȭ�ϴ� ��� <= ���� ����)
//	// ���� �����ڸ� Ư���� ����� ���� ���� ���¿��� ���� ������ �� ���, ���� ���簡 �Ͼ��. // ����� ��Ÿ�� ������ ���� ������ ���� ����� ���Ͽ� �޸� ������ �� �� �Ͽ��� �����̴�.
//	// ���� ������ ���� ��� : String(String &rhs) {} 
//	cout << s1.GetLen() << endl;
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetLen() << endl;
//	cout << s2.GetStrData() << endl;
//}


// ex11.4 String Ŭ������ ���� ������ �߰��ϱ�
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
//		strcpy(strData, str); // ���� ����
//	}
//	String(const String& rhs) { // ���� ������ ����, �Ű������δ� String�� ���� ���۷����� �޴´�.
//		len = rhs.len;
//		strData = new char[len + 1];
//		strcpy(strData, rhs.strData); // ���� ����
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
//	String s2 = s1; // String s2(s1); �� ���� ��. ���� �����ڰ� ȣ��ȴ�.
//
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetStrData() << endl;
//} // ������ �߻����� �ʴ´�. �� ���� �������� ���ǿ� ����, �� ��ü���� �޸𸮸� ���� �Ҵ��ϰ�, ���� �Ҵ��� �޸𸮸� ���� �����߱� �����̴�.


// 11.3.3 ���� ���� ������ �����ε� (copy assignment operator overloading (String& operator=(const String& rhs)) (���� �Լ��� �ƴ϶�, Ŭ���� �ȿ� �����ؾ��Ѵ�.)
// ex11.5 String Ŭ������ ���� ���� ������ �߰��ϱ�
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
//	String& operator=(const String& rhs) { // ���� ���� ������ �����ε� (�����ڴ� �����Ҷ� �� �ѹ� �Ͼ��)
//		if (this != &rhs) { // ������ ���ο��� ������ ��츦 ó���ϱ� ���Ͽ�
//			delete[] strData; // ������ �ִ� String ��ü�� strData�� �������� ������ �޸� ����(memory leak)�� �߻��Ѵ�.
//			len = rhs.len;
//			strData = new char[len + 1];
//			strcpy(strData, rhs.strData);
//		}
//		return *this; // ���� �����ڴ� ���ϰ��� �ִ�. (���� ������ ��츦 ���Ͽ�)
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
//	String s2 = s1; // ���� ������ ���� String s2(s1); �� ���� ǥ���̹Ƿ� ���� �����ڰ� ����ȴ�.
//	String s3;
//	String s4("Hi"); 
//	s3 = s1; // ���� ���� ������ ����
//	s4 = s1; // ���� ���� ������ ����
//	s4 = s4; // ���� ���� ������ ����
//	String s5;
//	String s6;
//	s6 = s5 = s4; // ���� ���� ������ ����
//
//	cout << s1.GetStrData() << endl;
//	cout << s2.GetStrData() << endl;
//	cout << s3.GetStrData() << endl;
//	cout << s4.GetStrData() << endl;
//}


// 11.4 �̵� �ø�ƽ(move semantic) : ���� ���Ŀ� �ٷ� ������� ��ü�� ���ؼ��� �ǵ������� ���� ���縦 �� �����͸� �������� �ʰ� "�̵�"�� ��Ű���� �ϴ� ����
// ex11.6 �̵� �����ڿ� �̵� ���� �����ڸ� �������� �ʾ��� ���� �۵�
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
//		cout << "strData �Ҵ�� : " << (void*)strData << endl; // (void*)�� ���¿��� ���� ���� �ּҰ��� ���ڴٴ� ��
//	}
//	void release() {
//		if (strData) cout << "strData ������ : " << (void*)strData << endl;
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


// 11.5.2 �̵� ������ �� �̵� ���� ������ �����ε� (�̵� �ø�ƽ ����)
// ��ü�� ���ϵǴ� ������ ������ ���� ������/���� ���� �����ڰ� ȣ��Ǵ� ���� �̵� ������/�̵� ���� �����ڸ� �����س����� �̵� �����ڿ� �̵� ���� �����ڰ� ȣ��ǵ��� �ٲ��.
// �̵� �����ڰ� �ؾ��ϴ� ������ ���� �����̴�!
// �̵� ���� ������ �����ε��� ��� ���� ���� ������ �����ε����� �ٸ���, �ڱ� �ڽſ� �����ϴ� ���� ���� �������� �ʴ´�. (�̵��� �Ͼ�� �ִٴ� ���� �캯�� ���� ���� ���Ŀ� ������ٴ� ���̹Ƿ�...)
// ex11.7 �̵� �����ڿ� �̵� ���� ������ �����ϱ�
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
//		cout << "strData �Ҵ�� : " << (void*)strData << endl;
//	}
//	void release() {
//		if (strData) cout << "strData ������ : " << (void*)strData << endl;
//		delete[] strData;
//	}
//
//public:
//	String() { // �Ű������� ���� ���� ������
//		cout << "String() : " << this << endl;
//		strData = NULL;
//		len = 0;
//	}
//	String(const char* str) { // �Ű������� ���� ���� ������
//		cout << "String(const char*) : " << this << endl;
//		len = strlen(str);
//		alloc(len);
//		strcpy(strData, str);
//	}
//	String(const String& rhs) { // ���� ������
//		cout << "String(const String&) : " << this << endl;
//		len = rhs.len;
//		alloc(len);
//		strcpy(strData, rhs.strData);
//	}
//	// �̵� ������
//	String(String&& rhs) { // �Ű������� r-value�� �޾ƾ��ϹǷ� ������ ���� ���۷����� ����Ѵ�.
//		cout << "String(String&&) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL; // �Ű������� ������ �������� �Ҹ�Ǳ� ���� ������������Ѵ�.
//	}
//	~String() // �Ҹ���
//	{
//		cout << "~String() : " << this << endl;
//		release();
//		strData = NULL;
//	}
//	String& operator=(const String& rhs) { // ���� ���� ������ �����ε�
//		cout << "String& operator=(const String&) : " << this << endl;
//		if (this != &rhs) {
//			release();
//			len = rhs.len;
//			alloc(len);
//			strcpy(strData, rhs.strData);
//		}
//		return *this;
//	}
//	// �̵� ���� ������ �����ε�
//	String& operator=(String&& rhs) {
//		cout << "String& operator=(String&& rhs) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL; // �Ű������� ������ �������� �Ҹ�Ǳ� ���� ������������Ѵ�.
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
//} // ����� Ȯ���غ���, ���� ���� �ѹ��� �� ���� ���� �ѹ��� �پ�� �� 2���� ���簡 �پ�����. �̷ν�, ������ ����� ����� �� �ִ�.


// �� ���� ����
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
//		cout << "strData �Ҵ�� : " << (void*)strData << endl;
//	}
//	void release() {
//		if (strData) cout << "strData ������ : " << (void*)strData << endl;
//		delete[] strData;
//	}
//
//public:
//	String() { // ������1
//		cout << "String() : " << this << endl;
//		len = 0;
//		strData = NULL;
//	}
//	String(const char* str) { // ������2
//		cout << "String(const char*) : " << this << endl;
//		len = strlen(str);
//		alloc(len);
//		strcpy(strData, str);
//	}
//	String(const String& rhs) { // ���� ������
//		cout << "String(const String&) : " << this << endl;
//		len = rhs.len;
//		alloc(len);
//		strcpy(strData, rhs.strData);
//	}
//	String(String&& rhs) { // �̵� ������
//		cout << "String(String&& rhs) : " << this << endl;
//		len = rhs.len;
//		strData = rhs.strData;
//		rhs.strData = NULL;
//	}
//	~String() // �Ҹ���
//	{
//		cout << "~String() : " << this << endl;
//		release();
//		strData = NULL;
//	}
//
//	String& operator=(const String& rhs) { // ���� ���� ������ �����ε�
//		if (this != &rhs) {
//			cout << "String& operator=(const String&) : " << endl;
//			release();
//			len = rhs.len;
//			alloc(len);
//			strcpy(strData, rhs.strData);
//		}
//		return *this;
//	}
//	String& operator=(String&& rhs) { // �̵� ���� ������ �����ε�
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


// �� ���� ���� 2
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
//		cout << "strData �Ҵ�� : " << (void*)strData << endl;
//	}
//	void release() {
//		if (strData) cout << "strData ������ : " << (void*)strData << endl;
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


// 11.6 ������ ����ȯ (implicit conversion) / ����� ����ȯ (explicit conversion)
// 11.6.2 ����ȯ ������ �����ε�
// ex11.8 ����ȯ �����ڸ� ����� ����ϱ�
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
//	item a3 = (item)3; // ����� ����ȯ (�̶��� �����ڸ� (��)��ȯ �����ڶ� �Ѵ�.)
//	item a4 = 4; // ������ ����ȯ
//	item a5, a6, a7;
//	a5 = item(5);  // �̵� ���� 
//	a6 = 6; // ������ ����ȯ
//	a7 = (item)7; // ����� ����ȯ (�̶��� �����ڸ� (��)��ȯ �����ڶ� �Ѵ�.) // (��)��ȯ ������(conversion constructor) : �캯�� Ÿ���� �º����� ��ȯ�Ϸ� �Ҷ�
//	
//	cout << "===== b =====" << endl;
//	
//	item b1 = item("stone");
//	item b2("stone");
//	item b3 = (item)"stone"; // ����� ����ȯ (�̶��� �����ڸ� (��)��ȯ �����ڶ� �Ѵ�.)
//	item b4 = string("stone"); // ������ ����ȯ
//	item b5, b6, b7;
//	b5 = item("stone");  // �̵� ���� 
//	b6 = string("stone"); // ������ ����ȯ
//	b7 = (item)"stone"; // ����� ����ȯ (�̶��� �����ڸ� (��)��ȯ �����ڶ� �Ѵ�.) // (��)��ȯ ������(conversion constructor) : �캯�� Ÿ���� �º����� ��ȯ�Ϸ� �Ҷ�
//
//	cout << "===== c =====" << endl;
//	item c1 = item(1, "stone");
//	item c2(2, "dirt");
//	// item c3 = (item){ 3, "wood" }; // �߰�ȣ ���� ���빰�� ��������� ����ȯ�ϴ� ������ �������� ����
//	item c4 = { 3, "wood" }; //������ ����ȯ, (��)��ȯ ������ ȣ��
//	item c5, c6;
//	c5 = item(4, "grass");
//	c6 = { 5, "water" }; // (��)��ȯ ������ ȣ��
//}


// 11.6.3 ����ȯ ������ �����ε�
// ex11.9 ����ȯ ������ �����ε�
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
//	operator int() const { // ����ȯ ������ �����ε��� ��� �Ű������� �����Ƿ� �����ϰ�, ����Ÿ�Ե� �������ش�.
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
//	int inum = i1; // �Ͻ��� ����ȯ ������ ����
//	string iname = i1; // �Ͻ��� ����ȯ ������ ����
//
//	cout << inum << endl;
//	cout << iname << endl;
//
//	Item i2(2, "Grass");
//	int i2num = (int)i2; // ����� ����ȯ ������ ����
//	string i2name = (string)i2; // ����� ����ȯ ������ ����
//
//	cout << i2num << endl;
//	cout << i2name << endl;
//}


// 11.6.4 explicit Ű���� (����� ����ȯ���� �����ϰ� �ϴ� Ű����)
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
//	//Item i1 = 1; // ����! explicit Ű����� ���Ͽ�, ������ ����ȯ�� �� �� ����!
//	Item i2(2); // OK, �̰� ����ȯ�� �ƴϰ� �����ڸ� ȣ���� ���̴�.
//	Item i3 = (Item)3; // OK, 3�� ��������� Item���� ����ȯ�ߴ�.
//	// Item i4 = { 2,"Dirt" }; // ����! explicit Ű����� ���Ͽ�, ������ ����ȯ�� �� �� ����!
//	Item i5(2, "Dirt"); // OK
//}

// C++11���ʹ� ����ȯ ������ �տ��� ���������� explicit Ű���带 ���� �� �ִ�.
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
//	// int a = i5; // ����! ������ ����ȯ�� �� �� ����.
//	int b = (int)i5; // OK. ����� ����ȯ�̴�.
//}


// ���չ���
// 1��
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 10, b = 20, c = 30;
//	int* p = &a;
//	int& r = b;
//	int** pp = &p; // p��� �����͸� ����Ű�� ���� ������ pp
//	int* (&rp) = p; // p��� �����͸� ����Ű�� ���۷��� ���� rp (51��) (int* <- �����Ѿ��ϴ°��� Ÿ��)
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


// 2��
#include <iostream>	
using namespace std;

struct Point {
	int x, y;
};

class Polygon {
private:
	int nPoints; // �������� ����
	Point* points; // �������� ��ǥ
public:
	Polygon() {
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point* points) : nPoints(nPoints) {
		this->points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			this->points[i] = points[i]; // �����͸� �迭ó�� ����
		}
	}
	// ���� ������ ����
	Polygon(const Polygon& rhs) {
		nPoints = rhs.nPoints;
		points = new Point[nPoints];
		for (int i = 0; i < nPoints; i++) {
			points[i] = rhs.points[i];
		}
	}
	// �̵� ������ ����
	Polygon(Polygon&& rhs) {
			nPoints = rhs.nPoints;
			points = rhs.points;
			rhs.points = NULL;
	}

	~Polygon()
	{
		delete[] points;
	}

	// ���� ���� ������ ����
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

	// �̵� ���� ������ ����
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
	a = getSquare(); // ���� ��ü ���� 2ȸ (�ӽ� ��ü ������ �̵� ������ -> �� �� �̵� ���� �������� �� 2��)
	Polygon b = a; // ���� ��ü ���� 1ȸ (���� �����ڷ� �� 1��)
	Polygon c;
	c = a; // ���� ��ü ���� 1ȸ (���� ���� �����ڷ� �� 1��)

	int nPoints = c.GetNPoints();
	Point* points = c.GetPoints();
	for (int i = 0; i < nPoints; i++) {
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
}