#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=5000;
int pow10[20];

void input(int *a,int &len)
{
	char str[N];
	scanf("%s",str+1);
	len=strlen(str+1);
	for(int i=0;i<=len;i++)
		a[i]=0;
	for(int i=1;i<=len;i++)
		a[(len-i)/8]+=pow10[(len-i)%8]*(str[i]-'0');
	len=(len-1)/8;
}

void mul(int *a,int *b,int *aMulB,int lenA,int lenB)
{
	ll tmp[N];
	for(int i=0;i<=lenA+lenB+1;i++)
		tmp[i]=0;
	for(int i=0;i<=lenA;i++)
		for(int j=0;j<=lenB;j++)
			tmp[i+j]+=(ll)a[i]*b[j];
	for(int i=0;i<=lenA+lenB+1;i++)
	{
		tmp[i+1]+=tmp[i] / pow10[8];
		aMulB[i]=tmp[i] % pow10[8];
	}
}

void output(int *a,int len)
{
	int i;
	for(i=len;!a[i]&&i>=0;i--);
	if(i<0)
		printf("0");
	else
		printf("%d",a[i]);
	for(i--;i>=0;i--)
		printf("%08d",a[i]);
	printf("\n");
}

void solve()
{
	int lenA,lenB;
	int a[N],b[N],aMulB[2 * N];
	
	input(a,lenA);
	input(b,lenB);
	
	mul(a,b,aMulB,lenA,lenB);
	
	output(aMulB,lenA+lenB+1);
}

void init()
{
	pow10[0]=1;
	for(int i=1;i<=9;i++)
		pow10[i]=pow10[i-1]*10;
}

int main()
{
#ifdef DEBUG
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif

	init();
	
	int dataNum;
	scanf("%d",&dataNum);
	while(dataNum--)
		solve();
	
	return 0;
}
