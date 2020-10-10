#include<stdio.h>
#include<stdlib.h>
void sumsub(int**a,int m,int n,int k){
    int** b=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        b[i]=(int *)malloc(sizeof(int)*n);
    }
    b[0][0]=a[0][0];
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",b[i][j]); 
        }
        printf("\n");
    }*/
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]); 
        }
        printf("\n");
    }*/
    for(int i=1;i<m;i++){
        b[i][0]=b[i-1][0]+a[i][0];
    }
    for(int i=1;i<n;i++){
        b[0][i]=b[0][i-1]+a[0][i];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
        }
    }
    //a=b;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",b[i][j]); 
        }
        printf("\n");
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //printf("%d ",b[i][j]); 
            if(i-k>=0&&j-k>=0){
                ans=b[i][j]-b[i-k][j]-b[i][j-k]+b[i-k][j-k];
                printf("%d ",ans);                
            }
            else if(i-k==-1&&j-k==-1){
                ans=b[i][j];
                printf("%d ",ans);               
            }
            else if(i-k>=0&&j-k==-1){
                ans=b[i][j]-b[i-k][j];
                printf("%d ",ans);
            }
            else if(j-k>=0&&i-k==-1){
                ans=b[i][j]-b[i][j-k];
                printf("%d ",ans);
            }
             //printf("%d ",ans);
        }
        printf("\n");
    }
}
int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    int** a=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        a[i]=(int *)malloc(sizeof(int)*n);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/

    sumsub(a,m,n,k);
}