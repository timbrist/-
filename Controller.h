#include"Model.h"
#include"View.h"

void MainWindow();


//============控制视图==============
void Menu();
void Exit();
void Input(studentnode *studentlist);
void Delete();
void Search();
void Modify();
void Insert();
void Order();
void Sum();


//===========控制模型==================
void FreeList(studentnode *node);

void Append(studentnode* studentlist, studentnode *node);
void DisplayList(studentnode *studentlist);
