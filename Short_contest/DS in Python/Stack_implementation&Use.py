"""
Line 7 - 28 Stack Implementaion
Line 30 - 37Reversing a string using stack 
Line 39 - 55 Checking wheather different types of paranthesis are balanced or not (Refer Line 57 onward for clarity)
"""

from collections import deque # deque is Double Ended QUEue (pronounced as deck)

class Stack:
    def __init__(self):
        self.container = deque()

    def push(self, val):
        self.container.append(val)

    def pop(self):
        if not self.isEmpty():
            return self.container.pop()
        return None

    def peek(self): 
        return self.container[-1]

    def isEmpty(self):
        return (len(self.container) == 0)

    def size(self):
        return len(self.container)

def reverse_string(string):
    stack = Stack()
    rev_string = ""
    for i in range(len(string)):
        stack.push(string[i])
    for i in range(len(string)):
        rev_string += stack.pop()
    return rev_string

def is_balanced(exp) -> bool:
    stack = Stack()
    ans = True
    map = {"}" : "{", "]" : "[", ")" : "("}
    closed_brackets = {")", "}", "]"}; open_brackets = {"(", "{", "["}
    brackets = {"{", "[", "(", "}", ")", "]"}
    for i in exp:
        if i in open_brackets:
            stack.push(i)
            continue
        if i in closed_brackets:
            if stack.isEmpty():
                return False
            if not (map[i] == stack.pop()):
                return False
        
    return (stack.isEmpty())
            
# print(is_balanced("({a+b})")) #True
# print(is_balanced("))((a+b}{"))  #False 
# print(is_balanced("((a+b))"))  # True
# print(is_balanced("[a+b]*(x+2y)*{gg+kk}")) #True
# print(is_balanced("(")) #False
