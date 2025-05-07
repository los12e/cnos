#include <stdio.h>
#include <string.h>
int main() {
 char a[100], c[200]; // Input and stuffed strings
 int i = 0, k = 0;
 printf("Enter the string: ");
 scanf("%s", a); // Read the input string
 // Character stuffing logic
 for (i = 0; a[i] != '\0'; i++)
{
 if (a[i] == 'D' && a[i+1] == 'L' && a[i+2] == 'E')
 {
 // Check for DLE sequence
 c[k++] = 'D';
 c[k++] = 'L';
 c[k++] = 'E';
 c[k++] = 'D'; // Escape the DLE with an extra D
 i += 2; // Skip the DLE in input
 } else {
 c[k++] = a[i]; // Copy other characters
 }
 }
 c[k] = '\0'; // Null-terminate the stuffed string
 // Printing the results
 printf("DLESTX%sDLEETX\n", c); // Add protocol framing
 return 0;
}
