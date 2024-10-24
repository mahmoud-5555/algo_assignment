#include <vector>
#include <iostream>
using namespace std;

unsigned long long fibonacci(unsigned int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

vector<vector<int>> powDavidConquer(int n)
{
	if (n == 1)
	{
		return {{1, 1}, {1, 0}};
	}

	vector<vector<int>> temp = powDavidConquer(n / 2);

	vector<vector<int>> t = {{temp[0][0] * temp[0][0] + temp[0][1] * temp[1][0], temp[0][0] * temp[0][1] + temp[0][1] * temp[1][1]}, {temp[1][0] * temp[0][0] + temp[1][1] * temp[1][0], temp[1][0] * temp[0][1] + temp[1][1] * temp[1][1]}};

	if (n % 2 == 1)
	{

		return {{t[0][0] + t[0][1], t[0][0]}, {t[1][0] + t[1][1], t[1][0]}};
	}
	return t;
}

unsigned long long FibonacciDavidConquer(unsigned int n)
{
	return powDavidConquer(n)[0][1];
}
unsigned long long FibonacciDP(unsigned int n)
{

	vector<long long> fibo(2, 0);
	fibo[1] = 1;

	for (size_t i = 2; i <= n; i++)
	{
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	}
	return fibo[n];
}
int main()
{
	cout << "Enter the position of Fibonacci number\n";
	int n;
	cin >> n;
	cout << "fibonacci recursion: " << fibonacci(n) << "\n";
	cout << "Fibonacci David and Conquer: " << FibonacciDavidConquer(n) << "\n";
	cout << "Fibonacci Dynamic programming: " << FibonacciDP(n) << "\n";
}