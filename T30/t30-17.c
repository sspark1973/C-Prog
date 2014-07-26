/*
17.Write a program to replace a specified line in a text file.
*/

#include <stdio.h>

int main() 
{
	FILE *fp1, *fp2;
	char filename[40];
	char c;
	int del_line, temp=1;

	printf("Enter File Name :\n");
	scanf("%s", &filename);

	fp1 = fopen(filename, "r");

	c = getc(fp1);

	while(c != EOF) {
		printf("%c", c);
		c = getc(fp1);
	}

	printf("\n Enter line number to be deleted and replaced:\n");
	scanf("%d", &del_line);

	rewind(fp1);

	fp2 = fopen("copy.c", "w");
	c = getc(fp1);

	while(c != EOF) {
		if(c == '\n') {
			temp++;
		}

		if(temp != del_line) {
			putc(c, fp2);
		} else {
			printf("Enter new text:\n");
			fflush(stdin);  //fflush(stdin)??? stdin????? ?? ??? ????.
			putc('\n', fp2);

			while((c = getchar()) != '\n')
				putc(c, fp2);
			temp++;
		}

		c = getc(fp1);
	}

	fclose(fp1);
	fclose(fp2);

	remove(filename);
	rename("copy.c", filename);

	fp1 = fopen(filename, "r");
	c = getc(fp1);

	while(c != EOF ) {
		printf("%c", c);
		c = getc(fp1);
	}
	fclose(fp1);
	return 0;
}
	
	

