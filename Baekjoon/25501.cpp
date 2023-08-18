#include <stdio.h>
#include <string.h>

int recursionCount(const char *s, int l, int r)
{
	if (l >= r) return 1;
	if (s[l] != s[r]) return 1;
	return recursionCount(s, l + 1, r - 1) + 1;
}

int recursion(const char *s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		char str[1001];
		scanf("%s", str);
		printf("%d %d\n", isPalindrome(str), recursionCount(str, 0, strlen(str) - 1));
	}

	return 0;
}