/**************************************************************************************/
/*                                                                                    */
/*  Finding prime numbers between 1 and 100                                           */
/*  Speed and RAM usage comparison of three C code samples (Educational purpose only) */                  
/*  Code source: https://prepinsta.com/c-program/prime-number-between-1-to-100/       */
/*                                                                                    */                       
/*                                                                                    */
/**************************************************************************************/

#include <stdio.h>
#include <math.h>

int checkPrimeA(int num)
{
    // 0, 1 and negative numbers are not prime
    if(num < 2){
        return 0;
    }
    else{   
    // no need to run loop till num-1 as for any number x the numbers in
    // the range(num/2 + 1, num) won't be divisible anyways. 
    // Example 36 wont be divisible by anything b/w 19-35
        int x = num/2;
        for(int i = 2; i <=x; i++)
        {
            if(num % i == 0)
            {
                return 0;
            }
        }
    }
    // the number would be prime if we reach here
    return 1;
}
//Time Complexity: O(N^2)
//Space Complexity O(1)
/**************************************************************************************/

int checkPrimeB(int n)
{
    // 0 and 1 are not prime numbers
    // negative numbers are not prime
    if (n <= 1)
        return 0;

    // special case as 2 is the only even number that is prime
    else if (n == 2)
        return 1;

    // Check if n is a multiple of 2 thus all these won't be prime
    else if (n % 2 == 0)
        return 0;

    // If not, then just check the odds
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    
    return 1;
}
//Time Complexity: O(N√N)
//Space Complexity O(1)
// This method is obviously faster as makes around half lesser comparision due skipping even iterations in the loop

/**************************************************************************************/
int main()
{
    int a = 1, b = 100;
    
    for(int i=a; i <= b; i++){
        if(checkPrimeB(i))
            printf("%d ",i);
    }
 
    return 0;
}