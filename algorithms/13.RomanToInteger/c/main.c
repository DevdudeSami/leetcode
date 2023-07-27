int romanToInt(char * s){
    int n = strlen(s);
    int result = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'M') {
            result += 1000;
            continue;
        }

        // Check for 900
        if(s[i] == 'C' && i < n-1 && s[i+1] == 'M') {
            result += 900;
            i++;
            continue;
        } 

        // Check for 500
        if(s[i] == 'D') {
            result += 500;
            continue;
        }

        // Check for 400
        if(s[i] == 'C' && i < n-1 && s[i+1] == 'D') {
            result += 400;
            i++;
            continue;
        }

        // Check for 100s
        if(s[i] == 'C') {
            result += 100;
            continue;
        }

        // 90
        if(s[i] == 'X' && i < n-1 && s[i+1] == 'C') {
            result += 90;
            i++;
            continue;
        }

        // 50
        if(s[i] == 'L') {
            result += 50;
            continue;
        }

        // 40
        if(s[i] == 'X' && i < n-1 && s[i+1] == 'L') {
            result += 40;
            i++;
            continue;
        }

        // 10s
        if(s[i] == 'X') {
            result += 10;
            continue;
        }

        // 9
        if(s[i] == 'I' && i < n-1 && s[i+1] == 'X') {
            result += 9;
            i++;
            continue;
        }

        // 5
        if(s[i] == 'V') {
            result += 5;
            continue;
        }

        // 4
        if(s[i] == 'I' && i < n-1 && s[i+1] == 'V') {
            result += 4;
            i++;
            continue;
        }

        // 1s
        if(s[i] == 'I') {
            result += 1;
            continue;
        }
    }

    return result;
}