#!/bin/bash
ls 1*.txt |
while read file_name;
do
    # 用.为分隔符只要文件名，去掉文件后缀
    echo "${file_name%.*}:" >> all.txt
    cat "$file_name" >> all.txt
    echo "" >> all.txt
    rm "$file_name"
done
times1=0
total=0
average=0
four=4
fourteen=14
#cat all.txt | 
while read line
do
    #if["${#line}" -eq "4"];then	
    #	let $total=$total+1
    #elif["${#line}" -eq "14"];then
    #	let $times1=$times1+1
    #fi
    if [ ${#line} -eq $four ] ; then
     total=$[$total+1];
    elif [ ${#line} -eq $fourteen ] ; then
     times1=$[$times1+1];
    fi
    	
done < all.txt
str1="在过去"
str2="次程序执行中，计算机平均花费"
str3="次之后将正确数字猜出"
str_times="$times1"
str=$str1$str_times$str2
echo $str >> all.txt
awk -v a=$total -v b=$times1 'BEGIN{printf "%0.6f",a/b}' >>all.txt
echo $str3 >> all.txt
echo -e >> all.txt
