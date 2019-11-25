#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h> 

//Prime Checker
static bool isPrime(int n)
        {
            
            if (n <= 1)
                return false;

            
            for (int i = 2; i < n; i++)
                if (n % i == 0)
                    return false;

            return true;
        }

//to find gcd
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

int main()
{
    //Intialization of p and q along with counter for 10th and 19th Prime Number
    double p = 3;
    double q = 7;
    int PrimeCounter = 0;
    
    //Finding 10th and 19th prime number between 1000 and 10000
    for(int prime = 1000; prime < 10000; prime++)
            {
                if (isPrime(prime))
                {
                    PrimeCounter++;
                    if (PrimeCounter == 10)
                        p = prime;
                    if(PrimeCounter == 19)
                    {
                        q = prime;
                    }
                }

            }

    double n=p*q;
    double count;
    double phi = (p-1)*(q-1);
 
    //public key
    //e stands for encrypt
    double e=2;
 
    //for checking co-prime which satisfies e>1
    while(e<phi){
    count = gcd(e,phi);
    if(count==1)
        break;
    else
        e++;
    }
 
    //private key
    //d stands for decrypt
    double d;
 
    //k can be any arbitrary value
    double k = 2;
 
    //choosing d such that it satisfies d*e = 1 + k * totient
    d = (1 + (k*phi))/e;
    d=round(d);
    double msg = 12;
    double c = pow(msg,e);
    double m = pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);
 
    printf("Message data = %lf",msg);
    printf("\np = %lf",p);
    printf("\nq = %lf",q);
    printf("\nn = pq = %lf",n);
    printf("\nphi = %lf",phi);
    printf("\ne = %.1lf",e);
    printf("\nd = %.1lf",d);
    printf("\nEncrypted data = %.1lf",c);
    printf("\nOriginal Message Sent = %.1lf",m);
 
    return 0;
}