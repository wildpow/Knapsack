#include <stdio.h>

#define MAX_SIZE 1000

void loadFile()
{
  printf("Called unimplemented function loadFile\n");
} 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int MaxW, int wt[], int val[], int itemNum)
{
  printf("Called knapsack, itemNum = %d\n", itemNum);
   // Base Case
   if (itemNum == 0 || MaxW == 0)
      return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[itemNum-1] > MaxW)
       return knapSack(MaxW, wt, val, itemNum-1);
 
   // Return the maximum of two cases: 
   // (1) nth item included 
   // (2) not included
   else return max( val[itemNum-1] + knapSack(MaxW-wt[itemNum-1], wt, val, itemNum-1),
                    knapSack(MaxW, wt, val, itemNum-1)
                  );
}
int main(int argc, char *argv[])
{
  //TODO: Read command line arguments
  int maxWeight = 100;
  FILE *fp;  


  // char buff[255];

  int weights[MAX_SIZE] = {0};
  int values[MAX_SIZE] = {0};
  int numObjects = 0;

  fp = fopen("../data/small1.txt", "r");

  int numberRead = 0;

  for(int i = 0; i < MAX_SIZE; i++)
  { 
    for(int j = 0; i < 3; j++)
    {
      
    }
    int found = fscanf(fp, "%d", &numberRead);
    if(found > 0)
    {
      printf("found is %d\n", found);
    }
    //fscanf(fp, "%d", &weights[i]);
  }

  
  printf("Tring to get a number : %d\n", weights[3]);
  
  fclose(fp);

  int result = knapSack(maxWeight, weights, values, numObjects);
  printf("The answer is %d\n", result);
  printf("I think I remember how this works.\n");
  return 0;
}