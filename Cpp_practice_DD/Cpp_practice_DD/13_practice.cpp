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
//		cout << e << "(const string&)" << endl;
//	}
//	catch (const char* e) { // "abc" 객체를 받음
//		cout << e << "(const char*)" << endl;
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
//	catch (const string& e) {
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
//	for (int i = 0; i < 7; i++) {
//		cout << arr[i] << endl;
//	} // 기본 for문 사용
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
//} // 또, auto를 너무 많이 사용하면 코드를 읽는 사람이 각 변수의 타입이 무엇인지 알기 어려워지므로 남용하지 않는 것이 좋다.


// 13.4 함수 포인터, 함수 객체와 람다식
// 13.4.1 함수 포인터 (C와 C++에 존재) (Function pointer) : 함수를 가리키는 포인터 (함수도 메모리상 어딘가에 저장되기 때문에 주소값을 가지고 있고, 이 주소값을 함수 포인터에 저장할 수 있다!)
// 선언 방법 : bool (*fp) (int, int); <- int 2개를 매개변수로 받고, bool을 리턴하는 함수를 가리키는 포인터를 만들고, 그 포인터의 이름을 fp로 하겠다는 뜻이다. 
// 주의! bool *fp (int, int); <- int 2개를 매개변수로 받고, bool*를 리턴하는 함수의 프로토타입을 만드는 꼴이므로 함수 포인터와는 완전 다르다. 함수 포인터를 선언할 때는 괄호를 까먹지 말고 적어야한다!


 //int (*arrPtr)[10]; // 배열(을 가리키는) 포인터
 //int *ptrArr[10]; // 포인터(로 이루어진) 배열
 //bool (*fp)(int, int); // 함수(를 가리키는) 포인터
 //bool *fp(int, int); // 포인터를 리턴하는 함수의 프로토타입


// 함수 포인터에 어떤 함수의 주소를 집어넣으려면 우변에 함수의 주소를 쓰면 된다. 함수의 주소를 가져오기 위해서는 함수 이름 앞에 &를 쓰면 되는데, &를 생략하고 그냥 함수의 이름만 써도 된다. (보통은 생략 하는 경우가 많다.) (이 말인 즉슨, 함수의 이름 자체를 함수의 주소값으로도 쓸 수 있다는 것이다.)
// 다음으로 함수 포인터가 가리키는 함수를 실행하기 위해서는 함수 포인터를 역참조한 후, () 속에 원하는 인수를 집어넣으면 되는데, 이때도 역참조를 생략할 수 있다. (역참조는 괄호안에서 이루어져야한다.)
// 함수 포인터 사용 예시 1
//#include <iostream>
//using namespace std;
//
//bool compare(int a, int b) {
//////	return (a 
// == b);  // a와 b가 같으면 true, 아니면 false 리턴
//}
//
//int main() {
//	bool (*fp)(int, int); // 함수 포인터 선언
//	
//	// 함수 포인터 정의하기
//	//fp = &compare; // OK
//	fp = compare; // OK. 윗줄과 같은 의미
//
//	// 함수 포인터 사용하기
//	bool res1 = (*fp)(1, 3); // OK
//	bool res2 = fp(1, 3); // OK
//	//bool res3 = *fp(1, 3); // 에러!!! fp(1, 3)의 리턴 값을 역참조하라는 뜻이다! (이 예시의 경우 리턴값이 포인터 타입이 아니라 bool 타입이기 때문에 에러가 발생한다!)
//	
//	//(*arrPtr)[1]; // arrPtr(배열 포인터)가 가리키는 배열의 1번 칸
//	//*ptrArr[1]; // ptrArr(포인터 배열)의 1번 칸이 가리키는 것
//}


// 함수 포인터 사용 예시 2
//int arrMin(const int arr[], int n) {
//	int min = arr[0];
//	for (int i = 1; i < n; i++) {
//		if (min > arr[i])min = arr[i];
//	}
//	return min;
//} // 만약 제곱의 최소값을 찾고 싶다면? 세제곱의 최소값은? 네제곱은? ... <- 이럴 때 함수 포인터를 사용하면 편하다! (임의의 함수가(제곱, 세제곱, ...) 무엇인지를 함수 포인터의 형태로 매개변수로 넘기는 것이다!)


//ex13.9 함수 포인터를 사용해 배열의 각 칸에 임의의 함수를 적용한 값의 최소 찾기
//#include <iostream>
//using namespace std;
//
//int n_double(int n) { return n * 2; } // n의 2배를 리턴하는 함수
//int square(int n) { return n * n; } // n의 제곱을 리턴하는 함수
//int myFunc(int n) { return n * (n - 15) / 2; } // 어떤 다른 함수
//
//int arrFnMin(const int arr[], int n, int (*fp)(int)) {
//	//int min = fp(arr[0]);
//	int min = (*fp)(arr[0]);
//	for (int i = 1; i < n; i++) {
//		if (min > fp(arr[i])) min = fp(arr[i]);
//	}
//	return min;
//}
//
//int main() {
//	int arr[7] = { 3, 1, -4, 1, 5, 9, -2 };
//
//	cout << arrFnMin(arr, 7, n_double) << endl; // 2배의 최소
//	cout << arrFnMin(arr, 7, square) << endl; // 제곱의 최소 
//	cout << arrFnMin(arr, 7, &myFunc) << endl; // myFunc 함수를 적용한 것의 최소
//}


