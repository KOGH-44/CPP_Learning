// 13 C++ 고급 기능

// 13.1 템플릿 (Template)
// 13.1.1 함수 템플릿 (함수를 찍어내는 틀) (이건 함수가 아니다. 함수를 찍어내는 틀이므로, 함수를 선언하기 전까지 함수는 없다.)
//ex13.1 함수 템플릿 사용하기
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Vector2 {
//public:
//	Vector2() : x(0), y(0) {}
//	Vector2(float x, float y) : x(x), y(y) {}
//
//	float GetX() const { return x; }
//	float GetY() const { return y; }
//
//	Vector2 operator+(const Vector2 other) const {
//		return Vector2(x + other.x, y + other.y);
//	}
//	Vector2 operator-(const Vector2 other) const {
//		return Vector2(x - other.x, y - other.y);
//	}
//	Vector2& operator+=(const Vector2 other) {
//		x += other.x;
//		y += other.y;
//		return *this;
//	}
//	Vector2& operator-=(const Vector2 other) {
//		x -= other.x;
//		y -= other.y;
//		return *this;
//	}
//
//private:
//	float x, y;
//};
//
//template<typename T>
//T getArraySum(const T arr[], int n) {
//	T sum = arr[0]; // T sum = 0; <- sum을 0으로 초기화하면 T에 또 다른 제약 사항(double이나 int일 떄는 문제 없음)이 하나 더 붙기 때문에 sum을 배열의 0번째 원소로 초기화 한 것이다.
//	for (int i = 1; i < n; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//int main() {
//	int iarr[5] = { 3,1,4,1,5 };
//	double darr[5] = { 3.5, 1.2, 4.3, 1.1, 5.7 };
//	Vector2 varr[3] = { Vector2(1,2), Vector2(3,4), Vector2(5,6) };
//	string sarr[3] = { "hello", "world", "doodle" };
//
//	int isum = getArraySum<int>(iarr, 5); // 템플릿 인수 명시 (타입 유추 안 하는 방식)
//	double dsum = getArraySum(darr, 5); // 템플릿 인수 생략 (타입 유추 하는 방식) (함수 템플릿의 경우는 템플릿 인수 생략이 가능하다.)
//	Vector2 vsum = getArraySum<Vector2>(varr, 3);
//	string ssum = getArraySum(sarr, 3);
//
//	cout << isum << endl;
//	cout << dsum << endl;
//	cout << vsum.GetX() << ", " << vsum.GetY() << endl;
//	cout << ssum << endl;
//
//	cout << endl;
//
//	cout << int() << endl; // 기본 생성자 실행시 0 리턴
//	cout << double() << endl; // 기본 생성자 실행시 0 리턴
//	cout << string() << endl; // 기본 생성자 실행시 빈 문자열 ("") 리턴
//}


// 위 예제 약간 변형한 방식 (T sum = arr[0]; 대신 T sum = T(); 사용)
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Vector2 {
//public:
//	Vector2() : x(0), y(0) {}
//	Vector2(float x, float y) : x(x), y(y) {}
//
//	Vector2 operator+(const Vector2 rhs) const {
//		return Vector2(x + rhs.x, y + rhs.y);
//	}
//	Vector2 operator-(const Vector2 rhs) const {
//		return Vector2(x - rhs.x, y - rhs.y);
//	}
//	Vector2& operator+=(const Vector2 rhs) { // 복합 대입 연산자 오버로딩
//		x += rhs.x;
//		y += rhs.y;
//		return *this;
//	}
//	Vector2& operator-=(const Vector2 rhs) { // 복합 대입 연산자 오버로딩
//		x -= rhs.x;
//		y -= rhs.y;
//		return *this;
//	}
//
//	float GetX() const {
//		return x;
//	}
//	float GetY() const {
//		return y;
//	}
//private:
//	float x, y;
//};
//
//template<typename T>
//T getArraySum(const T* arr, int n) {
//	T sum = T(); // sum을 타입의 기본 생성자로 초기화!
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//int main() {
//	int iarr[5] = { 1, 2, 3, 4, 5 };
//	double darr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
//	Vector2 varr[3] = { Vector2(1,2), Vector2(3,4), Vector2(5,6) };
//	string sarr[3] = { "Hello", "World", "!" };
//
//	int isum = getArraySum(iarr, 5);
//	double dsum = getArraySum(darr, 5);
//	Vector2 vsum = getArraySum<Vector2>(varr, 3);
//	string ssum = getArraySum<string>(sarr, 3);
//
//	cout << isum << endl;
//	cout << dsum << endl;
//	cout << vsum.GetX() << ", " << vsum.GetY() << endl;
//	cout << ssum << endl;
//} 


// 템플릿에는 타입 파라미터를 여러 개 줄 수 있다!
//#include <iostream>
//using namespace std;
//
//template<typename T, typename U, typename X>
//void doSomething(T t, U u) {
//	cout << t << endl;
//	cout << u << endl;
//	X x = 'a';
//	cout << x << endl;
//}
//
//int main() {
//	int a = 3;
//	double b = 3.14;
//	doSomething<int, double, char>(a, b);
//}


// 13.1.2 클래스 템플릿 (클래스를 찍어내는 틀) (이것도 클래스가 아니다. 클래스를 찍어내는 틀이므로 클래스를 만들려면 객체를 선언해야 한다.)
// 함수와는 다르게 클래스는 "오버로딩"하는 방법이 없다.
//ex13.2 클래스 템플릿 만들어 보기
//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Vector2 {
//public:
//	Vector2() : x(0), y(0) {}
//	Vector2(T x, T y) : x(x), y(y) {}
//	
//	T GetX() const { return x; }
//	T GetY() const { return y; }
//
//	Vector2 operator+(const Vector2 rhs) const {
//		return Vector2(x + rhs.x, y + rhs.y);
//	}
//	Vector2 operator-(const Vector2 rhs) const {
//		return Vector2(x - rhs.x, y - rhs.y);
//	}
//	Vector2& operator+=(const Vector2 rhs) {
//		x += rhs.x;
//		y += rhs.y;
//		return *this;
//	}
//	Vector2& operator-=(const Vector2 rhs) {
//		x -= rhs.x;
//		y -= rhs.y;
//		return *this;
//	}
//
//private:
//	T x, y;
//};
//
//int main() {
//	Vector2<int> v1(1, 3); // 각 성분이 int인 벡터 (클래스 템플릿은 템플릿 인수를 생략 하지 않는다.)
//	Vector2<double> v2(1.5, 3.5); // 각 성분이 double인 벡터 (클래스 템플릿은 템플릿 인수를 생략 하지 않는다.)
//	// 위 두 벡터는 서로 다른 타입이다.
//
//	cout << v1.GetX() << ", " << v1.GetY() << endl;
//	cout << v2.GetX() << ", " << v2.GetY() << endl;
//
//	cout << sizeof(v1) << endl; // 8 출력
//	cout << sizeof(v2) << endl; // 16 출력
//	// 같은 타입이라면 최소한 타입의 크기는 같아야 하는데, 크기부터 다르다.
//	// 즉, 클래스 템플릿을 사용하여 클래스를 만들 때, 타입 파라미터만 달라도 서로 다른 타입이다.
//}


// Tip : 배열은 복사하면 무조건 깊은 복사가 일어난다! (동적 할당이 아니기 때문이다!)


// 13.1.3 템플릿 특수화 (Template specialiaztion) (어떤 특수한 인수가 들어왔을 때 원래 템플릿의 정의를 따르지 않고, 예외적으로 그 인수에 대한 정의를 따로 할 수 있게 하는 것을 말한다.)
//ex13.3 템플릿 특수화 사용해보기
//#include <iostream>
//#include <string>
//using namespace std;
//
//template<typename T> // 기존 템플릿
//T getArraySum(T* arr, int n) {
//	T sum = T();
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//template<> // 특수화 
//string getArraySum<string>(string arr[], int n) { // <string> 생략 가능
//	string sum = arr[0];
//	for (int i = 1; i < n; i++) {
//		sum += " " + arr[i]; // 단어 사이에 공백도 넣어준다.
//	}
//	return sum;
//}
//
//int main() {
//	int iarr[] = { 3, 1, 4, 1, 5 };
//	string sarr[] = { "Hello", "world", "!!!" };
//
//	int isum = getArraySum(iarr, 5); // 기존 템플릿으로부터 생성된 함수 실행
//	string ssum = getArraySum(sarr, 3); // 특수화된 함수 실행
//
//	cout << isum << endl;
//	cout << ssum << endl;
//}


// 위 예제 연습
//#include <iostream>	
//#include <string>
//using namespace std;
//
//template<typename T>
//T getArraySum(const T arr[], int n) {
//	T sum = T();
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//template<>
//string getArraySum<string>(const string arr[], int n) {
//	string sum = arr[0];
//	for (int i = 1; i < n; i++) {
//		sum += " " + arr[i];
//	}
//	return sum;
//}
//
//int main() {
//	int iarr[] = { 1, 2, 3, 4, 5 };
//	string sarr[] = { "Hello", "world", "!" };
//
//	int isum = getArraySum<int>(iarr, 5);
//	string ssum = getArraySum<string>(sarr, 3);
//
//	cout << isum << endl;
//	cout << ssum << endl;
//}


// 13.1.4 비타입 파라미터 (Non-type template parameter) 
// 템플릿이 받을 수 있는 파라미터는 타입 뿐만 아니라, 정수, 포인터 등도 받을 수 있다!
// 비타입 파라미터 없이 임의의 n차원 벡터 클래스 만들기
//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Vector { // 임의의 차원을 나타낼 수 있는 벡터
//	Vector(int n) { // n : 차원
//		this->n = n;
//		components = new T[n]; (동적 할당이 일어나게 되고, 이로 인해 이 객체를 넘겨줄때 얕은 복사가 일어나는 문제가 발생하게 된다.)
//	}
//	~Vector() {
//		delete[] components;
//	}
//
//	T GetComponent(int i) { // i번째 성분을 리턴
//		return components[i];
//	}
//	void SetComponent(int i, T val) { // i번째 성분을 T타입의 val로 설정
//		components[i] = val;
//	}
//
//	Vector operator+(const Vector rhs) const { // 여기서 문제가 발생! (이유 : operator+ 에서 양변의 차원이 다를 수 있다! 근데 벡터는 다른 차원끼리 더할 수 없다! <- 이것을 비타입 파라미터로 해결 가능!)
//		???
//	}
//
//private:
//	int n; // 차원
//	T* components; // 각 성분을 저장하는 배열
//};


// 위 문제가 생기는 예시를 비타입 파라미터로 해결 하는 방법
//#include <iostream>
//using namespace std;
//
//template<typename T, int n> // 여기서 int n이 비타입 파라미터 이다. n은 컴파일타임에 초기화 되므로, 상수처럼 사용 가능하게 된다!
//class Vector {
//public:
//	T GetComponent(int i) const { // i번째 성분을 리턴
//		return component[i];
//	}
//	void SetComponent(int i, T val) { // i번째 성분을 T타입의 val로 설정
//		component[i] = val;
//	}
//
//	Vector operator+(const Vector rhs) const { // 이 연산자 오버로딩을 사용할 수 있는 객체는 + 연산자 우측에 오는 객체의 타입이 +연산자 좌측과 같은 경우만 가능하다. (좌측이 우선권을 가짐)
//		Vector res;
//		for (int i = 0; i < n; i++) {
//			res.component[i] = this->component[i] + rhs.component[i];
//			//res.SetComponent(i, this->GetComponent(i) + rhs.GetComponent(i));
//		}
//		return res; // 위 문제점으로 지적되었던 얕은 복사 대신 배열을 넘기는 것이므로 깊은 복사가 일어나게 된다!
//	}
//
//private:
//	T component[n]; // 각 성분을 저장하는 배열
//};
//
//int main() {
//	Vector<float, 3> v1, v2;
//	Vector<float, 2> v4;
//
//	v1.SetComponent(0, 2);
//	v1.SetComponent(1, 3);
//	v1.SetComponent(2, 4);
//
//	v2.SetComponent(0, 5);
//	v2.SetComponent(1, 6);
//	v2.SetComponent(2, 7);
//
//	Vector<float, 3> v3 = v1 + v2;
//	//Vector<float, 3> v5 = v1 + v4; // 이러한 에러를 비타입 파라미터를 사용하므로써 원천 차단할 수 있음 (3차원 벡터에 2차원 벡터를 더하려는 행위) // 같은 템플릿을 사용하여 만든 클래스 객체이지만, 비타입 파라미터가 다르기 때문에 완전 다른 타입임. (뭐든 다르면 다름.)
//	
//	cout << v3.GetComponent(0) << ", " << v3.GetComponent(1) << ", " << v3.GetComponent(2) << endl;
//}


// 위 예제 연습
//#include <iostream>
//using namespace std;
//
//template<typename T, int n>
//class Vector {
//private:
//	T comp[n];
//
//public:
//	void setComp(int i, T val) {
//		comp[i] = val;
//	}
//	T getComp(int i) const {
//		return comp[i];
//	}
//
//	Vector operator+(const Vector rhs) const {
//		Vector res;
//
//		for (int i = 0; i < n; i++) {
//			//res.setComp(i, (this->getComp(i) + rhs.getComp(i)));
//			res.comp[i] = this->comp[i] + rhs.comp[i];
//		}
//		return res;
//	}
//};
//
//int main() {
//	Vector<int, 3> v1, v2;
//	v1.setComp(0, 0);
//	v1.setComp(1, 1);
//	v1.setComp(2, 2);
//
//	v2.setComp(0, 0);
//	v2.setComp(1, 10);
//	v2.setComp(2, 20);
//
//	Vector<int, 3> v3 = v1 + v2;
//	cout << v3.getComp(0) << ", " << v3.getComp(1) << ", " << v3.getComp(2) << endl;
//}


// 13.2 예외 처리 (Exception handling) (C에는 예외 처리 문법이 아예 없다!)
// 1! = 1
// 0! = 1
//ex13.4 if문을 사용한 팩토리얼 범위 확인
//#include <iostream>
//using namespace std;
//
//int fact(int n) {
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int main() {
//	int n;
//	cout << "자연수를 입력하세요 : ";
//	cin >> n;
//	if (n >= 1) { // n이 자연수일 때만 팩토리얼 계산
//		cout << n << "! = " << fact(n) << endl;
//	}
//	else { // 아니면 에러 메시지 출력
//		cout << n << " : 자연수가 아닙니다." << endl;
//	}
//}


// 예외 처리는 항상 try, throw (던지면), catch (받아)라는 3개의 키워드를 통해 작동한다. 예외는 변수나 객체이기만 하면 된다.
// 즉, 정수를 던질 수도 있고, 포인터를 던질 수도 있고, 아무 클래스나 만들어서 그 타입의 객체를 던져도 된다. (이 때, 던져지는 예외를 예외 객체라 한다.)
// try 안의 내용물은 끝까지 성공적으로 실행될 수도 있고, 중간에 실행되다 말 수도 있다. try문 안의 내용물을 실핼하는 도중 예외가 하나라도 발생한다면 하던 일을 멈추고 catch문을 찾아가 그 내용물을 실행한다.
// 반대로, try문을 끝까지 실행했는데도 예외가 발생하지 않는다면 catch문을 실행하지 않고 다음 코드로 넘어간다.


//ex13.5 예외 처리를 통해 작성한 팩토리얼 코드
//#include <iostream>
//using namespace std;
//
//int fact(int n) {
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int main() {
//	int n;
//
//	try {
//		cout << "자연수를 입력하세요 : ";
//		cin >> n;
//		if (n <= 0) {
//			throw n; // 예외 발생
//		}
//		// 예외가 발생하지 않았을 때의 코드
//		cout << n << "! = " << fact(n) << endl;
//	}
//	catch (int e) { // 예외 받기
//		cout << e << " : 자연수가 아닙니다." << endl; // 적절한 처리
//	}
//}


// 예외 처리의 장점 : 예외는 함수 간에도 전달될 수 있다! (어떤 함수에서 예외를 던졌다고 해서 그 함수에서 예외를 처리할 필요는 없다. 그러면 이 예외는 그 함수를 호출했던 함수로 "떠넘겨진다".)
//ex13.6 예외 떠넘기기
//#include <iostream>
//#include <string> 
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : 자연수가 아닙니다."; // 다음 예외가 main 함수에서 발생할 경우 main함수에서 호출한 곳으로 이동한 후 catch문을 찾아 들어간다. (다른 함수에서 호출했으면 그 곳으로 간다.)
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int main() {
//	int n, r;
//	try {
//		cout << "자연수 2개 입력 : ";
//		cin >> n >> r;
//
//		int a = fact(n); //
//		int b = fact(r); // 셋 중 한 군데서라도 예외 발생 시 catch로 이동
//		int c = fact(n - r); // 
//		
//		int result = a / b / c;
//		cout << result << endl;
//	}
//	catch (const string& e) { // 복사 생성을 막기 위해 래패런스로 선언!
//		cout << e << endl;
//	}
//} // 핵심 : 예외를 던지는 부분도 하나밖에 없고, 예외를 처리하는 부분도 하나밖에 없다. (if만 가지고도 비슷한 효과를 낼 수 있지만 예외 처리를 사용한 방법이 더 깔끔하다.)


// 여러 함수에 걸쳐서 예외 떠넘기기 예제
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : 자연수가 아닙니다.";
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int comb(int n, int r) {
//	int a = fact(n);
//	int b = fact(r);
//	int c = fact(n - r);
//	return a / b / c;
//} // 조합(Combination) : nCr = n! / (r! * (n - r)!)  // 순열(Permutation) : nPr = n! / (n - r)!
//
//int main() {
//	int n, r;
//	try {
//		cout << "자연수 2개 입력 : ";
//		cin >> n >> r;
//		cout << comb(n, r) << endl;
//	}
//	catch (string& e) {
//		cout << e << endl;
//	}
//}


//ex13.7 try문 안에 반복문이 있는 경우
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : 자연수가 아닙니다.";
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int comb(int n, int r) {
//	int a = fact(n);
//	int b = fact(r);
//	int c = fact(n - r);
//	return a / b / c;
//}
//
//int main() {
//	int n, r;
//
//	try {
//		while (true) { // try 안에 루프가 있으면 루프 내에서 한 번이라도 예외가 발생하면 catch로 넘어가므로 루프를 빠져나가게 된다. (잘못된 입력이 들어왔을 때 에러메시지 출력한 후 종료)
//			cout << "자연수 2개 입력 : ";
//			cin >> n >> r;
//			cout << comb(n, r) << endl;
//		}
//	}
//	catch (const string& e) {
//		cout << e << endl;
//	}
//}


//ex13.8 반복문 안에 try-catch문이 있는 경우
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : 자연수가 아닙니다.";
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int comb(int n, int r) {
//	int a = fact(n);
//	int b = fact(r);
//	int c = fact(n - r);
//	return a / b / c;
//}
//
//int main() {
//	int n, r;
//	
//	while (true) { // 루프 안에 try-catch문 전체를 포함시킨다면 한 번 catch로 넘어간다고 해서 루프가 끝나지 않는다. (잘못된 입력이 들어왔을 때 에러메시지 출력한 후 다시 반복)
//		try {
//			cout << "자연수 2개 입력 : ";
//			cin >> n >> r;
//			cout << comb(n, r) << endl;
//		}
//		catch (const string& e) {
//			cout << e << endl;
//		}
//	}
//}


// 예외의 타입이 여러 가지라면 catch문을 여러 개 만들 수도 있다! (ex. 123을 throw하면 int를 받는 catch문이 실행되고, string("abc")를 throw하면 string을 받는 catch문이 실행되는 식이다. (명시적으로 string 객체를 던지지 않고 그냥 "abc"를 throw하면 const char*를 받는 catch문이 실행된다!))
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	int n;
//
//	try {
//		cin >> n;
//		if (n == 1)
//			throw 123; // 첫 번째 catch문 실행
//		if (n == 2)
//			throw string("abc");
//		if (n == 3)
//			throw "abc";
//	}
//	catch (int e) {
//		cout << e << endl;
//	}
//	catch (const string& e) { // string("abc") 객체를 받음
//		cout << e << endl;
//	}
//	catch (const char* e) { // "abc" 객체를 받음
//		cout << e << endl;
//	}
//}


// 어떠한 catch문에도 해당하는 타입이 없다면 예외가 받아지지 않고 바깥 함수(현재 함수를 호출했던 함수)로 떠넘겨진다. 하지만 main에서는 더 이상 떠넘길 바깥 함수가 없기 때문에 이렇게 예외를 받을 수 있는 catch문이 없는 경우에는 런타임 에러가 난다.
// 이렇게 catch문을 통해 잡히지 않은 예외는 catch(...)라는 특별한 구문을 사용하면 잡을 수 있다!!!
// catch(...) 구문을 사용한 예시
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	int n;
//
//	try {
//		cin >> n;
//		if (n == 1)
//			throw 123; // 첫 번째 catch문 실행
//		if (n == 2)
//			throw string("abc"); // 두 번째 catch문 실행
//		if (n == 3)
//			throw 3.14; // 세 번째 catch문 실행
//	}
//	
//	catch (int e) {
//		cout << e << endl;
//	}
//	catch (const string e) {
//		cout << e << endl;
//	}
//	catch (...) {
//		cout << "알 수 없는 예외 발생" << endl;
//	}
//}


// 13.3 auto (우변의 타입을 분명히 알아낼 수 있을 때 좌변의 타입을 말 그대로 자동으로(auto) 정해주는 키워드이다. (C++11 이후에서만 작동한다.)) (타입을 적으려면 복잡하거나 우변의 타입이 나중에 바뀌어서 귀찮아지는 것을 막기 위해 사용하면 좋다.)
// vector<pair<string, int>>::iterator it = v.begin(); // 다음과 같은 예시에서 매번 vector<pair<string, int>>::iterator 을 적어주기 어렵다.
// auto it = v.begin(); // 다음과 같이 auto로 바꾸어서 컴파일러가 자동으로 채우게 할 수 있는 장점이 있다.


// 범위 기반 for문에서도 auto를 사용하면 유용하다.
//#include <iostream>
//using namespace std;
//
//class Base {
//	int b;
//
//public:
//	void f() {
//		cout << "Base" << endl;
//	}
//};
//
//class Derived : public Base {
//	int d;
//
//public:
//	void f() {
//		cout << "Derived" << endl;
//	}
//};
//
//int main() {
//	int arr[7] = { 3, 1, 4, 1, 5, 9, 2 };
//	
//	for (int i : arr) {
//		cout << i << endl;
//	} // auto 키워드를 사용하지 않고 범위 기반 for문 사용
//	
//	for (auto i : arr) {
//		cout << i << endl;
//	} // auto 키워드를 사용한 범위 기반 for문 사용
//
//
//	// auto를 쓰면 안되는 상황 : 양변의 타입을 의도적으로 다르게 하는 경우
//	Derived d;
//	auto b = &d; // 우리가 의도한 것은 Base* b = &d; 이지만, auto를 사용하면 Derived* b = &d가 된다. 
//	b->f();
//} 
// 또, auto를 너무 많이 사용하면 코드를 읽는 사람이 각 변수의 타입이 무엇인지 알기 어려워지므로 남용하지 않는 것이 좋다.


// 13.4 함수 포인터, 함수 객체와 람다식
// 13.4.1 함수 포인터 (C와 C++에 존재) (Function pointer) : 함수를 가리키는 포인터 (함수도 메모리상 어딘가에 저장되기 때문에 주소값을 가지고 있고, 이 주소값을 함수 포인터에 저장할 수 있다!)
// 선언 방법 : bool (*fp) (int, int); <- int 2개를 매개변수로 받고, bool을 리턴하는 함수를 가리키는 포인터를 만들고, 그 포인터의 이름을 fp로 하겠다는 뜻이다. 
// 주의! bool *fp (int, int); <- int 2개를 매개변수로 받고, bool*를 리턴하는 함수의 프로토타입을 만드는 꼴이므로 함수 포인터를 선언할 때는 괄호를 까먹지 말고 적어야한다!


// int (*arrPtr)[10]; // 배열(을 가리키는) 포인터
// int *ptrArr[10]; // 포인터(로 이루어진) 배열
// bool (*fp)(int, int); // 함수(를 가리키는) 포인터
// bool *fp(int, int); // 포인터를 리턴하는 함수의 프로토타입


// 함수 포인터에 어떤 함수의 주소를 집어넣으려면 우변에 함수의 주소를 쓰면 된다. 함수의 주소를 가져오기 위해서는 함수 이름 앞에 &를 쓰면 되는데, &를 생략하고 그냥 함수의 이름만 써도 된다. (보통은 생략 하는 경우가 많다.)
// 다음으로 함수 포인터가 가리키는 함수를 실행하기 위해서는 함수 포인터를 역참조한 후, () 속에 원하는 인수를 집어넣으면 되는데, 이때도 역참조를 생략할 수 있다. (역참조는 괄호안에서 이루어져야한다.)
// 함수 포인터 사용 예시 1
//#include <iostream>
//using namespace std;
//
//bool compare(int a, int b) {
//	return (a == b); // a와 b가 같으면 true, 아니면 false 리턴
//}
//
//int main() {
//	bool (*fp)(int, int); // 함수 포인터 선언
//	
//	// 함수 포인터 정의하기
//	fp = &compare; // OK
//	fp = compare; // OK. 윗줄과 같은 의미
//
//	// 함수 포인터 사용하기
//	bool res1 = (*fp)(1, 3); // OK
//	bool res2 = fp(1, 3); // OK
//	//bool res3 = *fp(1, 3); // 에러!!! fp(1, 3)의 리턴 값을 역참조하라는 뜻이다! (이 예시의 경우 리턴값이 포인터 타입이 아니라 bool 타입이기 때문에 에러가 발생한다!)
//	
//	(*arrPtr)[1]; // arrPtr(배열 포인터)가 가리키는 배열의 1번 칸
//	*ptrArr[1]; // ptrArr(포인터 배열)의 1번 칸이 가리키는 것
//}

