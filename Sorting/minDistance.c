#include<stdio.h>
#include<math.h>
struct points{
  int x;
  int y;
};
int main(){
  int n;
  float distance , min=99999.9;
  printf("Enter the number of points\n");
  scanf("%d" , &n);
  struct points str[n];
  for(int i=0;i<n;i++){
    printf("Enter x for point %d\n" , i-1);
    scanf("%d" , &str[i].x);
    printf("Enter y for point %d\n" , i+1);
    scanf("%d" , &str[i].y);
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      distance=sqrt(pow((str[i].x-str[j].x) , 2) + pow((str[i].y-str[j].y) , 2));
      if(distance<min){
        min=distance;
      }
    }
  }
  printf("Minimum distance is: %f\n" , min);
  return 0;
}
