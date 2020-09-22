class Heap:
    def get_parent_idx(self,idx):
        return idx // 2
    def get_right_child_idx(self,idx):
        return idx * 2 + 1
    def get_left_child_idx(self,idx):
        return idx * 2 

    def get_prior(self,value1, value2):
        # value1 이 우선순위가 크면 -1
        # value2 가 우선순위가 크면 1
        # 숫자가 같으면 0 

        if self.min_max == 1: #MIN_HEAP인 경우
            if value1 < value2:
                return -1
            elif value1 > value2:
                return 1
            else:
                return 0

        if self.min_max == 2: #MAX_HEAP인 경우
            if value1 > value2:
                return -1
            elif value1 < value2:
                return 1
            else:
                return 0

    def __init__(self, s_min_max = 'min'): #MIN_heap 인지 MAX_heap인지 받아야함

        # min_max = 1 -> MIN_HEAP, min_max = 2 -> MAX_HEAP

        self.dynamic_arr = [None,]
        self.num_of_data = 0 # 데이터 개수

        if s_min_max == 'max':
            self.min_max = 2 
        else :
            self.min_max = 1

    def is_empty(self):
        if self.num_of_data == 0:
            return True

        return False
    
    def up_heap(self,idx, data):

        if idx <= 1:
            return False
        
        parent_value = self.dynamic_arr[self.get_parent_idx(idx)] # 부모의 값을 불러옴

        if self.get_prior(parent_value,data) == 1 : #부모의 우선순위 < data의 우선순위 -> swap이 필요한 상황
            return True
        else:
            return False
        
    def insert_heap(self,data):
        if self.is_empty():
            self.dynamic_arr.append(data)
            self.num_of_data = 1
            return
        # 첫번째 데이터일 경우 넣어주고 끝남

        self.dynamic_arr.append(data)
        self.num_of_data += 1

        idx_data = self.num_of_data

        while self.up_heap(idx_data,data): #부모의 노드가 새로운 데이터보다 우선순위가 높아질 때까지 계속 돌기
            
            parent_idx = self.get_parent_idx(idx_data)
            self.dynamic_arr[idx_data] = self.dynamic_arr[parent_idx]
            idx_data = parent_idx

        self.dynamic_arr[idx_data] = data 

    def which_is_prior_child(self,idx):

        left_idx = self.get_left_child_idx(idx)
        
        if left_idx > self.num_of_data:
            return None
        elif left_idx == self.num_of_data:
            return left_idx
        #왼쪽자식의 인덱스보다 총 개수가 작으면 아무것도 보내지 않고 같으면 왼쪽자식의 인덱스를 보냄

        right_idx = self.get_right_child_idx

        left_value = self.dynamic_arr[left_idx]
        right_value = self.dynamic_arr[right_idx]

        if self.get_prior(left_value,right_value) == 1: # 오른쪽이 더 큰 경우
            return right_idx
        else: # 왼쪽의 우선순위가 더 큰 경우
            return left_idx

    def down_heap(self,idx,data):
        child_idx = self.which_is_prior_child(idx)

        if not child_idx: # which is prior child에서 None이 나오면 실행되는 함수
            return False

        child_value = self.dynamic_arr[child_idx]

        if self.get_prior(child_value,data) == -1: # 자식의 우선순위가 더 높은 경우 
            return True
        else:
            return False 
    
    def delete_heap(self):
        if self.is_empty():
            print("There is no data")
            return None
            # 삭제할 데이터가 없을 때
        
        root_data = self.dynamic_arr[1]
        last_data = self.dynamic_arr[self.num_of_data]
        self.num_of_data -= 1

        idx_data = 1

        while self.down_heap(idx_data,last_data):
            child_idx = self.which_is_prior_child(idx_data)
            self.dynamic_arr[idx_data] = self.dynamic_arr[child_idx]
            idx_data = child_idx
        
        self.dynamic_arr[idx_data] = last_data
        self.dynamic_arr.pop()

        return root_data

if __name__ == "__main__":

    heap = Heap("max")

    while 1:
        ch = str(input("i ( insert ) d ( delete ) p ( print ) q (quit) ==> "))

        if ch == 'q':
            break
    
        if ch == 'i':
            a = int(input("Please write down the Number "))
            heap.insert_heap(a)
    
        if ch == 'd':
            ch = heap.delete_heap()
            print(ch)

        if ch == 'p':

            for i in range(1,heap.num_of_data+1):
                print(heap.dynamic_arr[i], end= " ")
            print(" ")

    

        




