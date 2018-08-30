// ����16���ɶ�ʹ�� new �� delete ʱҪ��ȡ��ͬ����ʽ
#ifndef __RULE16_H__
#define __RULE16_H__

#include <string>
#include <iostream>

extern void Rule16();

namespace rule16
{
	inline void bug1()
	{
		// ������Ϊδ�ж��壬ʵ������ vs �±���
		std::string* stringArray = new std::string[100];

		int *np = (int*)stringArray - 1;	// ǰһ���֣�������鳤��
		std::cout << *np << std::endl;

		delete stringArray;
	}

	inline void correct()
	{
		std::string* stringPtr1 = new std::string;
		std::string* stringPtr2 = new std::string[100];

		delete stringPtr1;		// ɾ��һ������
		delete[] stringPtr2;	// ɾ��һ���ֶ�����ɵ�����
	}

	inline void case_typedef()
	{
		// ��� typedef ��һ�����飬��ôҲҪʹ�� delete[] ɾ����̬����
		typedef std::string AddressLines[4];
		std::string *pal = new AddressLines;

		//delete pal;	// ��Ϊδ�ж��壡
		delete[] pal;	// ��ȷ
	}
}

#endif // __RULE16_H__