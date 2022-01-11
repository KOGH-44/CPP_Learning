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
//		if (level >= minLevel) {
//			doLogJob(s, level);
//		}
//	}
//
//	int GetMinLevel() const { return minLevel; }
//
//protected:
//	virtual void doLogJob(const string& s, int level) = 0;
//
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
//void testLogger(Logger& logger) {
//	logger.Log("abc", LogLevels::ERROR);
//	logger.Log("def", LogLevels::INFO);
//	logger.Log("ghi", LogLevels::WARNING);
//}
//
//int main() {
//	ConsoleLogger c(LogLevels::WARNING);
//	testLogger(c);
//
//	FileLogger f(LogLevels::DEBUG, "log.txt");
//	testLogger(f);
//}


//#include <iostream>
//using namespace std;
//
//class IPerson {
//public:
//	~IPerson() {}
//
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
//	}
//	void Study() {
//		cout << "공부한다..." << endl;
//	}
//	void Work() {
//		cout << "일한다..." << endl;
//	}
//	
//	void SetAge(int age) {
//		this->age = age;
//	}
//	int GetAge() {
//		return age;
//	}
//private:
//	int age;
//};
//
//int main() {
//	Researcher r;
//	r.Eat();
//	r.Study();
//	r.Work();
//	r.SetAge(20);
//	cout << r.GetAge() << endl;
//
//	IPerson* p = new Researcher;
//	IStudent* s = new Researcher;
//	IWorker* w = new Researcher;
//
//	p->Eat();
//	s->Study();
//	w->Work();
//
//	p->SetAge(20);
//	s->SetAge(20);
//	w->SetAge(25);
//	
//	delete p;
//	delete s;
//	delete w;
//}


//functor / function object
//#include <iostream>
//using namespace std;
//
//class Equals {
//public:
//	Equals(int value) : value(value) {}
//	
//	bool operator()(int x) {
//		return x == value;
//	}
//
//private:
//	int value;
//};
//
//class Plus {
//public:
//	int operator()(int x, int y) {
//		return x + y;
//	}
//};
//
//class Minus {
//public:
//	int operator()(int x, int y) {
//		return x - y;
//	}
//};
//
//int main() {
//	Equals eq(111);
//	Plus plus;
//	Minus minus;
//
//	cout << eq(111) << endl;
//	cout << eq(11) << endl;
//	cout << plus(123, 321) << endl;
//	cout << minus(333, 53) << endl;
//}


// functor/function object 2
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
//
//	bool operator()(int x, int y) const {
//		return (x + y) == value;
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
//	cout << eq(1, 122) << endl;
//	cout << eq(111) << endl;
//}


// functor를 사용하여 바꿔본 예제 (함수 포인터 대신 functor를 사용)
//#include <iostream>
//using namespace std;
//
//class Func {
//public:
//	virtual int operator()(int n) const = 0;
//};
//
//struct Square : public Func {
//	int operator()(int n) const {
//		return n * n;
//	}
//};
//
//struct MyFunc : public Func {
//	int operator()(int n) const {
//		return n * (n - 15) / 2;
//	}
//};
//
//int arrFnMin(const int arr[], int n, const Func& f) {
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
//	Square square;
//	MyFunc myfunc;
//
//	cout << arrFnMin(arr, 7, square) << endl;
//	cout << arrFnMin(arr, 7, myfunc) << endl;
//}


//#include <iostream>
//#include <functional>
//using namespace std;
//
//struct Square {
//	int operator()(int n) const {
//		return n * n; 
//	}
//} square_ob;
//
//int square_fn(int n) {
//	return n * n;
//}
//
//int arrFnMin(const int arr[], int n, const function<int(int)>& f) {
//	int min = f(arr[0]);
//	for (int i = 1; i < n; i++) {
//		if (min > f(arr[i])) min = f(arr[i]);
//	}
//	return min;
//}
//
//int main() {
//	int arr[5] = { 3, -4, 5, 9, -2 };
//
//	int(*fp)(int) = &square_fn;
//	cout << fp(5) << endl;
//	cout << arrFnMin(arr, 5, square_ob) << endl;
//	cout << arrFnMin(arr, 5, square_fn) << endl;
//	cout << arrFnMin(arr, 5, *fp) << endl;
//}


//#include <iostream>
//using namespace std;
//
//template<typename Fn_t>
//int arrFnMin(const int arr[], int n, Fn_t& f) {
//	int min = f(arr[0]);
//	for (int i = 1; i < n; i++) {
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
//	return n * (n-15) / 2;
//}
//
//class Test_1 {
//public:
//	int operator()(int x) {
//		return x + 1;
//	}
//};
//
//int main() {
//	int arr[7] = { 1,3,-4,1,5,9,-2 };
//	
//	Test_1 test_1;
//	int(*fp)(int) = &square;
//	
//	cout << arrFnMin(arr, 7, square) << endl;
//	cout << arrFnMin(arr, 7, MyFunc) << endl;
//	cout << arrFnMin(arr, 7, test_1) << endl;
//	cout << arrFnMin(arr, 7, *fp) << endl;
//}


