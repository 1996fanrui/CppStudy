// ����28�����ⷵ�� handles ָ������ڲ��ɷ�
#ifndef __RULE28_H__
#define __RULE28_H__

#include <memory>
#include <cstdio>

extern void Rule28();

namespace rule28
{
	class Point {
	public:
		Point(int x, int y) : x_(x), y_(y) {}
		void SetX(int x) { x_ = x; }
		void SetY(int y) { y_ = y; }

		int GetX() const { return x_; }
		int GetY() const { return y_; }

	private:
		int x_, y_;
	};

	struct Rect {
		Point ulhs;		// upper left-hand corner ���Ͻ�
		Point lrhs;		// lower right-hand corner ���½�
	};

	class Rectangle {
	public:
		Rectangle(const Rect rect) : pData_(std::make_shared<Rect>(rect)) {}
		void Print() const {
			printf("ulhs: {%d, %d}\n", upperLeft().GetX(), upperLeft().GetY());
			printf("lrhs: {%d, %d}\n", lowerRight().GetX(), lowerRight().GetY());
		}

		// ��Ȼ�������ñ����˿�����������ͨ�����룬��ȴ�Ǵ����
		// ԭ���������û��޸��ڲ�����
		Point& upperLeft_BUG() const { return pData_->ulhs; }
		Point& lowerRight_BUG() const { return pData_->lrhs; }

		// ���� const handle ��һ�ֽ���취
		const Point& upperLeft() const { return pData_->ulhs; }
		const Point& lowerRight() const { return pData_->lrhs; }

	private:
		std::shared_ptr<Rect> pData_;
	};

	inline void bug()
	{
		// �û������޸��ڲ�����
		Point ulhs(10, 10);
		Point lrhs(20, 20);

		Rect rect{ ulhs, lrhs };

		Rectangle rectangle(rect);
		auto &ulhs_ref = rectangle.upperLeft_BUG();
		ulhs_ref.SetX(0); // ��������Ӧ�ò�������

		rectangle.Print();
	}

	inline void bug2()
	{
		// ����ʹ������ȷ�ķ��� handle �ĺ�������ȻҪ����һ�����⣺����
		const Point* ulhs_p = nullptr;

		{
			Point ulhs(10, 10);
			Point lrhs(20, 20);

			Rect rect{ ulhs, lrhs };

			Rectangle rectangle(rect);
			ulhs_p = &rectangle.upperLeft();
			rectangle.Print();
		}
		
		printf("%d", ulhs_p->GetX()); // ���󶨵Ķ����Ѿ������ڣ�
	}
}

#endif // __RULE28_H__