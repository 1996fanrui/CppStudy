#include "rule15.h"
#include <memory>

using namespace rule15;

void Rule15()
{
	{
		std::shared_ptr<Investment> pInv(createInvestment());

		//int days = daysHeld(pInv);	// ������Ҫԭʼָ��
		int days = daysHeld(pInv.get());
	}

	FontHandle f2;
	{
		Font f(getFont());
		int newFontSize = 10;
		changeFontSize(f.get(), newFontSize);

		changeFontSize(f, newFontSize);

		// ��ʽת����Σ�յ�
		f2 = f;
	}
	// f2 �� dangle ���� f ����ʱ�ͷ��˵ײ���Դ
}