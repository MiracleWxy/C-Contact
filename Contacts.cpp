#include <iostream>
using namespace std;
#include <string>
#define MAX 1000


//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};

//添加
void addPerson(Addressbooks * abs)
{
	if(abs->m_Size == MAX)
	{
		cout<<"通讯录已满，无法添加"<<endl;
		return;
	}
	else
	{
		string name;
		cout<<"请输入姓名： "<<endl;
		cin>>name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout<<"请输入性别：  "<<endl;
		cout<<"1---男"<<endl;
		cout<<"2---女"<<endl;
		int sex = 0;

		while(true)
		{
			cin>>sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout<<"输入有误，请重新输入"<<endl;

		}
		
		//年龄
		cout<<"请输入年龄： "<<endl;
		int age = 0;
		while (true)
		{
			cin>>age;
			if(age>0 && age<150)
			{
				abs->personArray[abs->m_Size].m_age = age;
				break;
			}
			cout<<"输入有误，请重新输入"<<endl;
		}

		//电话
		cout<<"请输入联系电话： "<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		
		//住址
		cout<<"请输入联系人住址: "<<endl;
		string addr;
		cin>>addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		
		abs->m_Size++;
	
		cout<<"添加成功"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		//system("cls");
	}
}

void showPerson(Addressbooks * abs)
{
	//判断是否为0
	if(abs->m_Size == 0)
	{
		cout<<"当前记录为空"<<endl;
	}
	else
	{
		for(int i=0;i < abs->m_Size;i++)
		{
			cout<<"姓名: "<<abs->personArray[i].m_Name <<"\t";
			cout<<"性别: "<< (abs->personArray[i].m_Sex ==1 ? "男":"女") <<"\t";
			cout<<"年龄: "<<abs->personArray[i].m_age <<"\t";
			cout<<"电话: "<<abs->personArray[i].m_Phone <<"\t";
			cout<<"住址: "<<abs->personArray[i].m_Addr <<endl;
		
		}
	}
	cout<<endl;
	cout<<endl;
}

int isExist(Addressbooks *abs,string name)
{
	for(int i=0;i < abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks *abs)
{
	cout<<"请输入要删除的联系人姓名: "<<endl;
	string name;
	cin>>name;

	int ret = isExist(abs,name);
	if(ret != -1)
	{
		for(int i = ret;i < abs->m_Size;i++)
		{
			abs->personArray[i] = abs->personArray[i+1];	

		}
		abs->m_Size--;
		cout<<"删除成功"<<endl;
		cout<<endl;
		cout<<endl;	

	}
	else
	{ 
		cout<<"查无此人"<<endl;  
		cout<<endl;
		cout<<endl;	
	}
}

void findPerson(Addressbooks *abs)
{
	cout<<"请输入你要查找的联系人: "<<endl;
	string name;
	cin>>name;

	int ret = isExist(abs,name);

	if(ret != -1)
	{
		cout<<"姓名: "<<abs->personArray[ret].m_Name <<"\t";
		cout<<"性别: "<< (abs->personArray[ret].m_Sex ==1 ? "男":"女") <<"\t";
		cout<<"年龄: "<<abs->personArray[ret].m_age <<"\t";
		cout<<"电话: "<<abs->personArray[ret].m_Phone <<"\t";
		cout<<"住址: "<<abs->personArray[ret].m_Addr <<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	cout<<endl;
	cout<<endl;
}

void modifyPerson(Addressbooks *abs)
{
	cout<<"请输入你要修改的联系人: "<<endl;
	string name;
	cin>>name;
	
	int ret = isExist(abs,name);

	if(ret != -1)
	{
	
	
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
}


void showMenu()
{
	cout<<endl;
	cout<<"  ——————————————"<<endl;
	cout<<" 丨1.添加联系人丨"<<endl;
	cout<<" 丨2.显示联系人丨"<<endl;
	cout<<" 丨3.删除联系人丨"<<endl;
	cout<<" 丨4.查找联系人丨"<<endl;
	cout<<" 丨5.修改联系人丨"<<endl;
	cout<<" 丨6.清空联系人丨"<<endl;
	cout<<" 丨0.退出通讯录丨"<<endl;
	cout<<"  ——————————————"<<endl;
}


int main()
{
	Addressbooks abs;
	
	abs.m_Size = 0;

	int select = 0;//用户输入变量	
	while (true)
	{
		showMenu();
	
		cin>>select;
		switch(select)
		{
		case 1: //添加
			addPerson(&abs);
			break;
		case 2: //显示
			showPerson(&abs);
			break;
		case 3: //删除
			deletePerson(&abs);
			break;
		case 4: //查找
			findPerson(&abs);
			break;
		case 5: //修改
		
			break;
		case 6: //清空
		
			break;
		case 0:
			cout<<"欢迎下次使用"<<endl;
			return 0;
			break;
		}
	}
	//system("pause");
	return 0;
}
