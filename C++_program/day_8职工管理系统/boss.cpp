#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_did = dId;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "�ɶ���ţ�" << this->m_id
		<< "\tԱ��������" << this->m_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t����ְ���ǣ��ù����Ӱ���" << endl;
}

//��ȡְ����λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}