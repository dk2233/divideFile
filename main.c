
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#define SEARCH_FILE_NAME   "<file"
#define END_OF_FILE        "</file"
#define BUFFER_LENGTH 		150U

#if defined(__WIN32) ||  defined(WIN32)
#define		HOW_MANY_DIGIT_LESS		1U
#define	HOW_MANY_DIGIT_LESS2  0U
#elif defined(__APPLE__)
#define		HOW_MANY_DIGIT_LESS		1U
#endif


void removeAllsymbol(char symbol, char * array_c);
void copyAllLineToFile(char *file_name, FILE *fromFile);
void showAllChars(char *string);


void showAllChars(char *string)
{
	int i;
	for(i=0; i<strlen(string); i++)
	{
		printf("%d %c \n",i,string[i]);
	}
}


void copyAllLineToFile(char *file_name, FILE *fromFile)
{
	FILE *file1;

	char *line;
	//char *fileName2;
	char tab[BUFFER_LENGTH]={0};

	strcpy(tab,".\\");
	strcat(tab,file_name);
	printf(" file to open %s",tab);
	file1= fopen(tab,"w+");

	line= malloc(BUFFER_LENGTH);

	if (NULL == file1)
	{
		perror(" there is a problem opening file :");
		exit(1);
	}
	printf("\n open file %s \n",file_name);
	fgets(line,BUFFER_LENGTH,fromFile);

	while( (line!=NULL) &&  (strstr(line,END_OF_FILE) == NULL)  )
	{

		fprintf(file1,"%s",line);
		fgets(line,BUFFER_LENGTH,fromFile);

	}

	printf(" LAST line %s ",line);
	fclose(file1);


}





void removeAllsymbol(char symbol, char * array_c)
{
	int i, j;

	printf(" length of string %d \n",strlen(array_c));
	while( strchr(array_c, symbol) )
	{
		for(i=0; i<strlen(array_c);i++)
		{
			if  (array_c[i] == symbol)
			{
				printf("position %d of %c \n",i,array_c[i]);
				for(j=i; j<(strlen(array_c));j++)
				{
					array_c[j]=array_c[j+1];
					printf("%d -> %c ",j,array_c[j]);
				}
				printf(" removed %c in %s \n\n",symbol,array_c);

			}
		}

	}

	printf("AFTER length of string %d \n",strlen(array_c));

}


int main(int argc, char *argv[])
{
	char *line = malloc(BUFFER_LENGTH);
	char *temp = malloc(BUFFER_LENGTH);
	FILE *file_to_analyse;


	printf(" \n\n *************** \n\n");
	if (argc>1)
	{
		printf(" I opened file %s ",argv[1]);

		file_to_analyse = fopen(argv[1],"r");
		if (NULL == file_to_analyse)
		{
			perror(" I cant open file:");
			exit(0);
		}
		fgets(line,BUFFER_LENGTH,file_to_analyse);
		while(line != NULL)
		{


			if (strstr(line,SEARCH_FILE_NAME) != NULL)
			{
				printf(" \t I have found %s \n",line);
				temp = strpbrk(line," ");
				printf(" line with marker %s",temp);
				if (temp != NULL)
				{

					//showAllChars(temp);
					removeAllsymbol('\n',temp);
					removeAllsymbol('>',temp);
					removeAllsymbol(' ',temp);
					//showAllChars(temp);


					copyAllLineToFile(temp,file_to_analyse);
				}
				else
				{
					printf(" sthg wrong ");
					return 1;
				}

			}


			line = fgets(line,BUFFER_LENGTH,file_to_analyse);
			printf("LINE %s ",line);

		}
	fclose(file_to_analyse);
	}
	else
	{
		printf(" \n Please give file name as an arguement \n");
	}

	return 0;
}
