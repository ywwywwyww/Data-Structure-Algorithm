//严蔚敏《数据结构》标准分割函数
 Paritition1(int A[], int low, int high) {
   int pivot = A[low];
   while (low < high) {
     while (low < high && A[high] > pivot) {
       --high;
     }
     if(low<high)
     {
     	A[low] = A[high];
     	low++;
     }
     while (low < high && A[low] < pivot) {
       ++low;
     }
     if(low<high)
     {
     A[high] = A[low];
     high--;
 }
   }
   A[low] = pivot;
   return low;
 }

 void QuickSort(int A[], int low, int high) //快排母函数
 {
   if (low < high) {
     int pivot = Paritition1(A, low, high);
     QuickSort(A, low, pivot - 1);
     QuickSort(A, pivot + 1, high);
   }
 }
 int a[1000010];
 int  main()
 {
 	int n=100000;
 	for(int i=1;i<=n;i++)
 		a[i]=1;
 	QuickSort(a,1,n);
 	return 0;
 }
