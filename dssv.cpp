#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<stddef.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<graphics.h>
typedef struct sinhvien{
	char ten[30];
	char gt[5];
	int tuoi;
	float dt,dl,dh,dtb;
}sv;
void nhapN(sv a[],int n);
void xuatN(sv a[],int n);
void sapxepN(sv a[],int n);
void xeploaiN(sv a[],int n);
void xuatFILE(sv a[],int n,char filename[]);
void fixN(sv a[],int n);
int main(){

	int n,key;
	char filename[]="DSSV.txt";
	bool DaNhap=false;
	SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), 10);
	SetConsoleOutputCP(65001);//viet tieng viet 
	do{int d=100;
    
		printf("nhap so luong sinh vien: ");
		scanf("%d",&n);
	}while(n<=0);
	sv a[n];
	while(true){
		SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ),253);
		system("cls");
		printf("**********************************************\n");
		printf("***     CHUONG TRINH QUAN LI SINH VIEN     ***\n");
		printf("***     Bam tu 0 den 5 de thuc hien        ***\n");
		printf("***     1. Nhap du lieu                    ***\n");
		printf("***     2. In danh sach sinh vien          ***\n");
		printf("***     3. Sap xep sinh vien theo DTB      ***\n");
		printf("***     4. Xep loai sinh vien              ***\n");
		printf("***     5. Xuat danh sach sinh vien        ***\n");
		printf("***     6. Sua thong tin sinh vien         ***\n");
		printf("***     0. Thoat                           ***\n");
		printf("**********************************************\n");
		printf("***     Hay nhap lua chon cua ban          ***\n");
		scanf("%d",&key);
	
		switch(key){
			case 1:
				printf("Ban da chon nhap danh sach sinh vien!\n");
				nhapN(a,n);
				printf("Ban da nhap thanh cong!\n");
				printf("An bat ki nut nao de tiep tuc!");
				DaNhap=true;
				getch();
				break;
			case 2:
				if(DaNhap){
					printf("Ban da chon in danh sach sinh vien!\n");
					xuatN(a,n);
				}
				else printf("Nhap danh sach sinh vien truoc!\n");
				printf("An bat ki nut nao de tiep tuc!");
				getch();
				break;
			case 3:
				if(DaNhap){
					printf("Ban da chon sap xep danh sach sinh vien thao DTB\n");
					sapxepN(a,n);
					xuatN(a,n);
				}
				else printf("Nhap danh sach sinh vien truoc!\n");
				printf("An bat ki nut nao de tiep tuc!");
				getch();
				break;
			case 4:
				if(DaNhap){
					printf("Ban da chon xep loai sinh vien!\n");
					xeploaiN(a,n);
				}	
				else printf("Nhap danh sach sinh vien truoc!\n");
				printf("An bat ki nut nao de tiep tuc!");
				getch();
				break;
			case 5:
				if(DaNhap){
					printf("Ban da chon xuat danh sach sinh vien\n");
					xuatFILE(a,n,filename);
				}
				else {
					printf("Nhap danh sach sinh vien truoc!\n");
					printf("An bat ki nut nao de tiep tuc!");
					getch();
					break;
					}
				printf("Ban da thanh cong xuat danh sach sinh vien vao File %s\n",filename);
				printf("An bat ki nut nao de tiep tuc!");
				getch();
				break;
			case 6:
				if(DaNhap){
					printf("Ban da chon sua danh sach sinh vien\n");
					fixN(a,n);
					xuatN(a,n);
				}
				else printf("Nhap danh sach sinh vien truoc!\n");
				printf("An bat ki nut nao de tiep tuc!");
				getch();
				break;
			case 0:
				printf("Ban da chon thoat chuong trinh");
				getch();
				return 0;
			default:
				printf("chuong trinh khong co chuc nang nay");
				getch();
				break;
		}
	}    
}
void DTB(sv&SV){
	SV.dtb=(SV.dt+SV.dl+SV.dh)/3;
}
void nhap(sv&SV){
	printf("Nhap ten: ");fflush(stdin);gets(SV.ten);
	printf("Nhap gioi tinh: ");gets(SV.gt);
	printf("Nhap tuoi: ");scanf("%d", &SV.tuoi);
	printf("Nhap diem toan-ly-hoa: ");
	scanf("%f%f%f",&SV.dt,&SV.dl,&SV.dh);
	DTB(SV);
}
void nhapN(sv a[],int n){
	printf("\n____________________________________\n");\
	for(int i=0;i<n;i++){
		printf("nhap thong tin cho sinh vien thu %d: \n",i+1);
		nhap(a[i]);
	}
	printf("\n____________________________________\n");
}
void xuat(sv SV){
	printf("\nHo va ten: %s",SV.ten);
	printf("\nGioi tinh: %s",SV.gt);
	printf("\nTuoi: %d",SV.tuoi);
	printf("\nDiem toan-ly-hoa lan luot la: %.2f - %.2f - %.2f",SV.dt,SV.dl,SV.dh);
	printf("\nDiem trung binh la: %.2f",SV.dtb);
}
void xuatN(sv a[],int n){
printf("\n____________________________________\n");\
	for(int i=0;i<n;i++){
		printf("\nThong tin cho sinh vien thu %d la: \n",i+1);
		xuat(a[i]);
	}
	printf("\n____________________________________\n");
}
void sapxepN(sv a[],int n){
	sv tmp;
	for(int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if(a[i].dtb<a[j].dtb){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
void xeploai(sv SV){
	if(SV.dtb>=8.0)printf("Gioi");
	else if(SV.dtb>=6.5)printf("kha");
	else if(SV.dtb>=5.0)printf("trung binh");
	else if(SV.dtb>=3.5)printf("Yeu");
	else printf("Kem");
}
void xeploaiN(sv a[],int n){
printf("\n____________________________________\n");
	for(int i=0;i<n;i++){
		printf("\nXep loai cua sinh vien thu %d la: ",i+1);
		xeploai(a[i]);
	}
	printf("\n____________________________________\n");	
}
void xuatFILE(sv a[],int n,char filename[]){
	FILE*fp=fopen(filename,"w");
	fprintf(fp,"   %20s%15s%10s%10s%10s%10s%20s\n","Ho va ten","Gioi tinh","Tuoi","Diem toan","Diem ly","Diem hoa","Diem trung binh");
	for(int i=0;i<n;i++)
	fprintf(fp,"%d. %20s%15s%10d%10f%10f%10f%20f\n",i+1,a[i].ten,a[i].gt,a[i].tuoi,a[i].dt,a[i].dl,a[i].dh,a[i].dtb);
	fclose(fp);
}
void fixN(sv a[],int n){
	int i;
	printf("\n____________________________________\n");
	printf("ban muon sua thong tin cua sinh vien thu may: ");
	scanf("%d",&i);
	if(i>n)return;
	nhap(a[i-1]);
	printf("\n____________________________________\n");
}
