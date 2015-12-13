//Calendar Program by-Ravi kumar(14MCMI12) ,Naresh Reddy(14MCMI32) ,Tulasi Dash Ganta(14MCMI).

#include<stdio.h>
#include<string.h>

#define TRUE    1
#define FALSE   0
#define normal    "\x1B[0m"
#define red       "\033[1m\033[31m"
#define green     "\x1B[32m"
#define yellow   "\x1B[33m"
#define blue      "\x1B[34m"
#define magenta   "\x1B[35m"
#define cyan      "\x1B[36m"
#define white     "\x1B[37m"
#define bold      "[1m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

char *months[]={ " ","January","February","March","April","May","June","July","August","September","October","November","December"};
char days[7][50] = {"Sun","Mon","Tus","Wed","Thu","Fri","Sat"};

int cal[37][13];

int jan[7][6];
int feb[7][6];
int mar[7][6];
int apr[7][6];
int may[7][6];
int jun[7][6];
int jul[7][6];
int aug[7][6];
int sep[7][6];
int oct[7][6];
int nov[7][6];
int des[7][6];

int input_year; // to print input year

int inputyear(void)
{
	int year;
	
	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	input_year = year;
	return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	
	return daycode;
}


int determineleapyear(int year)
{
	if( (year% 4 == FALSE && year%100 != FALSE ) || ( year%400 == FALSE) )
	{
		days_in_month[2] = 29;
		return TRUE;
	
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}
int daycodeFun(int daycode,int month)
	{
		daycode = ( daycode + days_in_month[month] ) % 7;
		
		return daycode;
	}

//Calendar format -1
void monthfunction1(int month,int daycode,int array[7][6]){
	int count=1,i,j;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			if(i==0){
				if(j<daycode){
					array[j][i]=0;
				} else {
					array[j][i] = count;
					count++;
				}
			} else {
				if(count <= days_in_month[month]){
					array[j][i] = count;
					count++;
				} else {
					array[j][i] =0;
				}
			}
			}
	}
}	

void calendar1(int year, int daycode)
{
	//int month, day;
	     int daycode1 = daycode;
	     int daycode2=daycodeFun(daycode1,1);
	     int daycode3=daycodeFun(daycode2,2);
	     int daycode4=daycodeFun(daycode3,3);
	     int daycode5=daycodeFun(daycode4,4);				
             int daycode6=daycodeFun(daycode5,5);	
             int daycode7=daycodeFun(daycode6,6);
             int daycode8=daycodeFun(daycode7,7);
             int daycode9=daycodeFun(daycode8,8);
             int daycode10=daycodeFun(daycode9,9);
             int daycode11=daycodeFun(daycode10,10);
             int daycode12=daycodeFun(daycode11,11);
	int daycode_array[13] = {0,daycode1,daycode2,daycode3,daycode4,daycode5,daycode6,daycode7,daycode8,daycode9,daycode10,daycode11,daycode12};	


	int i,j;


	   monthfunction1(1,daycode_array[1],jan);
	   monthfunction1(2,daycode_array[2],feb);
	   monthfunction1(3,daycode_array[3],mar);
	   monthfunction1(4,daycode_array[4],apr);	
	   monthfunction1(5,daycode_array[5],may);	
	   monthfunction1(6,daycode_array[6],jun);	
	   monthfunction1(7,daycode_array[7],jul);	
	   monthfunction1(8,daycode_array[8],aug);	
	   monthfunction1(9,daycode_array[9],sep);	
	   monthfunction1(10,daycode_array[10],oct);	
	   monthfunction1(11,daycode_array[11],nov);	
	   monthfunction1(12,daycode_array[12],des);	
	
	   printf("%s\t\t\t\t\t\t---------------------------\t\t\t\n",BOLDCYAN);
	   printf("\t\t\t\t\t\t %s|| \t Year : %d \t|| \t\t\t\t\t \n",BOLDCYAN,input_year);// year printing
	   printf("\t\t\t\t\t\t---------------------------\t\t\t\n");

           printf("%s\t\tJanuary \t \t \t \t%sFebruary\t\t \t \t%sMarch  \n",blue,blue,blue);

printf("%s\t\t-------------------------------\t\t---------------------------------\t---------------------------------\n",red);
	for(i=0;i<7;i++){
		printf("\t\t%s%s|  ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(jan[i][j] == 0){
				printf("     ");
			}else{
				if(jan[i][j]>9)
					printf("%s%d   ",white,jan[i][j]);
				else
					printf("%s%d    ",white,jan[i][j]);
			}
		}
		printf("\t");
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(feb[i][j] == 0){
				printf("     ");
			}else{
				if(feb[i][j]>9)
					printf("%s%d   ",white,feb[i][j]);
				else
					printf("%s%d    ",white,feb[i][j]);
			}
		}
		printf("\t");
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(mar[i][j] == 0){
				printf("     ");
			}else{
				if(mar[i][j]>9)
					printf("%s%d   ",white,mar[i][j]);
				else
					printf("%s%d    ",white,mar[i][j]);
			}
		}
		printf("\n");
	}	
