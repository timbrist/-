# 学生管理系统
c语言,课程设计,数据结构,管理系统,crud, 复制即可使用

#前言  
一定要好好使用数据结构！  

#该项目环境： 
Centos7 GCC-8  

#如何使用
Windows:  
vs2015版本及以上  
进入vs2015目录, 点击Student.vcxproj  
在vs2015中直接运行  
若出现无法打开.exe 在vs中添加当前目录debug/Student.exe  
或直接在当前目录debug/打开Student.exe  
linux:  
cd StudentManagement  
mkdir build && cd build  
cmake ..  
make -j4  
./Student  


#需求功能  
1. 录入学生信息： 学生学号，姓名，选修课成绩， 实验课成绩，必修课成绩  
2. 查： 输入学生学号能查出学生相关信息；  
3. 删： 输入学生学号删除学生信息；  
4. 改： 输入学号修改相关信息；
5. 插： 输入要插入的位置，插入到该位置。
6. 排： 按三门课的总成绩进行高到低排序。  
7. 统： 统计学生人数；  
8. 显： 显示学生信息;
9. 存:  保存到文件中;

#数据结构   
链式存储；单链表   

#效果图  
功能已全部完成, 效果图如下  
![界面](https://github.com/timbrist/StudentMangement/blob/master/pic/interface.png)  
![查找](https://github.com/timbrist/StudentMangement/blob/master/pic/find.png)  
![排序](https://github.com/timbrist/StudentMangement/blob/master/pic/order.png)    
#设计模式   
MVC  

#参考  
需求分析: << c语言程序开发范例宝典 >> 458页  
