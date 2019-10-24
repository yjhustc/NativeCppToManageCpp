using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

using testnamespace;



namespace cs
{


    unsafe class Program
    {
        static void Main(string[] args)
        {

            MyPrintClr test = new MyPrintClr();

            ////枚举类型下发测试
            //test.setEnum(NumClr.ONE);
            //test.setEnum(NumClr.TOW);

            ////普通结构体下发测试
            //ParamClr pa = new ParamClr();
            //pa.cData = 71;
            //pa.iData = 15;
            //test.setParam(pa);

            ////数组下发测试
            //Byte[] array = new Byte[10];
            //for (int i = 0; i < 10; i++)
            //    array[i] = (Byte)(i + 5);
            //test.setArray(array);

            ////父结构体下发测试
            //multiParamClr multi = new multiParamClr();
            //multi.param0.cData = 71;
            //multi.param0.iData = 15;
            //multi.param1.cData = 72;
            //multi.param1.iData = 16;
            //multi.param2.cData = 73;
            //multi.param2.iData = 17;
            //test.setMutiParam(multi);


            ////数组拷贝测试
            //test.printData();
            //for (int i = 0; i < 10; i++)
            //    test.data[i] = 101;
            //test.changeDataClr();
            //test.printData();


            //test.printDataClr();

            //for (int i = 0; i < 10; i++)
            //    Console.WriteLine(test.data[i]);

            //test.changeData();
            //test.printDataClr();
            //for (int i = 0; i < 10; i++)
            //    Console.WriteLine(test.data[i]);

            ////字符串下发测试
            //test.setStr("COM44");

            ////字符串上行测试
            //Console.WriteLine(test.mystr);
            //test.getStr();
            //Console.WriteLine(test.mystr);

            ////结构体数组测试
            //test.changestuArray();
            //for (int i = 0; i < 3; i++)
            //{
            //    Console.WriteLine("------------------------------");
            //    Console.WriteLine(i);
            //    Console.WriteLine(test.stuAray.num);
            //    Console.WriteLine(test.stuAray.mstuArray[i].cData);
            //    Console.WriteLine(test.stuAray.mstuArray[i].iData);
            //}

            //test.stuAray.num = 10;
            //for (int i = 0; i < 3; i++)
            //{
            //    test.stuAray.mstuArray[i].cData = (sbyte)(71 + i);
            //    test.stuAray.mstuArray[i].iData = 15 + i;
            //}
            //test.printstuArray();

            //c#读取C++数组测试
            Byte* pointer = (Byte*)test.upArray.ToPointer();
            for (int i = 0; i < test.upArrayLen; i++)
            {
                Console.WriteLine(pointer[i]);
            }

            Console.Read();
        }
    }
}
