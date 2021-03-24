#include <iostream>
using namespace std;
#include <String>
#define MAX 1

struct Person
{
	string m_name;
	int m_sex;			//1����	2��Ů
	int m_age;
	string m_number;
	string m_addr;
};
struct AddressBook
{
	struct Person personArry[MAX];
	int m_size;
};

int q = 0;
AddressBook new_abs;

void showMainMenu()
{
	
	cout << "*****************" << endl;
	cout << "***1������ϵ��***" << endl;
	cout << "***2������ϵ��***"  << endl;
	cout << "***3��ɾ��ϵ��***"  << endl;
	cout << "***4������ϵ��***"	 << endl;
	cout << "***5������ϵ��***"	 << endl;
	cout << "***6������ϵ��***"	 << endl;
	cout << "***0��  �˳�  ***"	<< endl;
	cout << "***           ***" << endl;
	cout << "*****************" << endl;
}

void showPerson(AddressBook * abs)
{
	if (abs->m_size == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "����:" << abs->personArry[i].m_name << "\t";
			cout << "����:" << abs->personArry[i].m_age << "\t";
			cout << "�Ա�:" << (abs->personArry[i].m_sex == 1 ? "��":"Ů") << "\t";
			cout << "�绰:" << abs->personArry[i].m_number << "\t";
			cout << "סַ:" << abs->personArry[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void addPerson(AddressBook* abs)
{
	
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
	}
	else {
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArry[abs->m_size].m_name = name;
		//***************************************
		cout << "�������Ա�" << endl;
		cout << " 1--man  2---woman " << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
				break;
			else
				cout << "�����������������" << endl;
		}
		abs->personArry[abs->m_size].m_sex = sex;
		//************************************
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArry[abs->m_size].m_age = age;
		//************************************
		cout << "������绰���룺" << endl;
		string phone;
		cin >> phone;
		abs->personArry[abs->m_size].m_number = phone;
		//************************************
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArry[abs->m_size].m_addr = address;
		//************************************
		abs->m_size++;
	}
	
	system("pause");
	system("cls");
}

int isExist(AddressBook abs, string name)
{
	for (int i = 0; i < abs.m_size; i++)
	{
		if (abs.personArry[i].m_name == name)
			return i;
	}
	return -1;
}

void deletPers()
{
	string name;
	cout << "������Ҫɾ����ϵ�˵�����" << endl;
	cin >> name;
	int ret = isExist(new_abs, name);
	if (ret == -1)
	{
		cout << "��ϵ��Ϊ��" << endl;
	}
	//else if (ret = MAX - 1)
	//{
	//	new_abs.m_size--;
	//}
	else
	{
		for (int i = ret; i < new_abs.m_size; i++)
		{
			new_abs.personArry[i] = new_abs.personArry[i + 1];
		}
		cout << "ɾ���ɹ�" << endl;
		new_abs.m_size--;
	}
	system("pause");
	system("cls");
}

void checkPer(AddressBook* abs)
{
	cout << "����������˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(new_abs, name);
	if (ret != -1)
	{
		cout << "����:" << abs->personArry[ret].m_name << "\t";
		cout << "����:" << abs->personArry[ret].m_age << "\t";
		cout << "�Ա�:" << (abs->personArry[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "�绰:" << abs->personArry[ret].m_number << "\t";
		cout << "סַ:" << abs->personArry[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPers(AddressBook *abs)
{
	cout << "������Ҫ�޸ĵ��û�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(new_abs, name);
	if (ret != -1)
	{
		cout << "�ҵ�����ϵ��" << endl;
		cout << "�������޸��ߵ�������" << endl;
		cin >> name;
		abs->personArry[ret].m_name = name;
		//***************************************
		cout << "�������޸��ߵ��Ա�" << endl;
		cout << " 1--man  2---woman " << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
				break;
			else
				cout << "�����������������" << endl;
		}
		abs->personArry[ret].m_sex = sex;
		//************************************
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArry[ret].m_age = age;
		//************************************
		cout << "������绰���룺" << endl;
		string phone;
		cin >> phone;
		abs->personArry[ret].m_number = phone;
		//************************************
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArry[ret].m_addr = address;
		//************************************
		cout << "�޸���ɣ�" << endl;	
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBook * abs)
{
	abs->m_size = 0;
	cout << "ͨѶ����������" << endl;
	system("pause");
	system("cls");
}

void checkPersonByNumber(AddressBook* abs)
{
	cout << "������������" << endl;
	int ret;
	cin >> ret;
	cout << "����:" << abs->personArry[ret].m_name << "\t";
	cout << "����:" << abs->personArry[ret].m_age << "\t";
	cout << "�Ա�:" << (abs->personArry[ret].m_sex == 1 ? "��" : "Ů") << "\t";
	cout << "�绰:" << abs->personArry[ret].m_number << "\t";
	cout << "סַ:" << abs->personArry[ret].m_addr << endl;
	system("pause");
	system("cls");
}

void selet()
{
	int flag = 0;
	cin >> flag;

	switch (flag)
	{
	case 1:
		addPerson(&new_abs);
		break;
	case 2:
		showPerson(&new_abs);
		break;
	case 3:
		deletPers();
		break;
	case 4:
		checkPer(&new_abs);
		break;
	case 5:
		modifyPers(&new_abs);
		break;
	case 6:
		cleanPerson(&new_abs);
		break;
	case 7:
		checkPersonByNumber(&new_abs);
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
	new_abs.m_size = 0;
	while (true)
	{
		showMainMenu();
		selet();
		if (q == 1) break;
	}

	//system("pause");
	return 0;
}