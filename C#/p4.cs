namespace csharp;


using System;

class Exception { 
      
    // Main Method 
    static void Main1(String[] args) 
    { 
  
        // Here, number is greater than divisor. 
        int[] number = {8, 17, 24, 5, 25}; 
        int[] divisor = {2, 0, 0, 5}; 
  
        // Outer try block 
          
        // Here IndexOutOfRangeException occurs 
        // due to which program may terminates 
        try { 
              
            for (int j = 0; j < number.Length; j++) { 
  
                // Inner try block 
                  
                // Here DivideByZeroException caught 
                // and allow the program to continue  
                // its execution 
  
                try { 
                      
                    Console.WriteLine("Number: " + number[j] +  
                                      "\nDivisor: " + divisor[j] +  
                                      "\nQuotient: " + number[j] / divisor[j]); 
                } 
                  
                // Catch block for inner try block 
                catch (DivideByZeroException e) { 
                      
                    Console.WriteLine("Inner Try Catch Block"); 
	 Console.WriteLine("An Exception has occurred : {0}", e.Message);

                } 
            } 
        } 
  
        // Catch block for outer try block 
        catch (IndexOutOfRangeException e) { 
                          Console.WriteLine("Outer Try Catch Block"); 
Console.WriteLine("An Exception has occurred : {0}", e.Message);
                      } 
    } 
} 