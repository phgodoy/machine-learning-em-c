#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int main() {
	float v;
	int i=0;
	int j,l;
	int n,m;
	int cs;
	float er;
	float I0[15];
	float O0[15];
	float I1[15];
	float O1[15];
	float I2[13];
	float O2[13];
	float w1[15][14];
	float w2[15][13];
	float nw1[15][14];
	float nw2[15][13];
	float vw1[15][14];
	float vw2[15][13];
	float d2[13];
	float d1[14];
	
	float E1[2000];
	float E2[2000];
	float E3[2000];
	float E4[2000];
	float E5[2000];
	float E6[2000];
	float E7[2000];
	float E8[2000];
	float E9[2000];
	float E10[2000];
	float E11[2000];
	float E12[2000];
	float t1[2000];
	float t2[2000];
	float t3[2000];
	float t4[2000];
	float t5[2000];
	float t6[2000];

	FILE *in;
	
	if ((in =fopen("data_vinhos_n.txt", "rt"))== NULL) {
		printf("Falha ao abrir o arquivo.\n");
		return 1;
	}
	
	
	while(!feof(in)){
		fscanf(in,"%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f",&E1[i],&E2[i],&E3[i],&E4[i],&E5[i],&E6[i],&E7[i],&E8[i],&E9[i],&E10[i],&E11[i],&E12[i],&t1[i],&t2[i],&t3[i],&t4[i],&t5[i],&t6[i]);
		
		i++;
	}
		
	for(j=0;j<(i-1);j++){
		printf("%d %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",j,E1[j],E2[j],E3[j],E4[j],E5[j],E6[j],E7[j],E8[j],E9[j],E10[j],E11[j],E12[j],t1[j],t2[j],t3[j],t3[j],t4[j],t5[j],t6[j]);
	}
	
	fclose(in);
	getch();
	
	for(j=1;j<=6;j++){
		for(i=1;i<=13;i++){
			w1[i][j]=((rand()%100)/10.0)-5.0;
			vw1[i][j]=0.0;
		}
	}
	
	for(l=1;l<=6;l++){
		for(j=1;j<=7;j++){
			w2[j][l]=((rand()%100)/10.0)-5.0;
			vw2[j][l]=0.0;
		}
	}
	
	for(m=0;m<=1000;m++){
		er=0.0;
		for(n=0;n<=10000;n++){
				
			cs=rand()%150;
			
			
			I0[1]=E1[cs];
			I0[2]=E2[cs];
			I0[3]=E3[cs];
			I0[4]=E4[cs];
			I0[5]=E5[cs];
			I0[6]=E6[cs];
			I0[7]=E7[cs];
			I0[8]=E8[cs];
			I0[9]=E9[cs];
			I0[10]=E10[cs];
			I0[11]=E11[cs];
			I0[12]=E12[cs];
			I0[13]=1.0;
			
			O0[1]=I0[1];
			O0[2]=I0[2];
			O0[3]=I0[3];
			O0[4]=I0[4];
			O0[5]=I0[5];
			O0[6]=I0[6];
			O0[7]=I0[7];
			O0[8]=I0[8];
			O0[9]=I0[9];
			O0[10]=I0[10];
			O0[11]=I0[11];
			O0[12]=I0[12];
			O0[13]=I0[13];
			
			for(j=1;j<=6;j++){
				I1[j]=0.0;
				
				for(i=1;i<=13;i++){
					I1[j]+=O0[i]*w1[i][j];
				}
				
				O1[j]=1.0/(1.0+exp(-I1[j]));
			}
			
			I1[7]=1.0;
			O1[7]=I1[7];
			
			for(l=1;l<=6;l++){
				I2[l]=0.0;
				
				for(j=1;j<=7;j++){
					I2[l]+=O1[j]*w2[j][l];
				}
				
				O2[l]=1.0/(1.0+exp(-I2[l]));
			}
			
			
			d2[1]=(t1[cs]-O2[1])*O2[1]*(1.0-O2[1]);
			d2[2]=(t2[cs]-O2[2])*O2[2]*(1.0-O2[2]);
			d2[3]=(t3[cs]-O2[3])*O2[3]*(1.0-O2[3]);
			d2[4]=(t4[cs]-O2[4])*O2[4]*(1.0-O2[4]);
			d2[5]=(t5[cs]-O2[5])*O2[5]*(1.0-O2[5]);
			d2[6]=(t6[cs]-O2[6])*O2[6]*(1.0-O2[6]);
			
			
			d1[1]=O1[1]*(1.0-O1[1])*(d2[1]*w2[1][1]+d2[2]*w2[1][2]+d2[3]*w2[1][3]+d2[4]*w2[1][4]+d2[5]*w2[1][5]+d2[6]*w2[1][6]);
			d1[2]=O1[2]*(1.0-O1[2])*(d2[1]*w2[2][1]+d2[2]*w2[2][2]+d2[3]*w2[2][3]+d2[4]*w2[2][4]+d2[5]*w2[2][5]+d2[6]*w2[2][6]);
			d1[3]=O1[3]*(1.0-O1[3])*(d2[1]*w2[3][1]+d2[2]*w2[3][2]+d2[3]*w2[3][3]+d2[4]*w2[3][4]+d2[5]*w2[3][5]+d2[6]*w2[3][6]);
			d1[4]=O1[4]*(1.0-O1[4])*(d2[1]*w2[4][1]+d2[2]*w2[4][2]+d2[3]*w2[4][3]+d2[4]*w2[4][4]+d2[5]*w2[4][5]+d2[6]*w2[4][6]);
			d1[5]=O1[5]*(1.0-O1[5])*(d2[1]*w2[5][1]+d2[2]*w2[5][2]+d2[3]*w2[5][3]+d2[4]*w2[5][4]+d2[5]*w2[5][5]+d2[6]*w2[5][6]);
			d1[6]=O1[6]*(1.0-O1[6])*(d2[1]*w2[6][1]+d2[2]*w2[6][2]+d2[3]*w2[6][3]+d2[4]*w2[6][4]+d2[5]*w2[6][5]+d2[6]*w2[6][6]);
			d1[7]=O1[7]*(1.0-O1[7])*(d2[1]*w2[7][1]+d2[2]*w2[7][2]+d2[3]*w2[7][3]+d2[4]*w2[7][4]+d2[5]*w2[7][5]+d2[6]*w2[7][6]);
			
			for(l=1;l<=6;l++){
				for(j=1;j<=7;j++){
					nw2[j][l]= w2[j][l]+0.5*d2[l]*O1[j]+0.5*vw2[j][l];
					vw2[j][l]=nw2[j][l]-w2[j][l];
					w2[j][l]=nw2[j][l];
				}
			}
		
			for(j=1;j<=6;j++){
				for(i=1;i<=13;i++){
					nw1[i][j]= w1[i][j]+0.5*d1[j]*O0[i]+0.5*vw1[i][j];
					vw1[i][j]=nw1[i][j]-w1[i][j];
					w1[i][j]=nw1[i][j];
				}
			}
			
			er+= (t1[cs]-O2[1])*(t1[cs]-O2[1])+(t2[cs]-O2[2])*(t2[cs]-O2[2])+(t3[cs]-O2[3])*(t3[cs]-O2[3])+(t4[cs]-O2[4])*(t4[cs]-O2[4])+(t5[cs]-O2[5])*(t5[cs]-O2[5])+(t6[cs]-O2[6])*(t6[cs]-O2[6]);
		}
		er=er/10000.0;
		printf("%d %f \n",m,er);
	}
	
	for(j=1;j<=6;j++){
		
		for(i=1;i<=13;i++){
			printf("%f ",w1[i][j]);
		}
		
		printf("\n");
	}
	
	for(l=1;l<=6;l++){
		
		for(j=1;j<=7;j++){
			printf("%f ",w2[j][l]);
		}
		
		printf("\n");
	}
	
	for(m=0;m<=149;m++){
		I0[1]=E1[m];
		I0[2]=E2[m];
		I0[3]=E3[m];
		I0[4]=E4[m];
		I0[5]=E5[m];
		I0[6]=E6[m];
		I0[7]=E7[m];
		I0[8]=E8[m];
		I0[9]=E9[m];
		I0[10]=E10[m];
		I0[11]=E11[m];
		I0[12]=E12[m];
		I0[13]=1.0;
		
		O0[1]=I0[1];
		O0[2]=I0[2];
		O0[3]=I0[3];
		O0[4]=I0[4];
		O0[5]=I0[5];
		O0[6]=I0[6];
		O0[7]=I0[7];
		O0[8]=I0[8];
		O0[9]=I0[9];
		O0[10]=I0[10];
		O0[11]=I0[11];
		O0[12]=I0[12];
		O0[13]=I0[13];
		
		for(j=1;j<=6;j++) {
			I1[j]=0.0;
			
			for(i=1;i<=13;i++) {
				I1[j]+=O0[i]*w1[i][j];
			}
			
			O1[j]=1.0/(1.0+exp(-I1[j]));
		}
		I1[7]=1.0;
		O1[7]=I1[7];
		
		for(l=1;l<=6;l++){
			I2[l]=0.0;
			
			for(j=1;j<=7;j++){
				I2[l]+=O1[j]*w2[j][l];
			}
			
			O2[l]=1.0/(1.0+exp(-I2[l]));
		}
		printf("%d %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",m,E1[m],E2[m],E3[m],E4[m],E5[m],E6[m],E7[m],E8[m],E9[m],E10[m],E11[m],E12[m],O2[1],O2[2],O2[3],O2[4],O2[5],O2[6]);
	}

}
