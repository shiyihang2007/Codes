#include <cstdio>
/*using namespace std*/
int n,k;
inline int function(int m){
	if((m-k)%2==1||m<=k) return 1;
	return function((m-k)/2+k)+function((m-k)/2);
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d",function(n));
	return 0;
}
