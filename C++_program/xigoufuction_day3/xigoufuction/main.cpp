#include <iostream>

using namespace std;

class Line
{
public:
	void setlen(double len);
	double getlen(void);  //˽����Ҫͨ�������Ĺ�������ȡ��һ��ͨ�����캯����ʵ�ֳ�ʼ��
	Line(double len);
	~Line();	

private:
	double length;
};

Line::Line(double len):length(len)
{
	cout << "object is being created, length = " << len << endl;
}
Line::~Line(void)
{
	cout << "boject is being deleate " << endl;
}
void Line::setlen(double len)
{
	length = len;
}
double Line::getlen(void)
{
	return length;
}

int main()
{
	Line line(10.0);
	line.setlen(6.0);
	cout << "length of line " << line.getlen() << endl;
	system("pause");
	return 0;
}