// 13.4.2 함수 객체 (Function object/Functor) : 함수처럼 작동하는 객체
//ex13.10 함수 객체 사용해보기
//#include <iostream>
//using namespace std;
//
//class Equals { // 함수 객체 선언
//public:
//	Equals(int value) : value(value) {}
//	bool operator()(int x) const { // () 연산자 오버로딩을 통해서 함수처럼 사용 가능함
//		return x == value;
//	}
//
//private:
//	int value;
//};
//
//int main() {
//	Equals eq(123);
//
//	cout << eq(123) << endl; // 함수 객체를 통해 객체를 함수처럼 사용가능하다.
//	cout << eq(12) << endl;
//}


// 함수 객체 사용해보기 2
//#include <iostream>
//using namespace std;
//
//class Equals {
//public:
//	Equals(int value) : value(value) {}
//	
//	bool operator()(int x) const {
//		return x == value;
//	}
//	bool operator()(int x, int y) const {
//		return x == value && y == value;
//	}
//
//private:
//	int value;
//};
//
//int main() {
//	Equals eq(123);
//	
//	cout << eq(123) << endl;
//	cout << eq(12) << endl;
//
//	cout << eq(123, 123) << endl;
//	cout << eq(113, 113) << endl;
//	cout << eq(123, 12) << endl;
//} // 함수 포인터는 단순히 한 가지 함수만 가리킬 수 있지만, 함수 객체를 사용하면 이렇게 여러 변종의 함수를 만들 수 있다. (함수 포인터 하나를 가지고 여러 오버로딩된 함수를 가리킬 수는 없다.(함수 포인터를 만들 때는 가리킬 함수의 리턴 타입과 매개변수 목록을 알아야 하기 때문이다.))
// 하지만 함수 객체를 사용하면 한 가지 이름(eq)만을 사용해 여러 오버로딩된 함수를 실행할 수도 있다는 장점이 있다.


//ex13.11.1 함수 객체를 사용해 바꿔본 예제 13.9 (부모 클래스를 직접 만들어 동적 다형성을 이용하는 방법) (RTTI가 동반된다.)
//#include <iostream>
//using namespace std;
//
//struct Func { // 함수를 나타내는 상위 추상 클래스
//	virtual int operator()(int n) const = 0;
//};
//
//struct Square : Func { // n의 제곱을 나타내는 클래스
//	int operator()(int n) const { return n * n; }
//};
//
//struct MyFunc : Func { // 어떤 다른 함수를 나타내는 클래스
//	int operator()(int n) const { return n * (n - 15) / 2; }
//};
//
//int arrFnMin(const int arr[], int n, const Func& f) { // 래퍼런스를 받는 것도 가능하다.
//	int min = f(arr[0]);
//	for (int i = 0; i < n; i++) {
//		if (min > f(arr[i])) min = f(arr[i]);
//	}
//	return min;
//}
//
//int main() {
//	int arr[7] = { 3, 1, -4, 1, 5, 9, -2 };
//
//	Square square;
//	MyFunc myfunc;
//
//	cout << arrFnMin(arr, 7, square) << endl;
//	cout << arrFnMin(arr, 7, myfunc) << endl;
//}


//ex13.11.2 함수 객체를 사용해 바꿔본 예제 13.9 (function 내장 클래스 템플릿을 이용하는 방법 (C++11부터 가능하다.))(하지만 이 방법은 성능에 좋지 않으므로 추천하지 않는다.)
//#include <iostream>
//#include <functional> // function을 사용하기 위해 필요
//using namespace std;
//
//struct Square { // 함수 객체
//	int operator()(int n) const { return n * n; }
//} square_ob; // 함수 객체 선언과 동시에 만드는 방법
//
//int square_fn(int n) {
//	return n * n;
//} // 심지어 함수 포인터도 function<int(int)> 타입의 객체로 넘길 수 있다.
//
//int arrFnMin(const int arr[], int n, const function<int(int)>& f) { // function 내장 클래스 템플릿 이용 (int을 리턴하고 int를 매개변수로 받는 어떤 함수 객체든지 이 타입을 가지고 받을 수 있다!)
//	int min = f(arr[0]);
//	for (int i = 0; i < n; i++) {
//		if (min > f(arr[i])) min = f(arr[i]);
//	}
//	return min;
//}
//
//int main() {
//	int arr[7] = { 3, 4, -4, 2, 5, 9, -2 };
//	//Square square_ob; // 함수 객체 선언
//
//	cout << arrFnMin(arr, 7, square_ob) << endl; // 함수 객체
//	cout << arrFnMin(arr, 7, square_fn) << endl; // 함수 포인터
//}


