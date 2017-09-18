#include <cstdlib> 

#include <ctime> 

#include <sys/time.h> 

#include <iostream> 

#include <cstdio> 

using namespace std;

//convert to binay num and count shift time

/* What do this do? */

//how many odd num

int a(unsigned int i) {

	int c = 0;

	while (i) {

		//cout << "i: "<<i << "\n" ;

		if (i & 1) { c++;  }

		i >>= 1;

	}

	return c;

}



/* What does this one do? */



int b(unsigned int i) {

	static unsigned char n[] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 };

	int c = 0;

	while (i) {

		c += n[i & 15];

		//cout << "n: "<<n[i & 15] << "\n" ;

		//cout << "i: "<<i << "\n" ;

		i >>= 4;

	}

	return c;

}



int main() {

    

    	struct timeval start, end, t0, t1;  

	gettimeofday(&t0, NULL);

    	cout << a(100) << "\n" ;

	gettimeofday(&t1, NULL);

	printf("time: %lu\n", t1.tv_usec - t0.tv_usec);


	gettimeofday(&start, NULL);

	cout << b(100) << "\n" ;

	gettimeofday(&end, NULL);

	printf("time: %lu\n", end.tv_usec - start.tv_usec);

}
