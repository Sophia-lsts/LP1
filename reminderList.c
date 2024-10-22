#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RMD 25 //quantidade máxima de reminders
#define TAM_STR 70 //tamanho máximo do reminder

void clean(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void organizationRMD(char *rem[], int j){

    int i;
    int k;
    char *aux; //ponteiro para string auxiliar que vai só guardar temporariamente

    // strcmp == 0 (iguais), strcmp < 0 (primeiro menor que segundo), strcmp > 0 (primeiro maior que segundo)
    
    for(i=0;i<j;i++){
        for(k=i+1;k<j;k++){
            if((strncmp(rem[i], rem[k], 2) > 0) ){ //strncmp pode delimitar a parte da string a ser comparada
                aux = rem[i];
                rem[i] = rem[k];
                rem[k] = aux;
            }
        }
    }

} 

void newRMD(char *a, char *b, char *r[], int i){

    r[i] = (char *)malloc(((strlen(a)) + (strlen(b))) + 4); //aloca memória pro ponteiro que está no índice do array atual

    if(r[i] == NULL){ //verificação da alocação
        printf("Erro na alocação.");
        exit(1);
    }

    strcpy(r[i], a);
    strcat(r[i], " - "); //strcat concatena
    strcat(r[i], b);

} 

int main(){

    char *reminders[MAX_RMD]; //array de ponteiros pros diferentes lembretes
    char reminder[TAM_STR];
    int day;
    char day_str[3];
    char op = 's';
    int count = 0;
    int i;

    while(op == 's' && count < MAX_RMD){

        printf("Digite o seu dia:\n");
        scanf("%2d", &day);
        sprintf(day_str, "%2d", day); //transformando o dia em string

        getchar(); //tirando \n de day

        printf("Digite o seu lembrete:\n");
        fgets(reminder,TAM_STR,stdin); //tem /0 no final

        reminder[strcspn(reminder, "\n")] = '\0'; //strcspn procura a quando "\n" o enter da entrada aparece e retorna como índice p reminder
        // e dps substitui por \0 pra sinalizar o fim da string

        newRMD(day_str, reminder, reminders, count);
        count++;
        organizationRMD(reminders ,count);


        printf("Deseja adicionar outro lembrete? Digite s pra sim e qualquer outra tecla pra não. \n");
        scanf("%c", &op);
        getchar();
        clean();

    }

    clean();
    printf("Reminder Mounth List\n");
    for(i=0;i<count;i++){
        printf("%s\n", reminders[i]);
        free(reminders[i]); //liberar a memória alocada
    }
}