namespace csharp;

using System;

class Pascal
{
    static void Main()
    {
        int[,] pascal = new int[10, 10];

        for (int line = 0; line < 10; line++)
        {
            for (int i = 0; i <= line; i++)
            {
                if (line == i || i == 0)
                    pascal[line, i] = 1;
                else
                    pascal[line, i] = pascal[line - 1, i - 1] + pascal[line - 1, i];
                Console.Write(pascal[line, i] + " ");
            }
            Console.WriteLine();
        }
    }
}
