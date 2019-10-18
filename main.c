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

int main()
{
    printf("Hello world\n");
    ReadFile("test.txt");    
    return 0;
}
