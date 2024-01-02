#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	int i = 0, j = 0, k, d, ext = 8, m;
	char a[50] = "", flag[] = "01111110", temp[50] = "";

	printf("Enter the number of characters: ");
	scanf("%d", &m);

	printf("\nEnter the characters : ");
	for(i = 0 ; i < m+1 ; i++) {
		scanf("%c", &a[i]);
	}

	printf("\nOrignal Data : ");
	for(i = 0 ; i < m+1 ; i++) {
		printf("%c", a[i]);
	}

	strcpy(temp, flag);

	for(i = 0, j = 0; i < strlen(a); i++) {
		if(a[i] == '1') {
			j++;
		} else j = 0;

		temp[i + ext] = a[i];

		if(j == 5) {
			++ext;
			temp[i + ext] = '0';
			j = 0;
		}
	}
	
	strcat(temp, flag);
	printf("\nFinal sequence : ");
	for(i = 0 ; i < strlen(temp) + 1 ; i++) {
		if(temp[i] == '\n') continue;
		printf("%c", temp[i]);
	}
	return 0;
}
