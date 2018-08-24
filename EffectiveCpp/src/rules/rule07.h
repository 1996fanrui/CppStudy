// ����07��Ϊ��̬��������virtual��������
#ifndef __RULE07_H__
#define __RULE07_H__

#include <ctime>

extern void Rule07();

class TimeKeeper
{
public:
	TimeKeeper() {}
	//~TimeKeeper() {}		// ���ﲻӦ���� non-virtual �������������delete derived class�����δ����
	virtual ~TimeKeeper() {}// ��ȷ����������������

	virtual time_t GetCurrentTime() { return 0; }
};

class AtomicClock : public TimeKeeper {};			// ԭ����
class WaterClock : public TimeKeeper {};			// ˮ��
class WristWatch : public TimeKeeper {};			// ���

// ����һ��ָ�룬ָ��һ��TimeKeeper������Ķ�̬�������
inline TimeKeeper* getTimerKeeper()
{
	return new AtomicClock;
}

// ���class����virtual������������������Ϊvirtual�����Ǹ�������
class Point {
public:
	Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
	~Point() {}
	//virtual ~Point() {}	// �����⣬�����С����32bit ~ 64bit���������һ��vptrָ��

private:
	int x, y;
};

#endif // __RULE07_H__ 