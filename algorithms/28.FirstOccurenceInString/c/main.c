#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    int needle_pointer = 0;

    for(int i = 0; i < haystack_len; i++) {
        if(needle_pointer == needle_len) return i - needle_len;
        if(haystack[i] == needle[needle_pointer]) needle_pointer++;
        else { i -= needle_pointer; needle_pointer = 0; }
    }

    if(needle_pointer == needle_len) return haystack_len - needle_len;
    return -1;
}

int main() {
		char haystack[] = "hello";
		char needle[] = "ll";
		printf("%d\n", strStr(haystack, needle));

		char haystack2[] = "aaaaa";
		char needle2[] = "bba";
		printf("%d\n", strStr(haystack2, needle2));

		char haystack3[] = "";
		char needle3[] = "";
		printf("%d\n", strStr(haystack3, needle3));

		char haystack4[] = "a";
		char needle4[] = "a";
		printf("%d\n", strStr(haystack4, needle4));

		char haystack5[] = "mississippi";
		char needle5[] = "issip";
		printf("%d\n", strStr(haystack5, needle5));

		char haystack6[] = "mississippi";
		char needle6[] = "issipi";
		printf("%d\n", strStr(haystack6, needle6));

		char haystack7[] = "mississippi";
		char needle7[] = "pi";
		printf("%d\n", strStr(haystack7, needle7));

		char haystack8[] = "mississippi";
		char needle8[] = "issipi";
		printf("%d\n", strStr(haystack8, needle8));
}