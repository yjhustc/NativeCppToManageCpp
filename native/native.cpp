// native.cpp : 定义 DLL 应用程序的导出函数。
//
#include "native.h"
#include "iostream"

MyPrint::MyPrint()
{
	this->data = (UINT8*)(malloc(10 * sizeof(UINT8)));
	this->name[0] = '\0';

	this->upArrayLen = 256;
	this->upArray = (UINT8*)(malloc(this->upArrayLen * sizeof(UINT8)));
	this->setUpArray();
	
}

MyPrint::~MyPrint()
{
	free(this->data);

	free(this->upArray);
}

void MyPrint::setEnum(Num num)
{
	if(num == ONE)
		printf("one\n");
	else if (num == TOW)
		printf("two\n");
	else
		printf("err\n");
}

void MyPrint::setParam(Param param)
{
	printf("%c\n", param.cData);
	printf("%d\n", param.iData);
}

void MyPrint::setArray(int* array)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%c \n", array[i]);
	}
}

void MyPrint::setMultiParam(multiParam param)
{
	this->setParam(param.param0);
	this->setParam(param.param1);
	this->setParam(param.param2);
}

void MyPrint::printData()
{
	for (int i = 0; i < 10; i++)
		printf("%d ",this->data[i]);
	printf("\n");
}

void MyPrint::changeData()
{
	for (int i = 0; i < 10; i++)
		this->data[i] = 88;
}

void MyPrint::printName()
{
	printf("%s\n",this->name);
}

void MyPrint::changeName()
{
	strcpy_s(this->name,"COM YJH");
}

void MyPrint::printstuArray()
{
	for(int i=0;i<3;i++)
		printf("%d/%d   %c %d\n", i, this->stuArray.num,this->stuArray.stuArray[i].cData, this->stuArray.stuArray[i].iData);

}

void MyPrint::changestuArray()
{
	this->stuArray.num = 99;
	for (int i = 0; i < 3; i++)
	{
		this->stuArray.stuArray[i].cData = 'u' + i;
		this->stuArray.stuArray[i].iData = 88 + i;
	}
}

void MyPrint::setUpArray()
{
	for (int i = 0; i < this->upArrayLen; i++)
	{
		this->upArray[i] = i;
	}
}