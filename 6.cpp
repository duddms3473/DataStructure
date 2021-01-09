
#include <iostream>
using namespace std;
#include<ctime>
#include<cstdlib>
void Insert(const int e, int* a, int i){
 a[0] = e;
 while (e < a[i]){
  a[i + 1] = a[i];
  i--;
 }
 a[i + 1] = e;
 return;
}
void Insertion_Sort(int *a, const int n)
{
 for (int j = 2; j <= n; j++)
 {
  int temp = a[j];
  Insert(temp, a, j - 1);
 }
}

void QuickSort(int *b, int left, int right)
{
 int pivot = left;
 int j = pivot;
 int i = left + 1;

 if (left < right){
  for (; i <= right; i++){
   if (b[i] < b[pivot]){
    j++;
    int k = b[i];
    b[i] = b[j];
    b[j] = k;
   }
  }
   int k = b[j];
   b[j] = b[left];
   b[left] = k;
   pivot = j;

   QuickSort(b, left, pivot - 1);
   QuickSort(b, pivot + 1, right);
 }
}
void merge(int *a, int p, int q, int r)
{
 int n1 = q - p + 1;
 int n2 = r - q;
 int *l, *r1;
 int i, j, k;

 l = (int *)calloc(n1 + 1, sizeof(int));
 r1 = (int *)calloc(n2 + 1, sizeof(int));

 for (i = 0; i<n1; i++) l[i] = a[p + i];
 for (j = 0; j<n2; j++) r1[j] = a[q + j + 1];

 l[n1] = 100000;
 r1[n2] = 100000;

 i = 0;
 j = 0;

 for (k = p; k <= r; k++) {
  if (l[i] <= r1[j]) {
   a[k] = l[i];
   ++i;
  }
  else {
   a[k] = r1[j];
   ++j;
  }
 }
 return;
}

void merge_sort(int *A, int p, int r)
{
 if (p < r)
 {
  int q = (p + r) / 2;
  merge_sort(A, p, q);
  merge_sort(A, q + 1, r);
  merge(A, p, q, r);
 }
 else
  return;
}

int main() {

 /*Insertion Sort*/
 
 int a[3501];
 int num = 3500;
 for (int i = 1; i <= 3500; i++){
  a[i] = num;
  num--;
 }
 clock_t startTime = clock();

 Insertion_Sort(a, 3500);

 clock_t endTime = clock();
 clock_t clockTicksTaken = endTime - startTime;
 double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;

 std::cout << "Insertion Sort worst time: " << timeInSeconds << '\n' << std::endl;

startTime = clock();
for(int c=0;c<10;c++){
int d[3501];
for(int i=1;i<=3500;i++){
d[i]=rand();
}

 Insertion_Sort(d, 3500);
}
endTime = clock();
clockTicksTaken = endTime - startTime;
timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC/10.0;

 std::cout << "Insertion Sort average time: " << timeInSeconds << '\n' << std::endl;

 /*Quick Sort*/

 int b[3501];
 for (int i = 1; i < 3501; i++)
 {
  b[i] = i;
 }
 startTime = clock();

 QuickSort(b, 1, 3500);

 endTime = clock();
 clockTicksTaken = endTime - startTime;
 timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;

 std::cout << "Quick Sort worst time: " << timeInSeconds << '\n' << std::endl;


startTime = clock();
for(int c=0;c<10;c++){
int e[3501];
for(int i=1;i<3501;i++){
e[i]=rand();
}

 QuickSort(e,1, 3500);
}
endTime = clock();
clockTicksTaken = endTime - startTime;
timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC/10.0;

 std::cout << "Quick Sort average time: " << timeInSeconds << '\n' << std::endl;

 /*Merge Sort*/
 int c[3501];
 for (int i = 1; i <= 1750; i++)
 {
  int num = 2 * i - 1;
  c[i] = num;
  c[1750+i] = num + 1;
 }
 for (int i = 1; i <=875; i++)
 {
  int k;
  int num = 4 * i - 2;
  k = c[num + 1];
  c[num + 1] = c[num];
  c[num] = k;
 }
 for (int i = 1; i <= 1750; i++)
 {
  int k;
  int num = 2 * i - 1;
  k = c[num + 1];
  c[num + 1] = c[num];
  c[num] = k;
 }

 startTime = clock();

 merge_sort(c, 1, 3500);


 endTime = clock();
 clockTicksTaken = endTime - startTime;
 timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;

 std::cout << "Merge worst Sort time: " << timeInSeconds << '\n' << std::endl;

startTime = clock();
for(int s=0;s<10;s++){
int f[3501];
for(int i=0;i<=3500;i++){
f[i]=rand();
}

 merge_sort(f,1, 3500);
}
endTime = clock();
clockTicksTaken = endTime - startTime;
timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC/10.0;

 std::cout << "Merge Sort average time: " << timeInSeconds << '\n' << std::endl;
 return 0;
}