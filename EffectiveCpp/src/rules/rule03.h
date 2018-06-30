// ����03��������ʹ��const

#ifndef __RULE03_H__
#define __RULE03_H__

#include <vector>
#include <string>
#include <iostream>

extern void Rule03();

// const��ָ��
inline void Const_And_Pointer()
{
	char greeting[] = "Hello";
	
	char *p = greeting;					// non-const pointer, non-const data
	const char *lcp = greeting;			// non-const pointer, const data(low-level const)
	char *const tcp = greeting;			// const pointer, non-const data(top-level const)
	const char* const cp = greeting;	// const pointer, const data
}

// const�������
inline void Const_And_Iterator()
{
	std::vector<int> vec{1, 2, 3, 4};

	const std::vector<int>::iterator iter = vec.begin();	// iter���������T *const
	*iter = 10;				// û���⣬�ı�iter��ָ��
	///++iter;				// ����iter��const

	std::vector<int>::const_iterator citer = vec.begin();	// iter���������const T*
	//*citer = 10;			// ����*citer��const
	++citer;				// û���⣬�ı�citer
}

// const��Ա����
class TextBlock {
public:
	TextBlock(const char* _text) : text(_text) {}

	const char& operator[](std::size_t position) const		// operator[] for const����
	{ return text[position]; }

	char& operator[](std::size_t position)					// operator[] for non-const����
	{ return text[position]; }

private:
	std::string text;
};

inline void Use_TextBlock()
{
	TextBlock tb("Hello");
	std::cout << tb[0];		// ����non-const TextBlock::operator[]
	tb[0] = 'x';			// û���⣺дһ��non-const TextBlock

	const TextBlock ctb("Hello");
	std::cout << ctb[0];	// ����const TextBlock::operator[]
	//ctb[0] = 'x';			// ����дһ��const TextBlock����ͼ��һ��const char&��ֵ��
}

// ��const��non-const��Ա�����б����ظ�
class CTextBlock
{
public:
	CTextBlock(const char *text) : pText(new char[strlen(text) + 1]()) { strcpy(pText, text); }
	~CTextBlock() { delete pText; }

	const char& operator[](std::size_t position) const
	{
		// ... �߽��� bounds checking
		// ... ��־���ݷ��� log access data
		// ... �������������� verify data integrity
		return pText[position];
	}

	char &operator[](std::size_t position)
	{
		// ����const�汾�ĺ���
		return const_cast<char&>(
			static_cast<const CTextBlock&>(*this)[position]
			);
	}

private:
	char *pText;
};

inline void Use_CTextBlock()
{
	CTextBlock tb("Hello");
	std::cout << tb[0];
	tb[0] = 'x';

	const CTextBlock ctb("Hello");
	std::cout << ctb[0];
}

#endif // __RULE03_H__