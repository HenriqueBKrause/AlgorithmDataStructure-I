

#include <stdio.h>

    int minCostClimbingStairs(int* cost, int costSize){

     int StepsTaken[costSize + 1];
    StepsTaken[0] = cost[0];
    StepsTaken[1] = cost[1];

    for (int i = 2; i <= costSize; i++) {
        int currentCost = (i == costSize) ? 0 : cost[i]; 
        StepsTaken[i] = fmin(StepsTaken[i - 1], StepsTaken[i - 2]) + currentCost;
    }

    return StepsTaken[costSize];

}
  
int main() 
{ 
    int cost[] = { 10, 15, 20 }; 
    int n = sizeof(cost) / sizeof(cost[0]); 
    printf("%d", minCostClimbingStairs(cost, n)); 
    return 0; 
}

