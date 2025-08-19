#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Recursive function to count vowels
int countVowels(char str[], int i) {
    // Base Case: If the end of the string is reached, return 0.
    if (str[i] == '\0' || str[i] == '\n') {
        return 0;
    }

    // Convert the current character to lowercase for consistent checking.
    char ch = tolower(str[i]);

    // Recursive Step: Check if the current character is a vowel.
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        // If it's a vowel, add 1 to the count and recurse.
        return 1 + countVowels(str, i + 1);
    } else {
        // If it's not a vowel, don't add to the count and recurse.
        return countVowels(str, i + 1);
    }
}

int main() {
    char str[201];
    fgets(str, 201, stdin);

    // Call the recursive function starting from index 0.
    int vowelCount = countVowels(str, 0);
    printf("%d\n", vowelCount);

    return 0;
}
