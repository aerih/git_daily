#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = dId;
}

void Employee::showInfo()
{
	cout << "Ա����ţ�" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t����ְ���ǣ���ש" << endl;
}

string Employee::getDeptName()
{
	return string("Ա��");		//����ֱ����Ա������������string*�ĸ�ʽ
}