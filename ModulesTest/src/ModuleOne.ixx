//
// Created by michael.brunner on 11/11/2023.
//
module;

#include <cassert>

export module ModulesIntro.ModuleOne;

import std.core;

// TODO: force global fragment import header error
// #include <utility>

namespace Hello {
	export void hello()
	{
		std::cout << "Hello Amigos from ModulesTest =)" << std::endl;
	}

	export template<std::floating_point T>
	auto add(const T a, const T b)
	{
		return a + b;
	}

	template<typename T>
	concept Number = std::is_integral_v<T>;

	export template<Number ... T>
	auto sum(const T... a)
	{
		// (v[0] +(v[1] + (v[2] + (v[3] + v[4] + 0)))) right fold
		return (a + ... + 0);
	}

}



