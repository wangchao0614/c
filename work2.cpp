#include <iostream>
#include<fstream>//写入读取文件
#include<iomanip>
#include<string>
using namespace std;
void Makemenu();//制作主菜单界面
void Keydown();//switch下的功能选择函数
void inputinf();//虚函数
void createimage();//创建图像
void Judgeempty();//判空
void save();//保存
void read();//读取
void display();//显示
void drawpoints();//绘制点
void drawbox();//绘制框  
void thresholding();//阈值化
void overturn();//翻转
void rotate();//旋转
class Matrix
{
    protected:
    public:
    int x = 0;
    int y = 0;
    int sum = 0;
    void inputinf()
    {
        cin>>x>>y;
    }
}matrix[9999][9999];
void Makemenu()
{
    cout<<"***************0.创建图像 **************"<<endl;    
    cout<<"***************1.判空     ******************"<<endl;
    cout<<"***************2.保存     **************"<<endl;
    cout<<"***************3.读取     ****************"<<endl;
    cout<<"***************4.显示     ****************"<<endl;
    cout<<"***************5.绘制点   ****************"<<endl;
    cout<<"***************6.绘制框   ***************"<<endl;
    cout<<"***************7.阈值化   ****************"<<endl;
    cout<<"***************8.翻转     ***************"<<endl;
    cout<<"***************9.旋转     ***************"<<endl;
    cout<<"请输入(0~9):";
}
void Keydown()
{
int userkey;//选择的功能序号
cin>>userkey;
switch(userkey)
{
    case 0:
        createimage();
        break;
    case 1:
        Judgeempty();
        break;
    case 2:
        save();
        break;
    case 3:
        read();
        break;
    case 4:
        display();
        break;
    case 5:
        drawpoints();
        break;
    case 6:
        drawbox();
        break;
    case 7:
        thresholding();
        break;
    case 8:
        overturn();
        break;
    case 9:
        rotate();
        break;
    default:
        cout<<"输入错误!,请重新输入...!"<<endl;
        break;
}
}
void createimage()
{
    matrix[9999][9999].inputinf();
    for(int i=0;i<matrix[9999][9999].x;i++)
    {
        for(int j=0;j<matrix[9999][9999].y;j++)
        {
            matrix[i][j].sum= 0;
        }
    }
}
void display()
{
    for(int i=0;i<matrix[9999][9999].x;i++)
    {
        for(int j=0;j<matrix[9999][9999].y;j++)
        {
            cout<<matrix[i][j].sum<<"   ";
        }
        cout<<endl;
    }
}
int main() {
while(1)//设置死循环
{
Makemenu();
Keydown();
system("pause");//暂停一下-
system("cls");//清屏
}
return 0;
}