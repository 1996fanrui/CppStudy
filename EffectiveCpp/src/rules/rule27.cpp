#include "rule27.h"

using namespace rule27;

void Rule27()
{
	// һ����������ת�Ͷ���
	doSomeWork(Widget(15));

	// һ��C++����ת�Ͷ����������õ�Ӧ���������
	doSomeWork(static_cast<Widget>(15));

	Test2();
}