//ex13.11.3 함수 객체를 사용해 바꿔본 예제 13.9 (템플릿으로 정적 다형성을 사용한 방법) (제일 빠르다.)
//#include <iostream>
//using namespace std;
//
//template<typename Fn_t>
//int arrFnMin(const int arr[], int n, const Fn_t& f) { // f의 소괄호 연산이 가능하기만 하다면 (함수 객체(operator()), 함수, 함수포인터 등등...), 어떠한 타입이든 받을수 있는 것이다.
//	int min = f(arr[0]);
//	for (int i = 0; i < n; i++) {
//		if (min > f(arr[i])) min = f(arr[i]);
//	}
//	return min;
//}
//
//int square(int n) {
//	return n * n;
//}
//
//int MyFunc(int n) {
//	return n * (n - 15) / 2;
//}
//
//int main() {
//	int arr[7] = { 1, 3, -4, 1, 5, 9, -2 };
//
//	cout << arrFnMin(arr, 7, square) << endl;
//	cout << arrFnMin(arr, 7, MyFunc) << endl;
//}


// 13.4.3 람다식 (Lambda expression / Anonymous function) (C++11에서 새로 등장하였다.) : 특별히 붙여진 이름 없이 본문만 존재하는 함수이다. 따라서 등호의 좌변으로 대입되거나 함수의 인수로 넘겨져야만 사용할 수 있다. 
// 람다식의 일반적인 형태 : [캡쳐] (매개변수_목록) -> 리턴_타입 { 함수_본문 }  // 캡쳐(capture)는 개시자(introducer)라고도 한다. (캡쳐는 람다식이 정의된 외부 환경을 람다식 안에서 사용하고 싶을 때 사용한다.)
// 리턴_타입이 void일때는 -> 리턴_타입을 생략할 수 있다. : [캡쳐] (매개변수_목록) { 함수_본문 }
// 리턴_타입과 매개변수_목록이 void일 경우는 (매개변수_목록) -> 리턴_타입도 생략할 수 있다. : [캡쳐] { 함수_본문 }
// 람다식 사용 : [캡쳐] (매개변수_목록) -> 리턴_타입 { 함수_본문 } (매개변수);
// 람다식의 타입은 함수 객체 타입이다! (분명 타입이 있지만 이름이 없기 때문에 그 타입 자체를 "이거다"라고 얘기할 수는 없다. 따라서 람다식을 어딘가에 대입할 때는 그 람다식이 변환될 수 있는 다른 타입을 사용하거나 auto 키워드를 사용해야 한다.)
// 람다식은 function 타입이나 함수 포인터로도 변환될 수 있다. (단, 함수 포인터로 변환되기 위해서는 캡쳐가 비어있어야한다.)
 //function<int(int)> fa = [](int n) -> int { return n * n; }; // function 타입 객체
 //int (*fb) (int)       = [](int n) -> int { return n * n; }; // 함수 포인터
 //auto fc               = [](int n) -> int { return n * n; }; // auto

//ex13.12 람다식을 사용해 고쳐본 예제 13.9
//#include <iostream>
//using namespace std;
//
//template<typename Fn_t>
//int arrFnMin(const int arr[], int n, Fn_t f) {
//	int min = f(arr[0]);
//	for (int i = 1; i < n; i++) {
//		if (min > f(arr[i])) min = f(arr[i]);
//	}
//	return min;
//}
//
//int main() {
//	int arr[7] = { 3, 1, -4, 1, 5, 9, -2 };
//	
//	cout << arrFnMin(arr, 7, [](int n)->int {return n * n; }) << endl;
//	cout << arrFnMin(arr, 7, [](int n)->int {return n * (n - 15) / 2; }) << endl;
//}


// 람다 함수와 std::function, std::bind, for_each
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//using namespace std;
//
//void goodbye(const string& s) {
//	cout << "Goodbye " << s << endl;
//}
//
//
//class Object {
//public:
//	void hello(const string& s) {
//		cout << "Hello " << s << endl;
//	}
//};
//
//int main() {
//	// lambda-introducer
//	// lambda-parameter-declaration
//	// lambda-return-type-clause
//	// compound-statement
//	auto func = [](const int& i) -> void { cout << "Hello, world!" << endl; };
//	func(123);
//
//	[](const int& i) -> void { cout << "Hello, world! 2" << endl; } (1234);
//
//	{
//		string name = "JackJack";
//		[&name]() { cout << name << endl; } (); 
//		// [this]() { cout << name << endl; } (); // 클래스의 멤버를 정의할 때
//		[&]() { cout << name << endl; } (); // 래퍼런스
//		[=]() { cout << name << endl; } (); // 복사
//	}
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//
//	auto func2 = [](int val) { cout << val << endl; };
//	for_each(v.begin(), v.end(), func2); // algorithm 헤더 안에 정의된 for_each 사용
//	for_each(v.begin(), v.end(), [](int val) { cout << val*100 << endl; });
//
//	cout << []() -> int { return 44; }() << endl;
//
//	// std::function
//	std::function<void(int)> func3 = func2;
//	func3(123);
//
//	// std::bind
//	std::function<void()>func4 = std::bind(func3, 456);
//	func4();
//
//	{
//		Object instance;
//		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1); // bind(멤버 함수, 객체, 매개변수)
//
//		f(string("World"));
//
//		auto f2 = std::bind(goodbye, std::placeholders::_1); // bind(함수, 매개변수)
//
//		f2(string("World"));
//	}
//}


