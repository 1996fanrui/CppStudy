#include "rule09.h"

extern void Rule09()
{
	{
		using namespace bug;
		BuyTransaction b; // ��������������logTransaction�����仹δ����
	}

	{
		using namespace correct;
		BuyTransaction b;
	}
}