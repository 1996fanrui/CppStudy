// ����11����operator=�д������Ҹ�ֵ��
#ifndef __RULE11_H__
#define __RULE11_H__

#include <iostream>

extern void Rule11();

namespace rule11
{
	class Widget
	{
	public:
		Widget(int i) : ip(new int(i)) {}
		~Widget() { delete ip; }
		Widget(const Widget &w) : ip(new int(*w.ip)) {}

		void swap(Widget &w)
		{
			std::swap(ip, w.ip);
		}

		void print() { std::cout << *ip << std::endl; }

		Widget& operator=(const Widget& rhs);

	private:
		int *ip;
	};

	inline Widget& Widget::operator=(const Widget& rhs)
	{
		// ��������ӣ��޷������Ը�ֵ
		if (bool bug = false)
		{
			delete ip;
			ip = new int(*rhs.ip);
			return *this;
		}

		// ֤ͬ���ԣ������Ը�ֵ�������߱��쳣��ȫ�ԣ���new�׳����쳣���޷���ԭ��
		if (bool identity_test = false)
		{
			if (this == &rhs) return *this;

			delete ip;
			ip = new int(*rhs.ip);
			return *this;
		}

		// ��ȷ������������ָ��ĸ������ɹ�new����delete
		if (bool correct = false)
		{
			int *tmp = ip;
			ip = new int(*rhs.ip);
			delete tmp;
			return *this;
		}

		// copy and swap������Ҳӵ���쳣��ȫ����Ҫ����Ĵ��루һ��copy���캯����һ���Զ����swap������
		if (bool copy_and_swap = true)
		{
			Widget tmp(rhs);	// ��ʱ�ĸ����ǰ�ȫ�ģ������Զ�����
			swap(tmp);
			return *this;
		}

		return *this;
	}
}

#endif // __RULE11_H__