// std::bind, std::placeholder 더 알아보기
// std::bind(함수의 주소, 인자1, 인자2, ...);
//#include <iostream>
//#include <functional>
//using namespace std;
//
//void hello(const string& s){
//	cout << s << endl;
//}
//int main() {
//	auto func_1 = std::bind(hello, "Hello world");
//	func_1();
//}


// std::placeholder
//#include <iostream>
//#include <functional>
//using namespace std;
//
//int sum_1(int a, int b, int c) {
//	return a + b + c;
//}
//int sum_2(int a, int b, int c) {
//	return a + b * 10 + c;
//}
//int sum_3(int a, int b, int c) {
//	return a + b * 10 + c * 100;
//}
//
//int main() {
//	auto func_1 = std::bind(sum_1, std::placeholders::_1, 2, 3);
//	cout << func_1(1) << endl; // 1 + 2 + 3 = 6
//	auto func_2 = std::bind(sum_2, std::placeholders::_1, std::placeholders::_2, 3);
//	cout << func_2(2, 3) << endl; // 2 + 3 * 10 + 3 = 35 
//	auto func_3 = std::bind(sum_3, 1, std::placeholders::_2, std::placeholders::_1);
//	/*func_3에서 sum_3의 첫번째 인자는 이미 1로 고정 나머지 두 인자는 placeholder로 설정 됨
//	func_3의 첫번째 인자는 원래 함수 sum_3의 세번째 인자가 되고
//	func_3의 두번째 인자는 원래 함수 sum_3의 두번째 인자가 되고
//	즉, 고정되지 않은 남은 인자들의 순서를 palceholder로 변경할 수 있음*/
//	cout << func_3(2, 3); // 1 + 3 * 10 + 2 * 100 = 231
//}


//13.5 friend : 상속이 클래스 간의 부모 관계라면 C++에는 친구 관계도 있다. 
// friend를 사용하면 public, protected, private 세 가지 접근 제어자를 무시하고 현재 클래스의 모든 멤버를 특정 대상에게 모두 공개할 수 있다! (이때 공개할 대상은 다른 클래스가 될 수도 있고, 함수가 될 수도 있다.)


// friend가 없는 상황
//#include <iostream>
//using namespace std;
//
//class A {
//	void fa() {}
//};
//
//class B {
//	void fb() {
//		A a;
//		a.fa(); // 에러!
//	}
//}; // class의 기본 접근 제어는 private이므로 B::fb() 메서드에서 a.fa()를 호출하려고 하면 에러가 발생한다.


// friend를 사용하여 특별히 B에서만 A의 멤버에 접근하는 것을 허용할 수 있다.
//#include <iostream>
//using namespace std;
//
//class A {
//	friend class B; // B라는 클래스에서 내 멤버에 접근하는 것은 허용한다.
//	void fa() {}
//};
//
//class B {
//	void fb() {
//		A a;
//		a.fa(); // OK
//	}
//};
//
//int main() {
//	
//}


// 다른 함수에게도 접근을 허용할 수도 있다.
//#include <iostream>
//using namespace std;
//
//class A {
//	friend void fg(); // fg라는 함수에서 A의 멤버에 접근하는 것이 허용된다.
//	void fa() {}
//};
//
//void fg() {
//	A a;
//	a.fa(); // OK
//}
//
//int main() {
//
//}


// 13.6 메모리 소유권과 스마트 포인터 : 스마트 포인터는 오로지 동적 할당된 객체에 대한 메모리 해제를 자동으로 해주기 위해 등장하였다.
// 13.6.1 메모리 소유권 (Memory ownership) (메모리 소유권이란 어떠한 문법적인 것이 아니라 의미론적인 개념이다.)
// 메모리 소유권 예시
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a, * b;
//	a = new int(5); // 동적 할당을 a에게 하였으므로 a라는 포인터에게는 어떤 동적 할당된 객체의 주솟값을 받아서 단순히 가리키는 역할뿐만 아니라
//	// 특정 시기가 될 때까지 객체를 가리키는 상태를 유지하다가 객체를 다 사용하고 나면 안전하게 소멸시킬 의무가 있다. 이럴 때 a가 객체를 소유하고 있다고 말한다.
//	b = a; // b는 객체를 "소유"하고 있는것이 아니다. b는 단지 그 객체를 참조하기만 했을 뿐, b가 객체의 생성과 소멸에 관여하지 않는 상황이고, 관여해서도 안된다.
//	// 그렇기 때문에 delete b;를 하면 오히려 안되는 것이다. (의미론적으로는 안된다는 것이다. 문법적으로는 가능.) 
//	// 그런데 필요에 따라서는 소유권을 "이전"해야 할 수도 있다.
//	cout << *b << endl;
//	delete a;
//}


