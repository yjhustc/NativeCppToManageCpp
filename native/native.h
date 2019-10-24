#pragma once

#ifdef NATIVE_EXPORTS
#define NATIVE_API __declspec(dllexport)
#elif CLR_EXPORTS
#define NATIVE_API
#else
#define NATIVE_API __declspec(dllimport)
#endif

typedef unsigned __int8 UINT8;


typedef enum _Num
{
	ONE = 0x01,
	TOW = 0x02
}Num;

typedef struct _Param
{
	int iData;
	char cData;
}Param;

typedef struct _multiParam
{
	Param param0;
	Param param1;
	Param param2;
}multiParam;

typedef struct _structArray
{
	int num;
	Param stuArray[3];
}structArray;


class NATIVE_API MyPrint
{
public:
	MyPrint();
	~MyPrint();
	void setEnum(Num num);//枚举类型
	void setParam(Param param);//结构体
	void setArray(int* array);
	void setMultiParam(multiParam param);

	void changeData();
	void printData();
	UINT8* data;

	char name[20];
	void printName();
	void changeName();


	structArray stuArray;
	void printstuArray();
	void changestuArray();

	UINT8* upArray;
	int upArrayLen;
	void setUpArray();
};

