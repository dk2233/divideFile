#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "defines.h"
#include "timing.h"

void removeAllsymbol(char symbol, char * array_c);
void copyAllLineToFile(char *file_name, char** fromFile);
void showAllChars(char *string);
long int FileSize(FILE* file);
char* FindWord(char** table);

long int FileSize(FILE* file)
{
    long int size=0;
    if (0==fseek(file,0L, SEEK_END))
    {
        size = ftell(file);
        /*         (void)fseek(file,0L,SEEK_SET);
        */
        rewind(file);
    }
    return size;

}



void showAllChars(char *string)
{
    unsigned int i;
    for(i=0; i<strlen(string); i++)
    {
        printf("%d %c \n",i,string[i]);
    }
}


void copyAllLineToFile(char *file_name, char** fromFile)
{
    FILE *file1;
    char* str1, *str2;
    char *separator=PATH_SEPARATOR;
    char *tab = calloc(strlen(".")+1+strlen(separator)+1+strlen(file_name)+1,sizeof(char));

    /*     strcat(tab,".");
     *     strcat(tab,separator);
     */
    strcat(tab,file_name);
    printf(" file to write: %s\n",tab);
    file1= fopen(tab,"w+");
    free(tab);

    while((**fromFile!=0) && (*fromFile!=NULL))
    {
        str1 = strchr(*fromFile,'\n');
        if (str1 == NULL)
        {
            break;
        }

        str2 = calloc((str1+1-*fromFile)+1,sizeof(char));
        str2=strncpy(str2,*fromFile, (str1+1-*fromFile));

        if (strstr(str2,END_OF_FILE) != NULL)
        {
            free(str2);
            //            printf("\t\tfound end of file %s\n",END_OF_FILE);
            break;
        }
        while(*fromFile <= str1)
        {
            fputc(**fromFile,file1);
            (*fromFile)++;
        }
        free(str2);
    }
    fclose(file1);
}


char* FindWord(char** table)
{
    char* retStr=calloc(512,sizeof(char));
    uint32_t iStr=0U;
    for(  ; **table!=0;(*table)++)
    {
        if ((isalnum(**table)) || (**table=='.') || ('_'==**table))
        {
            retStr[iStr++]=**table;
        }
        /*  if no letter was found keep focus to next char */
        else if (iStr>0)
        {
            retStr[iStr++]=0;
            break;
        }
        else
        {
            ;
        }
    }
    return retStr;
}


void removeAllsymbol(char symbol, char * array_c)
{
    unsigned int i, j;

    printf(" length of string %d \n",strlen(array_c));
    while( strchr(array_c, symbol) )
    {
        for(i=0; i<strlen(array_c);i++)
        {
            if  (array_c[i] == symbol)
            {
                //                printf("position %d of %c \n",i,array_c[i]);
                for(j=i; j <(strlen(array_c));j++)
                {
                    array_c[j]=array_c[j+1];
                    printf("%d -> %c ",j,array_c[j]);
                }
                //                printf(" removed %c in %s \n\n",symbol,array_c);

            }
        }

    }

}


int main(int argc, char *argv[])
{
    char *line; 
    char *startLine;
    FILE *file_to_analyse;
    long int fSize;

    MeasureClock();
    if (argc>1)
    {
        printf(" I opened file %s\n",argv[1]);

        file_to_analyse = fopen(argv[1],"r");
        if (NULL == file_to_analyse)
        {
            perror(" I cant open file:\n\n");
            exit(0);
        }

        fSize = FileSize(file_to_analyse);
        line =  calloc(fSize+1,sizeof(char));     
        startLine=line;
        do
        {
            *line = fgetc(file_to_analyse); 
            line++;
        }
        while(0==feof(file_to_analyse));
        fclose(file_to_analyse);
        *line='\0';

        line=startLine;
        if (line != NULL)
        {
            while ((*line) && (*line!='\0') && (*line !=EOF)) 
            {
                char* str3;
                printf("%d\n",line-startLine);
                line = strstr(line,SEARCH_FILE_NAME) ;
                if (line != NULL)
                {
                    //                    printf(" \t I have found %.60s \n",line);
                    str3 = FindWord(&line);
                    free(str3);
                    str3 = FindWord(&line);
                    while(*line !='\n')
                    {
                        line++;
                    }
                    line++;
                    if (str3!=NULL)
                    {
                        copyAllLineToFile(str3,&line);
                        free(str3);
                    }
                    else
                    {
                        printf(" sthg wrong ");
                        return 1;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    else
    {
        printf(" \n Please give file name as an arguement \n");
    }
    MeasureClock();
    return 0;
}
