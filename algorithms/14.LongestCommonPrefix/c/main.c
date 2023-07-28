#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * longestCommonPrefix(char ** strs, int strsSize){

    if(strsSize == 1) return strs[0];

    int sizes[strsSize];
    for(int i = 0; i < strsSize; i++) sizes[i] = strlen(strs[i]);

    char *result = (char *)calloc(sizes[0], sizeof(char));

    for(int i = 0; i < sizes[0]; i++) {
        bool breaking = false;
        for(int j = 0; j < strsSize; j++) {
            printf("i %d, j %d\n",i,j);
            if(i >= sizes[j]) {
                breaking = true;
                break;
            }
            printf("processing %c\n", strs[j][i]);
            if(strs[0][i] != strs[j][i]) {
                breaking = true;
                break;
            }
        }
        if(breaking) break;
        result[i] = strs[0][i];
    }

    return result;
}

int main() {
		char *strs[] = {"flower","flow","flight"};
		char *result = longestCommonPrefix(strs, 3);
		printf("%s\n", result);
		free(result);

		char *strs2[] = {"dog","racecar","car"};
		result = longestCommonPrefix(strs2, 3);
		printf("%s\n", result);
		free(result);

		char *strs3[] = {"a"};
		result = longestCommonPrefix(strs3, 1);
		printf("%s\n", result);
		// free(result);

		char *strs10[] = {"flower", "flower", "flower", "flower"};
		result = longestCommonPrefix(strs10, 4);
		printf("%s\n", result);
		free(result);

		// char *strs4[] = {"ab", "a"};
		// result = longestCommonPrefix(strs4, 2);
		// printf("%s\n", result);
		// free(result);

		// char *strs5[] = {"ab", "ab"};
		// result = longestCommonPrefix(strs5, 2);
		// printf("%s\n", result);
		// free(result);

		// char *strs6[] = {"ab", "abc"};
		// result = longestCommonPrefix(strs6, 2);
		// printf("%s\n", result);
		// free(result);

		// char *strs7[] = {"ab", "abc", "abcd"};
		// result = longestCommonPrefix(strs7, 3);
		// printf("%s\n", result);
		// free(result);

		// char *strs8[] = {"ab", "abc", "abcd", "abcde"};
		// result = longestCommonPrefix(strs8, 4);
		// printf("%s\n", result);
		// free(result);

		return 0;
}