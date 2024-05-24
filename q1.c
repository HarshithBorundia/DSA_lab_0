/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char a[1000];
    char b[1000];

    // Use %999s instead of %s to avoid buffer overflow
    scanf("%s", a);
    scanf("%s", b);

    int i = 0;
    while (a[i] >= '0' && a[i] <= '9') {
        i++;
    }
    int len1 = i;

    int j = 0;
    while (b[j] >= '0' && b[j] <= '9') {
        j++;
    }
    int len2 = j;

    char sum[1001]; // Make room for a potential carry at the beginning
    int k = 1000;
    int carry = 0;

    while (len1 > 0 || len2 > 0) {
        int val1 = (len1 > 0) ? a[--len1] - '0' : 0;
        int val2 = (len2 > 0) ? b[--len2] - '0' : 0;

        int sum1 = val1 + val2 + carry;
        carry = sum1 / 10;
        sum1 = sum1 % 10;

        char ch = sum1 + '0';
        sum[k--] = ch;
    }

    // Add any remaining carry
    while (carry > 0) {
        sum[k--] = (carry % 10) + '0';
        carry /= 10;
    }

    // Print the result starting from k+1
    for (int t = k + 1; t <= 1000; t++) {
        printf("%c", sum[t]);
    }

    return 0;
}


