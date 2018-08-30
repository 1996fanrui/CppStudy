// ����15������Դ���������ṩ��ԭʼ��Դ�ķ���
#ifndef __RULE15_H__
#define __RULE15_H__

#include <iostream>

extern void Rule15();

namespace rule15
{
	// ��Ͷ�����͡��̳���ϵ�е�root class
	class Investment
	{
	public:
		Investment() { std::cout << "Investment()" << std::endl; }
		~Investment() { std::cout << "~Investment()" << std::endl; }
	};

	// ͨ�������������䶯̬����
	inline Investment* createInvestment()
	{
		return new Investment();
	}

	inline int daysHeld(const Investment* pi)
	{
		return 0;
	}

	// һ�� C API , inline ֻ��Ϊ�˷��㶨��
	typedef int* FontHandle;
	inline FontHandle getFont() { return new int(42); }
	inline void releaseFont(FontHandle fh) { delete fh; }
	inline void changeFontSize(FontHandle fh, int newSize) {}

	class Font
	{
	public:
		explicit Font(FontHandle fh) : f(fh) {}
		~Font() { releaseFont(f); }

		// ���ǿ�����Ҫ�� Font ת������ԭʼ��Դ FontHandler ����Ӧ C API
		FontHandle get() const { return f; }		// ��ʽת��
		operator FontHandle() const { return f; }	// ��ʽת��������ȫ������

	private:
		FontHandle f;			// ԭʼ��Դ
	};
}

#endif // __RULE15_H__