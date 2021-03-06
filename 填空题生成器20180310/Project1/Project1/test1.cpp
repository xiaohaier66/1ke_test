#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	enum state {blank,normal};
	state State = normal;

	FILE *fp1, *fp2, *fp3;
	fopen_s(&fp1, "test.txt", "rt");
	if (NULL == fp1)
	{
		printf("error");
		exit(1);
	}
	fopen_s(&fp2, "test_out.txt", "wt");
	if (NULL == fp2)
	{
		printf("error");
		exit(1);
	}
	
	fopen_s(&fp3, "test_out2.txt", "wt");
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
			State = blank;
		}
			
		if (ch == ']')
		{
			fputc(']', fp3);
			State = normal;
		}
			
		if (State == normal)
		{
			fputc(ch, fp2);
		}
		else
		{
			fputc(ch, fp3);
		}
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	system("pause");
	return 0;
}