import re
def solv(exp):
    stack = []
    for c in re.split("\\s+",exp):
        if c.isdigit():
            stack.append(c)
        else:
            op1 = stack.pop()
            op2 = stack.pop()
            if c == '+':
                stack.append(int(op1) + int(op2))
            elif c == '-':
                stack.append(int(op1) - int(op2))
            elif c == '*':
                stack.append(int(op1) * int(op2))
            elif c == '/':
                stack.append(int(op1) // int(op2))

    return stack[-1]

print(solv("45 40 +"))