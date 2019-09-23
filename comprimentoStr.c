#include <stdio.h>

//objetivo:indicar o comprimento de um string

int comprimento(char *s){
	char *p = s;
	while(*s !='\0')
		s++;
	return (int) (s-p);	
}

int main(){
	char s[100];
	gets(s);
	puts(s);
	printf("\n");
	printf("%d", comprimento(s));
	
	return 0;
}
