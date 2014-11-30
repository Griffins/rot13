#include <stdio.h>
#include <string.h>

int rot13(int c);
void interactive();
void direct_mode();
void direct_mode2();
char * rotate_text(char r[]);
int main (int argc, char * argv[])
{
	int c=0;
	for (c=1;c<argc;c++){
		if((strcmp(argv[c],"-t")==0) && (argc > c)){
			direct_mode(argv[c+1]);				
		}
		if((strcmp(argv[c],"-n")==0) && (argc > c)){
			direct_mode2(argv[c+1]);				
		}

	}	
	interactive();		
	return 0;
}
void direct_mode(char * a ){
	char *s  = a;		
	rotate_text(s);
	printf("Rotated text: %s\n",s);
	exit(0);
}

void direct_mode2(char * a ){
	char *s  = a;		
	rotate_text(s);
	printf("%s\n",s);
	exit(0);
}
void interactive(){
	char s[255];
	printf("Enter text to rot13");
	scanf("%s",&s);
	char *p  = &s;		
	rotate_text(p);
	printf("Rotated text: %s\n",s);

}
char * rotate_text(char  r[]){
	int x=0;
	while(1){
		int *d;
		d = r[x];
		if((char) d == '\0'){
			break;
		}
		d =  rot13 (d);
		r[x] = d;
		x++;
		//printf("rotating char %c\n",d);
	}
	return r;
}
int rot13(int c){
	int la = 65;
	int lb = 97;
	int v = c;
	if(c<(65+26) && (c>= 65)){
		if(c<(65+13)){
			v = c+13;
		}else{
			v = 65 + (c-65) -13 ;	
		}
	}else if(c<(97+26) && c > ( 65+26 )){
		if(c<(97+13)){
			v = c+13;
		}else{
			v = 97+ c-97 - 13;
		}
	}
	return v;
}
