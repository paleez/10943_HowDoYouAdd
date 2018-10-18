// 10943_HowDoYouAdd_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool even(int i) { return (i % 2) == 0; }
long long int multiply(long long int x, long long int y)
{
	if (y == 0)
	{
		return 0;
	}

	long long int z = multiply(x, floor(y / 2));
	if (even(y))
	{
		return 2*z;
	}
	else
	{
		return x + (2*z);
	}
}


/*
int arr[MAXN][MAXN];
for (int i = 0; i < MAXN; i++)
f[i][0] = 1;
for (int i = 1; i < MAXN; i++)
for (int j = 1; j <= i; j++)
f[i][j] = (f[i-1][j]+f[i-1][j-1]) % 1000000;

*/
int main()
{
	int n;
	int k;

	while (std::cin >> n >> k)
	{
		//Given a number N, how many ways can K numbers less than N add up to N?
		// We can solve this problem using Dynamic Programming. 
		//A good way to look at this problem is imagined that for each K we have an empty box to be filled. 
		//to fill each one of the boxes we have N objects, based on this analogy, we can further extend our ideas to the state of the solution.
		if (n == 0 & k == 0)
		{
			break;
		}
		else
		{
			unsigned long long int x1 = 1;
			unsigned long long int y1 = 1;
			for (int i = 1; i < k; i++)
			{
				x1 = multiply(x1, (x1 *(n + i)));
				y1 = multiply(y1, i);
				
				//x *= multiply(x,(n + i));
				//y *= multiply(y, i);
				
			}
			signed long int ans = (x1 / y1) %  1000000;
			
			std::cout << ans << std::endl;
		}
		
	}
    return 0;
}

/*

	sum(N,K) = sum(N-0,K-1) + sum(N-1,K-1) + sum(N-2,K-1) + ... + sum(N-N,K-1)



	In order to avoid repetitions in the calculation of solutions, we will store in a matrix the solutions sols (N, K) that we are calculating. 
	For this we create the matrix sols as static attribute of our class:

	static final int UNKNOWN = 0;
	static long[][] sols = new long[101][101];   // N,K <= 100, we'll not use indexes 0

	static void computeAdds(int N, int K) {

	if (sols[N][K] != UNKNOWN)  // already computed: carry on, there's nothing to do...
	return;

	if (K==1)
	sols[N][K] = 1;   // if there is just one parcel, the only possible solution is N itself
	else {

	long sum = 0;
	for(int i=0; i<=N; i++) {
	computeAdds(N-i, K-1);
	sum += sols[N-i][K-1];
	sum %= 1000000;  // keep it small
}
sols[N][K] = sum;    // keep solution for future use
}
}

*/

/*

This problem is described in [Halim] and has a dynamic programming resolution.

The central idea is that we can deconstruct the original problem of counting how many sums exist with K plots with total N, establishing a relation of the original problem with simpler subproblems. It is this relationship that will allow us to develop a dynamic programming solution!

Let us denote the number of distinct solutions by sum (N, K).

For example, if one of the plots was number 5, the rest of the solution would be given by sum (N-5, K-1). This is because we have already discounted 5 values ​​to the total N, and spent a portion on the number 5. If the next portion was a 3, the rest of the solution would be sum (N-8, K-2) ...

This indicates that sum (N, K) can be given by N + 1 subproblems, each corresponding to taking a parcel with a number from 0 to N

A detail about using the 1000000 module. 
The statement asks output in this format because the numbers would become absolutely gigantic for large N and K. 

In this way, we are guaranteed that the solutions give relatively small numbers.

This trick is possible because in module m arithmetic we can apply the module to each of the plots of the sum:

We have some habit of this kind of arithmetic because of the way the clocks use module 12 arithmetic. Eg, if it is now 11 hours, three hours later it will be two hours because (11 + 3) mod 12 = 2.

With this function we only have to read each pair of N, K values ​​and calculate the solutions. Note that as the pairs are being calculated, the sols matrix is ​​being filled, and the following pairs will tend to be calculated faster:

*/

