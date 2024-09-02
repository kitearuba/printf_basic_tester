
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "ft_printf.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int    ft_printf(char const *format, ...);

int main(void)
{
    char    *word;
    void    *nb;
    int    entero;
    unsigned int    unsign;
    unsigned int    num;
    int    total_format;
    int    total_verdadero;
    int    value;
    char    letter;
    double  decimal;
    int    passed_tests = 0;
    int    failed_tests = 0;

    // Function to compare results and update summary
    void check_test(int total_format, int total_verdadero, const char *test_name) {
        if (total_format == total_verdadero) {
            printf(GREEN "PASS: %s\n" RESET, test_name);
            passed_tests++;
        } else {
            printf(RED "FAIL: %s\n" RESET, test_name);
            failed_tests++;
        }
    }

    // Basic character tests
    ft_printf("Testing %%c with basic character:\n");
    letter = 'A';
    total_format = ft_printf("%c\n", letter);
    total_verdadero = printf("%c\n", letter);
    check_test(total_format, total_verdadero, "Basic %%c");

    ft_printf("Testing %%c with null character:\n");
    letter = '\0';
    total_format = ft_printf("%c\n", letter);
    total_verdadero = printf("%c\n", letter);
    check_test(total_format, total_verdadero, "Null %%c");

    ft_printf("Testing %%c with special characters:\n");
    letter = '\n';
    total_format = ft_printf("%c\n", letter);
    total_verdadero = printf("%c\n", letter);
    check_test(total_format, total_verdadero, "Special %%c");

    // String tests
    ft_printf("Testing %%s with basic string:\n");
    word = "Patri";
    total_format = ft_printf("Hello %s\n", word);
    total_verdadero = printf("Hello %s\n", word);
    check_test(total_format, total_verdadero, "Basic %%s");

    ft_printf("Testing %%s with empty string:\n");
    word = "";
    total_format = ft_printf("Hello %s\n", word);
    total_verdadero = printf("Hello %s\n", word);
    check_test(total_format, total_verdadero, "Empty %%s");

    ft_printf("Testing %%s with long string:\n");
    word = "This is an extremely long string to check the behavior of printf.";
    total_format = ft_printf("Hello %s\n", word);
    total_verdadero = printf("Hello %s\n", word);
    check_test(total_format, total_verdadero, "Long %%s");

    ft_printf("Testing %%s with special characters:\n");
    word = "\tHello\nWorld!";
    total_format = ft_printf("%s\n", word);
    total_verdadero = printf("%s\n", word);
    check_test(total_format, total_verdadero, "Special %%s");

    // Pointer tests
    ft_printf("Testing %%p with variable address:\n");
    value = 42;
    nb = &value;
    total_format = ft_printf("Hello %p\n", nb);
    total_verdadero = printf("Hello %p\n", nb);
    check_test(total_format, total_verdadero, "Pointer %%p");

    ft_printf("Testing %%p with NULL:\n");
    total_format = ft_printf("Hello %p\n", NULL);
    total_verdadero = printf("Hello %p\n", NULL);
    check_test(total_format, total_verdadero, "Pointer NULL %%p");

    // Integer tests
    ft_printf("Testing %%d with positive integer:\n");
    entero = 42;
    total_format = ft_printf("Hello %d\n", entero);
    total_verdadero = printf("Hello %d\n", entero);
    check_test(total_format, total_verdadero, "Positive %%d");

    ft_printf("Testing %%d with negative integer:\n");
    entero = -42;
    total_format = ft_printf("Hello %d\n", entero);
    total_verdadero = printf("Hello %d\n", entero);
    check_test(total_format, total_verdadero, "Negative %%d");

    ft_printf("Testing %%d with INT_MAX:\n");
    total_format = ft_printf("Hello %d\n", INT_MAX);
    total_verdadero = printf("Hello %d\n", INT_MAX);
    check_test(total_format, total_verdadero, "INT_MAX %%d");

    ft_printf("Testing %%d with INT_MIN:\n");
    total_format = ft_printf("Hello %d\n", INT_MIN);
    total_verdadero = printf("Hello %d\n", INT_MIN);
    check_test(total_format, total_verdadero, "INT_MIN %%d");

    // Unsigned integer tests
    ft_printf("Testing %%u with positive unsigned integer:\n");
    unsign = 42;
    total_format = ft_printf("Hello %u\n", unsign);
    total_verdadero = printf("Hello %u\n", unsign);
    check_test(total_format, total_verdadero, "Positive %%u");

    ft_printf("Testing %%u with UINT_MAX:\n");
    total_format = ft_printf("Hello %u\n", UINT_MAX);
    total_verdadero = printf("Hello %u\n", UINT_MAX);
    check_test(total_format, total_verdadero, "UINT_MAX %%u");

    // Hexadecimal tests
    ft_printf("Testing %%x with positive number:\n");
    num = 42;
    total_format = ft_printf("Hello %x\n", num);
    total_verdadero = printf("Hello %x\n", num);
    check_test(total_format, total_verdadero, "Positive %%x");

    ft_printf("Testing %%x with UINT_MAX:\n");
    total_format = ft_printf("Hello %x\n", UINT_MAX);
    total_verdadero = printf("Hello %x\n", UINT_MAX);
    check_test(total_format, total_verdadero, "UINT_MAX %%x");

    ft_printf("Testing %%X with positive number:\n");
    total_format = ft_printf("Hello %X\n", num);
    total_verdadero = printf("Hello %X\n", num);
    check_test(total_format, total_verdadero, "Positive %%X");

    ft_printf("Testing %%X with UINT_MAX:\n");
    total_format = ft_printf("Hello %X\n", UINT_MAX);
    total_verdadero = printf("Hello %X\n", UINT_MAX);
    check_test(total_format, total_verdadero, "UINT_MAX %%X");

    ft_printf("Testing %%x with value 0:\n");
    total_format = ft_printf("Hello %x\n", 0);
    total_verdadero = printf("Hello %x\n", 0);
    check_test(total_format, total_verdadero, "Zero %%x");

    ft_printf("Testing %%X with value 0:\n");
    total_format = ft_printf("Hello %X\n", 0);
    total_verdadero = printf("Hello %X\n", 0);
    check_test(total_format, total_verdadero, "Zero %%X");

    ft_printf("Testing %%i with value 0:\n");
    total_format = ft_printf("Hello %i\n", 0);
    total_verdadero = printf("Hello %i\n", 0);
    check_test(total_format, total_verdadero, "Zero %%i");

    ft_printf("Testing %%u with value 0:\n");
    total_format = ft_printf("Hello %u\n", 0);
    total_verdadero = printf("Hello %u\n", 0);
    check_test(total_format, total_verdadero, "Zero %%u");

    // NULL value tests
    ft_printf("Testing NULL with %%p:\n");
    total_format = ft_printf("Hello %p\n", NULL);
    total_verdadero = printf("Hello %p\n", NULL);
    check_test(total_format, total_verdadero, "NULL %%p");

    ft_printf("Testing NULL with %%s:\n");
    total_format = ft_printf("Hello %s\n", (char *)NULL);
    total_verdadero = printf("Hello %s\n", (char *)NULL);
    check_test(total_format, total_verdadero, "NULL %%s");

    // Special characters
    ft_printf("Testing special characters:\n");
    total_format = ft_printf("Hello \\t World\n");
    total_verdadero = printf("Hello \\t World\n");
    check_test(total_format, total_verdadero, "Special characters");

    ft_printf("Testing escape characters:\n");
    total_format = ft_printf("Hello \\n \\t \\r\n");
    total_verdadero = printf("Hello \\n \\t \\r\n");
    check_test(total_format, total_verdadero, "Escape characters");

    // Complex combinations
    ft_printf("Testing complex combination:\n");
    total_format = ft_printf("Number: %d, String: %s, Hex: %x\n", 42, "Text", 255);
    total_verdadero = printf("Number: %d, String: %s, Hex: %x\n", 42, "Text", 255);
    check_test(total_format, total_verdadero, "Complex combination");

    // Additional memory and limit tests
    ft_printf("Testing long and complex string:\n");
    word = "This is a test with an extremely long string to verify how printf handles memory cases and the limits of its implementation. We want to ensure there are no memory management issues and the behavior is consistent.";
    total_format = ft_printf("Result: %s\n", word);
    total_verdadero = printf("Result: %s\n", word);
    check_test(total_format, total_verdadero, "Long and complex string");

    // Summary of results
    printf("\n");
    printf("Summary:\n");
    printf(GREEN "Passed: %d\n" RESET, passed_tests);
    printf(RED "Failed: %d\n" RESET, failed_tests);

    return (0);
}
