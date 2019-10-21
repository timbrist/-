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
//
//====================StuNode 成员函数=====================
void SetStudentInfo(stuNode *node,unsigned int number, char name[],
                    unsigned int elective, unsigned int experiment,
                    unsigned int required)
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
}

//add info to Student data base;
void Append2File(stuNode *node)
{     
    if(node == NULL) return;
    WriteFile("StudentInfo.txt", "a",node->stuFile);
}

//输入学生学号，返回学生信息
stuNode *FindStudent(stuNode *node, unsigned int number)
{
    stuNode *head = node;
    stuNode *result = NULL;
    if(node == NULL) return NULL;

    while(head != NULL)
    {
        if(head->s.number = number)
        {
            result = head;
            break;
        }
        head = head->next;
    }
    return result;
}

//输入学生学号， 删除该节点
void DeleteStudent(stuNode *node, unsigned int number)
{
    stuNode *head = node;
    stuNode *pre = node;

    while(head != NULL)
    {
        if(head->s.number = number)
        {
            //TODO: delete linklist
            break;
        }
        head = head->next;
    }
}
void ModifyStudent(stuNode *node,unsigned int number, stuNode *newNode)
{
    stuNode *head = node;
    while(head != NULL)
    {
       if(head->s.number == number)
       {
          //TODO: Modify info with newNode;
          break;
       }
    } 
}

//输入序号， 在该序号上添加节点
void InsertStudent(stuNode *node, unsigned int index, stuNode *newNode)
{
    stuNode *head = node; 
    for(int i = 0; i < index; ++i)
        head = head->next;
    //TODO:add node to this position;
}


void OrderStudent(stuNode *node)
{
    //TODO:Qsort with link list
}

//统计学生人数
unsigned int StudentNumber(stuNode *node)
{
    return node->id;
}
