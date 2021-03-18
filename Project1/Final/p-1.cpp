/* C++ program to find a prime factor of composite using Pollard's p-1 algorithm */
#include<bits/stdc++.h> 
using namespace std; 

/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent, 
						long long int modulus) 
{ 
	/* initialize result */
	long long int result = 1; 

	while (exponent > 0) 
	{ 
		/* if y is odd, multiply base with result */
		if (exponent & 1) 
			result = (result * base) % modulus; 

		/* exponent = exponent/2 */
		exponent = exponent >> 1; 

		/* base = base * base */
		base = (base * base) % modulus; 
	} 
	return result; 
} 

long long int gcd(long long int a, long long int b)
{
if(b==0)
return a;
return gcd(b,a%b);
}

/* Method to return prime divisor for n */
long long int Pollard(long long int n,long long int B) 
{  

	/* no prime divisor for 1 */
	if (n==1) return n; 

	/* even number means one of the divisors is 2 */
	if (n % 2 == 0) return 2; 

	/* initialize a and e */
	long long int a = 2,d=1;
	long long int e = 2;

	/* until the prime factor isn't obtained. 
	If n is prime, return n */
	while (d==1) 
	{ 
		/* Update a=(a^e)mod n */
		a = (modular_pow(a, e, n))%n; 

		/* Increment e */
		e=e+1;
                d = gcd(abs(a-1), n);

	} 

	/* check gcd of |x-y| and n */
	 
        if(d==n)
        cout<<"\n It is a prime number\n";
        else
        cout<<"\n B = "<<e;

	return d; 
} 

/* driver function */
int main() 
{ 
	long long int n,B;
        cout<<"\n Enter number n : ";
        cin>>n; 
	printf("\n One of the divisors for %lld is %lld.\n", 
		n, Pollard(n,B)); 
	return 0; 
} 

