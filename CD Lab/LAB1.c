#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
	int ccount=0;
	int line=0;
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
	c = fgetc(fptr1);
	// Read contents from file
	while (c != EOF)
	{	
		ccount=ccount+1;
		fputc(c, fptr2);
		c = fgetc(fptr1);
		if(c ==' ')
			line=line+1;
	}

	fprintf(fptr2,"%s %d","No. of Characters =",ccount);
	fprintf(fptr2,"%s %d","\nNo. of Lines =",line);
	printf("\nContents copied to %s", filename);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
