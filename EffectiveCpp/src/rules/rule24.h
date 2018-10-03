// ����24�������в�����������ת������Ϊ�˲��� non-member ����
#ifndef __RULE24_H__
#define __RULE24_H__

#include <iostream>

extern void Rule24();

namespace rule24
{
	// һ������������
	class Rational {
	public:
		// ���캯�����ⲻΪ explicit ���Ӷ����� int-to-Rational ��ʽת��
		Rational(int numberator = 0, int denominator = 1) : numberator_(numberator), denominator_(denominator) {}

		int numerator() const { return numberator_; }
		int denominator() const { return denominator_; }

		// ���˷����㶨��� member ���������������Բ�ǿ
		/*const Rational operator* (const Rational& rhs) const
		{
			return Rational(numberator_ * rhs.numberator_, denominator_ * rhs.denominator_);
		}*/

	private:
		int numberator_, denominator_;
	};

	// Ӧ�ý��˷���������� non-member ����
	inline const Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
	}

	inline std::ostream& operator<<(std::ostream &os, Rational &r)
	{
		os << r.numerator() << "/" << r.denominator();
		return os;
	}
}

#endif // __RULE24_H__