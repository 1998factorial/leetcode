#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){

	int* a1 = NULL;
	a1 = malloc(sizeof(int)*3);
	int* a2 = NULL;
	a2 = malloc(sizeof(int)*3);
	//case 1 
	a1[0] = 1;a1[1] = 2;a1[2] = 3;
	a2[0] = 4;a2[1] = 5;a2[2] = 6;

	float m1 = findMedian(a1,3,a2,3);	

	free(a1);free(a2);

}

//log(m+n) algo for finding median of 2 sorted arrays
//log(m+n) = log(m)*log(n) 
/*
	idea: since log(m+n) = log(m)*log(n), we suspect that binary search is the key
	to approach this task.(By finding the desired number using binary search, although
	we are not sure how now.)

	Algorithm:
		say we start by looking at A[n/2]. We then find that B[k] is the maximal number in
		B that is less than A[n/2]. 
		If k = m/2 then we are done. 
		If k > m/2,
			we know that A[n/2] is too large for median. Therefore we know that if median is
			in A, it will be located in A[0..n/2 - 1].
			now, pick A[n/4], find maximal number that is less than A[n/4] in B, call it B[k]
			.If k = m/2 + n/4 then A[n/4] is the desired number. Repeat the process otherwise.

		If k < m/2, 
			we know that A[n/2] is too small for median, so we look for A[3n/4].
			find maximal number that is less than A[3n/4] in B, call this number
			B[k].If k = m/2 - n/4, then A[n/4] is the desired number.
			
 		If at the end we can't find any in A then we know that the median is in
 		B and we repeat the above procedure for B.



	now we consider 4 cases:
	say |A| = n, |B| = m, say C = sorted(A+B) and |C| = m+n
	case 1: n is odd, m is odd (need C[(m+n)/2] and C[(m+n)/2 - 1])
		
		

	case 2: n is odd, m is even (need C[(m+n)/2])
 
	case 3: n is even, m is odd (need C[(m+n)/2])

	case 4: n is even, m is even (need C[(m+n)/2] and C[(m+n)/2 - 1])






if m+n is even => need (A+B)[(n+m)/2] and (A+B)[(n+m)/2 - 1]
	


if m+n is odd => need (A+B)[(n+m)/2]
	m = A[n/2]
	



	A[0]<=A[1]<=...<=A[n/2]<=...<=A[n]
	B[0]<=B[1]<=...<=B[m/2]<=...<=B[m]

	*need to find the (m+n)/2 th number
		if A[n/2] = B[m/2] => A[n/2] is the median.
		eg [1,3,5,7,9]+[3,5] = [1,3,3,5,5,7,9]
		
		eg [1,3,5,7,9]+[5,10] = [1,3,5,5,7,9,10]

case 2 
	A = [2,12,18]	
	B = [3,4,5]
	A+B = [2,3,4,5,12,18]

	m(A) = 12
	m(B) = 4
	m(A+B) = 
	
*/

float findMedian(int* a1, int length1, int* a2, int length2){
	int m = 0;
	//TODO
	return m;
}
