#include <stdio.h>

int rot13(int c);
int main ()
{
	char  var;
	int x = 0;
	
	for (x = 65;x<(65+26);x++)
		printf (" ascii %d  %c \n",x, (char) (rot13(x)));
	printf("\n");
	return 0;
}

int rot13(int c){
	int la = 65;
	int lb = 97;
	int v = 0;
	if(c<(65+26)){
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

}
