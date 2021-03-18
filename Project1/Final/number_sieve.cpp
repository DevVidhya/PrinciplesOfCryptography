#include<bits/stdc++.h> 
using namespace std;

long long int len;

void Sieve(){
        cout<<"\nEnter number n : ";
        cin>>len;
        cout<<"\n";
        long long int sp[len];
        bool v[len];
	for (long long int i = 2; i <= len; i += 2)	
        sp[i] = 2;                                       //even numbers have smallest prime factor 2
	for (long long int i = 3; i <= len; i += 2)
        {
		if (!v[i]) 
                {
			sp[i] = i;
			for (long long int j = i; (j*i) <= len; j += 2) 
                        {
				if (!v[j*i])	
                                v[j*i] = true, sp[j*i] = i;
			}
		}
	}
        int count=0;
	for (int i = 2; i <= len; i++)	
        {
                if(i==sp[i])
                {
                count++;
                cout <<i<<" is a prime number \n";
                }
                else
                cout <<i<<" is divisible by "<< sp[i] << endl;
        }
        cout<<"\nCount of prime numbers = "<<count<<"\n";
}

int main(){
	Sieve();
	
    return 0;
}
