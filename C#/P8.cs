using System;
namespace Stack
{
    { 
    class Stack
    private int maxSize;
        private int top;
        private int[] stackArray;
        public Stack(int size)
        {
            maxSize = size;
            stackArray = new int[maxSize];
            top = -1;
        }
        public int Top
        {
            get { return top; }
        }
        public void Push(int value)
        {
            if (top < maxSize - 1)
            {
                stackArray[++top] = value;
                Console.WriteLine($"Pushed {value} to the stack.");
            }
            else
            {
                Console.WriteLine("Stack overflow! Cannot push more elements.");
            }
        }
        public int Pop()
        {
            if (top >= 0)
            {
                int poppedValue = stackArray[top--];
                Console.WriteLine($"Popped {poppedValue} from the stack.");
                return poppedValue;
            }
            else
            {
                Console.WriteLine("Stack underflow! Cannot pop from an empty stack.");
                return -1; // You may choose a different value to indicate an error condition.
            }
        }
        public void DisplayStack()
        {
            if (top == -1)
            {
                Console.WriteLine("Stack is empty.");
            }
            else
            {
                Console.Write("Stack elements: ");
                for (int i = 0; i <= top; i++)
                {
                    Console.Write($"{stackArray[i]} ");
                }
                Console.WriteLine();
            }
        }
    }
}
 
class Program {
    static void Main()
    {
    Console.Write("Enter the size of the stack: ");
    int stackSize = Convert.ToInt32(Console.ReadLine());
    Stack myStack = new Stack(stackSize);
    while (true)
    {
        Console.WriteLine("\nChoose operation:");
        Console.WriteLine("1. Push");
        Console.WriteLine("2. Pop");
        Console.WriteLine("3. Display Stack");
        Console.WriteLine("4. Exit");
        Console.Write("Enter your choice (1-4): ");
        int choice = Convert.ToInt32(Console.ReadLine()); switch (choice)
        {
            case 1:
                Console.Write("Enter the value to push: ");
                int valueToPush = Convert.ToInt32(Console.ReadLine());
                myStack.Push(valueToPush);
                break;
            case 2:
                int poppedValue = myStack.Pop();
                if (poppedValue != -1)
                {
                    Console.WriteLine($"Popped value: {poppedValue}");
                }
                break;
            case 3:
                myStack.DisplayStack();
                break;
            case 4:
                Console.WriteLine("Exiting the program.");
                Environment.Exit(0);
                break;
            default:
                Console.WriteLine("Invalid choice. Please enter a valid option.");
                break;
        }
    }
} 
} 

