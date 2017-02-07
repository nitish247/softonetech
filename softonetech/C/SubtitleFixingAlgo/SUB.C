#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* reduceby3(char*);
int delaytime;

void main()
{
	FILE *fin,*fout,*ftemp;
	int i,j,token;
	char c,*time,*newt,temp[4];
	const char *base=time;
	clrscr();
	printf("Please enter the delay time: ");
	scanf("%d",&delaytime);
	fin=fopen("file.srt","r");
	fout=fopen("file1.srt","w");
	token=0;
	do
	{
		c=fgetc(fin);
		if(token==0&&(c>='0'&&c<='9'))
		{
			temp[0]=c;
			c=temp[1]=fgetc(fin);
			if(c=='\n')
			{
				temp[2]='\0';
				fputs(temp,fout);
				token=0;
				continue;
			}
			c=temp[2]=fgetc(fin);
			if(c==':')
			{
				token=1;
				time=base;
				*time++=temp[0];
				*time++=temp[1];
				*time++=temp[2];
				temp[3]='\0';
				continue;
			}
			else
			{
				temp[3]='\0';
				fputs(temp,fout);
				token=0;
				continue;
			}

		}
		if(token==1&&((c>='0'&&c<='9')||c==':'||c==','))
		{
			*time++=c;
			if(c==',')
			{
				*time='\0';
				newt=reduceby3(base);
				fputs(newt,fout);
				token=0;
				fputc(c,fout);
			}

		}
		else
		{
			fputc(c,fout);
			token=0;
		}
	}while(c!=EOF);
	printf("Done!");
	getch();
	fclose(fin);
	fclose(fout);
}

char* reduceby3(char* time)
{
	int tm[3],i,j;
	char t[3],*base,*newt,tms[3][3];
	base=time;
	newt=(char*)malloc(8*sizeof(char));
	i=0;
	j=0;
	while(1)
	{
		if(*time==':'||*time=='\0')
		{
			t[i]='\0';
			tm[j]=atoi(t);
			i=0;
			j++;
		}
		else
			t[i++]=*time;
		if(*time=='\0')
			break;
		time++;
	}
	if(tm[2]>=3)
		tm[2]-=delaytime;
	else
	{
		tm[1]--;
		tm[2]=60-(delaytime-tm[2]);
	}
	for(j=0;j<3;j++)
	{
		if(tm[j]<10)
		{
			tms[j][0]='0';
			tms[j][1]=tm[j]+48;
			tms[j][2]='\0';
		}
		else
			sprintf(tms[j],"%d",tm[j]);
	}

	sprintf(newt,"%s:%s:%s",tms[0],tms[1],tms[2]);
	return newt;
}