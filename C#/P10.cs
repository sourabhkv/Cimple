using System;
class Shape
{
    public int X { get; set; }
    public int Y { get; set; }
    public virtual void draw()
    {
        Console.WriteLine("Drawing a Generic Shape");
    }
    public virtual void erase()
    {
        Console.WriteLine(" Erasing the Generic Shape ");
    }
}
class Circle : Shape
{
    public override void draw()
    {
        Console.WriteLine("Drawing a Circle");
        base.draw();
    }
    public override void erase()
    {
        Console.WriteLine("Erasing Circle ");
    }
}
class Triangle : Shape
{
    public override void draw()
    {
        Console.WriteLine("Drawing Triangle ");
    }
    public override void erase()
    {
        Console.WriteLine("Erasing Triangle ");
    }
}
class Square : Shape
{
    public override void draw()
    {
        Console.WriteLine("Drawing a Square ");
    }
    public override void erase()
    {
        Console.WriteLine("Erasing a Square ");
    }
}
public class Program
{
    static void Main(String[] args)
    {
        /* a Circle, Triangle and Square can all be used wherever a Shape is expected. No cast is
        required because an implicit conversion exists from a derived class to its base class. */
        var shapes = new List<Shape>
        {
        new Circle(),
        new Triangle(),
        new Square(),
        };
        // the virtual method Draw is // invoked on each of the derived classes, not the base class.
        foreach (var shape in shapes)
        {
            shape.draw();
        }
        foreach (var shape in shapes)
        {
            shape.erase();
        }
        /* Shape s1 = new Shape();
        s1.draw();
        s1 = new Circle();
        s1.draw(); */
    }
}