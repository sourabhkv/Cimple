namespace csharp;

using System; 

class Substring{ 
	
// Function to get the substrings 
static void find_substrings(string input_string) 
{ 
	int j = 0; 
	int i = 0; 

	for(i = 1; i <= input_string.Length; i++) 
	{ 
		for(j = 0; j <= input_string.Length - i; j++) 
		{ 
			
			// Using Substring() function 
			Console.WriteLine(input_string.Substring(j, i)); 
		} 
	} 
} 

// Driver code 
public static void Main1() 
{ 
	
	// Declare the main string 
	string input_string; 

	Console.Write("Enter String : "); 
	Console.Write("\n"); 
	
	// Read the string 
	input_string = Console.ReadLine(); 

	// Call the function 
	find_substrings(input_string); 
} 
}
