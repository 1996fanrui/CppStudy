// ����08�������쳣������������
#ifndef __RULE08_H__
#define __RULE08_H__

#include <stdexcept>
#include <iostream>

extern void Rule08();

#pragma warning(disable:4297) // ignore warning: function assumed not to throw an exception ...

class Widget
{
public:
	~Widget() { throw std::runtime_error("exception occured on destructor"); }
};

#pragma warning(default:4297)

class DBConnection
{
public:
	static DBConnection create()	// �����������DBConnection����
	{
		static DBConnection db;
		return db;
	}

	// �ر�������ʧ�����׳��쳣
	void close()
	{
		int is_succ = false;
		if (!is_succ)
		{
			throw std::runtime_error("close failed");
		}
	}
};

class DBConn
{
public:
	DBConn(const DBConnection& _db) : db(_db), closed(false) {}
	~DBConn()			// ȷ�����ݿ��������ǻᱻ�ر�
	{
		// ���close�׳��쳣�����񲢼�¼
		try { db.close(); }
		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
		}
	}

	// ���ͻ�ʹ�õ��º���
	void close()
	{
		db.close();
		closed = true;
	}

private:
	DBConnection db;
	bool closed;
};

#endif //__RULE08_H__