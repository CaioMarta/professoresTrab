#include <stdio.h>
#include <stdlib.h>
#define tam 10

struct professores
{
       char nome [30];
       char sexo;
       int numHoras;
       float SB, SL, desc;
};

void lerDados(struct professores p[10])
{
     int i;
     for(i=0; i<2; i++)
     {
              printf("\n Informe o nome do professor: "); 
              scanf("%s", p[i].nome);
              printf("\n Digite o sexo do professor: ");
              scanf(" %c", &p[i].sexo);
              printf("\n Digite o numero de horas do professor: ");
              scanf("%d", &p[i].numHoras);
     }
}

void calculos(struct professores p[])
{
     int i;
     for (i=0; i<2; i++)
     {
         p[i].SB = p[i].numHoras * 85;
         if(p[i].sexo == 'M')
         {
                          if(p[i].numHoras <= 70)
                          {
                              p[i].desc = 0.10*p[i].SB;
                          }
                          else
                          {
                              p[i].desc = 0.08*p[i].SB;
                          }
         }
         else
         {
             if(p[i].numHoras <= 70)
             {
                p[i].desc = 0.07*p[i].SB;
             }
             else
             {
                 p[i].desc = 0.05*p[i].SB;
             }
         }
         p[i].SL = p[i].SB - p[i].desc;
     }
}

void media(struct professores p[])
{
             int fem = 0, i;
             float somaSL = 0, mediaSLfem;
             for(i=0; i<2; i++)
             {
                      if(p[i].sexo == 'F')
                      {
                                   somaSL = somaSL + p[i].SL;
                                   fem++;
                      }
             }
             mediaSLfem = somaSL/fem;
             printf("\n EA media salarial feminina e: %.2f \n\n\n\n", mediaSLfem);
}
             

int main()
{
    
    struct professores p[10];
    lerDados(p);
    calculos(p);
    media(p);
    system("pause");

}
