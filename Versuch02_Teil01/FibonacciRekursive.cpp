#include <iostream>

int rekursivFib(int n)
{
	if( n == 0 )
	{
		return 0;
	}
	else if ( n == 1)
	{
		return 1;
	}
	else
	{
		return rekursivFib(n-1) + rekursivFib(n-2);
	}
}

int main()
{
	std::cout << "Fibonacci Zahlen von 0 bis 25: " << "\n";

	for(int i = 0; i <= 42; i++)                                /// int = 2147483647
	{                                                           /// fibonacci nach 47 = 2971215073
		std::cout << "f("<<i<<")= " << rekursivFib(i) << "\n";  /// to make it bigger than 47,
	}                                                           /// we should use long long ( long long int )
	                                                            /// rekursiv 2hochn, iteration o(n)

	return 0;
}

