#include<stdio.h>
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
void WriteFile(const char *filename,char *str)
{
    FILE *fp;
    if( (fp = fopen(filename,"w")) ==NULL)
    {
        printf("Open file failed\n");
        return;
    }
    fputs(str,fp);
    fclose(fp);
}

int main()
{
    printf("Hello world\n");
    WriteFile("test.txt", "hhhhhhhhhhelo world\n");
    ReadFile("test.txt");    
    return 0;
}
