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
void FibonacciDP(vector<long long> &fibo, unsigned int n)
{
	if (n <= 1)
	{
		fibo[n] = n;
		return;
	}

	if (fibo[n] != -1)
	{
		return;
	}
	FibonacciDP(fibo, n - 1);
	FibonacciDP(fibo, n - 2);

	fibo[n] = fibo[n - 1] + fibo[n - 2];
	return;
}
unsigned long long FibonacciDP(unsigned int n)
{

	vector<long long> fibo(n + 1, -1);

	FibonacciDP(fibo, n);
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