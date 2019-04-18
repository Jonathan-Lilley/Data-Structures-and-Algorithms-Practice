#include <iostream>
using namespace std;

int COUNTER = 0;

int *maxCrossSubarray(int A[], int low, int mid, int high){
    int lsum = -99999;
    int sum = 0;
    int mleft = 0;
    for(int i=mid; i>low; i--){
        sum = sum + A[i];
        if(sum > lsum){
            lsum = sum;
            mleft = i;
        }
    }
    int rsum = -99999;
    sum = 0;
    int mright = 0;
    for(int j=mid+1; j<high; j++){
        sum = sum + A[j];
        if(sum > rsum){
            rsum = sum;
            mright = j;
        }
    }
    int *a = new int[3];
    *a = mleft; *(a+1) = mright; *(a+2) = lsum + rsum;
    return a;
}

int *maxSubarray(int A[], int low, int high){
    if(high == low){
        int *a = new int[3];
        *a = low; *(a+1) = high; *(a+2) = A[low];
        return a;
    }
    else{
        int mid = (low+high)/2;
        int *llhs = new int[3];
        llhs = maxSubarray(A, low, mid);
        int *rlhs = new int[3];
        rlhs = maxSubarray(A, mid+1, high);
        int *clhs = new int[3];
        clhs = maxCrossSubarray(A, low, mid, high);
        if(*(llhs+2)>=*(rlhs+2) && *(llhs+2)>=*(clhs+2)){
            return llhs;
        }
        else if(*(rlhs+2)>=*(llhs+2) && *(rlhs+2)>=*(clhs+2)){
            return rlhs;
        }
        else{
            return clhs;
        }
    }
}

int main(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int *MSA = maxSubarray(A, 0, sizeof(A)/sizeof(int));
    for(int i=0; i<3; i++){
        cout << *(MSA+i) << endl;
    }
    return 0;
}