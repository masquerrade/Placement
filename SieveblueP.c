#include<stdio.h>
void prm(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    a[0]=a[1]=0;
    for(int i=2;a[i]*a[i]<n;i++){
        if(a[i]!=0){
            for(int j=a[i]*a[i];j<n;j+=a[i]){
                a[j]=0;
            }
        }
    }
}
int main(){
    int a[10001];
    
    int l;
    scanf("%d",&l);
    //printf("Begin");
    prm(a,10001);
    for(int i=0;i<=l;i++){
        if(a[i]!=0){
            printf("%d ",a[i]);
        }
    }
    return 0;
}
