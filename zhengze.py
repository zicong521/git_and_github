
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 22:31:40 2019

@author: 子聪
"""

def fun1(s,p):
    pass
def fun2(s,p):
    pass
def fun3(s,p):
    pass
def fun4(s,p):
    pass
def is_match(s,p):
    #考虑空值
    if s=='' and p=='':
        return True
    elif s=='' or p=='':
        return False
    #四种情况
    if p.find('*') == -1 and p.find('.') == -1:
        return fun1(s,p)
    if p.find('*') == -1 and p.find('.') != -1:
        return fun2(s,p)
    if p.find('*') != -1 and p.find('.') == -1:
        return fun3(s,p)
    if p.find('*') != -1 and p.find('.') != -1:
        return fun4(s,p)

if __name__ == "__main__":
    s=str(input('please input the original string = '))
    p=str(input('please input the Match Rule = '))
    if(is_match(s,p)):
        print(True)
    else:
        print(False)
    