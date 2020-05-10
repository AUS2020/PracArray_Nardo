#include <stdio.h>
#include <stdlib.h>

#define L 10
#define M 5
#define R 30
#define J 20
#define K 15
#define X 3
#define Y 4
#define Resp(x) ((x!='n'&& x!='N'))
#define ResSN(r) ((r!='n')&&(r!='N')&&(r!='s')&&(r!='S'))

void ValCar(char *c) //subrutina que valida s/n
{char r=*c;
while(ResSN(r))
{printf("Error ingrese S/N\n");
fflush(stdin);
scanf("%c",&r);
}
  *c=r;
}

int main()
{ char resn='s',respo;
 int opn,ope,A[L],C[L],a[M],b[M],s[M],i,j,n,cont[4],suma,con,d[R],aux,N,car,r,k[X][Y],G[K],g[J];
 float f,prom,vari, B[L];

 while(Resp(resn))
 {printf("______MENU DE NIVELES DE ARREGLO______\n");
printf("1_Nivel 1 FACIL\n");
printf("2_Nivel 2 MEDIO\n");
printf("3_Nivel 3 DIFICIL\n");
printf("4_Salir\n");
printf("Ingrese una opcion [1,4]\n");
scanf("%d",&opn);
while(opn<1||opn>4)
{
    printf("Error ingrese valor entre 1 y 4\n");
    scanf("%d",&opn);
}

  switch(opn)
  { case 1: //Nivel 1
      {   respo='s';
          while(Resp(respo))
          {printf("\n\nEligio nivel %d\n",opn);
          printf("-----Menu del Nivel %d-----\n",opn);
          printf("1_ A1-1)\n");
          printf("2_ A1-2)\n");
          printf("3_ A1-3)\n");
          printf("4_ A1-4)\n");
          printf("5_ A1-5)\n");
          printf("6_ A1-6)\n");
          printf("7_ A1-7)\n");
          printf("8_ Salir\n");
          printf("Ingrese opcion entre [1,8]\n");
          scanf("%d",&ope);
          while(ope<1||ope>8)
          {printf("Error ingrese valor entre [1,8]");
           scanf("%d",&ope);
          }
          switch(ope)
          {  case 1:
              {printf("\nA1-1) Declare un array de 10 enteros y permita que el usuario ingrese valores comprendidos entre el -10 y el 10 (asegurar esto) y luego lo muestre por pantalla\n");
               for(i=0;i<L;i++) //CArga
               {printf("Ingrese el %d numero comprendido entre [-10,10]\n",i+1);
                scanf("%d",&A[i]);
                while(A[i]<-10||A[i]>10)
                {printf("Error ingrese un numero entre [-10,10] para la pos %d\n",i+1);
                 scanf("%d",&A[i]);
                }
               }
               printf("Se cargo el siguiente arreglo\n");
               for(i=0;i<L;i++)
               {printf("%d ",A[i]);

               }


              }break;
            case 2:
              {printf("\nA1-2) Declare dos arrays de 5 enteros cada uno, llamados A y B, luego en un tercer array de igual dimensión llamado S almacene la suma de los dos anteriores.\n");
               for(i=0;i<M;i++)
               { printf("Ingrese el numero %d de %d para A\n",i+1,M);
                 scanf("%d",&a[i]);
                 printf("Ingrese el numero %d de %d para B\n",i+1,M);
                 scanf("%d",&b[i]);
                 s[i]=a[i]+b[i];
               }
               printf("Se creo el siguiente arreglo que representa A+B\n");
               for(i=0;i<M;i++)
               { printf("%d ",s[i]);
               }
               printf("\n");
              }break;
            case 3:
              {printf("A1-3) Declare un array de 10 enteros, permita la carga manual y luego determine lo siguiente:\n");
               printf("- cuantos elementos son positivos y pares \n- cuantos elementos son positivos e impares \n- cuantos elementos son negativos y pares\n- cuantos elementos son negativos e impares\n");
               for(i=0;i<4;i++)
               {cont[i]=0;
               }
               for(i=0;i<L;i++)
               {printf("Ingrese el numero %d de %d\n",i+1,L);
                scanf("%d",&A[i]);
                if(A[i]>0&& A[i]%2==0)
                {cont[0]++;
                }
                if(A[i]>0&& A[i]%2!=0)
                {cont[1]++;
                }
                 if(A[i]<0&& A[i]%2==0)
                {cont[2]++;
                }
                if(A[i]<0&& A[i]%2!=0)
                {cont[3]++;
                }
               }
               printf("Hay %d numeros positivos y par \n Hay %d numeros positivos e impar \nHay %d numeros negativos y par \n Hay %d numeros negativos e impar \n",cont[0],cont[1],cont[2],cont[3]);


              }break;
            case 4:
              {printf("A1-4) Declare un array A de N floats, se realice la carga manual y pida al usuario un float f en el rango (0, 100] y en un nuevo array P establezca los elementos de esta forma.\n Cada elemento P[i] debe ser de la forma A[i]*f para i=0...N-1.\n");
               printf("Cuantos numeros quiere ingresar? nro>0\n");
               scanf("%d",&n);
               while(n<0)
               {printf("Error ingrese num>0\n");
                scanf("%d",&n);
               }
               float l[n],p[n];
               for(i=0;i<n;i++)
               {printf("Ingrese el numero %d de %d\n",i+1,n);
                scanf("%f",&l[i]);
               }
               printf("Ingrese un numero real entre (0,100]\n");
               scanf("%f",&f);
               while(f<=0||f>100)
               {printf("Error ingrese un numero real entre (0,100]\n");
                scanf("%f",&f);
               }
               printf("Se creo el siguiente arreglo. Cada elemento es de la forma P[i]=A[i]*f\n");
               for(i=0;i<n;i++)
               {p[i]=l[i]*f;
                printf("%.2f X %.2f = %.2f\n",l[i],f,p[i]);
               }
               printf("\n");
              }break;
            case 5:
              {printf("A1-5) Dado un array de 10 floats, mostrar por pantalla cuales elementos superan al promedio.\n");
               printf("Se cargara el arreglo de reales\n");
               prom=0;
               for(i=0;i<L;i++)
               {printf("Ingrese el numero real %d de %d ",i+1,L);
                scanf("%f",&B[i]);
                prom=prom+B[i];
               }
               prom=prom/L;
               printf("Los elementos del arreglo creado que superan el prom= %.2f son:",prom);
               for(i=0;i<L;i++)
               { if(B[i]>prom)
                 { printf("%.2f ",B[i]);
                 }
               }
               printf("\n");
              }break;
            case 6:
              { printf("A1-6) Declare un array de 10 enteros en el rango [0, 100] (asegurarlo) y muestre por pantalla dichos elementos junto con la suma, el promedio y la varianza.\n");
                suma=0;
                for(i=0;i<L;i++)
                {printf("Ingrese el numero entero %d de %d en el rango[0,100]\n",i+1,L);
                 scanf("%d",&A[i]);
                 while(A[i]<0||A[i]>100)
                 {printf("Error ingrese un numero entre[0,100]\n",i+1,L);
                 scanf("%d",&A[i]);
                 }
                 suma=suma+A[i];
                }
                prom=(suma+0.0)/L;
                vari=0;
                printf("Los elementos del arreglo son: ");
                for(i=0;i<L;i++)
                {printf("%d ",A[i]);
                 vari=vari+(A[i]-prom)*(A[i]-prom);
                }
                printf("\nLa suma de todos los elementos es %d_ El prom general es %.2f y la varianza es %.2f",suma,prom,vari/(L-1));

              }break;
            case 7:
              {printf("Declare dos arrays de 10 enteros con valores entre [0, 50] llamados M y N, luego determine si son:\n- iguales: cuando cada componente ubicada en misma posición coincide.\n- similares frente a suma: cuando no tienen las mismas componentes pero la suma de los elementos coincide\n- diferentes: cuando no coinciden ni en las componentes ni en la suma");
               n=0;suma=0;con=0;
               for(i=0;i<L;i++)
               {printf("Ingrese el numero entero %d de %d en el rango[0,50]\n",i+1,L);
                 scanf("%d",&A[i]);
                 while(A[i]<0||A[i]>50)
                 {printf("Error ingrese un numero entre[0,50] de M\n",i+1,L);
                 scanf("%d",&A[i]);
                 }
                 n=n+A[i];
                 printf("Ingrese el numero entero %d de %d en el rango[0,50] de N\n",i+1,L);
                 scanf("%d",&C[i]);
                 while(C[i]<0||C[i]>50)
                 {printf("Error ingrese un numero entre[0,50]\n",i+1,L);
                 scanf("%d",&C[i]);
                 }
                 suma=suma+C[i];
                 if(A[i]=C[i])
                 {con++;

                 }
               }
               if(con==L||suma==n)
               {if(con==L)
                {printf("Los arreglos M y N son iguales\n");
                }
                else
                {printf("Los arreglos M y N son similares frente a la suma\n");
                }
               }
               else{
                 printf("Los arreglos M y N son diferentes");
               }

              }break;
            case 8:
              {respo='n';

              }break;

          }
          if(Resp(respo))
          { printf("Desea ver otro ejercicio del nivel %d? (S/N)\n",ope);
            fflush(stdin);
            scanf("%c",&respo);
            ValCar(&respo);

          }

      }break;
    }
    case 2: //Nivel 2
      {
         respo='s';
          while(Resp(respo))
          {printf("\n\nEligio nivel %d\n",opn);
          printf("-----Menu del Nivel %d-----\n",opn);
          printf("1_ A2-1)\n");
          printf("2_ A2-2)\n");
          printf("3_ A2-3)\n");
          printf("4_ A2-4)\n");
          printf("5_ A2-5)\n");
          printf("6_ Salir.\n");
          printf("Ingrese opcion entre [1,6]\n");
          scanf("%d",&ope);
          while(ope<1||ope>6)
          {printf("Error ingrese valor entre [1,6]");
           scanf("%d",&ope);
          }
          switch(ope)
           {
            case 1:
            {printf("A2-1)Permita la caga de una array de 30 enteros aleatorios. Luego mostrarlos por pantalla.\n");
             printf("Se creo el siguiente arreglo aleatorio: ");
             for(i=0;i<R;i++)
             {d[i]=rand();
             printf("%d ",d[i]);
             }
             printf("\n");

            }break;

            case 2:
            {  printf("A2-2)Permita la carga aleatoria de dos arrays de 10 enteros cada uno, llamados A y B, e indique cual de los dos tiene más números pares tratando de utilizando como máximo dos bucles for en todo el programa.\n");
               con=0;suma=0;
               for(i=0;i<L;i++)
               { A[i]=rand();
                 C[i]=rand();
                 if(A[i]%2==0)
                 {con++;
                 }
                 if(C[i]%2==0)
                 {suma++;
                 }
                }
                if(con>suma)
                {printf("El arreglo A tiene mas numeros pares que B\n");
                }
                else
                { if(suma>con)
                  {printf("El arreglo B tiene mas numeros pares que A\n");
                  }
                  else
                  {printf("Tienen la misma cantidad de numeros pares A y B\n");
                  }
                  }

            }break;

            case 3:
            {printf("A2-3) Dado un array A de 10 floats cagado aleatoriamente y con valores comprendidos entre 0 y 100, determinar si se tienen más elementos negativos que positivos o bien misma cantidad.\n");
             con=0;suma=0;
             for(i=0;i<L;i++)
             {A[i]=rand()%201-100;
              printf("%d ",A[i]);
              if(A[i]<0)
              {con++;
              }
              else
              {if(A[i]>0)
                {suma++;
                }
              }
             }
             if(con>suma)
             {printf("Hay mas numeros negativos que positivos\n");
             }
             else
             {if(suma>con)
              {printf("Hay mas numeros positivos que negativos\n");
              }
              else
                printf("Hay misma cantidad de elementos positivos que negativos\n ");

             }

            }break;

            case 4:
            {printf("A2-4) Dado un array A de 10 enteros cargados automáticamente (con números aleatorios), invertir el array, es decir si se tiene el array \nA= [ 45, 11, -5, 80, 6, 99, 105, -200, 22, 1 ], A deberá quedar del siguiente modo al finalizar el programa\nA= [ 1, 22, -200, 105, 99, 6, 80, -5, 11, 45 ]. Considere el uso de una variable a modo de pivote.\n\n");
            for(i=0;i<L;i++)
            {A[i]=rand()%401 -200;
            }
            printf("Se creo el siguiente arreglo: [");
            for(i=0;i<L;i++)
            {printf("%d ",A[i]);
             }
             printf("]\n");

            printf("Los elementos del arreglo se intercambiaran  de la siguiente forma: [  \n");
            for(i=0;i<L-1;i++)
            { for(j=i+1;j<L;j++)
               {if(i+j==L-1)
                {
                aux=A[i];
                A[i]=A[j];
                A[j]=aux;
                }

               }
            }
            for(i=0;i<L;i++)
            {printf("%d ",A[i]);
            }
            printf("]\n");

            }break;
            case 5:
            {printf("A2-5) Dado un array A de N enteros cargados manualmente o bien de forma automatica y un numero entero r en el rango [-(N-1), N-1].\nEl valor r impondra rotaciones a derecha (en caso de r positivo) o rotaciones a izquierda (en caso de r negativo) sobre los elementos del array A.\n Una rotacion es el cambio de posicion en los elementos del array.\n\nEjemplo, un array A con N valiendo 10, r estara comprendido en [-9, 9].");
             printf("Es decir, dado el array A= [ 45, 11, -5, 80, 6, 99, 105, -200, 22, 1]\n Si r= 1  A= [ 1, 45, 11, -5, 80, 6, 99, 105, -200, 22 ] Todos los elementos rotaron 1 posición a la derecha\nSi r=-3  A= [ -5, 80, 6, 99, 105, -200, 22, 1, 45, 11 ] Todos los elementos rotaron 3 posiciones a la izquierda\n");
             printf("\nIngrese el tamano del arreglo deseado nro>0\n");
             scanf("%d",&N);
             while(N<0)
             {printf("Error ingrese num>0\n");
              scanf("%d",&N);
             }
             int F[N];
             printf("Se cargara el arreglo: Desea cargarlo manualmente (0) o automaticamente (1)\n");
             scanf("%d",&car);
             while(car<0||car>1)
             { printf("Error ingrese 0/1\n");
              scanf("%d",&car);
             }
             switch(car)
             {
                case 0:
                { printf("Carga manual\n");
                  for(i=0;i<N;i++)
                  { printf("\nIngrese el numero %d de %d: ",i+1,N);
                    scanf("%d",&F[i]);
                 }
                 }break;
                case 1:
                { printf("Carga automatica");
                  for(i=0;i<N;i++)
                  { F[i]=rand()%401-200;
                  }
                }break;
             }
             printf("Se creo el siguiente arreglo: [");
             for(i=0;i<N;i++)
             {printf("%d ",F[i]);
             }
              printf("]\n");
              printf("Ingrese un numero entre [%d,%d]\n",-(N-1),N-1);
              scanf("%d",&r);
              while(r<-(N+1)||r>(N-1))
              { printf("Error ingrese un numero entre [%d,%d]\n",-(N-1),N-1);
                scanf("%d",&r);
              }
              if(r>0)
              { printf("Todos los elementos rotaron %d veces hacia la derecha.",r);
                for(j=1;j<=r;j++)
                {
                for(i=N-1;i>0;i--)
                {
                    aux=F[i-1];
                    F[i-1]=F[i];
                    F[i]=aux;
                }

                }

              }
              else
                {if(r<0)
                  {r=(-r);
                   printf("Todos los elementos rotaron %d veces hacia la izquiera.",r);
                    for(j=1;j<=r;j++)
                       {for(i=0;i<N-1;i++)
                        { aux=F[i+1];
                          F[i+1]=F[i];
                          F[i]=aux;
                        }

                       }
                  }
                }
            printf("Los elementos del arreglo son: [ ");
            for(i=0;i<N;i++)
            {printf("%d ",F[i]);
            }
            printf("]\n");

            }break;

            case 6:
            {respo='n';

            }break;
           }
           if(Resp(respo))
          { printf("Desea ver otro ejercicio del nivel %d? (S/N)\n",ope);
            fflush(stdin);
            scanf("%c",&respo);
            ValCar(&respo);

          }
          }
      }

      break;
    case 3: //Nivel 3
      {respo='s';
          while(Resp(respo))
          {printf("\n\nEligio nivel %d\n",opn);
          printf("-----Menu del Nivel %d-----\n",opn);
          printf("1_ A3-1)\n");
          printf("2_ A3-2)\n");
          printf("3_ A3-3)\n");
          printf("4_ A3-4)\n");
          printf("5_ A3-5)\n");
          printf("6_ A3-6)\n");
          printf("7_ Salir\n");
          printf("Ingrese opcion entre [1,7]\n");
          scanf("%d",&ope);
          while(ope<1||ope>7)
          {printf("Error ingrese valor entre [1,7]");
           scanf("%d",&ope);
          }
          switch(ope)
           {case 1:
               {
                printf("A3-1)Permitir el ingreso de una matriz de enteros de dimensión 3x4 y mostrarla por pantalla.\n");
                for(i=0;i<X;i++)
                {for(j=0;j<Y;j++)
                {printf("\nIngrese el numero de f:%d c:%d = ",i+1,j+1);
                scanf("%d",&k[i][j]);
                }
                }
                for(i=0;i<X;i++)
                {for(j=0;j<Y;j++)
                  {printf("%d ",k[i][j]);
                  }
                 printf("\n");
                }

               }break;
            case 2:
               {
                printf("A3-2) Permitir la carga automática de una matriz de dimensión NxN y mostrarla por pantalla.\n");
                printf("\nIngrese el tamaño de la matriz cuadrada nro>0\n");
                scanf("%d",&N);
                while(N<0)
                {printf("Error ingrese el tamaño de la matriz cuadrada nro>0\n");
                scanf("%d",&N);
                }
                int ln[N][N];
                for(i=0;i<N;i++)
                { for(j=0;j<N;j++)
                  {ln[i][j]=rand()%2000-1000;
                  }
                }
                printf("Se creo el siguiente arreglo:\n");
                for(i=0;i<N;i++)
                { for(j=0;j<N;j++)
                  {printf("%d ",ln[i][j]);
                  }
                  printf("\n");
                }
               }break;
            case 3:
               {printf("A3-3) Dadas dos matrices de dimensión NxN, llamadas X e Y, mostrar por pantalla la suma de las mismas.\n");
                printf("\nIngrese el tamaño de la matriz cuadrada nro>0\n");
                scanf("%d",&N);
                while(N<0)
                {printf("Error ingrese el tamaño de la matriz cuadrada nro>0\n");
                scanf("%d",&N);
                }
                int t[N][N],T[N][N],S[N][N];
                for(i=0;i<N;i++)
                {  for(j=0;j<N;j++)
                    {
                      t[i][j]=rand()%200-100;
                      T[i][j]=rand()%200-100;
                      S[i][j]=t[i][j]+T[i][j];
                    }
                }
                printf("X=\n");
               for(i=0;i<N;i++)
                {  for(j=0;j<N;j++)
                    { printf("%d ",t[i][j]);
                    }
                    printf("\n");
                }
                  printf("Y=\n");
               for(i=0;i<N;i++)
                {  for(j=0;j<N;j++)
                    { printf("%d ",T[i][j]);
                    }
                    printf("\n");
                }


                printf("\nLa suma de la matriz X e Y  es X+Y=\n");
                for(i=0;i<N;i++)
                {  for(j=0;j<N;j++)
                    { printf("%d ",S[i][j]);
                    }
                    printf("\n");
                }

               }break;
            case 4:
               {
                   printf("\nA3-4) Declarar un array A de 15 elementos enteros. Solicitar al usuario el ingreso de un valor por vez e ir colocando dicho entero en el array, donde cada elemento previo existente en el array A deba ser menor o igual y cada elemento posterior deba ser mayor al que el usuario ingresó.\n En cada paso mostrar el estado del array. Al finalizar deberá quedar el array ordenado de forma ascendente.\n\n");
                    for(i=0;i<K;i++)
                    {
                    if(i==0)
                    {printf("Ingrese el numero %d de %d :\n",i+1,K);
                     scanf("%d",&G[i]);
                    }
                    else
                    {printf("Ingrese el numero %d de %d recuerde que tiene q ser nro>%d  :\n",i+1,K,G[i-1]);
                     scanf("%d",&G[i]);
                     while(G[i]<G[i-1])
                     {
                         printf("Error ingrese un num>%d\n",G[i-1]);
                         scanf("%d",&G[i]);
                     }
                    }
                    }
                    printf("Se creo el siguiente arreglo ascendente [ ");
                    for(i=0;i<K;i++)
                    {
                    printf("%d ",G[i]);
                    }
                    printf("]\n");

               }break;
            case 5:
               {printf("A3-5) Dado un array A de 20 enteros positivos en el rango [0, 100] cargados aleatoriamente, y un entero positivo e, determinar si dicho entero e está presente en el array.\n Extender luego el programa para indicar no solo si está, sino también en cuantas ocasiones aparece.\n");
                con=0;
                for(i=0;i<J;i++)
                {g[i]=rand()%101;
                }
                printf("Se creo el siguiente arreglo [ ");
                for(i=0;i<J;i++)
                {
                    printf("%d ",g[i]);
                }
                printf("]\n");
                printf("Ingrese un numero entre [0,100]\n");
                scanf("%d",&car);
                while((car<0)||(car>100))
                {printf("Error ingrese un numero entre [0,100]\n");
                scanf("%d",&car);
                }
                for(i=0;i<J;i++)
                { if(g[i]==car)
                  {con++;
                  }
                }
                if(con!=0)
                {
                    printf("El numero %d aparecio en el arreglo %d veces\n",car,con);
                }
                else
                {
                    printf("El numero %d nunca aparecio en el arreglo cargado\n",car);
                }

               }break;
            case 6:
               {  printf("\n\nA3-6) Dado un array de 10 enteros positivos en el rango [0, 100] cargados aleatoriamente, mostrarlo por pantalla, luego ordenar sus elementos de manera ascendente y finalmente mostrar el resultado.\n");
                  for(i=0;i<L;i++)
                  {
                   A[i]=rand()%101;
                  }
                  printf("\nSe creo el siguiente arreglo [ ");
                  for(i=0;i<L;i++)
                  {
                   printf("%d ",A[i]);
                  }
                   printf("]\n");
                   printf("Ordenamiento del arreglo: [");
                   for(i=0;i<L;i++)
                    {    for(j=i+1;j<L;j++)
                         { if(A[j]<A[i])
                            {aux=A[j];
                             A[j]=A[i];
                             A[i]=aux;
                            }
                         }
                    }
                    for(i=0;i<L;i++)
                    {
                    printf("%d ",A[i]);
                    }
                    printf("]\n");

               }break;
            case 7:
               {respo='n';

               }break;


           }
          if(Resp(respo))
          { printf("Desea ver otro ejercicio del nivel %d? (S/N)\n",ope);
            fflush(stdin);
            scanf("%c",&respo);
            ValCar(&respo);

          }
          }

      }break;
    case 4:
      {resn='n';

      }break;

  }
  if(Resp(resn))
  {printf("Desea ver otro nivel? (S/N)\n");
  fflush(stdin);
   scanf("%c",&resn);
   ValCar(&resn);


  }


}
printf("Fin del programa. Adios\n");
    return 0;
}
