/* Ex 1.a */

#include <iostream>

using namespace std;

int main()
{
  int n_max=10;
  float r=.7, x=.5; // r é o parametro geométrico, x é o valor inicial
  

  /* ciclo das iteradas */
  
  for (int i = 0; i < n_max; i++)
    {

      x *= r;
      cout << "x(" << i << ")= " << x << endl;
      
    }
  return 0;

}
