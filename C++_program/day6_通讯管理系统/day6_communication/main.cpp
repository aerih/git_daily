#include <iostream>
using namespace std;

int q = 0;
void showMainMenu()
{
	cout << "1������ϵ��" << endl;
	cout << "2������ϵ��" << endl;
	cout << "3��ɾ��ϵ��" << endl;
	cout << "4������ϵ��" << endl;
	cout << "5������ϵ��" << endl;
	cout << "6������ϵ��" << endl;
	cout << "0���˳�" << endl;
}

void selet()
{
	int flag = 0;
	cin >> flag;
	
	switch (flag)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 0:
		cout << "��ӭ�´�ʹ��" << endl;
		q = 1;
		break;
	default:
		break;
	}
}

int main()
{
	while(1)
	{ 
		showMainMenu();
		selet();
		if (q == 1) break;
	}

	system("pause");
	return 0;
}