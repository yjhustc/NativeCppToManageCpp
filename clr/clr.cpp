// clr.cpp : 定义 DLL 应用程序的导出函数。
//

#include "clr.h"
#include "iostream"
#include <stdlib.h>
#include <string.h>

//#include <msclr\marshal.h>
//
//using namespace System;
//using namespace msclr::interop;


void testnamespace::ParamClr::TSin(Param & in)
{
	this->cData = in.cData;
	this->iData = in.iData;
}

void testnamespace::ParamClr::TSout(Param & out)
{
	out.cData = this->cData;
	out.iData = this->iData;
}

testnamespace::multiParamClr::multiParamClr()
{
	this->param0 = gcnew ParamClr();
	this->param1 = gcnew ParamClr();
	this->param2 = gcnew ParamClr();
}

void testnamespace::multiParamClr::TSin(multiParam & in)
{
	this->param0->TSin(in.param0);
	this->param1->TSin(in.param1);
	this->param2->TSin(in.param2);
}

void testnamespace::multiParamClr::TSout(multiParam & out)
{
	this->param0->TSout(out.param0);
	this->param1->TSout(out.param1);
	this->param2->TSout(out.param2);
}

testnamespace::MyPrintClr::MyPrintClr()
{
	this->pMyPrint = new MyPrint();

	this->data = gcnew array<Byte>(10);
	this->mystr = gcnew String("COMMM");
	this->stuAray = gcnew structArrayClr();
}

testnamespace::MyPrintClr::~MyPrintClr()
{
	delete this->pMyPrint;
}


void testnamespace::MyPrintClr::setEnum(NumClr num)
{
	this->pMyPrint->setEnum(safe_cast<Num> (num));
}



void testnamespace::MyPrintClr::setParam(ParamClr^ param)
{
	Param tmp;

	param->TSout(tmp);

	this->pMyPrint->setParam(tmp);
}

void testnamespace::MyPrintClr::setMutiParam(multiParamClr^ param)
{
	multiParam tmp;

	param->TSout(tmp);

	this->pMyPrint->setMultiParam(tmp);
}

//void testnamespace::MyPrintClr::setArray(int* array)
//{
//	this->pMyPrint->setArray(array);
//}

void testnamespace::MyPrintClr::setArray(array<Byte>^ array)
{
	printf("array len:%d\n", array->Length);
	for (int i = 0; i < array->Length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void testnamespace::MyPrintClr::printData()
{
	this->pMyPrint->printData();
}

void testnamespace::MyPrintClr::printDataClr()
{
	this->byteArrayTSin(this->data, this->pMyPrint->data, 10);

	printf("array len:%d\n", this->data->Length);
	for (int i = 0; i < this->data->Length; i++)
		printf("%d ", this->data[i]);
	printf("\n");
}

void testnamespace::MyPrintClr::changeData()
{
	this->pMyPrint->changeData();
}

void testnamespace::MyPrintClr::changeDataClr()
{
	this->byteArrayTSout(this->data, this->pMyPrint->data, 10);
}

void testnamespace::MyPrintClr::byteArrayTSin(array<Byte>^ dest, UINT8* source, int num)
{
	for (int i = 0; i < num; i++)
	{
		dest[i] = source[i];
	}
}

void testnamespace::MyPrintClr::byteArrayTSout(array<Byte>^ source, UINT8* dest, int num)
{
	for (int i = 0; i < num; i++)
	{
		dest[i] = source[i];
	}
}

void testnamespace::MyPrintClr::setStr(String^ str)
{
	this->pMyPrint->changeName();
	this->pMyPrint->printName();

	const char* tmp = (const char*)(void*)Marshal::StringToHGlobalAnsi(str);
	strcpy_s(this->pMyPrint->name,tmp);
	this->pMyPrint->printName();
}

void testnamespace::MyPrintClr::getStr()
{
	char name[10] = "12345";

	this->mystr = gcnew String(name);
}

testnamespace::structArrayClr::structArrayClr()
{
	this->mstuArray = gcnew array<ParamClr^>(3);

	this->mstuArray[0] = gcnew ParamClr();
	this->mstuArray[1] = gcnew ParamClr();
	this->mstuArray[2] = gcnew ParamClr();
}

void testnamespace::structArrayClr::TSin(structArray & in)
{
	this->num = in.num;
	for (int i = 0; i < 3; i++)
	{
		this->mstuArray[i]->TSin(in.stuArray[i]);
	}
}

void testnamespace::structArrayClr::TSout(structArray & out)
{
	out.num = this->num;
	for (int i = 0; i < 3; i++)
	{
		this->mstuArray[i]->TSout(out.stuArray[i]);
	}
}

void testnamespace::MyPrintClr::printstuArray()
{
	this->stuAray->TSout(this->pMyPrint->stuArray);

	this->pMyPrint->printstuArray();
}

void testnamespace::MyPrintClr::changestuArray()
{
	this->pMyPrint->changestuArray();

	this->stuAray->num = this->pMyPrint->stuArray.num;
	this->stuAray->TSin(this->pMyPrint->stuArray);
}

testnamespace::ParamClr^ testnamespace::MyPrintClr::returnStruct()
{
	ParamClr^ param = gcnew ParamClr();
	param->cData = 78;
	param->iData = 99;

	return param;
}