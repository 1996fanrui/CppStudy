// ����05���˽�C++ĬĬ��д��������Щ����

#ifndef __RULE05_H__
#define __RULE05_H__

#include <string>

extern void Rule05();

// class Empty {}; �����ȼ��������д������������Ҫ������ʱ�������ᴴ����

class Empty {};

class EmptyCustom {
public:
	EmptyCustom() {}								// default���캯��
	EmptyCustom(const EmptyCustom&) {}				// copy���캯��
	~EmptyCustom() {}								// ����������ֻ�е�base class����Ϊ��ʱ�������
	EmptyCustom& operator=(const EmptyCustom&)		// copy assignment������
	{ /* ... */return *this; }
};

// ������Ϊ����Empty��Ա����
inline void Empty_Gen()
{
	Empty et1;							// default���캯������������
	Empty et2(et1);						// copy���캯��
	et2 = et1;							// copy assignment������
}

// ���������ܻ�ܾ�Ϊclass����operator=��������û�и�ֵ�������������ͺ�const���ͣ�
template<class T>
class NamedObject {
public:
	NamedObject(std::string &_namedValue, const T& _objectValue) : 
		namedValue(_namedValue), objectValue(_objectValue) {}
private:
	std::string &namedValue;
	const T objectValue;
};

inline void NoCopyAssign()
{
	static std::string name = "Default NamedObject";
	NamedObject<int> no1(name, 0);
	NamedObject<int> no2(name, 0);
	
	//no2 = no1; �޷���ֵ��������ɾ��
}

#endif // __RULE05_H__