printf("\n");

           printf("%s\t\tApril \t \t \t \t \t%sMay\t \t \t \t \t%sJune  \n",blue,blue,blue);

printf("%s\t\t-------------------------------\t\t---------------------------------\t---------------------------------\n",red);	
	for(i=0;i<7;i++){
		printf("\t\t%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(apr[i][j] == 0){
				printf("     ");
			}else{
				if(apr[i][j]>9)
					printf("%s%d   ",white,apr[i][j]);
				else
					printf("%s%d    ",white,apr[i][j]);
			}
		}
		printf("\t");		
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(may[i][j] == 0){
				printf("     ");
			}else{
				if(may[i][j]>9)
					printf("%s%d   ",white,may[i][j]);
				else
					printf("%s%d    ",white,may[i][j]);
			}
		}
		printf("\t");		
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(jun[i][j] == 0){
				printf("     ");
			}else{
				if(jun[i][j]>9)
					printf("%s%d   ",white,jun[i][j]);
				else
					printf("%s%d    ",white,jun[i][j]);
			}
		}
		printf("\n");
	}
printf("\n");
printf("\t\t%sJuly \t \t \t \t \t %sAugust \t\t\t\t%sSeptember  \n",blue,blue,blue);
printf("%s\t\t-------------------------------\t\t---------------------------------\t---------------------------------\n",red);	
	for(i=0;i<7;i++){
		printf("\t\t%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(jul[i][j] == 0){
				printf("     ");
			}else{
				if(jul[i][j]>9)
					printf("%s%d   ",white,jul[i][j]);
				else
					printf("%s%d    ",white,jul[i][j]);
			}
		}
		printf("\t");		
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(aug[i][j] == 0){
				printf("     ");
			}else{
				if(aug[i][j]>9)
					printf("%s%d   ",white,aug[i][j]);
				else
					printf("%s%d    ",white,aug[i][j]);
			}
		}
		printf("\t");		
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(sep[i][j] == 0){
				printf("     ");
			}else{
				if(sep[i][j]>9)
					printf("%s%d   ",white,sep[i][j]);
				else
					printf("%s%d    ",white,sep[i][j]);
			}
		}
		printf("\n");
	}
printf("\n");
printf("\t\t%sOctober \t\t\t\t%sNovember \t\t\t\t%sDecember  \n",blue,blue,blue);
printf("%s\t\t-------------------------------\t\t---------------------------------\t---------------------------------\n",red);	
	for(i=0;i<7;i++){
		printf("\t\t%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(oct[i][j] == 0){
				printf("     ");
			}else{
				if(oct[i][j]>9)
					printf("%s%d   ",white,oct[i][j]);
				else
					printf("%s%d    ",white,oct[i][j]);
			}
		}
		printf("\t");
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(nov[i][j] == 0){
				printf("     ");
			}else{
				if(nov[i][j]>9)
					printf("%s%d   ",white,nov[i][j]);
				else
					printf("%s%d    ",white,nov[i][j]);
			}
		}
		printf("\t");
		printf("%s%s| ",yellow,days[i]);
		for(j=0;j<6;j++){
			if(des[i][j] == 0){
				printf("     ");
			}else{
				if(des[i][j]>9)
					printf("%s%d   ",white,des[i][j]);
				else
					printf("%s%d    ",white,des[i][j]);
			}
		}
		printf("\n");
	}		

}

