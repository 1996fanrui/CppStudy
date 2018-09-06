// ����18���ýӿ����ױ���ȷʹ�ã����ױ�����
#ifndef __RULE18_H__
#define __RULE18_H__

extern void Rule18();

namespace rule18
{
	// ������͵Ľӿڿ��ܻᱻ���ã����ɴ������Ĳ����� int �޷�ʶ�������ʵ������
	class Date1 {
	public:
		Date1(int month, int day, int year) : month_(month), day_(day), year_(year) {}

	private:
		int month_, day_, year_;
	};

	// ʹ������ϵͳ
	struct Day {
		explicit Day(int d) : val(d) {}
		int	val;
	};

	struct Month {
	public:
		static Month Jan() { return Month(1); }	// �Ժ����滻���󣬱���ĳ���ض��·�
		static Month Feb() { return Month(2); }
		//...
		static Month Dec() { return Month(12); }
	private:
		explicit Month(int m) : val(m) {}		// ��ֹ�����µ��·�
		int val;
	};

	struct Year {
		explicit Year(int y) : val(y) {}
		int val;
	};

	class Date2 {
	public:
		Date2(const Month& m, const Day& d, const Year& y) : month_(m), day_(d), year_(y) {}

	private:
		Month month_;
		Day day_;
		Year year_;
	};
	
}

#endif // __RULE18_H__