class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None


class Stack:
    def __init__(self):
        self.size = 0
        self.top = None

    def __len__(self):
        return self.size

    def __str__(self):
        p = self.top
        arr = []
        while p:
            arr.append(p.data)
            p = p.prev
        return str(arr)

    def push(self, item):
        new_node = Node(item)
        self.size = self.size + 1
        if not self.top:
            self.top = new_node
        else:
            p = self.top
            self.top = new_node
            self.top.prev = p
        return new_node

    def pop(self):
        if not self.top:
            return None
        else:
            self.size = self.size - 1
            p = self.top
            self.top = self.top.prev
            return p

    def traverse(self):
        p = self.top
        while p:
            print(p.data, end=' ')
            p = p.prev
        print()

    def get_size(self):
        return self.size


stack = Stack()

stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
print(stack)
stack.pop()
stack.pop()
print(stack)
stack.pop()
stack.pop()
stack.pop()
stack.traverse()
print(len(stack))
