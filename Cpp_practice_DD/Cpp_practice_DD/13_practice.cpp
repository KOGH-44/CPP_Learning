// 13 C++ ��� ���

// 13.1 ���ø� (Template)
// 13.1.1 �Լ� ���ø� (�Լ��� ���� Ʋ) (�̰� �Լ��� �ƴϴ�. �Լ��� ���� Ʋ�̹Ƿ�, �Լ��� �����ϱ� ������ �Լ��� ����.)
//ex13.1 �Լ� ���ø� ����ϱ�
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
//	T sum = arr[0]; // T sum = 0; <- sum�� 0���� �ʱ�ȭ�ϸ� T�� �� �ٸ� ���� ����(double�̳� int�� ���� ���� ����)�� �ϳ� �� �ٱ� ������ sum�� �迭�� 0��° ���ҷ� �ʱ�ȭ �� ���̴�.
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
//	int isum = getArraySum<int>(iarr, 5); // ���ø� �μ� ��� (Ÿ�� ���� �� �ϴ� ���)
//	double dsum = getArraySum(darr, 5); // ���ø� �μ� ���� (Ÿ�� ���� �ϴ� ���) (�Լ� ���ø��� ���� ���ø� �μ� ������ �����ϴ�.)
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
//	cout << int() << endl; // �⺻ ������ ����� 0 ����
//	cout << double() << endl; // �⺻ ������ ����� 0 ����
//	cout << string() << endl; // �⺻ ������ ����� �� ���ڿ� ("") ����
//}


// �� ���� �ణ ������ ��� (T sum = arr[0]; ��� T sum = T(); ���)
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
//	Vector2& operator+=(const Vector2 rhs) { // ���� ���� ������ �����ε�
//		x += rhs.x;
//		y += rhs.y;
//		return *this;
//	}
//	Vector2& operator-=(const Vector2 rhs) { // ���� ���� ������ �����ε�
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
//	T sum = T(); // sum�� Ÿ���� �⺻ �����ڷ� �ʱ�ȭ!
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


// ���ø����� Ÿ�� �Ķ���͸� ���� �� �� �� �ִ�!
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


// 13.1.2 Ŭ���� ���ø� (Ŭ������ ���� Ʋ) (�̰͵� Ŭ������ �ƴϴ�. Ŭ������ ���� Ʋ�̹Ƿ� Ŭ������ ������� ��ü�� �����ؾ� �Ѵ�.)
// �Լ��ʹ� �ٸ��� Ŭ������ "�����ε�"�ϴ� ����� ����.
//ex13.2 Ŭ���� ���ø� ����� ����
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
//	Vector2<int> v1(1, 3); // �� ������ int�� ���� (Ŭ���� ���ø��� ���ø� �μ��� ���� ���� �ʴ´�.)
//	Vector2<double> v2(1.5, 3.5); // �� ������ double�� ���� (Ŭ���� ���ø��� ���ø� �μ��� ���� ���� �ʴ´�.)
//	// �� �� ���ʹ� ���� �ٸ� Ÿ���̴�.
//
//	cout << v1.GetX() << ", " << v1.GetY() << endl;
//	cout << v2.GetX() << ", " << v2.GetY() << endl;
//
//	cout << sizeof(v1) << endl; // 8 ���
//	cout << sizeof(v2) << endl; // 16 ���
//	// ���� Ÿ���̶�� �ּ��� Ÿ���� ũ��� ���ƾ� �ϴµ�, ũ����� �ٸ���.
//	// ��, Ŭ���� ���ø��� ����Ͽ� Ŭ������ ���� ��, Ÿ�� �Ķ���͸� �޶� ���� �ٸ� Ÿ���̴�.
//}


// Tip : �迭�� �����ϸ� ������ ���� ���簡 �Ͼ��! (���� �Ҵ��� �ƴϱ� �����̴�!)


// 13.1.3 ���ø� Ư��ȭ (Template specialiaztion) (� Ư���� �μ��� ������ �� ���� ���ø��� ���Ǹ� ������ �ʰ�, ���������� �� �μ��� ���� ���Ǹ� ���� �� �� �ְ� �ϴ� ���� ���Ѵ�.)
//ex13.3 ���ø� Ư��ȭ ����غ���
//#include <iostream>
//#include <string>
//using namespace std;
//
//template<typename T> // ���� ���ø�
//T getArraySum(T* arr, int n) {
//	T sum = T();
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//
//template<> // Ư��ȭ 
//string getArraySum<string>(string arr[], int n) { // <string> ���� ����
//	string sum = arr[0];
//	for (int i = 1; i < n; i++) {
//		sum += " " + arr[i]; // �ܾ� ���̿� ���鵵 �־��ش�.
//	}
//	return sum;
//}
//
//int main() {
//	int iarr[] = { 3, 1, 4, 1, 5 };
//	string sarr[] = { "Hello", "world", "!!!" };
//
//	int isum = getArraySum(iarr, 5); // ���� ���ø����κ��� ������ �Լ� ����
//	string ssum = getArraySum(sarr, 3); // Ư��ȭ�� �Լ� ����
//
//	cout << isum << endl;
//	cout << ssum << endl;
//}


// �� ���� ����
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


// 13.1.4 ��Ÿ�� �Ķ���� (Non-type template parameter) 
// ���ø��� ���� �� �ִ� �Ķ���ʹ� Ÿ�� �Ӹ� �ƴ϶�, ����, ������ � ���� �� �ִ�!
// ��Ÿ�� �Ķ���� ���� ������ n���� ���� Ŭ���� �����
//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Vector { // ������ ������ ��Ÿ�� �� �ִ� ����
//	Vector(int n) { // n : ����
//		this->n = n;
//		components = new T[n]; (���� �Ҵ��� �Ͼ�� �ǰ�, �̷� ���� �� ��ü�� �Ѱ��ٶ� ���� ���簡 �Ͼ�� ������ �߻��ϰ� �ȴ�.)
//	}
//	~Vector() {
//		delete[] components;
//	}
//
//	T GetComponent(int i) { // i��° ������ ����
//		return components[i];
//	}
//	void SetComponent(int i, T val) { // i��° ������ TŸ���� val�� ����
//		components[i] = val;
//	}
//
//	Vector operator+(const Vector rhs) const { // ���⼭ ������ �߻�! (���� : operator+ ���� �纯�� ������ �ٸ� �� �ִ�! �ٵ� ���ʹ� �ٸ� �������� ���� �� ����! <- �̰��� ��Ÿ�� �Ķ���ͷ� �ذ� ����!)
//		???
//	}
//
//private:
//	int n; // ����
//	T* components; // �� ������ �����ϴ� �迭
//};


