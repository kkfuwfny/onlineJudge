#include<stdio.h>
#include<string.h>

int leapYear(int yy){

	return ((yy %4 == 0 && yy % 100 != 0) || (yy % 400 == 0));
}

int main(){
	char week[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	char month[13][15]={"0","January","February","March","April",
		"May","June","July","August","September","October",
		"November","December"
	};
	
	int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	

	int yy,dd,imm;
	char mm[15];
	int sumDay = 0;
	int i,n;
	while(scanf("%d %s %d",&dd,mm,&yy),n){
		sumDay = 0;
		for(i=1;i<13;i++){
			if(strcmp(mm,month[i]) == 0){
				imm = i;
				break;
			}
		}
		//printf("month = %d\n",imm);
		sumDay = (yy - 1) * 365;

		for(i=1;i<yy;i++){
			if(leapYear(i)){
				sumDay += 1;
				//printf("leapYear = %d\n",i);
			}
		}
		
		for(i=1;i<imm;i++){
			sumDay += day[i];
			//printf("%d\n",i);
		}
		sumDay += dd;

		if((imm > 2) && leapYear(yy))
			sumDay += 1;
		//printf("sumDay = %d \n",sumDay);
		//printf("%d %s %d\n",yy,mm,dd);
		puts(week[sumDay % 7]);
		putchar(10);

	}
	return 0;
}