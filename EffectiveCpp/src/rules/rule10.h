// ����10��
#ifndef __RULE10_H__
#define __RULE10_H__

#include <iostream>

extern void Rule10();

// Ϊ��ʵ�֡�������ֵ������ֵ���������뷵��һ��referenceָ����������ʵ��
// ������Ϊclassesʵ�ָ�ֵ����ʱӦ����ѭ��Э��
namespace rule10
{
	class Widget
	{
		friend std::ostream& print(std::ostream &os, const Widget &w);
	public:
		Widget() : i(0) {}
		Widget& operator=(const Widget &rhs)
		{
			i = rhs.i;
			return *this;
		}

		Widget& operator+=(const Widget& rhs)	// ������+=, -=, *=, �ȵ�
		{
			i += rhs.i;
			return *this;
		}

		Widget& operator=(int rhs)	// Ҳ���ã���ʹ�������Ͳ�����Э��
		{
			i = rhs;
			return *this;
		}

	private:
		int i;
	};

	inline std::ostream& print(std::ostream &os, const Widget &w)
	{
		os << "Widget: " << w.i;
		return os;
	}
}

#endif // __RULE10_H__