#include<stdlib.h>
#include<stdio.h>

int main()
{
	enum state {blank,normal};
 enum 	state State = normal;

	FILE *fp1, *fp2, *fp3;
	fp1 = fopen( "test.txt", "rt");
	if (NULL == fp1)
	{
		printf("error");
		exit(1);
	}
	fp2 = fopen("test_out.txt", "wt");
	if (NULL == fp2)
	{
		printf("error");
		exit(1);
	}
	
	fp3 = fopen("test_out2.txt", "wt");
	if (NULL == fp3)
	{
		printf("error");
		exit(1);
	}

	char ch;
	while ((ch = fgetc(fp1))!=EOF)
	{
		if (ch == '[')
		{
   fputc(ch,fp3);
			State = blank;
		}
			
		if (ch == ']')
		{
			fputc(']', fp3);
			State = normal;
		}
			
		if (State == normal || ch == '[')
		{
			fputc(ch, fp2);
		}
		else
		{
			fputc(ch, fp3);
   fputc(' ',fp2);
		}
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