// �� ������ ����� ���ø� ��Ÿ�� �Ķ���ͷ� �ذ� �ϴ� ���
//#include <iostream>
//using namespace std;
//
//template<typename T, int n> // ���⼭ int n�� ��Ÿ�� �Ķ���� �̴�. n�� ������Ÿ�ӿ� �ʱ�ȭ �ǹǷ�, ���ó�� ��� �����ϰ� �ȴ�!
//class Vector {
//public:
//	T GetComponent(int i) const { // i��° ������ ����
//		return component[i];
//	}
//	void SetComponent(int i, T val) { // i��° ������ TŸ���� val�� ����
//		component[i] = val;
//	}
//
//	Vector operator+(const Vector rhs) const { // �� ������ �����ε��� ����� �� �ִ� ��ü�� + ������ ������ ���� ��ü�� Ÿ���� +������ ������ ���� ��츸 �����ϴ�. (������ �켱���� ����)
//		Vector res;
//		for (int i = 0; i < n; i++) {
//			res.component[i] = this->component[i] + rhs.component[i];
//			//res.SetComponent(i, this->GetComponent(i) + rhs.GetComponent(i));
//		}
//		return res; // �� ���������� �����Ǿ��� ���� ���� ��� �迭�� �ѱ�� ���̹Ƿ� ���� ���簡 �Ͼ�� �ȴ�!
//	}
//
//private:
//	T component[n]; // �� ������ �����ϴ� �迭
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
//	//Vector<float, 3> v5 = v1 + v4; // �̷��� ������ ��Ÿ�� �Ķ���͸� ����ϹǷν� ��õ ������ �� ���� (3���� ���Ϳ� 2���� ���͸� ���Ϸ��� ����) // ���� ���ø��� ����Ͽ� ���� Ŭ���� ��ü������, ��Ÿ�� �Ķ���Ͱ� �ٸ��� ������ ���� �ٸ� Ÿ����. (���� �ٸ��� �ٸ�.)
//	
//	cout << v3.GetComponent(0) << ", " << v3.GetComponent(1) << ", " << v3.GetComponent(2) << endl;
//}


// �� ���� ����
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


// 13.2 ���� ó�� (Exception handling) (C���� ���� ó�� ������ �ƿ� ����!)
// 1! = 1
// 0! = 1
//ex13.4 if���� ����� ���丮�� ���� Ȯ��
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
//	cout << "�ڿ����� �Է��ϼ��� : ";
//	cin >> n;
//	if (n >= 1) { // n�� �ڿ����� ���� ���丮�� ���
//		cout << n << "! = " << fact(n) << endl;
//	}
//	else { // �ƴϸ� ���� �޽��� ���
//		cout << n << " : �ڿ����� �ƴմϴ�." << endl;
//	}
//}


// ���� ó���� �׻� try, throw (������), catch (�޾�)��� 3���� Ű���带 ���� �۵��Ѵ�. ���ܴ� ������ ��ü�̱⸸ �ϸ� �ȴ�.
// ��, ������ ���� ���� �ְ�, �����͸� ���� ���� �ְ�, �ƹ� Ŭ������ ���� �� Ÿ���� ��ü�� ������ �ȴ�. (�� ��, �������� ���ܸ� ���� ��ü�� �Ѵ�.)
// try ���� ���빰�� ������ ���������� ����� ���� �ְ�, �߰��� ����Ǵ� �� ���� �ִ�. try�� ���� ���빰�� �����ϴ� ���� ���ܰ� �ϳ��� �߻��Ѵٸ� �ϴ� ���� ���߰� catch���� ã�ư� �� ���빰�� �����Ѵ�.
// �ݴ��, try���� ������ �����ߴµ��� ���ܰ� �߻����� �ʴ´ٸ� catch���� �������� �ʰ� ���� �ڵ�� �Ѿ��.


//ex13.5 ���� ó���� ���� �ۼ��� ���丮�� �ڵ�
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
//		cout << "�ڿ����� �Է��ϼ��� : ";
//		cin >> n;
//		if (n <= 0) {
//			throw n; // ���� �߻�
//		}
//		// ���ܰ� �߻����� �ʾ��� ���� �ڵ�
//		cout << n << "! = " << fact(n) << endl;
//	}
//	catch (int e) { // ���� �ޱ�
//		cout << e << " : �ڿ����� �ƴմϴ�." << endl; // ������ ó��
//	}
//}


