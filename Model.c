#include"Model.h"
void ReadFile(const char *filename)
{
    FILE *fp;
    char buff[255];
    if ( (fp = fopen(filename,"r")) == NULL)
    {
         printf("open file falied\n");
         return;
    }
    while((fgets(buff,255,fp) ) != NULL)
    {
        
         printf("%s", buff);   
    } 

    fclose(fp);
}
void WriteFile(const char *filename,const char *type,char *str)
{
    FILE *fp;
    if( (fp = fopen(filename,type)) ==NULL)
    {
        printf("Open file failed\n");
        return;
    }
    fputs(str,fp);
    fclose(fp);
}

void SetStudentInfo(stuNode *node, char *num, char *name,
                    unsigned int elective, unsigned int experiment,
                    unsigned int required)
{
    if(node == NULL) return;


}

//add info to Student data base;
void Add(stuNode *node)
{
    char info[MAXLINE];
    
}

