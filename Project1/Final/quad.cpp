#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
}

int main()
{
long long int i=0,j=0,d,c,n;
cin>>n;

for(i=2;i<n;i++)
{
for(j=2;j<n&&j!=i;j++)
{
d=(i^2)*(j^2);


