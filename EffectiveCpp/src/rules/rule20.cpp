#include "rule20.h"
#include <cstdio>

#ifdef __unix
#include <unistd.h>
#include <sys/time.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

unsigned long PITime()
{
#ifdef __unix
	struct timezone tz = { 0, 0 };
	timeval time;
	gettimeofday(&time, &tz);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
#elif defined(_WIN32)
	return GetTickCount();
#endif
}

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
