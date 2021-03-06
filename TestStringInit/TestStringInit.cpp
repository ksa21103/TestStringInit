// TestStringInit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <chrono>

////////////////////////////////////////////////////////////////////////////////
// class WriteTime - отображение времени
class ElapsedTimeHelper
{
public:

	ElapsedTimeHelper(const char* msg)
		: m_msg(msg),
		  m_startTime(std::chrono::high_resolution_clock::now())
	{
		std::cout << m_msg << "......processing.....";
	}

	~ElapsedTimeHelper()
	{
		const std::chrono::time_point<std::chrono::high_resolution_clock> stopTime = std::chrono::high_resolution_clock::now();

		auto elapsedTine = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - m_startTime).count();

		std::cout << m_msg << " : " << elapsedTine << " (ms);\n";
	}

private:

	const char*                                                         m_msg;
	const std::chrono::time_point<std::chrono::high_resolution_clock>   m_startTime;
};

class InitInConstructor
{
public:

	InitInConstructor(char* pStr)
	{
		m_str = pStr;
	}

	const std::string& get() const
	{
		return m_str;
	}

private:

	std::string m_str;
};

class InitInInitList
{
public:

	InitInInitList(char* pStr)
		: m_str(pStr)
	{
	}

	const std::string& get() const
	{
		return m_str;
	}

private:

	std::string m_str;
};

int main()
{
	const size_t kMaxCount(10000000);

	char pStr3[] = "123";

	{
		ElapsedTimeHelper eth("Init in constructor pStr3");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInConstructor data(pStr3);
			data.get();
		}
	}

	{
		ElapsedTimeHelper eth("Init in init list pStr3");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInInitList data(pStr3);
			data.get();
		}
	}

	{
		ElapsedTimeHelper eth("Init in constructor 123");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInConstructor data("123");
			data.get();
		}
	}

	{
		ElapsedTimeHelper eth("Init in init list 123");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInInitList data("123");
			data.get();
		}
	}

	char pStr64[] = "0123456789012345678901234567890123456789012345678901234567891234";

	{
		ElapsedTimeHelper eth("Init in constructor pStr64");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInConstructor data(pStr64);
			data.get();
		}
	}

	{
		ElapsedTimeHelper eth("Init in init list pStr64");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInInitList data(pStr64);
			data.get();
		}
	}

	{
		ElapsedTimeHelper eth("Init in constructor 0.....9");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInConstructor data("0123456789012345678901234567890123456789012345678901234567891234");
			data.get();
		}
	}

	{
		ElapsedTimeHelper eth("Init in init list 0.....9");

		for (size_t i = 0; i < kMaxCount; ++i)
		{
			InitInInitList data("0123456789012345678901234567890123456789012345678901234567891234");
			data.get();
		}
	}

	char ch;
	std::cin >> ch;
	
	return 0;
}

