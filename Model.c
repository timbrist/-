#include"Model.h"



//======================轮子====================
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

//======================================================

//====================StuNode 成员函数=====================
/*
void SetStudentInfo(studentnode *node,int number, char name[],
                    int elective, unsigned int experiment,
                    int required)
{
    if(node == NULL) return; 
    node->s.number = number;
    strcpy(node->s.name,name);
    node->s.elective = elective;
    node->s.experiment = experiment;
    node->s.required = required;
    //vc++要使用 sprintf_s strcat_s
    sprintf(node->s.elective_grade,"%d",elective);
    sprintf(node->s.experiment_grade,"%d",experiment);
    sprintf(node->s.required_grade,"%d",required);
    sprintf(node->s.num,"%d",number); 
    strcat(node->stuFile,node->s.num);
    strcat(node->stuFile,"\t");
    strcat(node->stuFile,node->s.name);
    strcat(node->stuFile,"\t");
    strcat(node->stuFile,node->s.elective_grade);
    strcat(node->stuFile,"\t");
    strcat(node->stuFile,node->s.experiment_grade);
    strcat(node->stuFile,"\t");
    strcat(node->stuFile,node->s.required_grade);
    strcat(node->stuFile,"\n");
}*/
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



//add info to Student data base;
void Append2File(studentnode *studentnode)
{     
    if(studentnode == NULL) return;
   
    studentfile sf;
    sprintf(sf.num, "%d", studentnode->s.num);
    strcpy(sf.name,studentnode->s.name);
    sprintf(sf.elective, "%d",studentnode->s.elective);   
    
    WriteFile("StudentInfo.txt", "a",StudentInfo);
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