// 메모리 소유권을 이전하는 예시
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a, * b;
//	a = new int(5);
//	b = a; // b에게 소유권을 이전 (a가 메모리를 관리하고 있다가 b에게 소유권을 이전하였다.)
//	cout << *b << endl;
//	delete b; // b에게 소유권을 이전하였기 때문에 b를 통해서 객체를 소멸시켜준다.
//} // 코드의 바뀐 부분은 delete b; 밖에 없다. 하지만 소유권은 이동하였다고 한다. 즉, 어떤 포인터가 객체를 소유하고 있는지는 오로지 그 코드를 짠 사람만 알고 있다는 뜻이기도 하다.
// 하지만, 스마트 포인터를 사용하면 이런 소유권에 대한 문제를 일반 포인터보다 체계적으로 관리하고, 문법적인 차원에서 다룰 수 있다. 
// 스마트 포인터의 종류로는 unique_ptr, shared_ptr, weak_ptr 총 세 종류가 있다.


// 13.6.2 unique_ptr (유일한 포인터) : unique_ptr에는 복사 생성자나 복사 대입 연산자를 사용할 수 없다.
// unique_ptr 설명
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	unique_ptr<int> a(new int(5)); // unique_ptr 초기화 방법
//	//unique_ptr<int> b = new int(5); // 에러! unique_ptr의 변환 생성자가 explicit으로 선언되어 있기 때문에 에러가 발생한다!
//	unique_ptr<int> e(new int(5));
//	
//	cout << *a << endl; // 다음과 같이 일반 포인터와 비슷하게 사용할 수 있다.(* 연산자가 unique_ptr에 오버로딩되어 있기 때문이다.) a가 구조체나 클래스 타입을 가리키고 있다면 ->연산자도 사용할 수 있다.
//	
//	// 하지만 a 자체에 새로운 무언가를 대입하거나 a를 다른 포인터에 대입할 수는 없다. (a가 가리키는 객체는 반드시 a만 가리켜야 하기 때문이다.)
//	//int* c = a; // 에러! unique_ptr은 다른 곳에 대입할 수 없다.
//	//unique_ptr<int> d = a; // 에러! 좌변이 unique_ptr이라 할지라도 대입할 수 없다.
//	//a = new int(7); // 에러! unique_ptr에 새로운 주솟값을 대입할 수는 없다.
//
//	// 하지만 unique_ptr에서도 소유권을 이전할 수 있는 방법은 존재한다! 바로 release라는 메서드를 쓰는 것!
//
//	// aa가 가지고 있던 소유권을 bb에게 이전한 예시
//	unique_ptr<int> aa(new int(5));
//	unique_ptr<int> bb(aa.release()); // aa가 가지고 있던 소유권을 bb에게 이전!
//	// 이렇게 되면 aa는 더 이상 객체를 가리키지 않게 되고, 오직 bb만이 그 객체를 가리키게 된다.
//
//	// unique_ptr은 선언된 스코프가 끝나든지 해서 그 포인터(a, aa..)가 소멸되면 그 포인터가 가리키는 객체는 알아서 소멸된다. (일반 포인터와는 다른 부분)
//
//	// unique_ptr이 가리키는 객체를 중간에 바꾸는 방법 : reset이란 메서드를 사용한다!
//	unique_ptr<int> aaa(new int(5));
//	aaa.reset(new int(7)); // 원래 가리키고 있던 객체의 메모리를 해제한 후 새로 할당된 객체를 가리키게 된다.
//	aaa.reset(NULL); // aaa가 아무 객체도 가리키지 않는 NULL 포인터인 상태가 된다.
//	aaa.reset(); // aaa가 아무 객체도 가리키지 않는 NULL 포인터인 상태가 된다.
//}


//ex13.13 unique_ptr 사용하기
//#include <iostream>
//#include <memory> // 스마트 포인터가 선언된 라이브러리
//using namespace std;
//
//class MyClass {
//public:
//	MyClass(int x) : x(x) {
//		cout << "MyClass(int)" << endl;
//	}
//	~MyClass()
//	{
//		cout << "~MyClass()" << endl;
//	}
//	int GetX() const { return x; }
//
//private:
//	int x;
//};
//
//int main() {
//	unique_ptr<MyClass> a(new MyClass(5));
//	cout << a->GetX() << endl;
//	cout << "=== 1 ===" << endl;
//	a.reset(new MyClass(7));
//	cout << a->GetX() << endl;
//	cout << "=== 2 ===" << endl;
//	a.reset(); // a가 가리키던 객체만 해제하고 아무것도 가리키지는 않음
//	cout << "=== 3 ===" << endl;
//	a.reset(new MyClass(9));
//	cout << "=== 4 ===" << endl;
//}


