#pragma once
#include "native.h"

using namespace System;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;



namespace testnamespace
{
	public enum  class NumClr  //枚举类型
	{
		ONE = 0x01,
		TOW = 0x02
	};
}



namespace testnamespace
{
	//public enum  class NumClr  //枚举类型
	//{
	//	ONE = 0x01,
	//	TOW = 0x02
	//};

	public ref class ParamClr  //普通结构体
	{
	public:
		Int32 iData;
		char cData;
		void TSin(Param & in);
		void TSout(Param & out);
	};

	public ref class multiParamClr //含有子结构体的父结构体
	{
	public:
		multiParamClr();
		ParamClr^ param0;
		ParamClr^ param1;
		ParamClr^ param2;

		void TSin(multiParam & in);
		void TSout(multiParam & out);
	};

	public ref class structArrayClr
	{
	public:
		structArrayClr();
		array<ParamClr^>^ mstuArray;
		int num;

		void TSin(structArray & in);
		void TSout(structArray & out);
	};

	public ref class MyPrintClr
	{
	public:
		MyPrintClr();
		~MyPrintClr();
		void setEnum(NumClr num);//枚举类型
		void setParam(ParamClr^ param);//结构体
		void setMutiParam(multiParamClr^ param);//结构体包含结构体
		void setArray(array<Byte>^ array);//数组下发

		void printData();
		void changeData();
		void printDataClr();
		void changeDataClr();
		array<Byte>^ data;//双向数组

		void setStr(String^ str);//字符串下发
		void getStr();//字符串获取
		String^ mystr;

		structArrayClr^ stuAray;
		void printstuArray();
		void changestuArray();

		property IntPtr upArray {IntPtr get() { return (IntPtr)(this->pMyPrint->upArray); }};
		property int upArrayLen{int get(){return this->pMyPrint->upArrayLen;}}

	private:
		MyPrint* pMyPrint;
		void byteArrayTSin(array<Byte>^ dest, UINT8* source, int num);
		void byteArrayTSout(array<Byte>^ source, UINT8* dest, int num);
	};
}