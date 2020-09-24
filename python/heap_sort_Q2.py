class Heap:
    def __init__(self,s_min_max = 'min'):

        self.dynamic_arr = [None,]
        self.num_of_data = 0

        if s_min_max == 'max':
            self.min_max = 2
        else:
            self.min_max = 1

    def get_left_child_idx(self,idx):
        return 2 * idx
    def get_right_child_idx(self,idx):
        return 2 * idx + 1
    def get_parent_idx(self,idx):
        return idx//2

    def build_heap(self):
        n = self.num_of_data//2
        for i in range(n,0,-1):
            self.down_heap(i)

    def down_heap(self,idx):
        l = self.get_left_child_idx(idx)
        r = self.get_right_child_idx(idx)
        n = self.num_of_data
        if (r > n) and (l > n):
            return

        largest = idx
        if r<=n :
            if self.dynamic_arr[r]>self.dynamic_arr[largest]:
                largest = r

        if self.dynamic_arr[largest]<self.dynamic_arr[l]:
            largest = l

        if largest != idx:
            tmp = self.dynamic_arr[largest]
            self.dynamic_arr[largest] = self.dynamic_arr[idx]
            self.dynamic_arr[idx] = tmp

            self.down_heap(largest)
    def print_heap(self):
        for i in range(1,self.num_of_data + 1):
            print(self.dynamic_arr[i], end= " ")
        print(" ")

if __name__ == "__main__":
    n = int(input("write down the number : "))
    arr = list(map(int,input("writh down the keys : ").split()))
    arr.insert(0,None)
    heap = Heap('max')
    heap.dynamic_arr = arr
    heap.num_of_data = n
    
    heap.build_heap()

    heap.print_heap()
    