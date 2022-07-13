operators = {'*','/','+','-','^'}
def precedence(c):
        if c == '+' or c == '-':
            return 1
        elif c == '*' or c == '/':
            return 2
        elif c == '^':
            return 3
        return -1

def operation(numbers,op):
        n2 = numbers.pop()
        n1 = numbers.pop()
        if op[-1] == '+':
            numbers.append(n1 + n2)
        elif op[-1] == '-':
            numbers.append(n1 - n2)
        elif op[-1] == '*':
            numbers.append(n1 * n2)
        elif op[-1] == '/':
            numbers.append(n1 // n2)
        elif op[-1] == '^':
            numbers.append(n1 ** n2)
        op.pop()
        
def evalute(exp):
    numbers = []
    op = []
    cur = []
    for i,c in enumerate(exp):
        if c.isdigit():
            cur.append(c)
        if (c in operators or i == len(exp) - 1) and cur:
            numbers.append(int("".join(cur)))
            cur = []
        if c == '(':
            op.append(c)
        elif c == ')':
            while op[-1] != '(':
                operation(numbers,op)
            op.pop()
        elif c in operators:
            while op and precedence(c) <= precedence(op[-1]):
                operation(numbers,op)
            op.append(c)
    while op:
        operation(numbers,op)
    return numbers[-1]

print(evalute(" 6 + 3 * 2 + 2 ^ 5 + 2 - 100"))