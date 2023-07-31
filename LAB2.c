#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
	
	FILE *fptr1, *fptr2;
	char filename[100], c;
	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	// Open one file for reading
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	printf("Enter the filename to open for writing: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+"); // Open another file for writing
	
	// Read contents from file
	fseek(fptr1,0,SEEK_END);
	long filesize = ftell(fptr1);
	fseek(fptr2,0,SEEK_SET);
	long pos= filesize -1;
	while ( pos >= 0)
	{	
		fseek(fptr1,pos,SEEK_SET);
		c = fgetc(fptr1);
		fputc(c, fptr2);
		pos--;
	}
	fprintf(fptr2,"%s %li","\nSize =",filesize);

	printf("\nContents copied to %s", filename);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}