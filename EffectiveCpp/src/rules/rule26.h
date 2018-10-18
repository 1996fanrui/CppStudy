// ����26���������Ӻ��������ʽ�ĳ���ʱ��
#ifndef __RULE26_H__
#define __RULE26_H__

#include <string>
#include <stdexcept>

inline void Rule26()
{
	// ����ѭ�������Ǳ����Ķ���λ�ã�ͨ���õڶ��֣���һ�ֳ���Ŀ�����ԺͿ�ά���Բ��ã�

	// 1���������� + 1�����캯�� + n����ֵ����
	{
		std::string s;
		for (int i = 0; i < 10; ++i) {
			s = std::to_string(i);
		}
	}
	
	// n�����캯�� + n����������
	{
		for (int i = 0; i < 10; ++i) {
			std::string s = std::to_string(i);
		}
	}
}

namespace rule26
{
	const int MinimumPasswordLength = 10;

	// �����������ض��������encrypted��
	// ����쳣���׳�����Ҫ���� encrypted �Ĺ���������ɱ�
	inline std::string encryptPassword_bad(const std::string& password)
	{
		using namespace std;
		string encrypted;
		if (password.length() < MinimumPasswordLength) {
			throw logic_error("password is too short");
		}

		// ���� ...
		return encrypted;
	}

	// �Ӻ� encrypted �Ķ��壬ֱ��������Ҫ��
	inline std::string encryptPassword_good(const std::string& password)
	{
		using namespace std;
		if (password.length() < MinimumPasswordLength) {
			throw logic_error("password is too short");
		}

		string encrypted(password); // ������ʼ�� �� defalut-construct + ��ֵ���� Ч�ʸ�
		// ���� ...
		return encrypted;
	}
}

#endif // __RULE26_H__