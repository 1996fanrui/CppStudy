#include "rule24.h"

using namespace rule24;

void Rule24()
{
	Rational oneEight(1, 8);
	Rational result = oneEight * 2; // OK
	result = 2 * oneEight;			// ����˷������� member ��������ô�� OK

	std::cout << result << std::endl;
}