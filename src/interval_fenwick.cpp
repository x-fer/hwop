/*RUN g++ % -Wall -Wextra -ot && ./t; rm t*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

#define MAXI 100000

class fenwick_tree
{
	private:
		int niz[MAXI];
	public:

		fenwick_tree()
		{
			memset(niz, 0, sizeof(niz));
		}

		void ubaci(int val, int poz)
		{
			for(poz = poz + 1; poz < MAXI ; poz += poz&-poz)
			{
				niz[ poz ] += val;
			}
		}

		int upit(int poz)
		{
			int ret = 0;
			for(poz = poz + 1; poz > 0 ; poz -= poz&-poz)
			{
				ret += niz[poz];
			}
			return ret;
		}
};


class interval_fenwick{

	private:

		fenwick_tree mul;
		fenwick_tree add;

	public:

		void ubaci(int X, int A, int B)
		{
			mul.ubaci(X, A);
			mul.ubaci(-X, B);

			add.ubaci(-X*(A-1), A);
			add.ubaci(X*B, B);
		}

		int upit(int C)
		{
			return mul.upit(C) * C + add.upit(C);
		}

		int upit(int A, int B)
		{
			return upit(B) - upit(A-1);
		}
};

int test()
{
	const int N = 1000; //duljina niza
	const int M = 1000; //broj naredbi
	const int S = 100; //najveci broj koji se dodaje

	interval_fenwick int_fen;
	int niz[MAXI] = {0};
	int A, B, X;
	int suma;

	srand(time(NULL));

	for(int i = 0 ; i < M ; ++i)
	{
		A = (rand() % N) + 1;
		B = (rand() % N) + 1;

		if ( A > B )
			swap(A, B);

		if ( rand() % 2 || i < M/10 )
		{
			X = (rand()%S)+1;

			//printf("%d %d %d\n", X, A, B);

			//ubacivanje u strukturu
			int_fen.ubaci(X, A, B);


			//ubacivanje u test
			for(int i = A ; i <= B ; ++i)
				niz[i] += X;
		}
		else
		{
			//upit za strukturu
			X = int_fen.upit(A, B);

			//upit za test
			suma = 0;
			for(int i = A ; i <= B ; ++i)
				suma += niz[i];

			//printf("%d = %d\n", X, suma);
			//struktura nije ispravna
			if ( X != suma )
				return 0;
		}
	}

	//test je uspjesan
	return 1;
}

int main(void)
{
	int T = test();
	if ( T )
		printf("PASS\n");
	else
		printf("FAIL\n");
	return 0;
}
