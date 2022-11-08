#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char GetCh (VOID);
int mystrcmp(char[], char[]);
int loncad (char []);

int main() {
	int j=0, p;
	char coi[2000];
	char cor[]="lagartijo";//Contraseña real//
	char c;
    for (j; j>=0;j++){
    	c=GetCh();
    	if(c==13){
    		coi[j]='\0';
    		break;
		}else if (c==8){
			if(j==0){
				printf("\a");
				continue;
			}
			printf("\b \b");
			j=j-2;
		}else{
			if((c==13)||(c==8)){
				break;
			}
			coi[j]=c;
			printf("*");
		}
	}
	
	p=mystrcmp(coi, cor);
	if(p==0){
		printf("La contraseña es correcta");
	}else{
		printf("La contraseña es incorrecta");
	}
	return 0;
}

char GetCh (VOID)
{
  HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
  INPUT_RECORD irInputRecord;
  DWORD dwEventsRead;
  CHAR cChar;

  while(ReadConsoleInputA (hStdin, &irInputRecord, 1, &dwEventsRead)) /* Read key press */
    if (irInputRecord.EventType == KEY_EVENT
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL)
    {
      cChar = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
	ReadConsoleInputA (hStdin, &irInputRecord , 1, &dwEventsRead); /* Read key release */
	return cChar;
    }
  return EOF;
}

int mystrcmp(char vec1[], char vec2[]){
	if ((loncad(vec1))!=(loncad(vec2))){
		return -1;
	}
	else{
		int i=0;
		int m=loncad(vec1), s=0;
		for (i; i<m; i++){
			s=s+(((int)vec1[i]) - ((int)vec2[i]));
		}
		return s;
	}
}

int loncad(char a[]){
	int j=0;
	for (j; j>=0; j++){
		if(a[j]==0){
			break;
		}
	}
	return j;
}


