class ArrayQueue(object):
    def __init__(self):
        self._data = [] #use [0] as front, [len-1] as rear

    def enqueue(self, item): #add item to the rear of queue
        self._data.append(item)
    
    def dequeue(self):
        if len(self._data)==0:
            raise Exception("Exception: dequeue from empty queue")
        return self._data.pop(0)

    def isEmpty(self): return len(self._data ==0)
    def front(self): return self._data[0]
    def __len__(self): return len(self._data)
    def __str__(self): 
        return " <-- ".join([str(i) for i in self._data])

def testqueue(queueType):
    myQueue = queueType()
    myQueue.enqueue("Monday")
    print("@100 ", myQueue)
    myQueue.enqueue("Tuesday")
    print("@200 ", myQueue)

if __name__ == '__main__':
    testqueue(ArrayQueue)

from Node import Node

class LinkedQueue(object):
    def __init__(self):
        self._front = None  #the front node
        self._rear = None   #the rear node
        self._size = 0  #length of queue

    def enqueue(self, item): #add item to the rear of queue
        lastNode = Node(item, None)
        if self._size ==0:
            self._front = lastNode
            self._rear = lastNode
        else:
            self._rear.next = lastNode
        self._size +=1
    
    def dequeue(self):
        if self._size ==0:  #empty queue
            raise Exception("Exception: dequeue from empty queue")
        value = self._front.data
        self._front = self._front.next
        if self._size ==1:
            self._rear = None
        self._size -=1
        return value

    def isEmpty(self): return len(self._data ==0)
    def front(self):
        if self._size ==0:  #empty queue
            raise Exception("Exception in front(): empty queue")
         return self._front.data
    def __len__(self): return len(self._data)
    def __str__(self):
        s = ""
        seperator = " "
        def helper(current):
            if current is None:
                return s
            s = s + seperator + str(current.data + helper(current.next) 
        return helper(self._front)

def testQueue(queueType):
    myQueue = queueType()
    myQueue.enqueue("Monday")
    print("@100 ", myQueue)
    myQueue.enqueue("Tuesday")
    print("@200 ", myQueue)

if __name__ == '__main__':
    testqueue(ArrayQueue)