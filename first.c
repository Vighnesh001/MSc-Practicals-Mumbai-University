#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char ch,newarr[20],newstr[20];
char str4[20]="if";
char str5[20]="<";
char str6[20]="<=";
int i=0,no,min=0,max,min1=0,max1,max2,j,cnt=0,var=0;
FILE *fout,*fin;
void splitting()
{
fin=fopen("file1.txt","r");
//fout=fopen("C:\\file2.txt","w");
while(ch!= EOF)
{
ch=fgetc(fin);
if(ch!=' ')
{
if(ch=='\n')
{
var=var+1;
for(j=strlen(newarr);j>=0;j--)
newarr[j]='\0';
i=0;
}
else
{
newarr[i]=ch;
i++;
}
//ch=fgetc(fin);
}
else
{
no = atoi(newarr);
if(no>=1 && no<200)
{
cnt=cnt+1;
if(cnt==1)

{
min=no;
}
if(cnt==2)
{
max=no;
}
if(cnt>=3 && var>=1)
{
if(strcmp(newstr,str4)==0)
{
min1=no;
}
else if(strcmp(newstr,str5)==0)
{
max1=no;
}
else if(strcmp(newstr,str6)==0)
{
max2=no;
}
}
}//if no>1 and no<20
strcpy(newstr,newarr);//previous string
for(j=strlen(newarr);j>=0;j--)
newarr[j]='\0';
i=0;
}
}//while
fout=fopen("file2.txt","w");
fputs("\nfor i=",fout);
fprintf(fout,"%d",min);
fputs("to",fout);
fprintf(fout,"%d",max1-1);
fputs("do",fout);
fputs("\nb1",fout);
fputs("\nend loop",fout);
fputs("\nfor i=",fout);
fprintf(fout,"%d",max1);
fputs("to",fout);
fprintf(fout,"%d",max2-1);
fputs("do",fout);
fputs("\nb2",fout);
fputs("\nend loop",fout);
fputs("\nfor i=",fout);
fprintf(fout,"%d",max2);
fputs("to",fout);

fprintf(fout,"%d",max);
fputs("do",fout);
fputs("\nb3",fout);
fputs("\nend loop",fout);
fclose(fout);
}//void
void main()
{
//clrscr();
splitting();
//getch();
}