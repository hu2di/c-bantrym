#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

int p = 0;

void dem(int i)
{
	while (i)
	{
		printf("%d  ",i);
		Sleep(1000);
		i--;
	}
}
void inkq(char b[], int n)
{
	printf("\n");
	printf("  -");
	for (int i = 0; i<n; i++)
		printf("%c-", b[i]);
	printf("\n|||                   |||\n");
	printf("|||                   |||\n");
	printf("|||                   |||\n");
	printf("|||                   |||\n");
	printf("===                   ===");
}

int level(int &lv)
{
	int k = lv; //So trym can tao
	int a[10] = { 0 }; //Day dien
	int n = 10; //Do dai day dien
	int m = 8; //So vien dan
	char b[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //Ket qua
	srand((unsigned)time(NULL));
	//Sinh ngau nhien trym
	int vt = 0, u = k;
	while (u)
	{
		vt = rand() % n;
		if (a[vt] == 0)
		{
			a[vt] = 1;
			u--;
		}
	}
	//Choi nao
	printf("\n\n     ___LEVEL %d____\n\n",lv);
	printf("   : %d TRYM + %d VIEN DAN :\n\n", k, m);
	inkq(b,n);
	int toado = 0;
	while (1)
	{
		while (1)
		{
			printf("\nFire In: ");
			scanf("%d", &toado);
			if (toado<n) break;
		}
		printf("\nPang %d !!!", toado);
		m--;
		if (a[toado] == 1)
		{
			a[toado] = 0;
			b[toado] = 'v';
			p=p++;
			k--;
			printf("=>>BAN TRUNG!\n");
			inkq(b, n);
		}
		else
		{
			b[toado] = 'x';
			printf("=>>BAN TRUOT!\n");
			inkq(b, n);
		}
		printf("\n=>Con %d Trym + %d Dan!!!\n", k, m);
		if ((k == 0) || (m == 0)) break;
	}
	printf("\n");
	if (k == 0)
	{
		p = p + m;
		printf("Configuration! Point = %d !!! (Bonus %d points!)\n", p,m);
		lv++;
		if (lv == 9)
		{
			printf("VICTORY!!!\n");
			system("pause");
			exit(0);
		}
		printf("\nNEXT LEVEL\n");
		dem(3);
		return lv;
	}
	else
	{
		printf("\nPoints = %d\n", p);
		printf("DEFEAT!!!\n");
		dem(5);
		exit(0);
	}
}

int main()
{
	int lv = 1;
	printf("\nBAN TRYM\n\n\n");
	printf("Hay cung tham gia ban chim. Ban co 1 khau sung voi 8 vien dan!\n\n");
	printf("Hay dung no de ban rung nhung con chim tren tren cot dien!\n\n");
	printf("Co 10 vi tri tu 0 -> 9 tren cot dien ma nhung chu chim co the\n\n");
	printf("dau nhung ban lai khong biet chinh xac vi tri nao co chim dau.\n\n");
	printf("Hay thu tai ban trym cua ban xem nao!\n\n");
	system("pause");
	while (1)
	{
		system("cls");
		level(lv);
	}
	return 0;
}
