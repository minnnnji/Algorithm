
def heap_sort(a):

    def swap(a,i,j):
        tmp = a[i]
        a[i] = a[j]
        a[j] = tmp

    def down_heap(a,i,size):
        l = 2 * i + 1
        r = 2 * i + 2
        largest = i

        if l <= size-1 and a[l]>a[i]:
            largest = l
        if r <= size - 1 and a[r] > a[largest]:
            largest = r
        if largest != i:
            swap(a,i,largest)
            down_heap(a,largest,size)

    def heapify(a,size):
        p = (size//2)-1
        while p>=0:
            down_heap(a,p,size)
            p -= 1

    size = len(a)
    heapify(a,size)
    end = size - 1
    while(end > 0):
        swap(a,0,end)
        down_heap(a,0,end)
        print(end,a)
        end -= 1 #phase 2

arr = [1,3,2,4,9,7]
heap_sort(arr)
print(arr)
