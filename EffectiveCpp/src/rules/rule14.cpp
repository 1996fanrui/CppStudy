#include "rule14.h"

using namespace rule14;

extern void Rule14()
{
	Mutex m;
	{
		Lock m1(&m);

		// ִ�� critical section �ڵĲ���
		// ��������ĩβ���Զ��������������
	}

	{
		Lock2 m2(&m);

		// ������ĩβ���Զ��������
	}
}