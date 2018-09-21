#ifndef __RULE23_H__
#define __RULE23_H__

#include <cstring>

extern void Rule23();

namespace rule23
{
	class WebBrowser {
	public:
		void clearCache()
		{
			memset(cache, 0, sizeof(cache));
		}

		void clearHistory()
		{
			memset(history, 0, sizeof(history));
		}

		void removeCookies()
		{
			memset(cookies, 0, sizeof(cookies));
		}

		// һ��ִ�������������ķ�ʽ
		// �����ַ�ʽ�ķ�װ�Եͣ�Խ�ຯ���ɷ��ʷ�װ���ݣ���װ�Ծ�Խ��
		void clearEverthing()
		{
			this->clearCache();
			this->clearHistory();
			this->removeCookies();
		}

	private:
		char cache[1024];
		char history[1024];
		char cookies[1024];
	};

	// ��һ��ִ�������������ķ�ʽ
	inline void clearBrowser(WebBrowser &wb)
	{
		wb.clearCache();
		wb.clearHistory();
		wb.removeCookies();
	}
}

#endif // __RULE23_H__