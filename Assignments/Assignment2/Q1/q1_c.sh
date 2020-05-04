#!/bin/bash

read -p "Enter number of lines you want in C Code (test.c) (approx) : " n1

touch test.c
echo ""
echo "Created test.c"
echo ""


echo "#include<stdio.h>" >> test.c
echo "#include<unistd.h>" >> test.c
echo "#include <stdlib.h>" >> test.c
echo "#include <string.h>" >> test.c
echo "int main()" >> test.c
echo "{" >> test.c


echo "	FILE * fPtr;" >> test.c
echo "	char ch;" >> test.c
echo "	char fname[50];" >> test.c
echo "	int pid = getpid();" >> test.c
echo "	char spid[50];" >> test.c
echo "	sprintf(spid, \"%d\", pid);" >> test.c
echo "	strcpy(fname, \"/proc/\");" >> test.c
echo "	strcat(fname, spid);" >> test.c
echo "	strcat(fname, \"/statm\");" >> test.c


echo "int i;" >> test.c

for (( c=1; c<=$n1; c++ ))
do  
   echo "i = 16 + 13;" >> test.c
   # 16 being no.of lines in test.c above the for loop and 13 being the later no.of lines 
done


echo "		printf(\"Below is the code-size, in pages, according to the data in /proc[pid]/statm\n\");" >> test.c
echo "		int num;" >> test.c
echo "		fPtr = fopen(fname, \"r\");" >> test.c
echo "		for(int k = 0; k < 7; k++)" >> test.c
echo "		{" >> test.c
echo "		fscanf(fPtr, \"%d\", &num);" >> test.c
echo "		if (k == 3){" >> test.c
echo "			printf(\"%d \", num);" >> test.c
echo "		}" >> test.c
echo "		}" >> test.c

echo "printf(\"\n\nNow, run the same file by changing the number of lines you want in C Code (test.c) significantly.\n\n\");" >> test.c


echo "return 0;" >> test.c
echo "}" >> test.c
gcc test.c
./a.out

rm test.c
echo "Deleted test.c"
rm a.out
echo "Deleted a.out"
