#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
	
	FILE *fptr1,*fptr3, *fptr2;
	char filename[100], c ,e ;
	printf("Enter the FIRST filename to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	// Open one file for reading
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	printf("Enter the SECOND filename to open for reading: \n");
	scanf("%s", filename);
	fptr3 = fopen(filename, "r");
	// Open one file for reading
	if (fptr3 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}


	printf("Enter the filename to open for writing: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+"); // Open another file for writing
	
	// Read contents from file
	c = fgetc(fptr1);
	e = fgetc(fptr3);
	while (c != EOF)
	{	
		
		fputc(c, fptr2);
		fputc(e, fptr2);
		while(c != '\0')
			c = fgetc(fptr1);
		while(e != '\0')
			e = fgetc(fptr3);

				
	}
	printf("\nContents copied to %s", filename);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}