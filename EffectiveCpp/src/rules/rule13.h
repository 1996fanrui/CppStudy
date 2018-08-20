// ����13���Զ��������Դ
#ifndef __RULE13_H__
#define __RULE13_H__

#include <iostream>
#include <memory>

extern void Rule13();

namespace rule13
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

	inline Investment* createInvestmentList(int n)
	{
		return new Investment[n];
	}

	inline void bug()
	{
		Investment *pInv = createInvestment();
		return; // ����ĳ��ԭ��С��return�ˣ���������ڴ�й©
		delete pInv;
	}

	inline void use_auto_ptr()
	{
		// auto_ptr������������Զ���ִ��delete
		std::auto_ptr<Investment> pInv(createInvestment());

		std::auto_ptr<Investment> pInv2(pInv);	// ����pInv2ָ�����pInvΪnullptr

		pInv = pInv2;							// ����pInvָ�����pInv2Ϊnullptr
	}

	inline void use_shared_ptr()
	{
		// shared_ptr��������ָ��ָ��ͬһ������
		std::shared_ptr<Investment> pInv(createInvestment());

		std::shared_ptr<Investment> pInv2(pInv);	// pInv��pInv2ָ��ͬһ������
	}

	inline void use_unique_ptr()
	{
		// unique_ptr�������ڷ��䶯̬����
		std::unique_ptr<Investment[]> pInv(createInvestmentList(3));
	}
}

#endif // __RULE13_H__