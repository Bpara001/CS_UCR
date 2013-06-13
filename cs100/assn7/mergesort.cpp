
/* 
 * Merge Sort
 * http://www.cplusplus.happycodings.com/Algorithms/code17.html
 */

#include <iostream>
using namespace std;

int a[50];
void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid-1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h];
   h++;
  }
  else
  {
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}

int main()
{
 int i, tmp;
 
 for(i=1; cin>>tmp; i++)
 {
  a[i] = tmp;
 }
 int num = i-1;
 
 //cout << "Initially:\n\n";
 //for(i=1;i<=num;i++) cout << "Index " << i-1 << " = " << a[i] << endl;
 
 merge_sort(1,num);

 //cout << "\nAfter sort:\n\n";	
 //for(i=1;i<=num;i++) cout << "Index " << i-1 << " = " << a[i] << endl;
 for(i=1;i<=num;i++) cout <<  a[i] << endl;


}
