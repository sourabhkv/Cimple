using System;
// Define the Resizable interface
interface Resizable
{
    void ResizeWidth(int width);
    void ResizeHeight(int height);
}
// Implement the Resizable interface in the Rectangle class
class Rectangle : Resizable
{
    private int width;
    private int height;
    public Rectangle(int width, int height)
    {
        this.width = width;
        this.height = height;
    }
    public void Display()
    {
        Console.WriteLine($"Rectangle - Width: {width}, Height: {height}");
    }
    public void ResizeWidth(int newWidth)
    {
        width = newWidth;
        Console.WriteLine($"Resized width to {newWidth}");
    }
    public void ResizeHeight(int newHeight)
    {
        height = newHeight;
        Console.WriteLine($"Resized height to {newHeight}");
    }
}
class Program
{
    static void Main()
    {
        // Input for initial values
        Console.WriteLine("Enter the initial width of the rectangle:");
        int initialWidth = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter the initial height of the rectangle:");
        int initialHeight = Convert.ToInt32(Console.ReadLine());
        // Create an instance of Rectangle
        Rectangle rectangle = new Rectangle(initialWidth, initialHeight);
        // Display the original size of the rectangle
        Console.WriteLine("\nOriginal Size:");
        rectangle.Display();
        // Input for resized values
        Console.WriteLine("\nEnter the new width for resizing:");
        int newWidth = Convert.ToInt32(Console.ReadLine());
        rectangle.ResizeWidth(newWidth);
        Console.WriteLine("Enter the new height for resizing:");
        int newHeight = Convert.ToInt32(Console.ReadLine());
        rectangle.ResizeHeight(newHeight);
        // Display the updated size of the rectangle
        Console.WriteLine("\nUpdated Size:");
        rectangle.Display();
    }
}