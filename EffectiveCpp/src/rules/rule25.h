// ����25������д��һ�������쳣�� swap ����
#ifndef __RULE25_H__
#define __RULE25_H__

#include <vector>

extern void Rule25();

namespace rule25
{
	class WidgetImpl {
	public:
		WidgetImpl() 
		{
			// ���ⴴ��һ������
			for (int i = 0; i < 100000; i++) v.push_back(3.14);
		}

	private:
		int a, b, c;			// �����кܶ�����
		std::vector<double> v;	// ��ζ�Ÿ���ʱ��ܳ�
	};

	class Widget {				// ��� class ʹ�� pimpl �ַ�
	public:
		Widget() : pImpl(new WidgetImpl) {}
		~Widget() { delete pImpl; }

		Widget(const Widget& rhs)	// ���� Widget ʱ������������ WidghtImpl ����
			: pImpl(new WidgetImpl(*rhs.pImpl))
		{}

		Widget& operator=(const Widget& rhs)
		{
			auto p = new WidgetImpl(*rhs.pImpl);
			delete pImpl;
			pImpl = p;
			return *this;
		}

		void swap(Widget& other)
		{
			using std::swap;
			swap(pImpl, other.pImpl);
		}

	private:
		WidgetImpl *pImpl;		// ָ�룬��ָ���� Widget ����
	};

	namespace WidgetStuff {
		inline void swap(Widget& a, Widget& b)
		{
			a.swap(b);
		}
	}
}

#endif // __RULE25_H__