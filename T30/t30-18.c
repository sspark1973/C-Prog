/*
18.Write a program to find the number of lines in a text file.
Number of lines in a file can be determined by counting the number of new line characters present.
*/

#include <stdio.h>

int main()
{
	FILE *fp;
	char filename[40], sample_chr;
	int no_lines = 0;

	printf("Enter the file name :\n");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	printf("fp = [%x]\n", fp);

	sample_chr = getc(fp);

	while(sample_chr != EOF) {
		printf("%c", sample_chr);
		if(sample_chr == '\n') {
			printf("New Line\n");
				no_lines++;
		}

		sample_chr = getc(fp);
	}

	fclose(fp);
	printf("There are %d lines in %s\n", no_lines, filename);
}
