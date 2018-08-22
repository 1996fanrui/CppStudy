// ����14������Դ��������С�� copying ��Ϊ
#ifndef __RULE14_H__
#define __RULE14_H__

#include "rule06.h"
#include <iostream>
#include <memory>

extern void Rule14();

namespace rule14
{
	class Mutex
	{
		friend void lock(Mutex*);
		friend void unlock(Mutex*);

	public:
		bool IsLocked() const { return is_locked; }

	private:
		bool is_locked = false;
	};

	inline void lock(Mutex *pm) { 
		/* if (locked) wait */pm->is_locked = true;
		std::cout << __FUNCTION__ << std::endl; 
	}
	inline void unlock(Mutex *pm) {
		pm->is_locked = false;
		std::cout << __FUNCTION__ << std::endl;
	}

	// Ϊ��ȷ����������Ҫ����һ��RAII class����
	class Lock : private Uncopyable // RAII ���󱻸���Ҳ����������˾ܾ�
	{
	public:
		explicit Lock(Mutex *pm) : mutexPtr(pm) { lock(pm); }
		~Lock() { unlock(mutexPtr); }

	private:
		Mutex *mutexPtr;
	};

	// ʹ�� shared_ptr ��ɾ�����������ü������͵���Դ
	class Lock2
	{
	public:
		explicit Lock2(Mutex *pm) : mutexPtr(pm, unlock) { lock(pm); }

	private:
		std::shared_ptr<Mutex> mutexPtr;
	};
}

#endif // __RULE14_H__