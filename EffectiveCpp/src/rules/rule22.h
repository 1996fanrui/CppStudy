// ����22������Ա��������Ϊ private

#include <iostream>

extern void Rule22();

namespace rule22
{
	// ����Ա������ public ��
	class Foo
	{
	public:
		Foo() : id(0) {}
		int GetID() const { return id; }

		int id;
	};

	// һ�������⣬�����Ա������ public ����ô���ж��ַ��ʰ취
	inline void func1()
	{
		Foo f;
		std::cout << f.id << std::endl;
		std::cout << f.GetID() << std::endl;
	}

	// �޷��õ���ȷ�Ŀ��ơ�û�з�װ��
	inline void func2()
	{
		Foo f;
		f.id = 10; // ������ id ���Ƴ��ˣ��ͻ���Ҳ�ᱻ�ƻ�
	}
}