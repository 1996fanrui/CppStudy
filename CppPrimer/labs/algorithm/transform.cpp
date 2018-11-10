#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>

/*
 * std::transform
 *
 * transform(first, last, d_first, unary_op);
 *
 * 应用给定的范围并存储结果于始于d_first的范围。此范围可以是：
 * (1) 应用一元函数 unary_op 到 [first, last) 所定义的范围。
 */

void Test1()
{
	// 将字符串的字符转换成大写
	std::string s("Hello");
	std::transform(s.begin(), s.end(), s.begin(), 
		[](unsigned char c) -> unsigned char { return std::toupper(c); });

	std::cout << s << std::endl;
}

void Test2()
{
	// 转换字符的 ASCII 序号
	std::string s("abcde");
	std::vector<std::size_t> ordinals;
	std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
		[](unsigned char c) -> std::size_t { return c; });

	for (auto i : ordinals)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main()
{
	Test1();
	Test2();

	return 0;
}
