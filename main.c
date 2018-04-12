
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define SEARCH_FILE_NAME   "<file"
#define END_OF_FILE        "</file"

void removeAllsymbol(char symbol, char * array_c);
void copyAllLineToFile(char *file_name, FILE *fromFile);


void copyAllLineToFile(char *file_name, FILE *fromFile)
{
	FILE *file1;
	printf(" file to open %s",file_name);
	file1= fopen(file_name,"w");
	printf("\n open file %s ",file_name);
	char *line = malloc(300);
	fgets(line,300,fromFile);

	while( (line!=NULL) &&   (strstr(line,END_OF_FILE) == NULL)  )
	{


		fprintf(file1,"%s",line);
		//printf("%s",line);
		fgets(line,300,fromFile);

	}


	fclose(file1);


}





void removeAllsymbol(char symbol, char * array_c)
{
	int i;
	//char *word1 = malloc(strlen(array_c));
	char *word2 = malloc(strlen(array_c));

	while( strchr(array_c, symbol) )
	{
		for(i=0; i<strlen(array_c);i++)
		{
			if (array_c[i] == symbol)
			{
				char *word1 = malloc(i);
				word2 = memcpy(word1,array_c,i);
				word2[i]='\0';
				strcpy(array_c,word2);
				printf(" removed %c in %s \n\n",symbol,word2);
				return;
			}
		}
	}



}


int main(int argc, char *argv[])
{
	char *line = malloc(300);
	char *temp = malloc(300);

	FILE *file_to_analyse;
	if (argc>1)
	{
		printf(" I opened file %s ",argv[1]);

		file_to_analyse = fopen(argv[1],"r");
		fgets(line,300,file_to_analyse);

		printf(" line 1 :\n %s \n",line);

		if (strstr(line,SEARCH_FILE_NAME) != NULL)
		{
			temp = strpbrk(line," ");
			if (temp != NULL)
			{

				//char *loc_p = strchr(line,">");
				removeAllsymbol('>',temp);
				printf("after1: %s \n",temp);
				removeAllsymbol(' ',temp);
				copyAllLineToFile(temp,file_to_analyse);
			}
			else
			{
				printf(" sthg wrong ");
				return 1;
			}
		}

		fclose(file_to_analyse);
	}
	return 0;
}
