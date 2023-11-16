//
// Created by michael.brunner on 16/11/2023.
//

export module Math:Algebra;

export float add(float a, float b)
{
	return a + b;
}

export auto factorial(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}


//
//export template <typename T>
//T add(T a, T b)
//{
//	return a + b;
//}
