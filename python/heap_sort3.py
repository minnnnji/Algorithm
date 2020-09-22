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

    def get_prior(self,value1, value2):
        # -1 = value 1 > value 2
        # 0 = value 1 = value 2
        # 1 = value 1 < value 2

        if min_max == 1:
            if value1 < value2 :
                return -1
            elif value1 > value2 :
                return 1
            else:
                return 0
        
        else:
            if value1 > value2 :
                return -1
            elif value1 < value2 :
                return 1
            else :
                return 0

    def is_empty(self):
        
        if self.num_of_data == 0:
            return True

        return False
    '''        
    def up_heap(self,idx):
        
        if idx <= 1:
            return False
        
        parent_value = dynamic_arr[self.get_parent_idx(idx)]

        if self.get_prior(parent_value,data) == 1:
            return True
        else :
            return False
    
    def insert_heap(self,data):
        
        if self.num_of_data == 0 :

            self.dynamic_arr.append(data)
            self.num_of_data += 1

            return
        
        idx_data = self.num_of_data

        while self.up_heap(idx_data):
            parent_idx = self.get_parent_idx(idx_data)
            self.dynamic_arr[idx_data] = self.dynamic_arr[parent_idx]
            idx_data = parent_idx
        
        self.dynamic_arr[idx_data] = data
    '''

    def build_heap(self):
        for i in range(self.num_of_data//2,1,-1):
            self.down_heap(i)

    def which_is_prior_child(self,idx):
        left_idx = self.get_left_child_idx(idx)

        if left_idx > self.num_of_data :
            return None
        elif left_idx == self.num_of_data:
            return left_idx

        right_idx = self.get_right_child_idx
        
        left_value = self.dynamic_arr[left_idx]
        right_value = self.dynamic_arr[right_idx]

        if self.get_prior(left_value,right_value) == -1:
            return left_idx
        else:
            return right_idx

    def down_heap(self,idx):

        r_child_idx = self.get_right_child_idx(idx)
        l_child_idx = self.get_left_child_idx(idx)

        if r_child_idx > self.num_of_data and l_child_idx > self.num_of_data:
            return
        
        largest = idx
        if (r_child_idx<=self.num_of_data):
            if self.dynamic_arr[r_child_idx]>self.dynamic_arr[largest]:
                largest = r_child_idx
        
        if self.dynamic_arr[l_child_idx]>self.dynamic_arr[largest]:
            largest = l_child_idx
        
        if largest != idx :
            tmp = self.dynamic_arr[largest]
            self.dynamic_arr[largest] = self.dynamic_arr[idx]
            self.dynamic_arr[idx] = tmp

            self.down_heap(largest)
    
    '''
    def delete_heap(self):
        if self.is_empty():
            return None
        
        root_data = self.get_parent_idx
        last_data = self.dynamic_arr[self.num_of_data]
        self.num_of_data -= 1

        idx_data = 1

        while self.down_heap(idx_data,last_data):
            child_idx = self.which_is_prior_child(idx_data)
            self.dynamic_arr[idx_data] = self.dynamic_arr[child_idx]
            idx_data = child_idx
        
        self.dynamic_arr[idx_data] = last_data
    '''
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
    print(heap.num_of_data)
    heap.print_heap()
    