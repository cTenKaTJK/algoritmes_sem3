def is_brackets_correct(line):
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


def to_polish(mth_ex):
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
    output = []
    operators = []
    i = 0

    while i < len(mth_ex):
        char = mth_ex[i]

        if char == '-' and (i == 0 or mth_ex[i - 1] in '(-+*/'):
            number = char
            i += 1
            while i < len(mth_ex) and mth_ex[i].isdigit():
                number += mth_ex[i]
                i += 1
            output.append(number)
            continue

        if char.isdigit():
            number = char
            while i + 1 < len(mth_ex) and mth_ex[i + 1].isdigit():
                i += 1
                number += mth_ex[i]
            output.append(number)
        elif char in precedence:
            while (operators and operators[-1] in precedence and
                   precedence[operators[-1]] >= precedence[char]):
                output.append(operators.pop())
            operators.append(char)
        elif char == '(':
            operators.append(char)
        elif char == ')':
            while operators and operators[-1] != '(':
                output.append(operators.pop())
            operators.pop()  # удаляем '('
        i += 1

    while operators:
        output.append(operators.pop())

    return output


def evaluate_rpn(rpn):
    stack = []

    for sym in rpn:
        if sym.lstrip('-').isdigit():  # Учитываем отрицательные числа
            stack.append(int(sym))
        else:
            b = stack.pop()
            a = stack.pop()

            if sym == '+':
                stack.append(a + b)
            elif sym == '-':
                stack.append(a - b)
            elif sym == '*':
                stack.append(a * b)
            elif sym == '/':
                if b == 0:
                    raise ZeroDivisionError("Деление на ноль")
                stack.append(a / b)

    return stack[0]


def evaluate_expression(mth_ex):
    mth_ex = mth_ex.replace('=', '')

    if not is_brackets_correct(mth_ex):
        print("Некорректные скобки в выражении")
        return

    try:
        rpn = to_polish(mth_ex)
        result = evaluate_rpn(rpn)
        print("Ответ:", result)
    except ZeroDivisionError as e:
        print(e)
    except Exception as e:
        print("Ошибка:", e)


if __name__ == '__main__':
    expression = input("Введите пример: ")
    evaluate_expression(expression)
