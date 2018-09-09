// ����20������ pass-by-reference-to-const �滻 pass-by-value
#ifndef __RULE20_H__
#define __RULE20_H__

#include <string>
#include <iostream>

extern void Rule20();

namespace rule20
{
	// ������������ڲ��Կ�����Ӧ��ʹ�� pass-by-reference-to-const
	class Person
	{
	public:
		Person() {}
		virtual ~Person() {}

	private:
		std::string name = "DefaultName";
		std::string address = "DefaultAddr";
	};

	class Student : public Person
	{
	public:
		Student() {}
		~Student() {}

	private:
		std::string schoolName = "DefaultSchoolName";
		std::string schoolAddress = "DefaultSchoolAddr";
	};

	inline bool validateStudent(Student s) { return false; } // ������ by-value	��ʽ���ݲ���
	inline bool validateStudent2(const Student& s) { return false; } // pass=by-reference-to-const

	class Window
	{
	public:
		Window(const std::string &name) : name_(name) {}
		std::string name() const { return name_; }
		virtual void display() const { std::cout << "Window display" << std::endl; }
	private:
		std::string name_;
	};

	class WindowWithScrollBars : public Window
	{
	public:
		WindowWithScrollBars(const std::string &name) : Window(name) {}
		virtual void display() const { std::cout << "WindowWithScrollBars display" << std::endl; }
	private:
		int type = 1;
	};

	// ����ȷ���������ܱ��и����ʵ�������� WindowWithScrollBars ��
	inline void printNameAndDisplay(Window w)
	{
		std::cout << w.name() << std::endl;
		w.display();
	}

	// �������ᱻ�и�
	inline void printNameAndDisplay2(const Window& w)
	{
		std::cout << w.name() << std::endl;
		w.display();
	}
}

#endif // __RULE20_H__