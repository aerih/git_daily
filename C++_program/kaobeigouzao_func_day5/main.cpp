#include <iostream>
using namespace std;

//class Line
//{
//public:
//	int getlength(void);
//	Line(int len);
//	Line(const Line& obj);
//	~Line();
//private:
//	int* ptr;
//};
//
//Line::Line(int len)
//{
//	cout << "���ù��캯��" << endl;
//	ptr = new int;
//	*ptr = len;
//}
//Line::Line(const Line& obj)
//{
//	cout << "���ÿ������캯����Ϊptr��ֵ" << endl;
//	ptr = new int;
//	*ptr = *obj.ptr;
//}
//Line::~Line()
//{
//	cout << "�ͷ��ڴ�" << endl;
//	delete ptr;
//}
//int Line::getlength(void)
//{
//	return *ptr;
//}
//void display(Line obj) {
//	cout << "line�ĳ��ȴ�С" << obj.getlength() << endl;
//}
//int main() {
//	Line line(10);
//	display(line);
//}
int Max(int x, int y)
{
	return (x > y) ? x : y;
}

// �����������
int main()
{

	cout << "Max (20,10): " << Max(20, 10) << endl;
	cout << "Max (0,200): " << Max(0, 200) << endl;
	cout << "Max (100,1010): " << Max(100, 1010) << endl;
	return 0;
}