// 13.6.3 shared_ptr (공유 포인터) : unique_ptr과는 다르게 여러 포인터가 한 객체를 가리킬 수 있다. (즉, 한 객체를 여러 포인터가 공유(share)할 수 있다.
// shared_ptr은 현재 정확히 몇 개의 포인터가 그 객체를 가리키고 있는지를 내부에서 추가적으로 기록하고 있다.  (use_count라는 메서드가 이 역할을 한다.)
// 포인터가 소멸될 때도 객체를 가리키는 포인터가 그 외에 하나라도 남아있다면 객체를 소멸시키지 않고, 그 객체를 가리키는 마지막 포인터까지 소멸되고 나서야 그 객체도 소멸된다.
// 따라서 shared_ptr도 delete를 해야 할지 말지 걱정하지 않아도 된다.
// shared_ptr의 핵심은 소유권이 한 포인터에 한정되어 있지 않다는 것이다. (일반 포인터를 사용한다면, 많은 포인터 중 정확히 한 포인터가 반드시 메모리 해제를 담당해야 하기 때문에 그 임무를 담당할 포인터가 그중 어떤 것인지를 잘 정해야 한다.)
// 하지만 shared_ptr을 사용하면 객체를 가리키는 포인터가 하나도 남지 않는 순간을 탐지하여 자동으로 객체를 삭제하므로 누가 객체 삭제를 담당할 것인지를 처음부터 정할 필요가 없게 된다.)


//ex13.14 shared_ptr 사용해 보기
//#include <iostream>
//#include <memory>
//using namespace std;
//
//class MyClass {
//private:
//	int x;
//	
//public:
//	MyClass(int x) : x(x) {
//		cout << "MyClass(int)" << endl;
//	}
//	~MyClass()
//	{
//		cout << "~MyClass()" << endl;
//	}
//
//	int GetX() const { return x; }
//};
//
//int main() {
//	shared_ptr<MyClass> a(new MyClass(5)); // use_count의 값이 1이 된다.
//	{
//		shared_ptr<MyClass> b = a; // use_count의 값이 2가 된다.
//		cout << a->GetX() << endl;
//		cout << b->GetX() << endl;
//		cout << a.use_count() << endl;
//		cout << b.use_count() << endl;
//	} // b가 소멸되어 use_count의 값이 1로 바뀌게 된다.
//	cout << a->GetX() << endl;
//	cout << a.use_count() << endl;
//} // a가 소멸되어 use_count의 값이 0으로 바뀌게 되고, 가리키던 객체가 소멸자가 호출된다.


//ex13.15 shared_ptr에서 reset 메서드 사용하기
//#include <iostream>
//#include <memory>	
//using namespace std;
//
//class MyClass {
//private:
//	int x;
//
//public:
//	MyClass(int x) : x(x) {
//		cout << "MyClass(int)" << endl;
//	}
//	~MyClass()
//	{
//		cout << "~MyClass()" << endl;
//	}
//
//	int GetX() const { return x; }
//};
//
//int main() {
//	shared_ptr<MyClass> a(new MyClass(5));
//	cout << "=== 1 ===" << endl;
//	{
//		cout << a.use_count() << endl;
//		shared_ptr<MyClass> b = a;
//		cout << b.use_count() << endl;
//		a.reset(); // use_count가 1이 되어버리게 된다.
//		cout << b.use_count() << endl;
//		cout << "=== 2 ===" << endl;
//	} // 스코프가 끝나고 b가 소멸되면서, use_count가 0이 되어버리게 되므로 객체가 소멸된다.
//	cout << "=== 3 ===" << endl;
//}


// 13.6.4 weak_ptr : weak_ptr은 shared_ptr이 가리키는 객체를 똑같이 가리킬 수는 있지만 소유하지는 않는 포인터이다. 소유하지 않는다는 말은 소멸에 관여하지 않는다는 뜻이고, 따라서 weak_ptr이 어떤 객체를 가리켜도 그 객체를 참조하기만 할 뿐 use_count의 값이 바뀌지는 않는다.
// ex
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//	cout << a.use_count() << endl; // 1 출력
//	cout << b.use_count() << endl; // 1 출력
//}


// weak_ptr은 객체에 대한 소유권이 없기 때문에 지금 가리키는 대상이 이미 소멸되었을 가능성이 있다!
// ex
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//	cout << *a << endl;
//	//cout << *b << endl; // weak_ptr은 위에 이유(소멸 가능성) 때문에 바로 역참조 연산자를 사용할 수 없다! (expire과 lock이라는 메서드를 사용해야함)
//	cout << b.use_count() << endl; // 1 출력
//	a.reset(); // use_count 값이 0이 되어버리므로 객체가 소멸된다.
//	cout << b.use_count() << endl; // 0 출력
//}

