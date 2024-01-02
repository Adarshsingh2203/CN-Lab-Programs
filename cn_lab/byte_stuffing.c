#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    char originalData[100] = "";
    char transmittedData[100] = "";
    char prefix[6] = "dlestx";
	char finalData[100] = "";

    int dataSize;
    int i, j;

    printf("Enter data size: ");
    scanf("%d", &dataSize);

	getchar() ;

    printf("Enter data: ");
    for (i = 0; i < dataSize; i++)
        scanf("%c", &originalData[i]);

    printf("Original data is: ");
    for (i = 0; i < dataSize; i++)
        printf("%c", originalData[i]);

    strncpy(transmittedData, prefix, 6);

    for (i = 0, j = 6; i <= dataSize; i++, j++) {
        if (originalData[i] == 'd' && originalData[i + 1] == 'l' && originalData[i + 2] == 'e') {
            transmittedData[j] = 'd';
			j++;
			transmittedData[j] = 'l';
			j++;
			transmittedData[j] = 'e';
			j++;
        }
        transmittedData[j] = originalData[i];
		
    }

    strcpy(finalData, transmittedData);
	strncat(finalData, prefix, 6);

    printf("\nTransmitted data is: ");
    for (i = 0; i <= strlen(finalData); i++) {
        if (finalData[i] == '\n') continue;
        printf("%c", finalData[i]);
    }

    return 0;
}
