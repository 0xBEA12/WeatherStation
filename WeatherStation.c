#include <stdio.h>
#include <time.h>

// define the size of the array
#define ARRAY 21

// structure for transmogrifier
struct transmogrifier
{
//temperature
   int t;
//valve pressure
   float vp;

// liquid sodium flow
   float sf;

   //liquid sodium temperature
   float st;
};

// function to generate random numbers
void generateRandom(float *vp,float *sf,float *st);

// function to display the array
void displayArray(struct transmogrifier *transmog);


int main()
{
   srand(time(NULL));

   // define an array of structure of size 21
   struct transmogrifier transmog[ARRAY];

   // define the required variables
   float vp=0,st=0,sf=0,difference=0;
   int temp=-10,index=0,count=0,round=0;




   // loop until the difference is at least 150 between current and the previous once
   while(difference <= 150)
   {

       index = index % ARRAY;

       generateRandom(&vp, &sf, &st);

       transmog[index].t = temp;

       if(temp == 10)
       {
           temp = -10;

           round++;
       }

       else
           temp = temp + 1;

       transmog[index].vp = vp;
       transmog[index].sf = sf;
       transmog[index].st = st;

       if(count == 0)
       {
           count++;
       }

       else
       {
           difference = (transmog[index].vp - transmog[index - 1].vp);
       }


       index++;
   }


   int i = 0;


   if(round<1)
   {
       // loop until the index reaches the SIZE
       while(index < ARRAY)
       {
           index = index % ARRAY;

           generateRandom(&vp, &sf, &st);

           // set the values of the transmogrifier instance with the above obtained values
           transmog[index].t = temp;
           transmog[index].vp = vp;
           transmog[index].sf = sf;
           transmog[index].st = st;

           temp = temp + 1;

           index++;
       }
   }

   else
   {
       for(i = 0; i < 10; i++)
       {
           index = index % ARRAY;

           generateRandom(&vp, &sf, &st);
           transmog[index].t = temp;
           transmog[index].vp = vp;
           transmog[index].sf = sf;
           transmog[index].st = st;

           // if the temperature is 10
           // reset the temperature to -10
           if(temp == 10)
               temp = -10;

           // otherwise increment the temperature and index
           else
               temp = temp + 1;


           index++;
       }
   }

   // call the displayArray() function by passing the transmogrifier
   displayArray(transmog);
   getchar();
   getchar();
   return 0;
}

// function to generate the random values
void generateRandom(float *vp, float *sf, float *st)
{
   *vp = (int)(rand() % (701 - 500)) + 500;

   *sf = (int)(rand() % (21 - 10))+10;

   *st = (int)(rand() % (601 - 500))+500;
}

// function to display the populated array values
void displayArray(struct transmogrifier *transmog)
{
   int i = 0;

   printf("Time \t vp \t sf \t st\n");
   printf("(secs) \t (psi) \t (gpm) \t (Deg C)\n");
   printf("=================================\n");
   for(i = 0; i < ARRAY; i++)
   {
       printf("%d\t%.2f\t%.2f\t%.2f\n", transmog[i].t, transmog[i].vp, transmog[i].sf, transmog[i].st);
   }
   printf("=================================\n");

   {
FILE *output;

    output=fopen("output.txt","w");

   fprintf(output,"Time \t tp \t tf \t tt\n");
   fprintf(output,"(secs) \t (psi) \t (gpm) \t (Deg C)\n");
   fprintf(output,"=================================\n");
   for(i = 0; i < ARRAY; i++)
   {
       fprintf(output,"%d\t%.2f\t%.2f\t%.2f\n", transmog[i].t, transmog[i].vp, transmog[i].sf, transmog[i].st);
   }
   fprintf(output,"=================================\n");
fclose(output);
}
}

