#include <stdio.h>
 
double max(double a,double b,double c){
    double d=a>=b?a:b;
    return d>=c?d:c;
}
 
double findMinRec(int arr[], int i, int sumCalculated, int sumTotal)
{
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i==0){
        if((sumTotal-sumCalculated)>sumCalculated&&(sumTotal-sumCalculated)!=0)
            return sumCalculated*1.0/(sumTotal-sumCalculated);
        else if(sumCalculated!=0)
            return (sumTotal-sumCalculated)*1.0/sumCalculated;
        else 
            return 0;
    }
 
 
    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return max(findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal),
               findMinRec(arr, i-1, sumCalculated, sumTotal),
               findMinRec(arr, i-1, sumCalculated, sumTotal-arr[i-1]));
}
 
// Returns minimum possible difference between sums
// of two subsets
double findMin(int arr[], int n)
{
    // Compute total sum of elements
    int sumTotal = 0;
    for (int i=0; i<n; i++)
        sumTotal += arr[i];
    
    return 1.0*findMinRec(arr, n, 0, sumTotal);
}
int main()
{
    int a[16];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    double an=1.0*findMin(a,n);
    //printf("%f--",an);
    if(an<1.0)
    printf("%0.6f",1.0-an);
    else
    printf("%0.6f",an-1.0);
    return 0;
}
