#include<stdio.h>
#include"./hipala_vector.h"

void input(Vec_ &v);
void output(Vec_ &v);

int main(){
	freopen("test_vector.txt","r",stdin);
	Vec_ a,b,c;
	input(a);input(b);
	c=a+b;
	putout(c);
}

void input(Vec_ &v){
	scanf("%d",&v.len);
	for(int i=0;i<v.len;i++)
		scanf("%lf",&v.num[i]);
}

void output(Vec_ &v){
	int jishu=0,lieshu=5;
	for(int i=0;i<v.len;i++){
		printf("%-6.2lf",v.num[i]);
		jishu++;
		if( jishu== lieshu){
			printf("\n");
			jishu=0;
		}
	}
}
