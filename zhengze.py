
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 22:31:40 2019

@author: 子聪
"""

def is_match(s,p):
    #考虑空值
    if s==NULL and p==NULL:
        retrun True
    elif s==NULL or p==NULL:
        retrun False
    #四种情况



if __name__ == "__main__":
    s=input('please input the original string = ')
    p=input('please input the Match Rule = ')
    if(is_match(s,p)):
        print(True)
    else:
        print(False)
    