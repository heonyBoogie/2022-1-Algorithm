#include <iostream>
#include <chrono>

using namespace std;

int foo(int n)// 일반 재귀
{
	if (n == 0) return 1;
	return 2*foo(n-1);
}

int foo2(int n,int t) // tail 재귀
{
	if (t == 0) return n;
	return foo2(2*n,t-1);
}

int main() 
{
	chrono::system_clock::time_point start = chrono::system_clock::now();
	foo(4000);
	chrono::duration<double>sec = chrono::system_clock::now() - start;
	cout << sec.count() << endl;
	
	start = chrono::system_clock::now();
	foo2(1, 4000);
	sec = chrono::system_clock::now() - start;
	cout << sec.count() << endl;

	return 0;
}


