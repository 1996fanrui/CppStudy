#include "rule18.h"

using namespace rule18;

extern void Rule18()
{
	{
		Date1 d(30, 1, 1995);	// ���ˣ���һ���������·ݣ�����Ȼͨ���˱���
		Date1 d2(2, 30, 1995);	// ���ˣ�2�·�û��30��
	}

	{
		//Date2 d(30, 3, 1995);	// �������Ͳ��ԣ��޷�ͨ������
		Date2 d(Month::Feb(), Day(30), Year(1995));	// OK ��������ȷ
	}
}