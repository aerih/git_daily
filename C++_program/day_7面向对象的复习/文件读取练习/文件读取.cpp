#include <fstream>
#include <iostream>
using namespace std;
#include <string>

void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}



	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

}

int main() {

	test01();

	system("pause");

	return 0;
}