//Calendar format-2

void monthfunction2(int month,int daycode){
	int count=1,i,j;
	for(i=0;i<37;i++){
		for(j=month;j<(month+1);j++){
			if(i < daycode){
				cal[i][j] = 0;
			} else {
				if(count <= days_in_month[j]){
					cal[i][j] = count;
					count++;
				} else {
					cal[i][j] = 0;
				}
			}
		}
	}
}

void calendar2(int year, int daycode)
{
	
	     int daycode1 = daycode;
	     int daycode2=daycodeFun(daycode1,1);
	     int daycode3=daycodeFun(daycode2,2);
	     int daycode4=daycodeFun(daycode3,3);
	     int daycode5=daycodeFun(daycode4,4);				
             int daycode6=daycodeFun(daycode5,5);	
             int daycode7=daycodeFun(daycode6,6);
             int daycode8=daycodeFun(daycode7,7);
             int daycode9=daycodeFun(daycode8,8);
             int daycode10=daycodeFun(daycode9,9);
             int daycode11=daycodeFun(daycode10,10);
             int daycode12=daycodeFun(daycode11,11);
	int daycode_array[13] = {0,daycode1,daycode2,daycode3,daycode4,daycode5,daycode6,daycode7,daycode8,daycode9,daycode10,daycode11,daycode12};	


	int i,j;

	for(i=1;i<=12;i++){
		monthfunction2(i,daycode_array[i]);
	}
	printf("\t\t\t\t\t%s---------------------------\t\t\t\t\t \n",white);
	printf("\t\t\t\t\t||       %sYear :%s %d\t%s|| \n",yellow,red,input_year,white);
	printf("\t\t\t\t\t%s---------------------------\t\t\t\t\t \n",white);	
printf(" \t \t%s-----------------------------------------------------------------------------------------------------\n",white);
 printf("\t\t      %sJan |\t%sFeb |\t%sMar |\t%sApr |\t%sMay |\t%sJun |\t%sJul |\t%sAug |\t%sSep |\t%soct |\t%sNov |\t%sDec \n",blue,yellow,magenta,green,yellow,yellow,yellow,yellow,normal,red,cyan,white);
printf(" \t \t-----------------------------------------------------------------------------------------------------\n");
	int d;
	for(i=0;i<37;i++){
		d = i%7;

		if(i<8){
			printf("\t \t| %s%s %s|\t",cyan,days[d],yellow);
		}else if(i>7&&i<15){
			printf("\t \t| %s%s %s|\t",magenta,days[d],yellow);
		}else if(i>14&&i<22){
			printf("\t \t| %s%s %s|\t",green,days[d],yellow);
		}else if(i>21&&i<28){
			printf("\t \t| %s%s %s|\t",blue,days[d],yellow);
		}else if(i>27&&i<36){
			printf("\t \t| %s%s %s|\t",yellow,days[d],yellow);
		} else{
			printf("\t \t| %s%s %s|\t",white,days[d],yellow);		
		}
		

		for(j=1;j<13;j++){
				if(cal[i][j] == 0){
					printf("%s*  %s|    ",green,yellow);
				} else {
					if(cal[i][j]>9)
						printf("%s%d %s|\t",normal,cal[i][j],yellow);
					else
						printf("%s%d  %s|\t",normal,cal[i][j],yellow);	
				}
		}
		printf("\n  ");
	}
printf(" \t \t--------------------------------------------------------------------------------------------------------\n");

}
	
