namespace csharp;

using System;

class Armstrong
{
    static void Main1()
    {
        for(int i=1; i<=1000; i++)
        {
            int sum=0, n=i;
            while(n!=0)
            {
                int digit = n % 10;
                sum += digit*digit*digit;
                n /= 10;
            }

            if(sum == i)
                Console.WriteLine(i);
        }
    }
}
