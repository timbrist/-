#include"Model.h"

int GetFileLines(const char *filename)
{
    FILE *fp;
    int count = 0;
    if( (fp = fopen(filename,"r+")) == NULL)
        return -1;
    while(!feof(fp))
    {
        if(fgetc(fp) == '\n')
            ++count;
    }
    count += 1;
    fclose(fp);
    return count;
}
int isFileEmpty(const char *filename)
{
    
}

void GetStudentLine(student *stu, int filelines)
{

    //1. 将文件内容读入 info[MAXROWS][128]
    //2. 将info[MAXROWS][128] 从0->MAXROWS赋值给 StudentInfo[128]
    //3. 将StudentFile[128] 通过 '\t' 进行分割 并把分隔的字符串赋值给StudentFile
    //4. 将StudentFile中的每一个值通过 atoi 转换为 student格式。
    //5. 将每一个student 动态申请内存给 studentnode
    //6. 将每一个studentnode通过链表连接起来；//我tm不想造轮子了。我就只是读个文件啊  
     
    FILE *fp;
    char buff[MAXLINE];//
    char *result;
    //char info[3][128];
    //2.申请一个info[MAXROWS][128]
    char **info = (char **)malloc(sizeof(char *) *filelines);
    for(int i = 0; i < filelines; ++i)
        info[i] = (char *)malloc(sizeof(char) * 128);
    if ( (fp = fopen(FILENAME,"r+")) == NULL)
    {
         printf("open file falied\n");
         return;
    }

    //2.文件内容读入info[MAXROWS] 
    int j = 0; 
    while(!feof(fp))
    {        
         fgets(buff,MAXLINE,fp);
         strcpy(info[j], buff);
         ++j;

    } 

    //3.字符串分割赋值给studentfile
    for(int i = 0; i < filelines; ++i)
    { 
        result = strtok(info[i],";");   
        //strcpy(sf[i].num, result);
        stu[i].num = atoi(result);
        result = strtok(NULL,";");
        //strcpy(sf[i].name, result);
        strcpy(stu[i].name, result);
        result = strtok(NULL,";");
        //strcpy(sf[i].elective, result);
        stu[i].elective = atoi(result);
        result = strtok(NULL,";");
        //strcpy(sf[i].experiment, result);
        stu[i].experiment = atoi(result);
        result = strtok(NULL,";");
        //strcpy(sf[i].required, result);
        stu[i].required= atoi(result);
        stu[i].total = stu[i].elective + stu[i].experiment+stu[i].required;
        result = strtok(NULL,";");
    } 

    fclose(fp);
    //free(sf);
    for(int i = 0; i < filelines; ++i)
      free(info[i]);
    free(info); 
}

void WriteFile(const char *filename,char *str)
{
    FILE *fp;
    if( (fp = fopen(filename,"a+")) ==NULL)
    {
        printf("Open file failed\n");
        return;
    }
    fputs(str,fp);
    fclose(fp);
}




