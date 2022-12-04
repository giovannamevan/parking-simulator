

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Horario {int dia; int mes; int ano; int hora; int min;};
typedef struct Horario horario;

struct Registro {char placa[7]; char modelo[10]; char cor[10]; horario entrada; horario saida; char status;};
typedef struct Registro registro;



horario tempo_de_permanencia (horario entrada0, horario saida0) {

// calculo da data

    horario permanencia;
    permanencia.ano = saida0.ano - entrada0.ano;
    permanencia.mes = saida0.mes - saida0.mes;  

if (saida0.dia < entrada0.dia) {
        if (entrada0.mes == 2 && ((entrada0.ano) % 400 == 0) || (((entrada0.ano) % 4 == 0) && ((entrada0.ano) % 100 != 0))) {
            permanencia.dia = 29 - entrada0.dia + saida0.dia;
        }
        else if (entrada0.mes == 2) {
            permanencia.dia = 28 - entrada0.dia + saida0.dia;
        }
        else if (entrada0.mes == 1 || entrada0.mes == 3 || entrada0.mes == 5 || entrada0.mes == 7 || entrada0.mes == 8 || entrada0.mes == 10 || entrada0.mes == 12)  {
            permanencia.dia = 31 - entrada0.dia + saida0.dia;
        }
        else {
            permanencia.dia = 30 - entrada0.dia + saida0.dia;
        }
    } else {
            permanencia.dia = saida0.dia - entrada0.dia;
    }

// calculo do tempo

    permanencia.hora = saida0.hora - entrada0.hora;
    permanencia.min = saida0.min - entrada0.min;

    if (permanencia.min < 0) {
        permanencia.min += 60;
        permanencia.hora -= 1;
    }
    else if (permanencia.hora < 0){
        permanencia.hora += 24;
        permanencia.dia -= 1;
    }
    else if (permanencia.mes < 0) {
        permanencia.mes += 12;
        permanencia.ano -= 1;
    }

    printf("\n==Tempo estacionado ==\nAnos: %d Meses: %d Dias: %d Horas: %d Minutos: %d\n", permanencia.ano, permanencia.mes, permanencia.dia, permanencia.hora, permanencia.min);
    
    return permanencia;


}


int valida_entrada (horario x){
  if (x.mes == 1 || x.mes == 3 || x.mes == 5 || x.mes == 7 || x.mes == 8 || x.mes == 10 || x.mes == 12 > 31) {
    printf ("Dia invalido! Digite um numero entre 1 e 31.");
        return -1;

  }
  if ( x.mes == 4 || x.mes == 6 || x.mes == 9 || x.mes == 11 > 30) {
    printf ("Dia invalido! Digite um numero entre 1 e 30.");
        return -1;

  }
  if (x.mes == 2) {
    int bissexto = 0;
    if ((x.ano % 400 == 0) || (x.ano % 4 == 0) && (x.ano % 100 != 0)) {
      bissexto = 1;
    } if (bissexto && x.dia > 29) {
      ("Dia invalido! Digite um numero entre 1 e 29\n.");
    }     return -1;

  }
  
  if (x.hora <= 0 || x.hora > 23) {
    ("Hora invalida! Digite um numero entre 1 e 23\n.");
        return -1;

  }

   if (x.min <= 0 || x.min > 59) {
    ("Minuto invalido! Digite um numero entre 1 e 59\n.");
    return -1;
  }
  return -1;
}

