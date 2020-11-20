#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <ctime>
#include <limits> //专门用于检测整型数据数据类型的表达值范围。
#include <stdlib.h>
#include<fstream>
#include<sstream>//stringstream通常用来做数据转换
#include<dirent.h>//文件夹操作函数。GCC，非ANSI C。 
#include<vector>//vector是动态数组，在堆上vector比array更常用
#include<sys/time.h>
using namespace std;

list<string> numList;
string RanddomNum();
int64_t getCurrentTime();
int countnumbers(const string& thenumber, const string& str);
int countpositions(const string& thenumber, const string& str);
int main()
{
    int x = 1;
    int n, p;    // 分别表示有几个数字猜对，有几个数字位置也对
    char alist[5] = { 0 };
    for (int i = '1'; i <= '9'; i++)
        for (int j = '0'; j <= '9'; j++)
            for (int k = '0'; k <= '9'; k++)
                for (int l = '0'; l <= '9'; l++)
                {
                    alist[0] = i;
                    alist[1] = j;
                    alist[2] = k;
                    alist[3] = l;
                    numList.push_back(alist);
                }   // 初始化
    //找到的文件的文件名
        string tmp;
        //for (vector<string> ::iterator a = zg.begin(); a != zg.end(); ++a)
          //  cout << *a << endl;
            stringstream ss;
            ss << getCurrentTime();
            ss >> tmp;
            string tmp1 =  tmp + ".txt";
    ofstream file;
    string path = "//var//www//html//"+tmp1;
    cout << path << endl;
    file.open(path);
    if (!file.is_open())
        cout << "打开失败" << endl;

    //   file.open("C:\\Users\\24657\\Desktop\\345.txt");
    //file << tmp << ":\n";
    string thenumber = "1234";//RanddomNum(); // 第1回合随机猜数
    while (1)
    {   cout << "emmmmm...   " << thenumber << endl;
        //.open("C:\\Users\\24657\\Desktop\\result.txt")


        file << thenumber << "\n";

        cin >> n >> p;
        if (n == 4 && p == 4)
        {
            cout << thenumber << "    goodgame!";// 猜中,直接goodgame，循环结束。
            break;
        }
        for (list<string>::iterator it = numList.begin();
            it != numList.end();)//遍历链表里面所有的四位数
        {
            if (countnumbers(thenumber, *it) != n) // 这个四位数中没有猜对的数字
            {
                it = numList.erase(it);  // 不可能是被猜数，删除
                continue;
            }
            if (countpositions(thenumber, *it) != p) // 这个四位数中没有猜对位置的数字
            {
                it = numList.erase(it);  // 不可能是被猜数，删除
                continue;
            }
            ++it;
        }
        if (numList.empty()) // 没有候选数了，人输入的指令有问题
        {
            cout << "wrong" << endl;
            break;
        }
        for (list<string>::iterator it = numList.begin();it != numList.end(); ++it)//将猜的数转换为链表中最大的数字
        {
            thenumber=*it;
        }
    }
    file.close();
    return 0;
    
}


string RanddomNum()
{
    srand(time(NULL));
    int i = rand() % 9000 + 1000;
    char buf[5] = { 0 };
    sprintf(buf, "%d", i);
    return buf;
}
int countnumbers(const string& thenumber, const string& num)
{
    string s = num;  // 复制num，用于下面避免重复匹配的操作
    int count = 0;
    for (int i = 0; i < 4; i++) // 对thenumber中每一个数字
    {
        string::size_type pos = s.find(thenumber[i]);
        if (pos != string::npos)
        {
            count++;
            s[pos] = 'o';  // 为避免重复匹配，将它替换为字符’o’
        }
    }
    return count;
}

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
    {    
       struct timeval tv;    
       gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
       return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
    }    

int countpositions(const string& thenumber, const string& str)
{
    int count = 0;
    for (int i = 0; i < 4; i++)
        count += (thenumber[i] == str[i]);
    return count;
}