// weak_ptr 역참조 하는 방법
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//	
//	cout << *b.lock() << endl; // weak_ptr 역참조 하는 방법
//
//	//a.reset(); // 객체 소멸
//	if (!b.expired()) {
//		cout << *b.lock() << endl;
//	}
//	else {
//		cout << "객체가 이미 소멸되었다!" << endl;
//	}
//}


// weak_ptr은 객체를 가리키고 싶지만 소유권은 필요 없을 때 사용한다. (보통 이런 경우는 현재 가리키는 대상이 weak_ptr을 통해 역참조하는 것보다 늦게 사라진다는 것이 보장되는 상황이다.)
// ex
//#include <iostream>
//#include <memory>
//using namespace std;
//
//void print(weak_ptr<int> x) {
//	cout << *x.lock() << endl;
//}
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	print(a); // 최소한 print 함수가 실행되는 동안은 x가 가리키는 객체가 살아있다는 것이 보장된다.
//}


// 13.7 STL (Standard Template Library) (표준 템플릿 라이브러리) : STL에는 프로그래밍을 편하게 해주기 위한 여러 클래스와 함수가 있다. (이름에서 알 수 있듯이, STL의 근간은 템플릿이다.)
// STL은 컨테이너, 알고리즘, 이터레이터 등으로 이루어져 있다. (ex. 컨테이너 : vector, pair, map, ... / 알고리즘 : sort, ...)


//13.7.1 vector (수학에서의 벡터와는 조금 다르다. vector는 배열과 비슷하지만, 배열과는 다르게 칸수가 고정되어 있지 않다.(vector는 필요에 따라 칸수가 자동으로 늘어나거나 줄어든다.))
// vector를 사용하려면 #include <vector>를 인클루드해야 한다.
// 벡터를 만드는 방법 : vector<int> vec; // int를 저장하는 vector vec를 만듬
// 벡터를 처음 만들면 비어 있다. 새로운 값을 벡터에 집어넣으려면 push_back 메서드를 실행하면 된다. 이 메서드는 벡터의 맨 끝에 새로운 원소를 추가하는 메서드이다.
// vec.push_back(1); {1}
// vec.push_back(2); {1, 2}
// vec.push_back(3); {1, 2, 3}

// C++11부터는 벡터를 처음 만들 때부터 초기화 리스트를 사용해 여러 원소를 배열처럼 한꺼번에 초기화할 수 있다.
// ex
// vector<int> vec = { 1, 2, 3 };

// vector에는 []연산자가 오버로딩되어 있기 때문에 벡터를 사용할 때는 배열과 같은 방법으로 사용할 수 있다.
// ex
//cout << vec[0] << endl; // 값 가져오기
//vec[1] = 5; // 새로운 값 대입

// vector는 배열과 마찬가지로 범위 기반 for문을 사용할 수 있다.
//for (int vi : vec) {
//	cout << vi << endl;
//}

// vector를 포함한 STL 컨테이너의 특징은 깊은 복사가 가능하다는 것이다.
// vector<int> vec2 = vec; // vec의 모든 내용물이 깊은 복사됨

