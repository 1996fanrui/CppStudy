#include "rule20.h"
#include <cstdio>
#include "../pitime.h"

using namespace rule20;

void Rule20()
{
	// �ô����õķ�ʽ���⿽�����Ӷ����Ч��
	{
		Student s;

		auto beg_time = PITime();
		for (int i = 0; i < 100000; ++i)
		{
			validateStudent(s);
		}
		auto end_time = PITime();
		printf("pass-by-value cost time: %lu ms\n", end_time - beg_time);

		beg_time = PITime();
		for (int i = 0; i < 100000; ++i)
		{
			validateStudent2(s);
		}
		end_time = PITime();
		printf("pass-by-reference-to-const cost time: %lu ms\n", end_time - beg_time);
	}

	// �ô����õķ�ʽ���� slicing ����
	{
		WindowWithScrollBars wsb("WindowWithScrollBars");
		printNameAndDisplay(wsb);

		printNameAndDisplay2(wsb);
	}
}
