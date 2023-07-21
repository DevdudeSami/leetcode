#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows){

		if(numRows == 1) return s;

    int size = strlen(s);
    int climb_factor = numRows-2;
    int climb_index = 0;
    int vertical_index = 0;
    bool climbing = false;

    char buffer[numRows][100];
    int row_indices[numRows];
    for(int i = 0; i < numRows; i++) row_indices[i] = 0;

    for(int i = 0; i < size; i++) {
        if(climbing) {
            if(climb_index == climb_factor) {
                climbing = false;
                climb_index = 0;
                i--; // process this character again
                continue;
            }

            int row = numRows - 2 - climb_index;
            int col = row_indices[row];

            buffer[row][col] = s[i];
            row_indices[row]++;
            climb_index++;
            continue;
        }

        if(vertical_index == numRows) {
            climbing = true;
            vertical_index = 0;
            i--; // process this character again
            continue;
        }

        int col = row_indices[vertical_index];
        buffer[vertical_index][col] = s[i];
         
        row_indices[vertical_index]++;
        vertical_index++;
    }

    // read the buffer
    char * result = (char*)malloc(sizeof(char)*size);
    int result_index = 0;

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < row_indices[i]; j++) {
            result[result_index] = buffer[i][j];
            result_index++;
        }
    }

    return result;
}

int main() {
		char * s = "PAYPALISHIRING";
		printf("%s\n", convert(s, 3));
		printf("%s\n", convert(s, 4));
		printf("%s\n", convert(s, 1));
		return 0;
}