int valida_saida (horario y){
  if (y.mes == 1 || y.mes == 3 || y.mes == 5 || y.mes == 7 || y.mes == 8 || y.mes == 10 || y.mes == 12 > 31) {
    printf ("Dia invalido! Digite um numero entre 1 e 31.");
       return -1;

  }
  if ( y.mes == 4 || y.mes == 6 || y.mes == 9 || y.mes == 11 > 30) {
    printf ("Dia invalido! Digite um numero entre 1 e 30.");
        return -1;

  }
  if (y.mes == 2) {
    int bissexto = 0;
    if ((y.ano % 400 == 0) || (y.ano % 4 == 0) && (y.ano % 100 != 0)) {
      bissexto = 1;
    } if (bissexto && y.dia > 29) {
      ("Dia invalido! Digite um numero entre 1 e 29\n.");
     
    }    return -1;

  }
  
  if (y.hora <= 0 || y.hora > 23) {
    ("Hora invalida! Digite um numero entre 1 e 23\n.");
        return -1;

  }

   if (y.min <= 0 || y.min > 59) {
    ("Minuto invalido! Digite um numero entre 1 e 59\n.");
          return -1;

  }
  return -1;
}


void adicionar_registro (FILE *f) {
  if (f == NULL) {
    printf ("Nao foi possivel abrir o arquivo de registros\n");
    return;
  }

  registro re;
  re.status = 'P';
  printf("Insira a placa do carro:\n");  scanf(" %s", re.placa); setbuf(stdin, NULL);
  printf("Insira a cor do carro:\n");    scanf(" %s",re.cor); setbuf(stdin, NULL);
  printf("Insira o modelo do carro:\n"); scanf(" %s", re.modelo); setbuf(stdin, NULL); 


  // LEITURA DE DADOS DA ENTRADA
  printf("=== DADOS DE ENTRADA DO VEICULO ===\n");

  printf("Insira o dia:\n"); scanf(" %d", &re.entrada.dia); setbuf(stdin, NULL);
  printf("Insira o mes:\n"); scanf(" %d", &re.entrada.mes); setbuf(stdin, NULL);
  printf("Insira o ano:\n"); scanf(" %d", &re.entrada.ano); setbuf(stdin, NULL);
  printf("Insira a hora:\n"); scanf(" %d", &re.entrada.hora); setbuf(stdin, NULL);
  printf("Insira o minuto:\n"); scanf(" %d", &re.entrada.min); setbuf(stdin, NULL);
  valida_entrada (re.entrada);

  // LEITURA DE DADOS DA SAIDA
  printf("=== DADOS DE SAIDA DO VEICULO ===\n");

  printf("Insira o dia:\n"); scanf(" %d", &re.saida.dia); setbuf(stdin, NULL);
  printf("Insira o mes:\n"); scanf(" %d", &re.saida.mes); setbuf(stdin, NULL);
  printf("Insira o ano:\n"); scanf(" %d", &re.saida.ano); setbuf(stdin, NULL);
  printf("Insira a hora:\n"); scanf(" %d", &re.saida.hora); setbuf(stdin, NULL);
  printf("Insira o minuto:\n"); scanf(" %d", &re.saida.min);setbuf(stdin, NULL);
  valida_saida (re.saida);

  fseek(f, 0, SEEK_END);
  fwrite(&re, sizeof(registro), 1, f);
}

void alterar_registros(FILE *f) {
 if (f == NULL) {
    printf ("Nao foi possivel abrir o arquivo de alteracao\n");
    return;
  }

  // busca pelo arquivo que vai ser alterado

  char busca[7];
  printf("Digite a placa a ser encontrada:\n");
  scanf (" %s", busca);

  fseek(f,0,SEEK_SET);
  registro re;

  while (1) {
    fread(&re, sizeof(registro), 1, f);
    if (feof(f)) {
      printf("VEICULO NAO ENCONTRADO!\n");
      return;

    } else if (strcmp(re.placa, busca) == 0) {
      printf("Digite a nova hora da saida:\n");
      scanf(" %d", &re.saida.hora); setbuf(stdin, NULL);

      fseek(f, -1 * sizeof(registro), SEEK_CUR);
      fwrite(&re, sizeof(registro), 1, f);
      break;
    }
  } printf ("\nRegistro Inserido!\n");
}

