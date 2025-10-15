#include <stdio.h>
//Khai bao
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;
//Ham nhap, xuat
void Read_Data(recordtype a[],int *n)
{
	FILE *f;
	f=fopen("data.txt","r");
	int i=0;
	if(f!=NULL)
	while (!feof(f)){
		fscanf(f,"%d %f",&a[i].key,&a[i].otherfields);
		i++;
	} else printf("Loi mo file\n");
	fclose(f);
	*n=i;
}

void Print_Data(recordtype a[],int n)
{
	int i;
	for (i=0; i<n;i++){
		printf("%3d %5d %8.2f \n", i+1,a[i].key, a[i].otherfields);
	}
}

//Ham Swap

void Swap(recordtype &a,recordtype &b)
{
	recordtype c;
	c=a;
	a=b;
	b=c;
}

// Selection Sort

void Selection_Sort(recordtype a[], int n)
{
	int i,j,lowindex;
	keytype lowkey;
	for(int i=0; i<=n-2;i++){
		lowkey=a[i].key;
		lowindex=i;
	for (int j=i+1;j<=n-1;j++){
		if(lowkey>a[j].key){
			lowindex =j;
			lowkey=a[j].key;
		}
	}
	Swap(a[i],a[lowindex]);
}
}

//InsertSort

void InsertSort(recordtype a[], int n)
{
	int i,j;
	for(i=0;i<=n-1;i++){
		j=i;
		while((a[j].key<=a[j-1].key)&&(j!=0))
		{
			Swap(a[j], a[j-1]);
			j--;
		}
	}
	
}

// BubleSort
void BubleSort(recordtype a[],int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j-1].key>a[j].key) Swap(a[j-1],a[j]);
		}
	}
}

//Ham main
main(){
	recordtype a[100];
	int n;
	printf("Thuat toan Selection_Sort\n\n");
	Read_Data(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	Print_Data(a,n);
	
	InsertSort(a,n);
	
	printf("Du Lieu sau khi duoc sap xep la:\n");
	Print_Data(a,n);
	
	return 0;
	
}


