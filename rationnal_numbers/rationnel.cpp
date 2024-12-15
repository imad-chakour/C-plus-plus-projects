#include"rationnel.h"

RAT saisir(RAT R){
    printf("entrer un num:");
    scanf("%d",&R.num);
    printf("entrer un denum:");
    scanf("%d",&R.denum);

    return R;
}

void convertion(RAT R){
	double c=0;
	c = (double)R.num/R.denum;
	printf("Convertion d'un rationnel en un reel: %lf",c);
}

void affichage(RAT R){
    printf("le numerateur est: %d\n",R.num);
    printf("le denumerateur est: %d",R.denum);
}

void invertion(RAT R){
	int A;
	A = R.num;
	R.num = R.denum;
	R.denum = A;
	printf("l'invertion numerateur: %d\nl'invertion denumerateur: %d",R.num,R.denum);
}

void PGCD(RAT R) {
    int t1[100],t2[100];
    int i,n1,n2,j=0;
    int max;
    for(i=1;i<=R.num/2+1;i++){
        if(R.num%i==0){
            t1[j]=R.num/i;
            j++;
        }
    }
    n1=j;
    printf("les diviseurs de %d sont :",R.num);
    for(i=0;i<n1;i++){
        printf("%d ",t1[i]);
    }
    
    j=0;
    for(i=1;i<=R.denum/2+1;i++){
        if(R.denum%i==0){
            t2[j]=R.denum/i;
            j++;
        }
    }
    n2=j;
    printf("\nles diviseurs de %d sont :",R.denum);
    for(i=0;i<n2;i++){
        printf("%d ",t2[i]);
    }

}

