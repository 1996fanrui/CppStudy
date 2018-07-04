// ����06��������ʹ�ñ������Զ����ɵĺ������͸���ȷ�ܾ�
#ifndef __RULE06_H__
#define __RULE06_H__

extern void Rule06();

// ���õķ���������Ա������˽���Ҳ�����
class HomeForSale
{
public:
	HomeForSale() {}

private:
	HomeForSale(const HomeForSale&);
	HomeForSale& operator=(const HomeForSale&);
};

// ��һ�ַ�������������һ�����ɿ�����empty base class����������̳�
class Uncopyable
{
protected:
	Uncopyable() {}			// ����derived�����������
	~Uncopyable() {}

private:
	Uncopyable(const Uncopyable&);		// ��֯copying
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale2 : public Uncopyable
{
public:
	HomeForSale2() {}
	~HomeForSale2() {}
};

#endif // __RULE06_H__