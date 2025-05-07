#include <stdio.h>
#include <string.h>
void bitStuffing(char input[], char output[]) {
 int count = 0; // Counter for consecutive 1's
 int j = 0; // Output index
 for (int i = 0; input[i] != '\0'; i++)
{
 output[j++] = input[i];
 if (input[i] == '1') {
 count++;
 } else {
 count = 0; // Reset count if 0 is encountered
 }
 // If 5 consecutive 1's are found, stuff a 0
 if (count == 5) {
 output[j++] = '0';
 count = 0; // Reset count after stuffing
 }
 }
 output[j] = '\0'; // Null-terminate the output string
}
int main() {
 char input[100], output[200];
 printf("Enter the input bit stream: ");
 scanf("%s", input);
 bitStuffing(input, output);
 printf("Bit-stuffed output: %s\n", output);
 return 0;
}
