class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.size = 0
        self.front = None
        self.rear = None

    def __len__(self):
        return self.size

    def __str__(self):
        p = self.front
        arr = []
        while p:
            arr.append(p.data)
            p = p.next
        return str(arr)

    def enqueue(self, item):
        new_node = Node(item)
        self.size = self.size + 1
        if not self.front:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        return new_node

    def dequeue(self):
        if not self.front:
            return None
        self.size = self.size - 1
        p = self.front
        self.front = self.front.next
        return p

    def traverse(self):
        p = self.front
        while p:
            print(p.data, end=' ')
            p = p.next
        print()

    def get_size(self):
        return self.size


queue = Queue()

queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
print(queue)
print(len(queue))
queue.dequeue()
queue.dequeue()
queue.dequeue()
queue.dequeue()
queue.enqueue(5)
queue.traverse()
print(queue.get_size())
