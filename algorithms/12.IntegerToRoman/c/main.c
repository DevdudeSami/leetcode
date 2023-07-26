#include <stdio.h>
#include <stdlib.h>

char * intToRoman(int num){
    char * result = (char *)calloc(16, sizeof(char));
    int cursor = 0;
    
    // Count the thousands
    int thousands = num / 1000;
    // this will only ever be between 0 and 3 because 1 <= num <= 3999
    for(int i = 0; i < thousands; i++) result[cursor++] = 'M';

    int remainder = num - thousands * 1000;
    // Decide on next number
    if(remainder >= 900) {
        result[cursor++] = 'C';
        result[cursor++] = 'M';
        remainder -= 900;
    }

    // Count the five hundreds
    if(remainder >= 500) {
        result[cursor++] = 'D';
        remainder -= 500;
    }

    // Count the hundreds
    int one_hundreds = remainder / 100;
    if(one_hundreds == 4) {
        result[cursor++] = 'C';
        result[cursor++] = 'D';
    } else for(int i = 0; i < one_hundreds; i++) result[cursor++] = 'C';

    remainder -= one_hundreds * 100;
    // Decide on next number
    if(remainder >= 90) {
        result[cursor++] = 'X';
        result[cursor++] = 'C';
        remainder -= 90;
    }

    // Count the fifties
    if(remainder >= 50) {
        result[cursor++] = 'L';
        remainder -= 50;
    }

    // Count the tens
    int tens = remainder / 10;
    if(tens == 4) {
        result[cursor++] = 'X';
        result[cursor++] = 'L';
    } else for(int i = 0; i < tens; i++) result[cursor++] = 'X';

    remainder -= tens * 10;

    // Decide on next number
    if(remainder >= 9) {
        // Either IIX or IX
        result[cursor++] = 'I';
        result[cursor++] = 'X';
        remainder -= 9;
    }

    // Count the fives
    if(remainder >= 5) {
        result[cursor++] = 'V';
        remainder -= 5;
    }
    
    if(remainder == 4) {
        result[cursor++] = 'I';
        result[cursor++] = 'V';
    } else for(int i = 0; i < remainder; i++) result[cursor++] = 'I';

    return result;
}

int main() {
    printf("%s\n", intToRoman(3));
    printf("%s\n", intToRoman(4));
    printf("%s\n", intToRoman(9));
    printf("%s\n", intToRoman(58));
    printf("%s\n", intToRoman(1994));
    printf("%s\n", intToRoman(3999));
    printf("%s\n", intToRoman(40));
    printf("%s\n", intToRoman(400));
    printf("%s\n", intToRoman(1540));
    printf("%s\n", intToRoman(1560));
    printf("%s\n", intToRoman(1740));
    printf("%s\n", intToRoman(1840));
    printf("%s\n", intToRoman(5));
    printf("%s\n", intToRoman(50));
    printf("%s\n", intToRoman(500));
    printf("%s\n", intToRoman(800));
    printf("%s\n", intToRoman(80));
    printf("%s\n", intToRoman(8));
    printf("%s\n", intToRoman(81));
    printf("%s\n", intToRoman(288));
    printf("%s\n", intToRoman(888));
    printf("%s\n", intToRoman(2888));


    return 0;
}