//Calender format -3
int datePrint(int month,int daycode,int count)
{
		int k;
		if(count==1){
		   // Correct the position for the first Row of Each Month only 
		   for (count=1; count<= 1 + daycode * 5; count++ ){
			 printf(" ");
		   }
		   for ( count = 1;  ( count+ daycode ) % 8 > 0; count++ )
		     {
			   printf("%d ",count);
			
			// Is day before Sat? Else start next line Sun.
			if ( ( count+ daycode ) % 8 > 0 )
				printf("   " );
	        }
	       }
	    else//Print Month date form 2nd row onwards.
	        { 
		    for (k=1;  k< 8 ; k++) {
				if(count<=days_in_month[month])
				{
			     printf("%2d", count);
			     printf("   ");
			     count++;
			    }
			    else//print space for last row  month.
				printf("     " );
			}
		   }
		return count;
}
void calendar3(int year)
{
	    int i,k,daycode1,daycode2,daycode3,newdaycode;
	    int dayCount1,dayCount2,dayCount3;
    	 
		for(k=1;k<=12;k=k+3)
		 {
			 dayCount1=1;
             dayCount2=1;
             dayCount3=1;
             if(k==1)
             {
              daycode1=determinedaycode(year);
              daycode2=daycodeFun(daycode1,k);
              newdaycode=daycode3=daycodeFun(daycode2,k+1);
             }
             else
             {
			  daycode1=daycodeFun(newdaycode,k-1);
              daycode2=daycodeFun(daycode1,k);
              newdaycode=daycode3=daycodeFun(daycode2,k+1);
             }
			 printf(" \t%s%s     \t\t\t\t\t\%s%s      \t\t\t\t\t\t%s%s%s    \n", blue,months[k],yellow,months[k+1],green,months[k+2],white);
			 printf("%s--------------------------------\t\t--------------------------------\t\t---------------------------------\n",red);
		     printf("%sSun  %sMon  %sTue  %sWed  %sThu  %sFri  %sSat",red,green,yellow,blue,cyan,magenta,normal);
		     printf("\t\t%sSun  %sMon  %sTue  %sWed  %sThu  %sFri  %sSat",red,green,yellow,blue,cyan,magenta,normal);
		     printf("\t\t%sSun  %sMon  %sTue  %sWed  %sThu  %sFri  %sSat\n",red,green,yellow,blue,cyan,magenta,normal);
		     
		 for(i=1;i<=6;i++)
		  {  
	        dayCount1=datePrint(k,daycode1,dayCount1);
	        printf("\t\t");
	        dayCount2=datePrint(k+1,daycode2,dayCount2);
	        printf("\t\t");
	        dayCount3=datePrint(k+2,daycode3,dayCount3);
	        printf("\n") ;
	      }
	     
	    }
}


int main()
	{
	  int opt;
	  char ch='y';
	  int year, daycode;

	  do	
	   {
         printf("\n %sProgram for  CALENDAR in Three FORMAT....\n",BOLDRED) ;
	     printf("\n1.%sCALENDAR FORMAT FIRST::\n",BOLDCYAN) ;
         printf("\n2.%sCALENDAR FORMAT SECOND::\n",blue) ;
	     printf("\n3.%sCALENDAR FORMAT THIRD::\n",green) ;
         printf("\n4.%sEXIT::\n ",BOLDRED) ;
         
	     printf("\n%sEnter your Options:",green);
             scanf("%d",&opt) ;

	    switch(opt)
	  	{
		  case 1:year = inputyear();
	             daycode = determinedaycode(year);
	             determineleapyear(year);
	             calendar1(year, daycode);
	             printf("\n");
	             break;

		  case 2:	
	             year = inputyear();
	             daycode = determinedaycode(year);
	             determineleapyear(year);
	             calendar2(year, daycode);
	             printf("\n");
                        break;

	 	  case 3:year = inputyear();
	 	         printf("\t\t\t\t\t%s---------------------------\t\t\t\t\t \n",white);
	             printf("\t\t\t\t\t||       %sYear :%s %d\t%s|| \n",yellow,red,year,white);
	             printf("\t\t\t\t\t%s---------------------------\t\t\t\t\t \n",white);	
	             determineleapyear(year);
	             calendar3(year);
	             printf("\n");
                        break;

		  case 4: exit(0);
                   

		 default:printf("\n Invalid Choice ..\n") ;
                        
		}printf("\nDo you want to continue ?? [y/n]:") ;
		 scanf("\n%c",&ch) ;
	   }while(ch == 'y' || ch == 'Y');
	   
	return 0;    
	}
