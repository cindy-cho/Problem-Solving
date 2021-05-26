#include <stdio.h>

void merge(int l, int r);
void sort(int l, int m, int r);
int arr[10000000];
int tmp[10000000];
int main(void) {
   int N;

   scanf("%d", &N);
   for (int i = 0; i < N; i++)
      scanf("%d", &arr[i]);

   merge(0, N - 1);

   for (int i = 0; i < N; i++)
      printf("%d\n", arr[i]);

   return 0;
}
void merge(int l, int r) {
   if (l < r) {
      int m = (l + r) / 2;

      merge(l, m);
      merge(m + 1, r);
      sort(l, m, r);
   }
}
void sort(int l, int m, int r) {
   int ll = l;
   int rr = m + 1;
   int idx = 0;

   while (ll <= m && rr <= r)
      if (arr[ll] < arr[rr])
         tmp[idx++] = arr[ll++];
      else
         tmp[idx++] = arr[rr++];
   while (ll <= m)
      tmp[idx++] = arr[ll++];
   while (rr <= r)
      tmp[idx++] = arr[rr++];
   for (int i = l; i <= r; i++)
      arr[i] = tmp[i - l];
}