// 따라서 벡터 안의 내용물이 많을수록 깊은 복사를 하는 데 시간이 오래 걸린다. 그렇기 때문에 벡터를 다른 함수로 넘겨줄 때 래퍼런스로 넘겨주는 것이 가능하다면 반드시 그렇게 해주는 것이 좋다
// ex
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const void print(const vector<int>& v) {
//	for (int vi : v) cout << vi << endl;
//}
//
//int main() {
//	vector<int> vec = { 1, 2, 3 };
//	print(vec);
//}


// 13.7.2 pair (두 값을 순서쌍처럼 묶어놓을 수 있는 컨테이너이다. (이때 두 값의 타입이 달라도 된다.))
// pair를 사용하려면 #include <utility>를 인클루드해야 한다.

//pair<int, string> a = { 123, "abc" }; // int와 string을 묶은 pair a를 만들고, 거기에 각각 123과 "abc"라는 문자열을 집어넣으라는 뜻이다.
// a의 앞쪽 원소를 의미할 때는 a.first, 뒤쪽 원소를 의미할 때는 a.second라고 적으면 된다.

// 값을 가져오거나 새로운 값을 집어넣을 수도 있다.
// ex
//cout << a.first << endl; // 123 출력
//a.second = "def"; // 새로운 값 집어넣기

// 세 값 이상을 묶을 때 사용할 수 있는 컨테이너도 있다!


// 13.7.3 map (다른 언어에서는 보통 사전(dictionary)으로 알려져 있는 기능이다. (어떤 값을 넣으면 그것에 해당하는 다른 값을 돌려준다.))
// 이때 넣는 값을 키(key)라고 부르고, 키를 넣었을 때 나오는 값을 밸류(value)라고 부른다. (즉, 맵은 키와 밸류의 쌍으로 이루어진 집합이라고 할 수 있다.)
// map을 사용하려면 #include <map>을 인클루드해야 한다.

// 키는 중복될 수 없지만, 밸류는 중복될 수 있다!!!
// 키끼리는 크기 비교가 가능해야 한다!!! (즉, 키를 가지고 '<'(부등호) 연산이 가능해야 한다.) (크기 비교가 불가능한 경우엔 unordered_map이라는 것을 사용한다.)
// ex (과일의 이름 -> 키, 그 과일의 개수 -> 밸류)
//#include <iostream>
//#include <map>
//using namespace std;
//
//int main() {
//	map<string, int> fruitCnt; // 템플릿 파라미터는 보통 두 개이며, 앞쪽에는 키의 타입, 뒤쪽에는 밸류의 타입을 적는다.
//
//	// 새로운 키를 추가하는 방법 
//	fruitCnt["apple"] = 7; // 단순히 새로운 키에 새로운 밸류를 넣으면 된다. (배열과 비슷하다.(인덱스 대신 키를 넣으면 된다.))
//	fruitCnt["banana"] = 4;
//	fruitCnt["orange"] = 10;
//
//	// 키("banana")의 밸류("banana"의 갯수)가 알고 싶다면?
//	cout << fruitCnt["banana"] << endl; // 바나나의 개수 출력 (배열의 원소를 가져오듯이 쓰면 된다.)
//	
//	// 없는 키에 해당하는 밸류를 가져오려고 하면 0을 반환하고, 키를 생성한 후 0으로 저장한다!!!
//	cout << fruitCnt["grape"] << endl; 
//
//	// 맵의 모든 원소를 범위 기반 for문으로 훑을 수도 있다.(이때는 키의 크기 순서대로 훑는다.)
//	// string도 크기를 비교할 수 있으며, 사전순으로 앞서는 것이 더 작다!
//	for (pair<string, int> fi : fruitCnt) {
//		cout << fi.first << ": " << fi.second << "개" << endl;
//	}
//}


// 13.7.4 sort (배열 따위의 원소들을 크기순으로 정렬하는 함수이다. 정렬 방법에는 각 방법마다 효율도 제각각이고, 어떤 정렬 방법을 사용할지는 컴파일러에게 달려있는데, 일단은 일반인이 생각해낼 수 있는 수준 이상으로 빨리 정렬된다고는 이야기할 수 있다.(그러니 정렬이 필요할 때 적극적으로 사용하자!))
// sort를 사용하려면 #include <algorithm>을 인클루드해야 한다.
// 배열을 정렬하기 위해서는 sort 함수에 배열의 시작을 가리키는 포인터와 끝을 가리키는 포인터를 넣는다. (이때, 끝을 가리키는 포인터는 가장 마지막 원소를 가리키는 포인터보다 하나 더 커야 한다.)
// ex1 (배열을 정렬하는 예시)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int arr[7] = { 7, 6, 5, 4, 3, 2, 1 };
//	sort(arr, arr + 5);  // arr+0 이상, arr+n 미만까지 범위의 배열의 원소 값들을 정렬한다. (배열이 바뀌게 된다)
//	for (int ai : arr) {
//		cout << ai << endl;
//	}
//
//	cout << endl; 
//
//	int arr_re[7] = { 3, 1, 4, 1, 5, 9, 2 };
//	sort(arr_re, arr_re + 7);  // arr+0 이상, arr+n 미만까지 범위의 배열의 원소 값들을 정렬한다. (배열이 바뀌게 된다)
//	for (int ai : arr_re) {
//		cout << ai << endl;
//	}
//}


// ex2 (vector를 정렬하는 예시)
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	vector<int> vec = { 3, 1, 4, 1, 5, 9, 2 };
//	sort(vec.begin(), vec.end()); // begin()은 vector의 시작 원소의 주소값을, end()은 vector의 마지막 원소 + 1의 주소값을 가리킨다.
//
//	for (int vi : vec) {
//		cout << vi << endl;
//	}
//}


// 종합문제
// 1번
//#include <iostream>
//using namespace std;
//
//double f1(double x) {
//	return x * x / 10;
//}
//
//double f2(int n) {
//	return (double)n * n / 10;
//}
//
//template<typename V_t>
//void printFnVal(V_t f, int st, int en) {
//	for (int i = st; i <= en; i++) {
//		cout << f(i) << endl;
//	}
//}
//
//int main() {
//	printFnVal(f1, 0, 10);
//	printFnVal(f2, 0, 10);
//}


// 2번
#include <iostream>
using namespace std;

// ※ 함수 포인터 배열 (함수 포인터로 이루어진 배열)
int (*OPS[4])(int, int) = {
	[](int a, int b) -> int {return a + b; },
	[](int a, int b) -> int {return a - b; },
	[](int a, int b) -> int {return a * b; },
	[](int a, int b) -> int {return a / b; }
};

int main() {
	int op;
	int a, b;

	cout << "연산의 종류 입력 (0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈) : ";
	cin >> op;
	cout << "정수 2개 입력 : ";
	cin >> a >> b;

	cout << OPS[op](a, b) << endl;
}