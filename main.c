
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define SEARCH_FILE_NAME   "<file"
#define END_OF_FILE        "</file"

void removeAllsymbol(char symbol, char * array_c);



void copyAllLineToFile(char *file_name, FILE *fromFile)
{
	FILE *file = fopen(file_name,"w");
	char *line = malloc(300);


	while(str )
	{
		fgets(line,300,file_to_analyse);
	}


	fclose(file);


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
				printf(" removed %c in %s",symbol,word2);
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
				printf("\n open file %s ",temp);

			}
			else
			{
				printf(" sthg wrong ");
				return 1;
			}
		}


	}
	return 0;
}