//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	unique_ptr<int> a(new int(5));
//	//unique_ptr<int> b = new int(5);
//	unique_ptr<int> e(new int(5));
//
//	cout << *a << endl;
//
//	//int* c = a;
//	//a = new int(7);
//	//unique_ptr<int> d = a;
//	
//	unique_ptr<int> aa(new int(5));
//	unique_ptr<int> bb(aa.release());
//
//
//	unique_ptr<int> aaa(new int(55)); 
//	aa.reset(new int(5555)); // 원래 가리키던 객체(int 55) 해제후 새로운 객체 가리킴(int 5555)
//	aa.reset(NULL); // 원래 가리키던 객체 (int 5555) 해제 후 아무 객체도 가리키지 않는 NULL 포인터 상태 됨
//	aa.reset(); // Null pointer 상태 유지
//
//
//	unique_ptr<int> aaaa(new int(44));
//	cout << *aaaa << endl;
//	//aaaa.reset();
//	//cout << *aaaa << endl;
//	aaaa.reset(new int(44444));
//	cout << *aaaa << endl;
//	aaaa.reset(NULL);
//	cout << *aaaa << endl;
//}

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
//	int GetX() const {
//		return x;
//	}
//};
//
//int main() {
//	unique_ptr<MyClass> a(new MyClass(5));
//	cout << a->GetX() << endl;
//	cout << "=== 1 ===" << endl;
//	a.reset(new MyClass(7));
//	cout << a->GetX() << endl;
//	cout << "=== 2 ===" << endl;
//	a.reset();
//	cout << "=== 3 ===" << endl;
//	a.reset(new MyClass(9));
//	cout << "=== 4 ===" << endl;
//}


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
//	int GetX() const {
//		return x;
//	}
//};
//
//int main() {
//	shared_ptr<MyClass> a(new MyClass(5));
//	{
//		shared_ptr<MyClass> b = a; 
//		cout << a->GetX() << endl;
//		cout << b->GetX() << endl;
//		cout << a.use_count() << endl;
//		cout << b.use_count() << endl;
//	}
//	cout << a->GetX() << endl;
//	cout << a.use_count() << endl;
//}


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
//	~MyClass() {
//		cout << "~MyClass()" << endl;
//	}
//
//	int GetX() const {
//		return x;
//	}
//};
//
//int main() {
//	shared_ptr<MyClass> a(new MyClass(5));
//	cout << "=== 1 ===" << endl;
//	{
//		cout << a.use_count() << endl;
//		shared_ptr<MyClass> b = a;
//		cout << b.use_count() << endl;
//		a.reset(); 
//		cout << b.use_count() << endl;
//		cout << "=== 2 ===" << endl;
//	}
//	cout << "=== 3 ===" << endl;
//}

//
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//
//	cout << *a << endl;
//	//cout << *b << endl;
//	cout << b.use_count() << endl;
//	a.reset();
//	cout << b.use_count() << endl;
//}


//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//
//	cout << *b.lock() << endl;
//	//a.reset();
//	if (!b.expired()) {
//		cout << *b.lock() << endl;
//	}
//	else {
//		cout << "객체가 이미 소멸되었다!" << endl;
//	}
//}


//#include <iostream>
//#include <memory>
//using namespace std;
//
//void Print(weak_ptr<int> x) {
//	cout << *x.lock() << endl;
//}
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	Print(a);
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	vector<int> vec;
//	vec.push_back(1);
//	vec.push_back(2);
//	vec.push_back(3);
//	
//	for (auto vi : vec) {
//		cout << vi << endl;
//	}
//	
//	vector<int> vec2 = vec; // 벡터는 깊은 복사가 일어난다.
//	// STL 컨테이너들의 특 : 깊은 복사가 가능함
//	for (auto vi : vec2) {
//		cout << vi << endl;
//	}
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//const void Print(const vector<int>& v) {
//	for (auto vi : v) {
//		cout << vi << endl;
//	}
//}
//
//int main() {
//	vector<int> vec = { 1,2,3 };
//	vec.push_back(4);
//	vec.push_back(5);
//	Print(vec);
//}


//#include <iostream>
//#include <utility>
//
//int main() {
//	std::pair<int, std::string> p = { 123, "abc" };
//
//	std::cout << p.first << std::endl;
//	std::cout << p.second << std::endl;
//
//	p.first = 12345;
//	p.second = "aaaaaa";
//
//	std::cout << p.first << std::endl;
//	std::cout << p.second << std::endl;
//
//}

//#include <iostream>
//#include <map>
//#include <utility>
//using namespace std;
//
//int main() {
//	map<string, string> fruitCnt;
//	fruitCnt["Banana"] = "six";
//	fruitCnt["Grape"] = "five";
//	fruitCnt["Orange"] = "ten";
//
//	cout << fruitCnt["Banana"] << endl;
//	cout << fruitCnt["Strawberry"] << endl;
//
//	fruitCnt["banana"] = "ten";
//	
//	for (auto fi : fruitCnt) {
//		cout << fi.first << " : " << fi.second << "개" << endl;
//	}
//}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int arr[] = { 7,6,5,4,3,2,1 };
//	sort(arr, arr + 5);
//	for (auto ai : arr) {
//		cout << ai << endl;
//	}
//
//	cout << endl;
//
//	int arr_re[] = { 3,1,4,1,5,9,2 };
//	sort(arr_re, arr_re + 7);
//	for (int ai : arr_re) {
//		cout << ai << endl;
//	}
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	vector<int> vec = { 9,8,7,6,5,4,3,2,1 };
//	sort(vec.begin(), vec.end()); 
//
//	for (int vi : vec) {
//		cout << vi << endl;
//	}
//}


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


//#include <iostream>
//using namespace std;
//
//int (*OPS[])(int, int) = {
//	[](int a, int b)->int {return a + b; },
//	[](int a, int b)->int {return a - b; },
//	[](int a, int b)->int {return a * b; },
//	[](int a, int b)->int {return a / b; },
//};
//
//int main() {
//	int op;
//	int a, b;
//
//	cout << "연산의 종류 입력 (0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈) : ";
//	cin >> op;
//	cout << "정수 2개 입력 : ";
//	cin >> a >> b;
//
//	cout << OPS[op](a, b) << endl;
//}