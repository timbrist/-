#include"Model.h"

//======================轮子====================
void ReadFile(const char *filename)
{
    FILE *fp;
    char buff[MAXLINE];
    if ( (fp = fopen(filename,"r")) == NULL)
    {
         printf("open file falied\n");
         return;
    }
    while((fgets(buff,MAXLINE,fp) ) != NULL)
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
//======================================================

//====================StuNode 成员函数=====================
void SetNum(studentnode *node, int number)
{
    if(node == NULL) return;
    node->s.num = number; 
}
void SetName(studentnode *node, char name[])
{
    if(node == NULL) return;
    strcpy(node->s.name, name);
}
void SetElective(studentnode *node, int elective)
{
    if(node == NULL) return;
    node->s.elective = elective;
}
void SetExperiment(studentnode *node, int experiment)
{
    if(node == NULL) return ;
    node->s.experiment = experiment;
}
void SetRequired(studentnode *node, int required)
{
    if(node == NULL) return;
    node->s.required = required;
}
//==========================


//void LoadFile(const char *filename, studentnode *node)
void LoadFile()
{
    //1. 将文件内容读入 info[MAXROWS][128]
    //2. 将info[MAXROWS][128] 从0->MAXROWS赋值给 StudentInfo[128]
    //3. 将StudentFile[128] 通过 '\t' 进行分割 并把分隔的字符串赋值给StudentFile
    //4. 将StudentFile中的每一个值通过 atoi 转换为 student格式。
    //5. 将每一个student 动态申请内存给 studentnode
    //6. 将每一个studentnode通过链表连接起来；//我tm不想造轮子了。我就只是读个文件啊
    studentfile sf[3]; 
    FILE *fp;
    char buff[MAXLINE];//
    char *result;
    char info[3][128];
    if ( (fp = fopen("StudentInfo.txt","r")) == NULL)
    {
         printf("open file falied\n");
         return;
    }
    int j = 0; 
    while(!feof(fp))
    {        
         fgets(buff,MAXLINE,fp);
         strcpy(info[j], buff);
         ++j;
    } 
    for(int i = 0; i < 3; ++i)
    { 
        result = strtok(info[i],";");   
        strcpy(sf[i].num, result);
        result = strtok(NULL,";");
        strcpy(sf[i].name, result);
        result = strtok(NULL,";");
        strcpy(sf[i].elective, result);
        result = strtok(NULL,";");
        strcpy(sf[i].experiment, result);
        result = strtok(NULL,";");
        strcpy(sf[i].required, result);
        result = strtok(NULL,";");
    }
    printf("%s\n", sf[2].name);
    fclose(fp);
   
}


//add info to Student data base;
void Append2File(studentnode *studentnode)
{     
    if(studentnode == NULL) return;   
    if(studentnode->id == 0) return;
    studentfile sf;
    sprintf(sf.num, "%d", studentnode->s.num);
    strcpy(sf.name,studentnode->s.name);
    sprintf(sf.elective, "%d",studentnode->s.elective);   
    sprintf(sf.experiment, "%d", studentnode->s.experiment);
    sprintf(sf.required, "%d", studentnode->s.required);
    sprintf(sf.sum, "%d", studentnode->s.elective+
            studentnode->s.experiment+
            studentnode->s.required);


    strcat(StudentInfo,sf.num);
    strcat(StudentInfo,"\t");
    strcat(StudentInfo,sf.name);
    strcat(StudentInfo,"\t");
    strcat(StudentInfo,sf.elective);
    strcat(StudentInfo,"\t");
    strcat(StudentInfo,sf.experiment);
    strcat(StudentInfo,"\t");
    strcat(StudentInfo,sf.required);
    strcat(StudentInfo,"\t");
    strcat(StudentInfo,sf.sum);
    strcat(StudentInfo,"\n");
        
    WriteFile("StudentInfo.txt", "a",StudentInfo);
    StudentInfo[0] = '\0';
}

//输入学生学号，返回学生信息
studentnode *FindStudent(studentnode *node, int number)
{
    studentnode *head = node;
    studentnode *result = NULL;
    if(node == NULL) return NULL;

    while(head != NULL)
    {
        if(head->s.num = number)
        {
            result = head;
            break;
        }
        head = head->next;
    }
    return result;
}

//输入学生学号， 删除该节点
void DeleteStudent(studentnode *node, int number)
{
    studentnode *head = node;
    studentnode *pre = node;

    while(head != NULL)
    {
        if(head->s.num = number)
        {
            //TODO: delete linklist
            break;
        }
        head = head->next;
    }
}
void ModifyStudent(studentnode *node,int number, studentnode *newNode)
{
    studentnode *head = node;
    while(head != NULL)
    {
       if(head->s.num == number)
       {
          //TODO: Modify info with newNode;
          break;
       }
    } 
}

//输入序号， 在该序号上添加节点
void InsertStudent(studentnode *node, int index, studentnode *newNode)
{
    studentnode *head = node; 
    for(int i = 0; i < index; ++i)
        head = head->next;
    //TODO:add node to this position;
}


void OrderStudent(studentnode *node)
{
    //TODO:Qsort with link list
}

//统计学生人数
int StudentNumber(studentnode *node)
{
    return node->id;
}
