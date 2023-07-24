#include "limits.h"
#include "stdbool.h"
#include <stdio.h>
#include <string.h>

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

bool is_digit(char c) {
    // '0' is 48, '9' is 57
    return c >= 48 && c <= 57;
}

int to_digit(char c) {
    return c - 48;
}

int myAtoi(char * s){
    int size = strlen(s);

    bool whitespace_trimmed = false;
    bool positive = true;
    bool sign_determined = false;

    int digits_read = 0;
    int result = 0;

    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    for(int i = 0; i < size; i++) {
        char c = s[i];
        if(!whitespace_trimmed) {
            if(is_whitespace(c)) continue;
            whitespace_trimmed = true;
        }

        if(!sign_determined) {
            sign_determined = true;
            if(c == '-') {
                positive = false;
                continue;
            }
            if (c == '+') continue;
             
            if(c != '+' && !is_digit(c)) {
                return 0;
            }
        }

        if(!is_digit(c)) break;
        int c_digit = to_digit(c);

        if(digits_read == 9) {
            if(INT_MAX/10 < result) return positive ? INT_MAX : INT_MIN;
            result *= 10;    
        
            if(INT_MAX - result < c_digit) return positive ? INT_MAX : INT_MIN;
            result += c_digit;

            continue;        
        }
        else result += c_digit * pow10[8-digits_read];
        digits_read++;
    }

    result /= pow10[9-digits_read];
    return positive ? result : -result;
}

int main() {
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("words and 987"));
    printf("%d\n", myAtoi("-91283472332"));
    printf("%d\n", myAtoi("21474836460"));
    printf("%d\n", myAtoi("2147483647"));
    printf("%d\n", myAtoi("-2147483648"));
    printf("%d\n", myAtoi("-2147483649"));
    printf("%d\n", myAtoi("0"));
    printf("%d\n", myAtoi("   +0 123"));
    printf("%d\n", myAtoi("   + 123"));
    printf("%d\n", myAtoi("   +123"));
}