/* Projeto 1- 5.10.2017*/
/* Ex 2.a */
/*João Pedro Gomes 87327
  Mariana Silva 87336*/


#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/* Função para gerar números aleatórios */

double prng(double x1)
{
  double r, c, m;
  double x2;

  /* Parâmetros do PRNG */
  m = pow(2, 32);
  c = 1013904223;
  r = 1664525; 
  
  x2 = fmod((r * x1 + c), m); // calcular x(i+1) com x(i) através da expressão do PRNG
   
  return x2;
}

int main()
{
  int n_max;
  double r, c, m;
  double x1, x2;

  m = pow(2, 32);

  /* Ponteiros */
    
  double **mat;
  double (*f)(double);
    
  /* Inicialização dos ficheiros */
  
  ofstream output("output3.dat");
  
  /* Verificação de erro */
  
  if (!(output.is_open()))
    {
      cout << "***** ERRO A ABRIR O FICHEIRO! Tente novamente! *****" << endl;
      return 1;
    }

  /* Input do valor inicial e do nº de iterações a correr */

  cout << " Introduza um x inicial: " << endl;
  while(!(cin >> x1)) // Teste de validação de input
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout<<"Introduza um número válido: ";
    }
  
  cout << " Introduza o número de iterações: " << endl;
  while(!(cin >> n_max)) // Teste de validação de input
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout<<"Introduza um número válido: ";
    }

  /* Atribuir o endereço da função PRNG ao ponteiro para funções */
  
  f = &prng;
  
  /* Alocar espaço na memória para a matriz */
  
  mat = new(nothrow) double*[n_max];

  /* Controlo de problemas na alocação. Condição procura ponteiros nulos deixados pelo operador new */
  
  if (!mat)
    {
      cout << "*** Falha na alocação da matriz ***" << endl;
      delete[] mat;
      return 1;
    }

  
  for (int i = 0; i < n_max; i++)
    {
      mat[i] = new(nothrow) double[2];

        /* Controlo de problemas na alocação. Condição procura ponteiros nulos deixados pelo operador new */
      
      if (!(mat[i]))
	{
	  cout << "*** Falha na alocação da matriz ***" << endl;
	  delete[] mat[i];
	  return 1;
	}
    }


  for (int i = 0; i < n_max; i++)
    {
      x2 = (*f)(x1);
      mat[i][0] = x1 / m;
      mat[i][1] = x2 / m;
      x1 = x2;
    }

  for (int i = 0; i < n_max; i++)
    {
      output << mat[i][0] << " " << mat[i][1] << endl;
      cout << mat[i][0] << " " << mat[i][1] << endl;
    }


  /* Ciclo de desalocação da memória dinâmica usada */

  for (int i = 0; i < n_max; i++)
    {
      delete[] mat[i];
    }
   
  delete[] mat; 
 
  return 0;

}
