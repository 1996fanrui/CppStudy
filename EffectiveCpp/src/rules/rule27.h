// ����27����������ת�Ͷ���
#ifndef __RULE27_H__
#define __RULE27_H__

#include <iostream>

extern void Rule27();

namespace rule27
{
	// ���ߵ�Ψһһ��ʹ�þ�ʽת�͵�ʱ��������һ�� explicit ���캯�����������󴫵ݸ�һ������
	class Widget {
	public:
		explicit Widget(int size) {}
	};
	inline void doSomeWork(const Widget& w) {}

	// ����ָ���ֵ���ܲ���ͬ�����ڶ��ؼ̳��м���һֱ������
	class Base1 {};
	class Base2 {};
	class Derived : public Base1, public Base2 {};
	inline void Test2() {
		Derived d;
		Base2* pb = &d;

		std::cout << "pb: " << pb << std::endl;
		std::cout << "&d: " << &d << std::endl;
	}
}

#endif // __RULE27_H__