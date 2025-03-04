#include<stdio.h>
void main() {
int n,leakrate,bsize,in,bucket_storage;
bucket_storage=0;
printf("Enter the bucket size: ");
scanf("%d",&bsize);
printf("Enter the no of inputs: ");
scanf("%d",&n);
printf("Enter the packet outgoing rate: ");
scanf("%d",&leakrate);
printf("Initially Bucket status contains %d out of %d\n",bucket_storage,bsize);
while(n>0) {
printf("Enter the incoming packet size \n");
scanf("%d",&in);
printf("Incoming packet size is %d\n",in);
if(in<=bsize-bucket_storage) {
bucket_storage=bucket_storage + in;
printf("Bucket status: contains %d out of %d\n",bucket_storage,bsize);
} else {
printf("Dropped packets:%d\n",in-bsize+bucket_storage);
bucket_storage=bsize;
printf("Bucket status: contains %d out of %d\n",bucket_storage,bsize);
}
bucket_storage=bucket_storage - leakrate;
if(bucket_storage<0)
bucket_storage=0;
printf("After sending, Bucket status contains %d packets out of %d\n",bucket_storage,bsize);
n--;
}
}



/// output /////
Enter the bucket size: 3
Enter the no of inputs: 5
Enter the packet outgoing rate: 2
Initially Bucket status contains 0 out of 3
Enter the incoming packet size 
3
Incoming packet size is 3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
^Z
[1]+  Stopped                 ./a.out
s6bcs12@admincs-ProLiant-ML10:~$ ./a.out
Enter the bucket size: 3
Enter the no of inputs: 5
Enter the packet outgoing rate: 2
Initially Bucket status contains 0 out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:2
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
5
Incoming packet size is 5
Dropped packets:3
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3
Enter the incoming packet size 
2
Incoming packet size is 2
Bucket status: contains 3 out of 3
After sending, Bucket status contains 1 packets out of 3

