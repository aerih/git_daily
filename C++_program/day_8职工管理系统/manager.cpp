#include "manager.h"


Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = dId;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "Ա����ţ�" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t����ְ���ǣ��ල��ש" << endl;
}

//��ȡְ����λ����
string Manager::getDeptName()
{
	return string("����");
}