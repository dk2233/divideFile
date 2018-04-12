
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
	printf("\n open file %s \n",file_name);
	char *line = malloc(300);
	fgets(line,300,fromFile);

	while( (line!=NULL) &&  (strstr(line,END_OF_FILE) == NULL)  )
	{


		fprintf(file1,"%s",line);
		//printf("%s",line);
		fgets(line,300,fromFile);

	}

	printf(" LAST line %s ",line);
	fclose(file1);


}





void removeAllsymbol(char symbol, char * array_c)
{
	int i, j;
	//char *word1 = malloc(strlen(array_c));
	char *word2 = malloc(strlen(array_c));

	while( strchr(array_c, symbol) )
	{
		for(i=0; i<strlen(array_c);i++)
		{
			if  (array_c[i] == symbol)
			{
				printf(" %d ",i);
				for(j=i; j<(strlen(array_c)-1);j++)
				{
					array_c[j]=array_c[j+1];
					printf("%d -> %c ",j,array_c[j]);
				}
				//array_c[j+1]='\0';
				array_c[j-1]='\0';
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
	//uint8_t nr_line;

	FILE *file_to_analyse;
	if (argc>1)
	{
		printf(" I opened file %s ",argv[1]);

		file_to_analyse = fopen(argv[1],"r");


		fgets(line,300,file_to_analyse);
		while(*line != (char)NULL)
		{

			printf("line  : %s \n",line);

			if (strstr(line,SEARCH_FILE_NAME) != NULL)
			{
				printf(" \t I have found %s \n",line);
				temp = strpbrk(line," ");
				printf(" line with marker %s",temp);
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

			*line = (char)NULL;
			fgets(line,300,file_to_analyse);


		}
		fclose(file_to_analyse);
	}
	return 0;
}
