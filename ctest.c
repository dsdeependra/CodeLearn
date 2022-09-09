#include<stdio.h>
int main(){
    // int arr[2][2][2] = {10,2,3,4,5,6,7,8};
    // int *p,*q;
    // p = &arr[1][1][1];
    // q= (int *)arr;
    // printf("%u %u %u %d\n",arr,*arr,**arr,***arr);
    // printf("%d %d\n",*p,*q);

    // float i = 10,*j;

    // void *k;
    // k = &i;
    // j = k;



    //k++;

    int arr[3] = {256,3,4};
    char *p;
    p = (char *)arr;

    printf("%u %d\n",p,*p);

    p=p+1;
    printf("%u %d\n",p,*p);

    p=p+1;
    printf("%u %d\n",p,*p);
    p=p+1;
    printf("%u %d\n",p,*p);
    p=p+1;
    printf("%u %d\n",p,*p);

    return 0;
}