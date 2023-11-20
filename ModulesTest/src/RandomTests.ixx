//
// Created by michael.brunner on 19/11/2023.
//

export module RandomTests;

import std.core;

export auto sumdown(int n) -> int
{
	if (n == 0) {
		return 0;
	}
	return n + sumdown(n - 1);
}

/*
 *      {
 * 		5 + sumdown(4)
 * 		{ apply sumdown(4) }
 * 		4 + sumdown(3)
 * 		{ apply sumdown(3) }
 * 		3 + sumdown(2)
 * 		{ apply sumdown(2) }
 * 		2 + sumdown(1)
 * 		{ apply sumdown(1) }
 * 		1 + sumdown(0)
 * 		{ apply sumdown(0) }
 * 		0
 * 		1 + 0
 * 		2 + 1
 * 		3 + 3
 * 		4 + 6
 * 		5 + 10
 * 		15
 * 		}
 */

export auto recursiveExponentiation(int n, int m) -> int
{
	if (m == 0) {
		return 1;
	}
	return n * recursiveExponentiation(n, m - 1);
}
/*
 *      {
 *      2^3
 *      { apply recursiveExponentiation(2, 3)}
 *      2 * { apply recursiveExponentiation(2, 2)}
 *      2 * 2 * { apply recursiveExponentiation(2, 1)}
 *      2 * 2 * 2 * { apply recursiveExponentiation(2, 0)}
 *      2 * 2 * 2 * 1
 *      = 8
 *      }
 */

export template<typename T>
auto zip(const std::vector<T>& a, const std::vector<T> b) -> std::vector<std::pair<T, T>>
{
	std::vector<std::pair<T, T>> result;
	for (int i = 0; i < a.size(); ++i) {
		result.push_back(std::make_pair(a[i], b[i]));
	}
	return result;
}

export auto multiply(const int a, const int b) -> int
{
	if (b == 0) {
		return 0;
	}
	return a + multiply(a, b - 1);
}

/**
* 		{
 * 		2 * 3
 * 		{ apply * }
 * 		2 + (2 * 2)
 * 		{ apply * }
 * 		2 + (2 + (2 * 1))
 * 		{ apply * }
 * 		2 + (2 + (2 + (2 * 0)))
 * 		{ apply * }
 * 		2 + (2 + (2 + 0))
 * 		{ apply + }
 * 		= 6
 *
*/