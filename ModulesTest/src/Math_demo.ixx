//
// Created by michael.brunner on 16/11/2023.
//
module;

#include <cmath>

export module Math;                        // define a module
import std.core;

export namespace Math {
	void SayHello()
	{
		std::cout << "Hello!";
		auto lAtan = std::atan(1);
		std::cout << lAtan;
	}

	constexpr float Pi{3.14};
};

namespace Math2
{
	export auto add(int a, int b)
	{
		return a + b;
	}
	auto sub(int a, int b)
	{
		return a - b;
	}
}


module : private; // following code is private to this module

void SomeMathFunction(){};
class SomeClass{};
using Alias = SomeClass;
