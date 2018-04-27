#include <stdio.h>

#define MAX_SIZE 1000

void loadFile()
{
  //TODO
  printf("Attending to call unimplemented function loadfile\n");
}



int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
  // Base Case
  if (n == 0 || W == 0)
    return 0;

  // If weight of the nth item is more than Knapsack capacity W, then
  // this item cannot be included in the optimal solution
  if (wt[n-1] > W)
    return knapSack(W, wt, val, n-1);

  // Return the maximum of two cases: 
  // (1) nth item included 
  // (2) not included
  else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
      knapSack(W, wt, val, n-1)
    );
}


int main(int argc, char *argv[]) 
{

  //TODO read command line arguments to get file and size
  int maxWeight = 100;
  FILE *fp;

  int weights[MAX_SIZE] = {0};
  int values[MAX_SIZE] = {0};
  int numObjects  = 0;

  fp = fopen("../data/small1.txt", "r");

  int numberRead = 0;

  for(int i = 0; i < 100; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      int found = fscanf(fp, "%d", &numberRead);
      if(found > 0)
      {
        switch(j)
        {
          case 0:
            numObjects++;
            break;
          case 1:
            weights[i] = numberRead;
            break;
          case 2:
            values[i] = numberRead;
            break;
        }
      }
    }
  }

  printf("trying to get a number : %d\n", weights[3]);
  printf("We couted %d objects\n", numObjects);


  fclose(fp);

  int result = knapSack(maxWeight, weights, values, numObjects);
  printf("The answer is: %d\n", result);

  printf("I think I remember how this works\n");



  return 0;
}