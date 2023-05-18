 #include<stdio.h>
int main(){
 int choice;
 int current=0;
 do{
  printf("Choices: \n");
  printf("1 UP | FIRST \n");
  printf("2 DOWN | GROUND \n");
  printf("3 CurrentFloor \n");
  printf("4 Exit \n");
  printf("Enter the Choice: ");
  scanf("%d",&choice);
  switch(choice){
   case 1:{
    current = 1;
    break;
   }
   case 2:{
    current=0;
    break;
   }
   case 3:{
    if(current == 0){
     printf("-------------------------\n");
     printf("You are in Ground Floor\n");
     printf("You have a Red Color\n");
     printf("-------------------------\n");
    }else{
     printf("-------------------------\n");
     printf("You are in First Floor\n");
     printf("You have a Green Color\n");
     printf("-------------------------\n");
    }
    break;
   }
   case 4:{
    break;
   }
   default:{
    printf("Please Choose Appropriate Choice");
    break;
   }
  }
 }while(choice!=4);
}