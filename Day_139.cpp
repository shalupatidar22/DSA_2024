#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char *s) {
    long long ans = 0;
    int i = 0, n = strlen(s);
    int sign = 1; // Default to positive

    // Skip leading spaces
    while (i < n && s[i] == ' ') i++;

    // Handle sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Process digits
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');

        // Check for overflow
        if (ans * sign > INT_MAX) return INT_MAX;
        if (ans * sign < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(ans * sign);
}

// Test the function
int main() {
    char input[] = "   -42";
    int result = myAtoi(input);
    printf("Converted number: %d\n", result);

    return 0;
}
