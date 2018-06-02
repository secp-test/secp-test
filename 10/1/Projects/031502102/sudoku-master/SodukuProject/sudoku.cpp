#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
#include<string.h> 
void swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}

int main(int argc,char* argv[])
{
int sodu1[9][9]=
{
3,6,7,2,5,4,9,8,1,
5,2,8,6,1,9,3,4,7,
4,9,1,3,7,8,5,2,6,
7,3,5,8,2,1,6,9,4,
6,8,2,4,9,5,7,1,3,
1,4,9,7,6,3,8,5,2,
9,5,4,1,3,6,2,7,8,
2,1,6,9,8,7,4,3,5,
8,7,3,5,4,2,1,6,9
},
sodu2[9][9]=
{
3,1,2,6,4,7,9,8,5,
7,8,6,9,5,3,2,4,1,
9,4,5,1,2,8,3,6,7,
8,5,4,3,7,9,1,2,6,
2,7,3,4,6,1,8,5,9,
6,9,1,2,8,5,4,7,3,
4,3,7,5,9,2,6,1,8,
5,6,9,8,1,4,7,3,2,
1,2,8,7,3,6,5,9,4,
},
sodu3[9][9]=
{
3,8,1,4,5,6,7,9,2,
6,9,7,8,3,2,4,1,5,
4,5,2,1,7,9,8,3,6,
8,6,9,2,4,5,3,7,1,
2,4,5,7,1,3,9,6,8,
1,7,3,9,6,8,5,2,4,
7,3,8,6,2,4,1,5,9,
9,1,6,5,8,7,2,4,3,
5,2,4,3,9,1,6,8,7,
},
sodu4[9][9]=
{
3,4,1,9,6,5,2,7,8,
2,6,8,4,7,3,9,5,1,
7,9,5,8,1,2,3,6,4,
5,7,4,6,2,1,8,3,9,
1,3,9,5,4,8,6,2,7,
8,2,6,3,9,7,4,1,5,
9,1,7,2,8,6,5,4,3,
6,8,3,1,5,4,7,9,2,
4,5,2,7,3,9,1,8,6,
},
sodu5[9][9]=
{
3,9,2,1,5,6,4,8,7,
4,5,1,7,8,2,3,6,9,
7,8,6,4,9,3,5,2,1,
5,2,7,6,4,9,8,1,3,
9,6,8,5,3,1,2,7,4,
1,3,4,2,7,8,6,9,5,
8,1,5,3,6,7,9,4,2,
6,7,3,9,2,4,1,5,8,
2,4,9,8,1,5,7,3,6,
},
soduku[9][9];
int row,line,i,j,chose;;
int N,l,ten,num=0;
srand((unsigned) time(NULL));
freopen("sudoku.txt","w",stdout);
//*********************************************//
l=strlen(argv[2]);
ten=1;
for(i=l-1;i>=0;i--) 
{
num+=(argv[2][i]-'0')*ten;
ten*=10;
}
N=num;
while(N--)
{
chose=rand()%5;
if(chose==0)
for(i=0;i<9;i++)
for(j=0;j<9;j++)
soduku[i][j]=sodu1[i][j];
else if(chose==1)
for(i=0;i<9;i++)
for(j=0;j<9;j++)
soduku[i][j]=sodu2[i][j];
else if(chose==2)
for(i=0;i<9;i++)
for(j=0;j<9;j++)
soduku[i][j]=sodu3[i][j];
else if(chose==3)
for(i=0;i<9;i++)
for(j=0;j<9;j++)
soduku[i][j]=sodu4[i][j];
else
for(i=0;i<9;i++)
for(j=0;j<9;j++)
soduku[i][j]=sodu5[i][j];
//********************************************//
for(i=0;i<4;i++)
{
row=rand()%3;
line=rand()%3;
if(row==1||row==2)
for(j=0;j<9;j++)
swap(soduku[1][j],soduku[2][j]);
if(line==1||line==2)
for(j=0;j<9;j++)
swap(soduku[j][1],soduku[j][2]);
}
//*********************************************//
for(i=0;i<9;i++)
{
chose=rand()%3;
row=rand()%3+3;
line=rand()%3+3;
if(row==3)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[3][j],soduku[4][j]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[3][j],soduku[5][j]);
		break;}
}
else if(row==4)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[4][j],soduku[3][j]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[4][j],soduku[5][j]);
		break;}
}
else
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[5][j],soduku[3][j]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[5][j],soduku[4][j]);
		break;}
}

chose=rand()%3;
if(line==3)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[j][3],soduku[j][4]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[j][3],soduku[j][5]);
		break;}
}
else if(line==4)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[j][4],soduku[j][3]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[j][4],soduku[j][5]);
		break;}
}
else
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[j][5],soduku[j][3]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[j][5],soduku[j][4]);
		break;}
}
}
//**********************************************//
for(i=0;i<9;i++)
{
chose=rand()%3;
row=rand()%3+6;
line=rand()%3+6;
if(row==6)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[6][j],soduku[7][j]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[6][j],soduku[8][j]);
		break;}
}
else if(row==7)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[7][j],soduku[6][j]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[7][j],soduku[8][j]);
		break;}
}
else
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[8][j],soduku[6][j]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[8][j],soduku[7][j]);
		break;}
}

chose=rand()%3;
if(line==6)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[j][6],soduku[j][7]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[j][6],soduku[j][8]);
		break;}
}
else if(line==7)
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[j][7],soduku[j][6]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[j][7],soduku[j][8]);
		break;}
}
else
{
	switch(chose)
	{case 0:break;
	case 1:
		for(j=0;j<9;j++)
			swap(soduku[j][8],soduku[j][6]);
		break;
	case 2:
		for(j=0;j<9;j++)
			swap(soduku[j][8],soduku[j][7]);
		break;}
}
}
//*********************************************//
//freopen("sudoku.txt", "w", stdout); 
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
printf("%d",soduku[i][j]);
if(j!=8)
printf(" ");
}
printf("\n");
}
if(N!=0)
printf("\n");
}
fclose(stdout);
return 0;
}
