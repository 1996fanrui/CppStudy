#include "rule25.h"
#include "../pitime.h"

using namespace rule25;

void Rule25()
{
	// �������ɴΣ��鿴Ч��
	Widget w1, w2;

	unsigned long beg_time = PITime();
	for (int i = 0; i < 10000; i++)
	{
		/*
		 ������Ĭ�ϵ� swap �����������ܸ�ֵ�Ĵ���
		 �����Զ���� swap ������ֱ�ӽ���ָ�룬����������������ݣ� HUGE SPEED ����
		*/
		//std::swap(w1, w2);

		using namespace std;
		swap(w1, w2);	// ������ using ����ʽ�����Ի������ȷ�İ汾
	}
	unsigned long end_time = PITime();

	printf("use time: %lu ms\n", end_time - beg_time);
}
