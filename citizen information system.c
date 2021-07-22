#include <stdio.h>
struct citizenList
{
 int sno;
 char name[30], father_name[30], dob[10], sex[10], address[50];
}record;
//    FUNCTION TO INSERT CITIZEN RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("file1", "a");
 printf("Enter the Sequence no : ");
 scanf("%d", &record.sno);
 printf("Enter the Name : ");
 scanf("%s", &record.name);
 printf("Enter the Father's Name : ");
 scanf("%s", &record.father_name);
 printf("Enter the Date of Birth : ");
 scanf("%s", &record.dob);
 printf("Enter the Sex : ");
 scanf("%s", &record.sex);
 printf("Enter the Address : ");
 scanf("%s", &record.address);
 
 fwrite(&record, sizeof(record), 1, fp);
 fclose(fp);
}
//    FUNCTION TO DISPLAY CITIZEN RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("file1", "r");
 printf("\nS.No\tName\tFather's Name\tDate of Birth\tSex\tAddress\n\n");
 while (fread(&record, sizeof(record), 1, fp1))
 printf("  %d\t%s\t%s\t%s\t%s\t%s\n", record.sno, record.name, record.father_name, record.dob, record.sex, record.address);
 fclose(fp1);
}

//    FUNCTION TO DELETE A CITIZEN RECORD


void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Sequence no you want to delete : ");
 scanf("%d", &r);
 if (isSequenceAvailable(r) == 0)
  printf("Sequence no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("file1", "r");
  fpt = fopen("File2", "w");
  while (fread(&record, sizeof(record), 1, fpo))
  {
   s = record.sno;
   if (s != r)
    fwrite(&record, sizeof(record), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("", "w");
  fpt = fopen("File2", "r");
  while (fread(&record, sizeof(record), 1, fpt))
   fwrite(&record, sizeof(record), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    FUNCTION TO UPDATE THE CITIZEN RECORD
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter sequence number to update : ");
 scanf("%d", &r);
 avl = isSequenceAvailable(r);
 if (avl == 0)
 {
  printf("sequence number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("file1", "r");
  fpt = fopen("File2", "w");
  while (fread(&record, sizeof(record), 1, fpo))
  {
   s = record.sno;
   if (s != r)
    fwrite(&record, sizeof(record), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of citizen with sequence Number %d", r);
    printf("\n\t2. Update Father's Name of citizen with sequence Number %d", r);
    printf("\n\t3. Update Date of Birth of citizen with sequence Number %d", r);
    printf("\n\t4. Update Sex of citizen with sequence Number %d", r);
    printf("\n\t5. Update Address of citizen with sequence Number %d", r);
    printf("\n\t6. Update all the details of citizen with sequence Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name: ");
     scanf("%s", & record.name);
     break;
   
    case 2:
     printf("Enter Father's Name: ");
     scanf("%s", & record.father_name);
     break;
    case 3:
     printf("Enter Date of Birth: ");
     scanf("%s", & record.dob);
     break;
    case 4:
     printf("Enter Sex: ");
     scanf("%s", & record.sex);
     break;
    case 5:
     printf("Enter Address: ");
     scanf("%s", & record.address);
     break;
    case 6:
     printf("Enter Name: ");
     scanf("%s", & record.name);
     printf("Enter Father's Name: ");
     scanf("%s", & record.father_name);
     printf("Enter Date of Birth: ");
     scanf("%s", & record.dob);
     printf("Enter Sex: ");
     scanf("%s", & record.sex);
     printf("Enter Address: ");
     scanf("%s", & record.address);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&record, sizeof(record), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("file1", "w");
  fpt = fopen("File2", "r");
  while (fread(&record, sizeof(record), 1, fpt))
  {
   fwrite(&record, sizeof(record), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}

//    FUNCTION TO CHECK GIVEN CITIZEN SEQUENCE NO IS AVAILABLE 
int isSequenceAvailable(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("file1", "r");
 while (!feof(fp))
 {
  fread(&record, sizeof(record), 1, fp);

  if (rno == record.sno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int isFileEmpty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("file1", "r");
 while (fread(&record, sizeof(record), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
// MAIN PROGRAM
void main()
{
 int c, empty;
 do
 {
  printf("############################");
  printf("\n          MENU          \n");
  printf("############################");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t");
  printf("3. DELETE\n\t4. UPDATE\n");
  printf("\t5. EXIT");
  printf("\n\n-----------------\n");
  printf("\nEnter your choice: ");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   empty = isFileEmpty();
   if (empty == 0)
    printf("\nThe file is Empty\n");
   else
    disp();
   break;
  case 3:
   deletefile();
   break;
  case 4:
   update();
   break;
  case 5:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 5);
}

