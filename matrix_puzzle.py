# -*- coding: utf-8 -*-
"""
Created on Tue Mar 12 18:23:50 2024

@author: patel
"""

class Node:
    
    def __init__(self, data, level, fval): 
        self.data = data
        self.level = level 
        self.fval = fval

    def generate_child(self):
        x, y = self.find_blank(self.data)
        val_list = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]] 
        children = []
        for i in val_list:
            child = self.shuffle(self.data, x, y, i[0], i[1]) 
            if child is not None:
                child_node = Node(child, self.level + 1, 0) 
                children.append(child_node)
        return children

    def shuffle(self, puz, x1, y1, x2, y2):
        if 0 <= x2 < len(puz) and 0 <= y2 < len(puz[0]): 
            temp_puz = self.copy(puz)
            temp = temp_puz[x2][y2] 
            temp_puz[x2][y2] = temp_puz[x1][y1] 
            temp_puz[x1][y1] = temp
            return temp_puz 
        else:
            return None

    def copy(self, root):
        return [row[:] for row in root]

    def find_blank(self, puz): 
        for i in range(len(puz)):
            for j in range(len(puz[0])): 
                if puz[i][j] == '_':
                    return i, j
        raise ValueError("Blank tile not found in the puzzle.")

class Puzzle:
    def __init__(self, size): 
        self.n = size 
        self.open = [] 
        self.closed = []

    def accept(self):
        puz = []
        for i in range(self.n): 
            temp = input().split(" ") 
            puz.append(temp)
        return puz

    def f(self, start, goal):
        return self.h(start.data, goal) + start.level

    def h(self, start, goal): 
        temp = 0
        for i in range(self.n): 
            for j in range(self.n):
                if start[i][j] != goal[i][j] and start[i][j] != '_': 
                    temp += 1
        return temp

    def process(self):
        print("Enter the start state matrix \n") 
        start = self.accept()
        print("Enter the goal state matrix \n") 
        goal = self.accept()
        start = Node(start, 0, 0) 
        start.fval = self.f(start, goal) 
        self.open.append(start) 
        print("\n\n")
        
        while True:
            cur = self.open[0] 
            print("")
            print("  ")
            for i in cur.data:
                print(" ".join(i))
            if self.h(cur.data, goal) == 0:
                break
            for i in cur.generate_child(): 
                i.fval = self.f(i, goal) 
                self.open.append(i) 
                self.closed.append(cur)
            del self.open[0]
            self.open.sort(key=lambda x: x.fval, reverse=False)

puz = Puzzle(3)
puz.process()
