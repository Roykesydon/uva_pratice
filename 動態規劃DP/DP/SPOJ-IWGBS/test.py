n=int(input())
arr=[[0,0] for i in range(0,n)]
for i in range(n):
    if i==0 :
        arr[i][0]=1
        arr[i][1]=1
    else:
        arr[i][0]=arr[i-1][1]
        arr[i][1]=arr[i-1][0]+arr[i-1][1]
print(arr[n-1][0]+arr[n-1][1])
    