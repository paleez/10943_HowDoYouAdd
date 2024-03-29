// 10943_HowDoYouAdd_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int arr[101][101];
int mod = 1000000;
int calc(int n, int k)
{
	if (arr[n][k] != 0) 
	{
		return arr[n][k];
	}
	else if (k <= 1)
	{
		return 1;
	}
	for (size_t i = 0; i <= n; i++)
	{
		arr[n][k] = (arr[n][k] + calc(i, k - 1)) % mod;
	}
	return arr[n][k];
};
int main()
{
	int n, k;
	while (std::cin >> n >> k)
	{
		if (n == 0 && k == 0)
		{
			break;
		}
		int res = calc(n, k);
		std::cout << res +1 << std::endl;
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

The central idea is that we can deconstruct the original problem of counting how many sums exist with K plots with total N, 

establishing a relation of the original problem with simpler subproblems. It is this relationship that will allow us to develop a dynamic programming solution!

Let us denote the number of distinct solutions by sum (N, K).

For example, if one of the plots was number 5, the rest of the solution would be given by sum (N-5, K-1). This is because we have already discounted 5 values 

​​to the total N, and spent a portion on the number 5. If the next portion was a 3, the rest of the solution would be sum (N-8, K-2) ...

This indicates that sum (N, K) can be given by N + 1 subproblems, each corresponding to taking a parcel with a number from 0 to N

A detail about using the 1000000 module. 
The statement asks output in this format because the numbers would become absolutely gigantic for large N and K. 

In this way, we are guaranteed that the solutions give relatively small numbers.

This trick is possible because in module m arithmetic we can apply the module to each of the plots of the sum:

We have some habit of this kind of arithmetic because of the way the clocks use module 12 arithmetic. 

Eg, if it is now 11 hours, three hours later it will be two hours because (11 + 3) mod 12 = 2.

With this function we only have to read each pair of N, K values ​​and calculate the solutions. Note that as the pairs are being calculated, 

the sols matrix is ​​being filled, and the following pairs will tend to be calculated faster:

*/

