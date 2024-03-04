using System;
public class Complex
{
    public int real;
    public int imaginary;
    public Complex(int real, int imaginary)
    {
        this.real = real;
        this.imaginary = imaginary;
    }
    public static Complex operator +(Complex c1, Complex c2)
    {
        return new Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
    }
    public override string ToString()
    {
        return (String.Format("{0} + {1}i", real, imaginary));
    }
}
class TestComplex
{
    static void Main(String[] args)
    {
        int real, imaginary;
        Console.WriteLine("First Complex number --> Enter the real and imaginary values");
        real = Int32.Parse(Console.ReadLine());
        imaginary = Int32.Parse(Console.ReadLine());
        Complex num1 = new Complex(real, imaginary);
        Console.WriteLine("Second Complex number --> Enter the real and imaginary values");
        real = Int32.Parse(Console.ReadLine());
        imaginary = Int32.Parse(Console.ReadLine());
        Complex num2 = new Complex(real, imaginary);
        Complex sum = num1 + num2;
        Console.WriteLine("First Complex Number : {0}", num1);
        Console.WriteLine("Second Complex Number : {0}", num2);
        Console.WriteLine("The Sum of the Two Numbers : {0}", sum);
        //Console.ReadLine();
    }
}