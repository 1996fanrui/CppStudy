// ����12�����ƶ���ʱ������ÿһ���ɷ�
#ifndef __RULE12_H__
#define __RULE12_H__

#include <string>
#include <iostream>

extern void Rule12();

namespace rule12
{
	inline void LogCall(const std::string& funcName) { std::cout << funcName << std::endl; }	// ����һ��log entry
	class Customer
	{
	public:
		Customer(const std::string &n) : name(n) {}

		Customer(const Customer& rhs) : name(rhs.name)
		{
			LogCall("Customer copy constructor");
		}

		Customer& operator=(const Customer& rhs)
		{
			LogCall("Customer copy assignment operator");
			name = rhs.name;
			return *this;
		}

	private:
		std::string name;
	};

	// �ǵ�ʹ�û���Ŀ���������������ĳɷ�
	class PriorityCustomer : public Customer
	{
	public:
		PriorityCustomer(const std::string &n, int p) : Customer(n), priority(p) {}

		PriorityCustomer(const PriorityCustomer& rhs) : Customer(rhs), priority(rhs.priority)
		{
			LogCall("PriorityCustomer copy constructor");
		}

		PriorityCustomer& operator=(const PriorityCustomer& rhs)
		{
			LogCall("PriorityCustomer copy assignment operator");
			Customer::operator=(rhs);
			priority = rhs.priority;
			return *this;
		}

	private:
		int priority;
	};
}

#endif // __RULE12_H__