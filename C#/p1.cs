using System;
class Program{
    static void Main1(String[] args){
        Console.WriteLine("enter 1st number : ");
        int num1 = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("enter 2nd number : ");
        int num2 = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter operator (+, -, *, /, %):");
        String op = Console.ReadLine();
        switch (op)
       {
           case "+":
               Console.WriteLine($"Result: {num1 + num2}");
               break;
           case "-":
               Console.WriteLine($"Result: {num1 - num2}");
               break;
           case "*":
               Console.WriteLine($"Result: {num1 * num2}");
               break;
           case "/":
                if (num2 != 0)
                {
                    Console.WriteLine($"Result: {num1 / num2}");
                }
                else
                {
                    Console.WriteLine("Error: Division by zero.");
                }
               break;
           case "%":
                if (num2 != 0)
                {
                    Console.WriteLine($"Result: {num1 % num2}");
                }
                else
                {
                    Console.WriteLine("Error: Division by zero.");
                }
               break;
        }
    }
}