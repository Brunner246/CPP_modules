//
// Created by michael.brunner on 11/11/2023.
//
module;

#include <concepts>

export module ModulesIntro.ModuleOne;

import std.core;


namespace Hello {
	export void hello()
	{
		std::cout << "Hello Amigos from Modules =)" << std::endl;
	}
	export template<std::floating_point T>
	auto add(const T a, const T b)
	{
		return a + b;
	}
}



