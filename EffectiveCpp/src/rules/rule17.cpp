#include "rule17.h"

#ifdef _MSC_VER
#include <windows.h>
#endif

#ifdef __unix
#include <unistd.h>
#endif

using namespace rule17;

static void sleep(int second)
{
#ifdef _MSC_VER
	Sleep(second * 1000);
#endif

#ifdef __unix
	::sleep(second);
#endif
}

void Rule17()
{
	// ����ĵ��ã������쳣�׳�ǰ��newed ָ��δ�ܳ�ʼ��������ָ�룬�Ӷ������ڴ�й©
	/*for (int i = 0; i < 100; ++i)
	{
		try
		{
			processWidget(std::shared_ptr<Widget>(new Widget()), priority());
		}
		catch ( ... ) {}
		
		sleep(1);
	}*/

	// ��ȷ���������ö������� newed ����洢������ָ����
	for (int i = 0; i < 100; ++i)
	{
		try
		{
			std::shared_ptr<Widget> pw(new Widget);
			processWidget(pw, priority());
		}
		catch (...) {}

		sleep(1);
	}
}