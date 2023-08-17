#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define max_length  11
#define min_length  5

#define alpha_max_ascii 88
#define alpha_min_ascii 65

#define salpha_max_ascii 120
#define salpha_min_ascii 97

#define digit_max_ascii 57
#define digit_min_ascii 48

char generate_random_alphanum_char();
char generate_random_alphanum_char()
{
    int chance;
    char palindrome;

    chance = rand() % 3;

        if (chance == 0)
        palindrome = rand() % ((digit_max_ascii - digit_min_ascii)+1) + digit_min_ascii;

         if (chance == 1)
        palindrome = rand() % ((alpha_max_ascii - alpha_min_ascii)+1) + alpha_min_ascii;

        if(chance == 2)
        palindrome = rand() % ((salpha_max_ascii - salpha_min_ascii)+1) + salpha_min_ascii;

        return palindrome;
    
    
   
}


void generateAlphanumericPalindrome(char *str, int length) {
    int i;
    
    // Generating half of the palindrome
    for (i = 0; i < (length+1) / 2; i++) {
        str[i] = generate_random_alphanum_char ();
    }

    // Mirroring it to create a palindrome
    for (; i < length; i++) {
        str[i] = str[length - i - 1];
    }

    str[length] = '\0';
}


int main() {

    int length;
    srand(time(NULL)); // Seed the random number generator with the current time

    length = rand() % ((max_length - min_length) + 1) + min_length;
    char palindrome[length];

    
    generateAlphanumericPalindrome(palindrome, max_length);

    printf("Generated Alphanumeric Palindrome: %s\n", palindrome);

    return 0;
}
