// ����17���Զ�����佫 newed ������������ָ��
#ifndef __RULE17_H__
#define __RULE17_H__

#include <stdexcept>
#include <memory>

extern void Rule17();

namespace rule17
{
	class Widget
	{
		char buffer[1024 * 1024];	// �����ڴ�й©��buffer�� vs2015 �¹۲�
	};

	inline int priority()
	{
		// ���׳�һ���쳣�ĺ���
		throw std::runtime_error("exception");
	}

	// һ�����ܻᷢ���ڴ�й©�ĺ��������ɴ���ĳ�ʼ�� pw
	inline void processWidget(std::shared_ptr<Widget> pw, int priority) {}
}

#endif // __RULE17_H__