
using System;
using System.IO;
namespace FileCopy{
class FileCopy
{
static void Main()
{
Console.Write("Enter the path of the source text file: ");
string sourceFilePath = Console.ReadLine();
Console.Write("Enter the path of the destination text file: ");
string destinationFilePath = Console.ReadLine();
try
{
// Read the contents of the source file
string fileContents = File.ReadAllText(sourceFilePath);
// Write the contents to the destination file
File.WriteAllText(destinationFilePath, fileContents);
Console.WriteLine("File copy successful!");
}
catch (FileNotFoundException)
{
Console.WriteLine("Error: Source file not found.");
}
catch (UnauthorizedAccessException)
{
Console.WriteLine("Error: Access to the file is unauthorized.");
}
catch (Exception ex)
{
Console.WriteLine($"Error: {ex.Message}");
}
}
}
}

