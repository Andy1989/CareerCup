/* 1.1 Implement an algorithm to determine if a string has all unique characters. 
   What if you cannot use additional data structures?
*/
// ID: qiaobao
/*
最容易想到的是这个：
将当前字符跟之后的所以字符逐个比较，找到相同的字符则返回；否则循环结束返回。
时间复杂度O(n^2).
*/

#define TRUE 1
#define FALSE 0
/*********************************
* Parameter: 
*   char *str pointer points to a string
* Return value: 
*   0  not unique
*   1  unique
*********************************/
int uniqueCharacter(char *str) {
  for(int i = 0; *(str+i) != '\0'; i++) {
    for(int j = 1; *(str+j) != '\0'; i++) {
      if(*(str+i) == *(str+j))
        return FALSE;
    }
  }
  return TRUE;
}

/*
好一点的算法：
先排序(O(nlogn)), 再比较当前字符跟后面的第一个字符(O(n))。
时间复杂度O(nlogn)
*/

int uniqueCharacter(char *str, int N) {
   mergeSort(str, 0, N-1);
   
   for(int i = 0; i < N - 1; i++) 
      if(*(str+i) == *(str + i + 1))
         return FALSE;
   return TRUE;
}

void mergeSort(char array[], int first, int last) {
   int mid = 0;
   if(first<last) {
      mid = (first+last) / 2;
      mergeSort(array, first, mid);
      mergeSort(array, mid+1,last);
      merge(array,first,mid,last);
   }
}

void merge(char array[], int left, int mid, int right) {
   int i, k;
   char *temp = (char*)malloc((right - left + 1) * sizeof(char)); 
   int begin1 = left;
   int endl = mid;
   int begin2 = mid + 1;
   int end2 = right;

   for(k = 0; begin1 <= end1 && begin2 <= end2; k++) {
      if(array[begin1] < array[begin2]) 
         temp[k] = array[begin1++];
      else
         temp[k] = array[begin2++];
   }
   while(begin1 <= end1)
      temp[k++] = array[begin1++];
   
   while(begin2 <= end2)
      temp[k++] = array[begin2++];
   
   for(i = 0; i < (right - left + 1); i++) 
      array[left + i] = temp[i];
   
   free(temp);
}
