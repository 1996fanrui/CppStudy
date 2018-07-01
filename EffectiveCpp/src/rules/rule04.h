// ����04��ȷ������ʹ��ǰ�ѱ���ʼ��

#ifndef __RULE04_H__
#define __RULE04_H__

#include <iostream>
#include <string>
#include <list>

// ��ʼ����������
inline void Init_BuiltinTyoe()
{
	int x = 0;				// �ֹ���ʼ��
	const char* text = "A C-style string";

	double d;
	std::cin >> d;			// �Զ�ȡinput stream�ķ�ʽ��ɳ�ʼ��
}

// �ù��캯����ʼ���б��ʼ�����ݳ�Ա
class PhoneNumber { /* ... */ };
class ABEntry {				// ABEntry = "Address Book Entry"
public:
	ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> phones)
		: theName(name),
		theAddress(address),
		thePhones(phones),
		numTimesConsulted(0)
	{}

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

// ��local static�������non-local static����
class FileSystem {
public:
	std::size_t numDisks() const { /* ... */return 0; }		// �ڶ��Ա����֮һ
};

inline FileSystem& tfs()
{
	static FileSystem fs;
	return fs;
}

class Directory {
public:
	Directory()
	{
		std::size_t disks = tfs().numDisks();
		/* ... */
	}
};

inline Directory& tempDir()
{
	static Directory td;
	return td;
}

extern void Rule04();

#endif // __RULE04_H__