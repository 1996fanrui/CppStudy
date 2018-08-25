#ifndef __RULE09_H__
#define __RULE09_H__

#include <string>
#include <iostream>

extern void Rule09();

namespace bug
{
	// ���н��׵�base class
	class Trasaction
	{
	public:
		Trasaction()
		{
			// ...
			logTransaction();	// ����û�а취������������д�ĺ�����C++������
		}
		virtual void logTransaction() const = 0;		// ����һ�������Ͳ�ͬ����ͬ����־��¼��log entry��
	};

	class BuyTransaction : public Trasaction
	{
	public:
		virtual void logTransaction() const { std::cout << "BuyTransaction::logTransaction" << std::endl; }		// Log���ͽ���
	};

	inline void Trasaction::logTransaction() const { std::cout << "Trasaction::logTransaction" << std::endl; }
}

namespace correct
{
	class Transaction
	{
	public:
		explicit Transaction(const std::string& log_info)
		{
			logTransaction(log_info); // ����Ǹ�non-virtual����
		}

		void logTransaction(const std::string& log_info) const // ����Ǹ�non-virtual����
		{
			std::cout << log_info << std::endl;
		}
	};

	class BuyTransaction : public Transaction
	{
	public:
		BuyTransaction() : Transaction(createLogString("Construct")) {} // ��Log��Ϣ���ݸ�base class���캯��

	private:
		static std::string createLogString(const char* log) { return std::string("BuyTransaction_") + log; }
	};
}

#endif //__RULE09_H__