void imprimir(registro n) {

  printf("DADOS DO CARRO:\n");
  printf("Placa: %s\n", n.placa);
  printf("Modelo: %s\n", n.modelo);
  printf("Cor: %s\n", n.cor);
  printf("Status: %c\n", n.status);

  printf("\n");

  printf("DADOS DE ENTRADA: ");
  printf("Dia: %d ", n.entrada.dia);
  printf("|  Mes: %d ", n.entrada.mes);
  printf("|  Ano: %d ", n.entrada.ano);
  printf("|  Hora:%d ", n.entrada.hora);
  printf("|  Minuto:%d ", n.entrada.min);

  printf("\n");

  printf("DADOS DE SAIDA: ");
  printf("Dia: %d ", n.saida.dia);
  printf("|  Mes: %d ", n.saida.mes);
  printf("|  Ano: %d ", n.saida.ano);
  printf("|  Hora: %d ", n.saida.hora);
  printf("|  Minuto: %d ", n.saida.min);

  tempo_de_permanencia (n.entrada, n.saida);

  printf("\n\n\n");
}

void buscar_registro(FILE *f) {

if (f == NULL) {
    printf ("Nao foi possivel abrir o arquivo de busca\n");
    return;
  }

  char busca_placa[7];
  printf("Digite a placa a ser encontrada:\n");
  scanf (" %s", busca_placa);

  fseek(f,0,SEEK_SET);
  registro re;

  while (1) {

    fread(&re, sizeof(registro), 1, f);
    if (feof(f)) {
      printf("VEICULO NAO ENCONTRADO!\n");
      return;

    } else if (strcmp(re.placa, busca_placa) == 0) {
      imprimir(re);
     
    }
    break;
  }
}

void listar_registros(FILE *f) {
if (f == NULL) {
    printf ("Nao foi possivel abrir o arquivo de listagem\n");
    return;
  }

  fseek(f,0,SEEK_SET);
  registro re;

  while (1) {
    fread(&re, sizeof(registro), 1, f);
    imprimir(re);
    break;
  }
  fseek(f, 0, SEEK_END);

  return;
}

void remover_registro(FILE *f) {
if (f == NULL) {
    printf ("Nao foi possivel abrir o arquivo de listagem\n");
    return;
  }

  char busc[7];
  printf("Digite a placa a ser encontrada:\n");
  scanf (" %s", busc);

  fseek(f,0,SEEK_SET);
  registro re;

  while (1) {

    fread(&re, sizeof(registro), 1, f);
    if (feof(f)) {
      printf("VEICULO NAO ENCONTRADO!\n");
      return;

    } else if (strcmp(re.placa, busc) == 0) {
      re.status = 'R';

      fseek(f, -1 * sizeof(registro), SEEK_CUR);
      fwrite(&re, sizeof(registro), 1, f);
      break;
    }
  } printf ("\nRegistro removido!\n");
}

int main() {

    FILE *f = fopen ("trabalhofinal.dat", "rb+");
    if (f == NULL) {
    FILE *f = fopen ("trabalhofinal.dat", "wb+");
    } else if (f == NULL) {
        printf ("Nao foi possivel executar o arquivo!");
    }

    int opcao = -1;

    while (opcao != 0) {
      printf("\n\n[0] SAIR\n[1] ADICIONAR REGISTRO\n[2] ALTERAR REGISTRO\n[3] BUSCAR REGISTRO\n[4] LISTAR REGISTROS\n[5] REMOVER REGISTROS\n");
      printf("\nOpcao: ");
      scanf(" %d", &opcao);
    

      switch (opcao) {
      case 1: adicionar_registro(f); break; 
      case 2: alterar_registros(f); break; 
      case 3: buscar_registro(f); break; 
      case 4: listar_registros(f); break;
      case 5: remover_registro(f); break; 
      printf("\n\n\n"); 

      }
     }

    fclose(f);

    return 0;
  }
