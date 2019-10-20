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

void SetStudentInfo(stuNode *node,char num[], char name[],
                    unsigned int elective, unsigned int experiment,
                    unsigned int required)
{
    if(node == NULL) return; 
    strcpy(node->s.num,num);
    strcpy(node->s.name,name);
    node->s.elective = elective;
    //vc++要使用 sprintf_s strcat_s
    sprintf(node->s.elective_grade,"%d",elective);
    sprintf(node->s.experiment_grade,"%d",experiment);
    sprintf(node->s.required_grade,"%d",required);
    node->s.experiment = experiment;
    node->s.required = required;
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



