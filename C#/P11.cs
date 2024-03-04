using System;
abstract class Shape
{
    // Abstract methods to calculate area and perimeter
    public abstract double CalculateArea();
    public abstract double CalculatePerimeter();
}
// Derived class for a Circle
class Circle : Shape
{
    public double Radius { get; set; }
    public override double CalculateArea()
    {
        return Math.PI * Radius * Radius;
    }
    public override double CalculatePerimeter()
    {
        return 2 * Math.PI * Radius;
    }
}
class Triangle : Shape
{
    public double Side1 { get; set; }
    public double Side2 { get; set; }
    public double Side3 { get; set; }
    public override double CalculateArea()
    {
        // Implementing the area calculation using Heron's formula
        double s = (Side1 + Side2 + Side3) / 2; // s= (a+b+c)/2
        return Math.Sqrt(s * (s - Side1) * (s - Side2) * (s - Side3)); // ABC = √[s × (s – a) × (s – b) × (s– c)].
}
    public override double CalculatePerimeter()
    {
        return Side1 + Side2 + Side3;
    }
}
class Program
{
    static void Main(string[] args)
    {
        Circle circle = new Circle { Radius = 5 };
        Triangle triangle = new Triangle { Side1 = 3, Side2 = 4, Side3 = 5 };
        Console.WriteLine("Area and Perimeter of Circle\n");
        Console.WriteLine("Circle Area: " + circle.CalculateArea());
        Console.WriteLine("Circle Perimeter: " + circle.CalculatePerimeter());
        Console.WriteLine();
        Console.WriteLine("Area and Perimeter of Triangle\n");
        Console.WriteLine("Triangle Area: " + triangle.CalculateArea());
        Console.WriteLine("Triangle Perimeter: " + triangle.CalculatePerimeter());
        // Console.ReadKey();
    }
}