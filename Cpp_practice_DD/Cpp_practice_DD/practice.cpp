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










