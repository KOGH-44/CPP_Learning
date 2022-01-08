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



#include <iostream>
using namespace std;

class IPerson {
public:
	~IPerson() {}

	virtual void Eat() = 0;
	virtual void SetAge(int age) = 0;
	virtual int GetAge() = 0;
};

class IStudent : public virtual IPerson {
public:
	virtual void Study() = 0;
};

class IWorker : public virtual IPerson {
public:
	virtual void Work() = 0;
};

class Researcher : public IStudent, public IWorker {
public:
	void Eat() {
		cout << "먹는다..." << endl;
	}
	void Study() {
		cout << "공부한다..." << endl;
	}
	void Work() {
		cout << "일한다..." << endl;
	}
	
	void SetAge(int age) {
		this->age = age;
	}
	int GetAge() {
		return age;
	}
private:
	int age;
};

int main() {
	Researcher r;
	r.Eat();
	r.Study();
	r.Work();
	r.SetAge(20);
	cout << r.GetAge() << endl;

	IPerson* p = new Researcher;
	IStudent* s = new Researcher;
	IWorker* w = new Researcher;

	p->Eat();
	s->Study();
	w->Work();

	p->SetAge(20);
	s->SetAge(20);
	w->SetAge(25);
	
	delete p;
	delete s;
	delete w;
}