// ���� ó���� ���� : ���ܴ� �Լ� ������ ���޵� �� �ִ�! (� �Լ����� ���ܸ� �����ٰ� �ؼ� �� �Լ����� ���ܸ� ó���� �ʿ�� ����. �׷��� �� ���ܴ� �� �Լ��� ȣ���ߴ� �Լ��� "���Ѱ�����".)
//ex13.6 ���� ���ѱ��
//#include <iostream>
//#include <string> 
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : �ڿ����� �ƴմϴ�."; // ���� ���ܰ� main �Լ����� �߻��� ��� main�Լ����� ȣ���� ������ �̵��� �� catch���� ã�� ����. (�ٸ� �Լ����� ȣ�������� �� ������ ����.)
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int main() {
//	int n, r;
//	try {
//		cout << "�ڿ��� 2�� �Է� : ";
//		cin >> n >> r;
//
//		int a = fact(n); //
//		int b = fact(r); // �� �� �� �������� ���� �߻� �� catch�� �̵�
//		int c = fact(n - r); // 
//		
//		int result = a / b / c;
//		cout << result << endl;
//	}
//	catch (const string& e) { // ���� ������ ���� ���� ���з����� ����!
//		cout << e << endl;
//	}
//} // �ٽ� : ���ܸ� ������ �κе� �ϳ��ۿ� ����, ���ܸ� ó���ϴ� �κе� �ϳ��ۿ� ����. (if�� ������ ����� ȿ���� �� �� ������ ���� ó���� ����� ����� �� ����ϴ�.)


// ���� �Լ��� ���ļ� ���� ���ѱ�� ����
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : �ڿ����� �ƴմϴ�.";
//	if (n == 1) return 1;
//	return n * fact(n - 1);
//}
//
//int comb(int n, int r) {
//	int a = fact(n);
//	int b = fact(r);
//	int c = fact(n - r);
//	return a / b / c;
//} // ����(Combination) : nCr = n! / (r! * (n - r)!)  // ����(Permutation) : nPr = n! / (n - r)!
//
//int main() {
//	int n, r;
//	try {
//		cout << "�ڿ��� 2�� �Է� : ";
//		cin >> n >> r;
//		cout << comb(n, r) << endl;
//	}
//	catch (string& e) {
//		cout << e << endl;
//	}
//}


//ex13.7 try�� �ȿ� �ݺ����� �ִ� ���
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : �ڿ����� �ƴմϴ�.";
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
//		while (true) { // try �ȿ� ������ ������ ���� ������ �� ���̶� ���ܰ� �߻��ϸ� catch�� �Ѿ�Ƿ� ������ ���������� �ȴ�. (�߸��� �Է��� ������ �� �����޽��� ����� �� ����)
//			cout << "�ڿ��� 2�� �Է� : ";
//			cin >> n >> r;
//			cout << comb(n, r) << endl;
//		}
//	}
//	catch (const string& e) {
//		cout << e << endl;
//	}
//}


//ex13.8 �ݺ��� �ȿ� try-catch���� �ִ� ���
//#include <iostream>
//#include <string>
//using namespace std;
//
//int fact(int n) {
//	if (n < 1) throw to_string(n) + " : �ڿ����� �ƴմϴ�.";
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
//	while (true) { // ���� �ȿ� try-catch�� ��ü�� ���Խ�Ų�ٸ� �� �� catch�� �Ѿ�ٰ� �ؼ� ������ ������ �ʴ´�. (�߸��� �Է��� ������ �� �����޽��� ����� �� �ٽ� �ݺ�)
//		try {
//			cout << "�ڿ��� 2�� �Է� : ";
//			cin >> n >> r;
//			cout << comb(n, r) << endl;
//		}
//		catch (const string& e) {
//			cout << e << endl;
//		}
//	}
//}


// ������ Ÿ���� ���� ������� catch���� ���� �� ���� ���� �ִ�! (ex. 123�� throw�ϸ� int�� �޴� catch���� ����ǰ�, string("abc")�� throw�ϸ� string�� �޴� catch���� ����Ǵ� ���̴�. (��������� string ��ü�� ������ �ʰ� �׳� "abc"�� throw�ϸ� const char*�� �޴� catch���� ����ȴ�!))
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
//			throw 123; // ù ��° catch�� ����
//		if (n == 2)
//			throw string("abc");
//		if (n == 3)
//			throw "abc";
//	}
//	catch (int e) {
//		cout << e << endl;
//	}
//	catch (const string& e) { // string("abc") ��ü�� ����
//		cout << e << "(const string&)" << endl;
//	}
//	catch (const char* e) { // "abc" ��ü�� ����
//		cout << e << "(const char*)" << endl;
//	}
//}


// ��� catch������ �ش��ϴ� Ÿ���� ���ٸ� ���ܰ� �޾����� �ʰ� �ٱ� �Լ�(���� �Լ��� ȣ���ߴ� �Լ�)�� ���Ѱ�����. ������ main������ �� �̻� ���ѱ� �ٱ� �Լ��� ���� ������ �̷��� ���ܸ� ���� �� �ִ� catch���� ���� ��쿡�� ��Ÿ�� ������ ����.
// �̷��� catch���� ���� ������ ���� ���ܴ� catch(...)��� Ư���� ������ ����ϸ� ���� �� �ִ�!!!
// catch(...) ������ ����� ����
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
//			throw 123; // ù ��° catch�� ����
//		if (n == 2)
//			throw string("abc"); // �� ��° catch�� ����
//		if (n == 3)
//			throw 3.14; // �� ��° catch�� ����
//	}
//	
//	catch (int e) {
//		cout << e << endl;
//	}
//	catch (const string& e) {
//		cout << e << endl;
//	}
//	catch (...) {
//		cout << "�� �� ���� ���� �߻�" << endl;
//	}
//}


// 13.3 auto (�캯�� Ÿ���� �и��� �˾Ƴ� �� ���� �� �º��� Ÿ���� �� �״�� �ڵ�����(auto) �����ִ� Ű�����̴�. (C++11 ���Ŀ����� �۵��Ѵ�.)) (Ÿ���� �������� �����ϰų� �캯�� Ÿ���� ���߿� �ٲ� ���������� ���� ���� ���� ����ϸ� ����.)
// vector<pair<string, int>>::iterator it = v.begin(); // ������ ���� ���ÿ��� �Ź� vector<pair<string, int>>::iterator �� �����ֱ� ��ƴ�.
// auto it = v.begin(); // ������ ���� auto�� �ٲپ �����Ϸ��� �ڵ����� ä��� �� �� �ִ� ������ �ִ�.


// ���� ��� for�������� auto�� ����ϸ� �����ϴ�.
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
//	} // �⺻ for�� ���
//
//	for (int i : arr) {
//		cout << i << endl;
//	} // auto Ű���带 ������� �ʰ� ���� ��� for�� ���
//	
//	for (auto i : arr) {
//		cout << i << endl;
//	} // auto Ű���带 ����� ���� ��� for�� ���
//
//
//	// auto�� ���� �ȵǴ� ��Ȳ : �纯�� Ÿ���� �ǵ������� �ٸ��� �ϴ� ���
//	Derived d;
//	auto b = &d; // �츮�� �ǵ��� ���� Base* b = &d; ������, auto�� ����ϸ� Derived* b = &d�� �ȴ�. 
//	b->f();
//} // ��, auto�� �ʹ� ���� ����ϸ� �ڵ带 �д� ����� �� ������ Ÿ���� �������� �˱� ��������Ƿ� �������� �ʴ� ���� ����.


// 13.4 �Լ� ������, �Լ� ��ü�� ���ٽ�
// 13.4.1 �Լ� ������ (C�� C++�� ����) (Function pointer) : �Լ��� ����Ű�� ������ (�Լ��� �޸𸮻� ��򰡿� ����Ǳ� ������ �ּҰ��� ������ �ְ�, �� �ּҰ��� �Լ� �����Ϳ� ������ �� �ִ�!)
// ���� ��� : bool (*fp) (int, int); <- int 2���� �Ű������� �ް�, bool�� �����ϴ� �Լ��� ����Ű�� �����͸� �����, �� �������� �̸��� fp�� �ϰڴٴ� ���̴�. 
// ����! bool *fp (int, int); <- int 2���� �Ű������� �ް�, bool*�� �����ϴ� �Լ��� ������Ÿ���� ����� ���̹Ƿ� �Լ� �����Ϳʹ� ���� �ٸ���. �Լ� �����͸� ������ ���� ��ȣ�� ����� ���� ������Ѵ�!


 //int (*arrPtr)[10]; // �迭(�� ����Ű��) ������
 //int *ptrArr[10]; // ������(�� �̷����) �迭
 //bool (*fp)(int, int); // �Լ�(�� ����Ű��) ������
 //bool *fp(int, int); // �����͸� �����ϴ� �Լ��� ������Ÿ��


// �Լ� �����Ϳ� � �Լ��� �ּҸ� ����������� �캯�� �Լ��� �ּҸ� ���� �ȴ�. �Լ��� �ּҸ� �������� ���ؼ��� �Լ� �̸� �տ� &�� ���� �Ǵµ�, &�� �����ϰ� �׳� �Լ��� �̸��� �ᵵ �ȴ�. (������ ���� �ϴ� ��찡 ����.) (�� ���� �ｼ, �Լ��� �̸� ��ü�� �Լ��� �ּҰ����ε� �� �� �ִٴ� ���̴�.)
// �������� �Լ� �����Ͱ� ����Ű�� �Լ��� �����ϱ� ���ؼ��� �Լ� �����͸� �������� ��, () �ӿ� ���ϴ� �μ��� ��������� �Ǵµ�, �̶��� �������� ������ �� �ִ�. (�������� ��ȣ�ȿ��� �̷�������Ѵ�.)
// �Լ� ������ ��� ���� 1
//#include <iostream>
//using namespace std;
//
//bool compare(int a, int b) {
//////	return (a 
// == b);  // a�� b�� ������ true, �ƴϸ� false ����
//}
//
//int main() {
//	bool (*fp)(int, int); // �Լ� ������ ����
//	
//	// �Լ� ������ �����ϱ�
//	//fp = &compare; // OK
//	fp = compare; // OK. ���ٰ� ���� �ǹ�
//
//	// �Լ� ������ ����ϱ�
//	bool res1 = (*fp)(1, 3); // OK
//	bool res2 = fp(1, 3); // OK
//	//bool res3 = *fp(1, 3); // ����!!! fp(1, 3)�� ���� ���� �������϶�� ���̴�! (�� ������ ��� ���ϰ��� ������ Ÿ���� �ƴ϶� bool Ÿ���̱� ������ ������ �߻��Ѵ�!)
//	
//	//(*arrPtr)[1]; // arrPtr(�迭 ������)�� ����Ű�� �迭�� 1�� ĭ
//	//*ptrArr[1]; // ptrArr(������ �迭)�� 1�� ĭ�� ����Ű�� ��
//}


// �Լ� ������ ��� ���� 2
//int arrMin(const int arr[], int n) {
//	int min = arr[0];
//	for (int i = 1; i < n; i++) {
//		if (min > arr[i])min = arr[i];
//	}
//	return min;
//} // ���� ������ �ּҰ��� ã�� �ʹٸ�? �������� �ּҰ���? ��������? ... <- �̷� �� �Լ� �����͸� ����ϸ� ���ϴ�! (������ �Լ���(����, ������, ...) ���������� �Լ� �������� ���·� �Ű������� �ѱ�� ���̴�!)


//ex13.9 �Լ� �����͸� ����� �迭�� �� ĭ�� ������ �Լ��� ������ ���� �ּ� ã��
//#include <iostream>
//using namespace std;
//
//int n_double(int n) { return n * 2; } // n�� 2�踦 �����ϴ� �Լ�
//int square(int n) { return n * n; } // n�� ������ �����ϴ� �Լ�
//int myFunc(int n) { return n * (n - 15) / 2; } // � �ٸ� �Լ�
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
//	cout << arrFnMin(arr, 7, n_double) << endl; // 2���� �ּ�
//	cout << arrFnMin(arr, 7, square) << endl; // ������ �ּ� 
//	cout << arrFnMin(arr, 7, &myFunc) << endl; // myFunc �Լ��� ������ ���� �ּ�
//}


// 13.4.2 �Լ� ��ü (Function object/Functor) : �Լ�ó�� �۵��ϴ� ��ü
//ex13.10 �Լ� ��ü ����غ���
//#include <iostream>
//using namespace std;
//
//class Equals { // �Լ� ��ü ����
//public:
//	Equals(int value) : value(value) {}
//	bool operator()(int x) const { // () ������ �����ε��� ���ؼ� �Լ�ó�� ��� ������
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
//	cout << eq(123) << endl; // �Լ� ��ü�� ���� ��ü�� �Լ�ó�� ��밡���ϴ�.
//	cout << eq(12) << endl;
//}


// �Լ� ��ü ����غ��� 2
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
//} // �Լ� �����ʹ� �ܼ��� �� ���� �Լ��� ����ų �� ������, �Լ� ��ü�� ����ϸ� �̷��� ���� ������ �Լ��� ���� �� �ִ�. (�Լ� ������ �ϳ��� ������ ���� �����ε��� �Լ��� ����ų ���� ����.(�Լ� �����͸� ���� ���� ����ų �Լ��� ���� Ÿ�԰� �Ű����� ����� �˾ƾ� �ϱ� �����̴�.))
// ������ �Լ� ��ü�� ����ϸ� �� ���� �̸�(eq)���� ����� ���� �����ε��� �Լ��� ������ ���� �ִٴ� ������ �ִ�.


//ex13.11.1 �Լ� ��ü�� ����� �ٲ㺻 ���� 13.9 (�θ� Ŭ������ ���� ����� ���� �������� �̿��ϴ� ���) (RTTI�� ���ݵȴ�.)
//#include <iostream>
//using namespace std;
//
//struct Func { // �Լ��� ��Ÿ���� ���� �߻� Ŭ����
//	virtual int operator()(int n) const = 0;
//};
//
//struct Square : Func { // n�� ������ ��Ÿ���� Ŭ����
//	int operator()(int n) const { return n * n; }
//};
//
//struct MyFunc : Func { // � �ٸ� �Լ��� ��Ÿ���� Ŭ����
//	int operator()(int n) const { return n * (n - 15) / 2; }
//};
//
//int arrFnMin(const int arr[], int n, const Func& f) { // ���۷����� �޴� �͵� �����ϴ�.
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


//ex13.11.2 �Լ� ��ü�� ����� �ٲ㺻 ���� 13.9 (function ���� Ŭ���� ���ø��� �̿��ϴ� ��� (C++11���� �����ϴ�.))(������ �� ����� ���ɿ� ���� �����Ƿ� ��õ���� �ʴ´�.)
//#include <iostream>
//#include <functional> // function�� ����ϱ� ���� �ʿ�
//using namespace std;
//
//struct Square { // �Լ� ��ü
//	int operator()(int n) const { return n * n; }
//} square_ob; // �Լ� ��ü ����� ���ÿ� ����� ���
//
//int square_fn(int n) {
//	return n * n;
//} // ������ �Լ� �����͵� function<int(int)> Ÿ���� ��ü�� �ѱ� �� �ִ�.
//
//int arrFnMin(const int arr[], int n, const function<int(int)>& f) { // function ���� Ŭ���� ���ø� �̿� (int�� �����ϰ� int�� �Ű������� �޴� � �Լ� ��ü���� �� Ÿ���� ������ ���� �� �ִ�!)
//	int min = f(arr[0]);
//	for (int i = 0; i < n; i++) {
//		if (min > f(arr[i])) min = f(arr[i]);
//	}
//	return min;
//}
//
//int main() {
//	int arr[7] = { 3, 4, -4, 2, 5, 9, -2 };
//	//Square square_ob; // �Լ� ��ü ����
//
//	cout << arrFnMin(arr, 7, square_ob) << endl; // �Լ� ��ü
//	cout << arrFnMin(arr, 7, square_fn) << endl; // �Լ� ������
//}


//ex13.11.3 �Լ� ��ü�� ����� �ٲ㺻 ���� 13.9 (���ø����� ���� �������� ����� ���) (���� ������.)
//#include <iostream>
//using namespace std;
//
//template<typename Fn_t>
//int arrFnMin(const int arr[], int n, const Fn_t& f) { // f�� �Ұ�ȣ ������ �����ϱ⸸ �ϴٸ� (�Լ� ��ü(operator()), �Լ�, �Լ������� ���...), ��� Ÿ���̵� ������ �ִ� ���̴�.
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


// 13.4.3 ���ٽ� (Lambda expression / Anonymous function) (C++11���� ���� �����Ͽ���.) : Ư���� �ٿ��� �̸� ���� ������ �����ϴ� �Լ��̴�. ���� ��ȣ�� �º����� ���Եǰų� �Լ��� �μ��� �Ѱ����߸� ����� �� �ִ�. 
// ���ٽ��� �Ϲ����� ���� : [ĸ��] (�Ű�����_���) -> ����_Ÿ�� { �Լ�_���� }  // ĸ��(capture)�� ������(introducer)��� �Ѵ�. (ĸ�Ĵ� ���ٽ��� ���ǵ� �ܺ� ȯ���� ���ٽ� �ȿ��� ����ϰ� ���� �� ����Ѵ�.)
// ����_Ÿ���� void�϶��� -> ����_Ÿ���� ������ �� �ִ�. : [ĸ��] (�Ű�����_���) { �Լ�_���� }
// ����_Ÿ�԰� �Ű�����_����� void�� ���� (�Ű�����_���) -> ����_Ÿ�Ե� ������ �� �ִ�. : [ĸ��] { �Լ�_���� }
// ���ٽ� ��� : [ĸ��] (�Ű�����_���) -> ����_Ÿ�� { �Լ�_���� } (�Ű�����);
// ���ٽ��� Ÿ���� �Լ� ��ü Ÿ���̴�! (�и� Ÿ���� ������ �̸��� ���� ������ �� Ÿ�� ��ü�� "�̰Ŵ�"��� ����� ���� ����. ���� ���ٽ��� ��򰡿� ������ ���� �� ���ٽ��� ��ȯ�� �� �ִ� �ٸ� Ÿ���� ����ϰų� auto Ű���带 ����ؾ� �Ѵ�.)
// ���ٽ��� function Ÿ���̳� �Լ� �����ͷε� ��ȯ�� �� �ִ�. (��, �Լ� �����ͷ� ��ȯ�Ǳ� ���ؼ��� ĸ�İ� ����־���Ѵ�.)
 //function<int(int)> fa = [](int n) -> int { return n * n; }; // function Ÿ�� ��ü
 //int (*fb) (int)       = [](int n) -> int { return n * n; }; // �Լ� ������
 //auto fc               = [](int n) -> int { return n * n; }; // auto

//ex13.12 ���ٽ��� ����� ���ĺ� ���� 13.9
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


// ���� �Լ��� std::function, std::bind, for_each
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
//		// [this]() { cout << name << endl; } (); // Ŭ������ ����� ������ ��
//		[&]() { cout << name << endl; } (); // ���۷���
//		[=]() { cout << name << endl; } (); // ����
//	}
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//
//	auto func2 = [](int val) { cout << val << endl; };
//	for_each(v.begin(), v.end(), func2); // algorithm ��� �ȿ� ���ǵ� for_each ���
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
//		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1); // bind(��� �Լ�, ��ü, �Ű�����)
//
//		f(string("World"));
//
//		auto f2 = std::bind(goodbye, std::placeholders::_1); // bind(�Լ�, �Ű�����)
//
//		f2(string("World"));
//	}
//}


// std::bind, std::placeholder �� �˾ƺ���
// std::bind(�Լ��� �ּ�, ����1, ����2, ...);
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
//	/*func_3���� sum_3�� ù��° ���ڴ� �̹� 1�� ���� ������ �� ���ڴ� placeholder�� ���� ��
//	func_3�� ù��° ���ڴ� ���� �Լ� sum_3�� ����° ���ڰ� �ǰ�
//	func_3�� �ι�° ���ڴ� ���� �Լ� sum_3�� �ι�° ���ڰ� �ǰ�
//	��, �������� ���� ���� ���ڵ��� ������ palceholder�� ������ �� ����*/
//	cout << func_3(2, 3); // 1 + 3 * 10 + 2 * 100 = 231
//}


//13.5 friend : ����� Ŭ���� ���� �θ� ������ C++���� ģ�� ���赵 �ִ�. 
// friend�� ����ϸ� public, protected, private �� ���� ���� �����ڸ� �����ϰ� ���� Ŭ������ ��� ����� Ư�� ��󿡰� ��� ������ �� �ִ�! (�̶� ������ ����� �ٸ� Ŭ������ �� ���� �ְ�, �Լ��� �� ���� �ִ�.)


// friend�� ���� ��Ȳ
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
//		a.fa(); // ����!
//	}
//}; // class�� �⺻ ���� ����� private�̹Ƿ� B::fb() �޼��忡�� a.fa()�� ȣ���Ϸ��� �ϸ� ������ �߻��Ѵ�.


// friend�� ����Ͽ� Ư���� B������ A�� ����� �����ϴ� ���� ����� �� �ִ�.
//#include <iostream>
//using namespace std;
//
//class A {
//	friend class B; // B��� Ŭ�������� �� ����� �����ϴ� ���� ����Ѵ�.
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


// �ٸ� �Լ����Ե� ������ ����� ���� �ִ�.
//#include <iostream>
//using namespace std;
//
//class A {
//	friend void fg(); // fg��� �Լ����� A�� ����� �����ϴ� ���� ���ȴ�.
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


// 13.6 �޸� �����ǰ� ����Ʈ ������ : ����Ʈ �����ʹ� ������ ���� �Ҵ�� ��ü�� ���� �޸� ������ �ڵ����� ���ֱ� ���� �����Ͽ���.
// 13.6.1 �޸� ������ (Memory ownership) (�޸� �������̶� ��� �������� ���� �ƴ϶� �ǹ̷����� �����̴�.)
// �޸� ������ ����
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a, * b;
//	a = new int(5); // ���� �Ҵ��� a���� �Ͽ����Ƿ� a��� �����Ϳ��Դ� � ���� �Ҵ�� ��ü�� �ּڰ��� �޾Ƽ� �ܼ��� ����Ű�� ���һӸ� �ƴ϶�
//	// Ư�� �ñⰡ �� ������ ��ü�� ����Ű�� ���¸� �����ϴٰ� ��ü�� �� ����ϰ� ���� �����ϰ� �Ҹ��ų �ǹ��� �ִ�. �̷� �� a�� ��ü�� �����ϰ� �ִٰ� ���Ѵ�.
//	b = a; // b�� ��ü�� "����"�ϰ� �ִ°��� �ƴϴ�. b�� ���� �� ��ü�� �����ϱ⸸ ���� ��, b�� ��ü�� ������ �Ҹ꿡 �������� �ʴ� ��Ȳ�̰�, �����ؼ��� �ȵȴ�.
//	// �׷��� ������ delete b;�� �ϸ� ������ �ȵǴ� ���̴�. (�ǹ̷������δ� �ȵȴٴ� ���̴�. ���������δ� ����.) 
//	// �׷��� �ʿ信 ���󼭴� �������� "����"�ؾ� �� ���� �ִ�.
//	cout << *b << endl;
//	delete a;
//}


// �޸� �������� �����ϴ� ����
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* a, * b;
//	a = new int(5);
//	b = a; // b���� �������� ���� (a�� �޸𸮸� �����ϰ� �ִٰ� b���� �������� �����Ͽ���.)
//	cout << *b << endl;
//	delete b; // b���� �������� �����Ͽ��� ������ b�� ���ؼ� ��ü�� �Ҹ�����ش�.
//} // �ڵ��� �ٲ� �κ��� delete b; �ۿ� ����. ������ �������� �̵��Ͽ��ٰ� �Ѵ�. ��, � �����Ͱ� ��ü�� �����ϰ� �ִ����� ������ �� �ڵ带 § ����� �˰� �ִٴ� ���̱⵵ �ϴ�.
// ������, ����Ʈ �����͸� ����ϸ� �̷� �����ǿ� ���� ������ �Ϲ� �����ͺ��� ü�������� �����ϰ�, �������� �������� �ٷ� �� �ִ�. 
// ����Ʈ �������� �����δ� unique_ptr, shared_ptr, weak_ptr �� �� ������ �ִ�.


// 13.6.2 unique_ptr (������ ������) : unique_ptr���� ���� �����ڳ� ���� ���� �����ڸ� ����� �� ����.
// unique_ptr ����
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	unique_ptr<int> a(new int(5)); // unique_ptr �ʱ�ȭ ���
//	//unique_ptr<int> b = new int(5); // ����! unique_ptr�� ��ȯ �����ڰ� explicit���� ����Ǿ� �ֱ� ������ ������ �߻��Ѵ�!
//	unique_ptr<int> e(new int(5));
//	
//	cout << *a << endl; // ������ ���� �Ϲ� �����Ϳ� ����ϰ� ����� �� �ִ�.(* �����ڰ� unique_ptr�� �����ε��Ǿ� �ֱ� �����̴�.) a�� ����ü�� Ŭ���� Ÿ���� ����Ű�� �ִٸ� ->�����ڵ� ����� �� �ִ�.
//	
//	// ������ a ��ü�� ���ο� ���𰡸� �����ϰų� a�� �ٸ� �����Ϳ� ������ ���� ����. (a�� ����Ű�� ��ü�� �ݵ�� a�� �����Ѿ� �ϱ� �����̴�.)
//	//int* c = a; // ����! unique_ptr�� �ٸ� ���� ������ �� ����.
//	//unique_ptr<int> d = a; // ����! �º��� unique_ptr�̶� ������ ������ �� ����.
//	//a = new int(7); // ����! unique_ptr�� ���ο� �ּڰ��� ������ ���� ����.
//
//	// ������ unique_ptr������ �������� ������ �� �ִ� ����� �����Ѵ�! �ٷ� release��� �޼��带 ���� ��!
//
//	// aa�� ������ �ִ� �������� bb���� ������ ����
//	unique_ptr<int> aa(new int(5));
//	unique_ptr<int> bb(aa.release()); // aa�� ������ �ִ� �������� bb���� ����!
//	// �̷��� �Ǹ� aa�� �� �̻� ��ü�� ����Ű�� �ʰ� �ǰ�, ���� bb���� �� ��ü�� ����Ű�� �ȴ�.
//
//	// unique_ptr�� ����� �������� �������� �ؼ� �� ������(a, aa..)�� �Ҹ�Ǹ� �� �����Ͱ� ����Ű�� ��ü�� �˾Ƽ� �Ҹ�ȴ�. (�Ϲ� �����Ϳʹ� �ٸ� �κ�)
//
//	// unique_ptr�� ����Ű�� ��ü�� �߰��� �ٲٴ� ��� : reset�̶� �޼��带 ����Ѵ�!
//	unique_ptr<int> aaa(new int(5));
//	aaa.reset(new int(7)); // ���� ����Ű�� �ִ� ��ü�� �޸𸮸� ������ �� ���� �Ҵ�� ��ü�� ����Ű�� �ȴ�.
//	aaa.reset(NULL); // aaa�� �ƹ� ��ü�� ����Ű�� �ʴ� NULL �������� ���°� �ȴ�.
//	aaa.reset(); // aaa�� �ƹ� ��ü�� ����Ű�� �ʴ� NULL �������� ���°� �ȴ�.
//}


//ex13.13 unique_ptr ����ϱ�
//#include <iostream>
//#include <memory> // ����Ʈ �����Ͱ� ����� ���̺귯��
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
//	a.reset(); // a�� ����Ű�� ��ü�� �����ϰ� �ƹ��͵� ����Ű���� ����
//	cout << "=== 3 ===" << endl;
//	a.reset(new MyClass(9));
//	cout << "=== 4 ===" << endl;
//}


// 13.6.3 shared_ptr (���� ������) : unique_ptr���� �ٸ��� ���� �����Ͱ� �� ��ü�� ����ų �� �ִ�. (��, �� ��ü�� ���� �����Ͱ� ����(share)�� �� �ִ�.
// shared_ptr�� ���� ��Ȯ�� �� ���� �����Ͱ� �� ��ü�� ����Ű�� �ִ����� ���ο��� �߰������� ����ϰ� �ִ�.  (use_count��� �޼��尡 �� ������ �Ѵ�.)
// �����Ͱ� �Ҹ�� ���� ��ü�� ����Ű�� �����Ͱ� �� �ܿ� �ϳ��� �����ִٸ� ��ü�� �Ҹ��Ű�� �ʰ�, �� ��ü�� ����Ű�� ������ �����ͱ��� �Ҹ�ǰ� ������ �� ��ü�� �Ҹ�ȴ�.
// ���� shared_ptr�� delete�� �ؾ� ���� ���� �������� �ʾƵ� �ȴ�.
// shared_ptr�� �ٽ��� �������� �� �����Ϳ� �����Ǿ� ���� �ʴٴ� ���̴�. (�Ϲ� �����͸� ����Ѵٸ�, ���� ������ �� ��Ȯ�� �� �����Ͱ� �ݵ�� �޸� ������ ����ؾ� �ϱ� ������ �� �ӹ��� ����� �����Ͱ� ���� � �������� �� ���ؾ� �Ѵ�.)
// ������ shared_ptr�� ����ϸ� ��ü�� ����Ű�� �����Ͱ� �ϳ��� ���� �ʴ� ������ Ž���Ͽ� �ڵ����� ��ü�� �����ϹǷ� ���� ��ü ������ ����� �������� ó������ ���� �ʿ䰡 ���� �ȴ�.)


//ex13.14 shared_ptr ����� ����
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
//	shared_ptr<MyClass> a(new MyClass(5)); // use_count�� ���� 1�� �ȴ�.
//	{
//		shared_ptr<MyClass> b = a; // use_count�� ���� 2�� �ȴ�.
//		cout << a->GetX() << endl;
//		cout << b->GetX() << endl;
//		cout << a.use_count() << endl;
//		cout << b.use_count() << endl;
//	} // b�� �Ҹ�Ǿ� use_count�� ���� 1�� �ٲ�� �ȴ�.
//	cout << a->GetX() << endl;
//	cout << a.use_count() << endl;
//} // a�� �Ҹ�Ǿ� use_count�� ���� 0���� �ٲ�� �ǰ�, ����Ű�� ��ü�� �Ҹ��ڰ� ȣ��ȴ�.


//ex13.15 shared_ptr���� reset �޼��� ����ϱ�
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
//		a.reset(); // use_count�� 1�� �Ǿ������ �ȴ�.
//		cout << b.use_count() << endl;
//		cout << "=== 2 ===" << endl;
//	} // �������� ������ b�� �Ҹ�Ǹ鼭, use_count�� 0�� �Ǿ������ �ǹǷ� ��ü�� �Ҹ�ȴ�.
//	cout << "=== 3 ===" << endl;
//}


// 13.6.4 weak_ptr : weak_ptr�� shared_ptr�� ����Ű�� ��ü�� �Ȱ��� ����ų ���� ������ ���������� �ʴ� �������̴�. �������� �ʴ´ٴ� ���� �Ҹ꿡 �������� �ʴ´ٴ� ���̰�, ���� weak_ptr�� � ��ü�� �����ѵ� �� ��ü�� �����ϱ⸸ �� �� use_count�� ���� �ٲ����� �ʴ´�.
// ex
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//	cout << a.use_count() << endl; // 1 ���
//	cout << b.use_count() << endl; // 1 ���
//}


// weak_ptr�� ��ü�� ���� �������� ���� ������ ���� ����Ű�� ����� �̹� �Ҹ�Ǿ��� ���ɼ��� �ִ�!
// ex
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//	cout << *a << endl;
//	//cout << *b << endl; // weak_ptr�� ���� ����(�Ҹ� ���ɼ�) ������ �ٷ� ������ �����ڸ� ����� �� ����! (expire�� lock�̶�� �޼��带 ����ؾ���)
//	cout << b.use_count() << endl; // 1 ���
//	a.reset(); // use_count ���� 0�� �Ǿ�����Ƿ� ��ü�� �Ҹ�ȴ�.
//	cout << b.use_count() << endl; // 0 ���
//}

// weak_ptr ������ �ϴ� ���
//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	shared_ptr<int> a(new int(5));
//	weak_ptr<int> b = a;
//	
//	cout << *b.lock() << endl; // weak_ptr ������ �ϴ� ���
//
//	//a.reset(); // ��ü �Ҹ�
//	if (!b.expired()) {
//		cout << *b.lock() << endl;
//	}
//	else {
//		cout << "��ü�� �̹� �Ҹ�Ǿ���!" << endl;
//	}
//}


// weak_ptr�� ��ü�� ����Ű�� ������ �������� �ʿ� ���� �� ����Ѵ�. (���� �̷� ���� ���� ����Ű�� ����� weak_ptr�� ���� �������ϴ� �ͺ��� �ʰ� ������ٴ� ���� ����Ǵ� ��Ȳ�̴�.)
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
//	print(a); // �ּ��� print �Լ��� ����Ǵ� ������ x�� ����Ű�� ��ü�� ����ִٴ� ���� ����ȴ�.
//}


// 13.7 STL (Standard Template Library) (ǥ�� ���ø� ���̺귯��) : STL���� ���α׷����� ���ϰ� ���ֱ� ���� ���� Ŭ������ �Լ��� �ִ�. (�̸����� �� �� �ֵ���, STL�� �ٰ��� ���ø��̴�.)
// STL�� �����̳�, �˰���, ���ͷ����� ������ �̷���� �ִ�. (ex. �����̳� : vector, pair, map, ... / �˰��� : sort, ...)


//13.7.1 vector (���п����� ���Ϳʹ� ���� �ٸ���. vector�� �迭�� ���������, �迭���� �ٸ��� ĭ���� �����Ǿ� ���� �ʴ�.(vector�� �ʿ信 ���� ĭ���� �ڵ����� �þ�ų� �پ���.))
// vector�� ����Ϸ��� #include <vector>�� ��Ŭ����ؾ� �Ѵ�.
// ���͸� ����� ��� : vector<int> vec; // int�� �����ϴ� vector vec�� ����
// ���͸� ó�� ����� ��� �ִ�. ���ο� ���� ���Ϳ� ����������� push_back �޼��带 �����ϸ� �ȴ�. �� �޼���� ������ �� ���� ���ο� ���Ҹ� �߰��ϴ� �޼����̴�.
// vec.push_back(1); {1}
// vec.push_back(2); {1, 2}
// vec.push_back(3); {1, 2, 3}

// C++11���ʹ� ���͸� ó�� ���� ������ �ʱ�ȭ ����Ʈ�� ����� ���� ���Ҹ� �迭ó�� �Ѳ����� �ʱ�ȭ�� �� �ִ�.
// ex
// vector<int> vec = { 1, 2, 3 };

// vector���� []�����ڰ� �����ε��Ǿ� �ֱ� ������ ���͸� ����� ���� �迭�� ���� ������� ����� �� �ִ�.
// ex
//cout << vec[0] << endl; // �� ��������
//vec[1] = 5; // ���ο� �� ����

// vector�� �迭�� ���������� ���� ��� for���� ����� �� �ִ�.
//for (int vi : vec) {
//	cout << vi << endl;
//}

// vector�� ������ STL �����̳��� Ư¡�� ���� ���簡 �����ϴٴ� ���̴�.
// vector<int> vec2 = vec; // vec�� ��� ���빰�� ���� �����

// ���� ���� ���� ���빰�� �������� ���� ���縦 �ϴ� �� �ð��� ���� �ɸ���. �׷��� ������ ���͸� �ٸ� �Լ��� �Ѱ��� �� ���۷����� �Ѱ��ִ� ���� �����ϴٸ� �ݵ�� �׷��� ���ִ� ���� ����
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


// 13.7.2 pair (�� ���� ������ó�� ������� �� �ִ� �����̳��̴�. (�̶� �� ���� Ÿ���� �޶� �ȴ�.))
// pair�� ����Ϸ��� #include <utility>�� ��Ŭ����ؾ� �Ѵ�.

//pair<int, string> a = { 123, "abc" }; // int�� string�� ���� pair a�� �����, �ű⿡ ���� 123�� "abc"��� ���ڿ��� ���������� ���̴�.
// a�� ���� ���Ҹ� �ǹ��� ���� a.first, ���� ���Ҹ� �ǹ��� ���� a.second��� ������ �ȴ�.

// ���� �������ų� ���ο� ���� ������� ���� �ִ�.
// ex
//cout << a.first << endl; // 123 ���
//a.second = "def"; // ���ο� �� ����ֱ�

// �� �� �̻��� ���� �� ����� �� �ִ� �����̳ʵ� �ִ�!


// 13.7.3 map (�ٸ� ������ ���� ����(dictionary)���� �˷��� �ִ� ����̴�. (� ���� ������ �װͿ� �ش��ϴ� �ٸ� ���� �����ش�.))
// �̶� �ִ� ���� Ű(key)��� �θ���, Ű�� �־��� �� ������ ���� ���(value)��� �θ���. (��, ���� Ű�� ����� ������ �̷���� �����̶�� �� �� �ִ�.)
// map�� ����Ϸ��� #include <map>�� ��Ŭ����ؾ� �Ѵ�.

// Ű�� �ߺ��� �� ������, ����� �ߺ��� �� �ִ�!!!
// Ű������ ũ�� �񱳰� �����ؾ� �Ѵ�!!! (��, Ű�� ������ '<'(�ε�ȣ) ������ �����ؾ� �Ѵ�.) (ũ�� �񱳰� �Ұ����� ��쿣 unordered_map�̶�� ���� ����Ѵ�.)
// ex (������ �̸� -> Ű, �� ������ ���� -> ���)
//#include <iostream>
//#include <map>
//using namespace std;
//
//int main() {
//	map<string, int> fruitCnt; // ���ø� �Ķ���ʹ� ���� �� ���̸�, ���ʿ��� Ű�� Ÿ��, ���ʿ��� ����� Ÿ���� ���´�.
//
//	// ���ο� Ű�� �߰��ϴ� ��� 
//	fruitCnt["apple"] = 7; // �ܼ��� ���ο� Ű�� ���ο� ����� ������ �ȴ�. (�迭�� ����ϴ�.(�ε��� ��� Ű�� ������ �ȴ�.))
//	fruitCnt["banana"] = 4;
//	fruitCnt["orange"] = 10;
//
//	// Ű("banana")�� ���("banana"�� ����)�� �˰� �ʹٸ�?
//	cout << fruitCnt["banana"] << endl; // �ٳ����� ���� ��� (�迭�� ���Ҹ� ���������� ���� �ȴ�.)
//	
//	// ���� Ű�� �ش��ϴ� ����� ���������� �ϸ� 0�� ��ȯ�ϰ�, Ű�� ������ �� 0���� �����Ѵ�!!!
//	cout << fruitCnt["grape"] << endl; 
//
//	// ���� ��� ���Ҹ� ���� ��� for������ ���� ���� �ִ�.(�̶��� Ű�� ũ�� ������� �ȴ´�.)
//	// string�� ũ�⸦ ���� �� ������, ���������� �ռ��� ���� �� �۴�!
//	for (pair<string, int> fi : fruitCnt) {
//		cout << fi.first << ": " << fi.second << "��" << endl;
//	}
//}


// 13.7.4 sort (�迭 ������ ���ҵ��� ũ������� �����ϴ� �Լ��̴�. ���� ������� �� ������� ȿ���� �������̰�, � ���� ����� ��������� �����Ϸ����� �޷��ִµ�, �ϴ��� �Ϲ����� �����س� �� �ִ� ���� �̻����� ���� ���ĵȴٰ�� �̾߱��� �� �ִ�.(�׷��� ������ �ʿ��� �� ���������� �������!))
// sort�� ����Ϸ��� #include <algorithm>�� ��Ŭ����ؾ� �Ѵ�.
// �迭�� �����ϱ� ���ؼ��� sort �Լ��� �迭�� ������ ����Ű�� �����Ϳ� ���� ����Ű�� �����͸� �ִ´�. (�̶�, ���� ����Ű�� �����ʹ� ���� ������ ���Ҹ� ����Ű�� �����ͺ��� �ϳ� �� Ŀ�� �Ѵ�.)
// ex1 (�迭�� �����ϴ� ����)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int arr[7] = { 7, 6, 5, 4, 3, 2, 1 };
//	sort(arr, arr + 5);  // arr+0 �̻�, arr+n �̸����� ������ �迭�� ���� ������ �����Ѵ�. (�迭�� �ٲ�� �ȴ�)
//	for (int ai : arr) {
//		cout << ai << endl;
//	}
//
//	cout << endl; 
//
//	int arr_re[7] = { 3, 1, 4, 1, 5, 9, 2 };
//	sort(arr_re, arr_re + 7);  // arr+0 �̻�, arr+n �̸����� ������ �迭�� ���� ������ �����Ѵ�. (�迭�� �ٲ�� �ȴ�)
//	for (int ai : arr_re) {
//		cout << ai << endl;
//	}
//}


// ex2 (vector�� �����ϴ� ����)
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	vector<int> vec = { 3, 1, 4, 1, 5, 9, 2 };
//	sort(vec.begin(), vec.end()); // begin()�� vector�� ���� ������ �ּҰ���, end()�� vector�� ������ ���� + 1�� �ּҰ��� ����Ų��.
//
//	for (int vi : vec) {
//		cout << vi << endl;
//	}
//}


// ���չ���
// 1��
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


// 2��
#include <iostream>
using namespace std;

// �� �Լ� ������ �迭 (�Լ� �����ͷ� �̷���� �迭)
int (*OPS[4])(int, int) = {
	[](int a, int b) -> int {return a + b; },
	[](int a, int b) -> int {return a - b; },
	[](int a, int b) -> int {return a * b; },
	[](int a, int b) -> int {return a / b; }
};

int main() {
	int op;
	int a, b;

	cout << "������ ���� �Է� (0: ����, 1: ����, 2: ����, 3: ������) : ";
	cin >> op;
	cout << "���� 2�� �Է� : ";
	cin >> a >> b;

	cout << OPS[op](a, b) << endl;
}