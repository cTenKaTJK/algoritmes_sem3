def brackets_check(line):
    brackets = []
    bracket_pairs = {')': '(', '}': '{', ']': '['}
    for sym in line:
        if sym in bracket_pairs.values():
            brackets.append(sym)
        elif sym in bracket_pairs.keys():
            if brackets and brackets[-1] == bracket_pairs[sym]:
                brackets.pop()
            else:
                return False

    return len(brackets) == 0


def to_polish(expression):
    opers = {'+': 1, '-': 1, '*': 2, '/': 2}    #определение приоритета оператора
    output, operators, i = [], [], 0

    while i < len(expression):
        print(*output, '\n', *operators, '\n---------------\n')
        sym = expression[i]

        if sym == '-' and (i == 0 or expression[i - 1] in '(-+*/'):
            number = sym
            i += 1
            while i < len(expression) and expression[i].isdigit():
                number += expression[i]
                i += 1
            output.append(number)
            continue

        if sym.isdigit():
            number = sym
            while i + 1 < len(expression) and expression[i + 1].isdigit():
                i += 1
                number += expression[i]
            output.append(number)
        elif sym in opers:
            while ((operators and operators[-1] in opers) and (opers[operators[-1]] >= opers[sym])):
                output.append(operators.pop())
            operators.append(sym)
        elif sym == '(':
            operators.append(sym)
        elif sym == ')':
            while operators and operators[-1] != '(':
                output.append(operators.pop())
        i += 1

    while operators:
        output.append(operators.pop())

    return output


def evaluate_pol(rpn):
    stack = []
    for sigh in rpn:
        if sigh.lstrip('-').isdigit():
            stack.append(int(sigh))
        else:
            b = stack.pop()
            a = stack.pop()

            if sigh == '+':
                stack.append(a + b)
            elif sigh == '-':
                stack.append(a - b)
            elif sigh == '*':
                stack.append(a * b)
            elif sigh == '/':
                if b == 0:
                    raise ZeroDivisionError("деление на ноль")
                stack.append(a / b)

    return stack[0]


def evaluate(expression):
    expression = expression.replace('=', '')

    if not brackets_check(expression):
        print("Некорректные скобки в выражении")
        return

    try:
        rpn = to_polish(expression)
        result = evaluate_pol(rpn)
        print("Результат:", result)
    except ZeroDivisionError:
        print(ZeroDivisionError)


if __name__ == '__main__':
    evaluate(input("Введите пример: "))
