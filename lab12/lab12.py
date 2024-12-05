main = "./src/input.txt"
supp1 = "./src/file1.txt"
supp2 = "./src/file2.txt"


def write(file, arr):
    with open(file, "a") as f:
        f.write(" ".join(map(str, arr)))
        f.write('\n')


def clean(file):
    with open(file, "w") as clear:
        pass


def is_simple(file):
    with open(file, "r") as f:
        counter = 0
        for line in f:
            counter += 1
            if counter > 1:
                return False
    return True


def arr_merge(arr1, arr2, file):
    arr = []
    len1, len2 = len(arr1), len(arr2)
    i, j = 0, 0
    while i < len1 and j < len2:
        if arr1[i] <= arr2[j]:
            arr.append(arr1[i])
            i += 1
        else:
            arr.append(arr2[j])
            j += 1
    if i != len1:
        arr += arr1[i:len1]
    if j != len2:
        arr += arr2[j:len2]
    write(file, arr)


def partition():
    clean(supp1)
    clean(supp2)
    with open(main, "r") as nums:
        prev = int(nums.readline())
        subsq = [prev]
        for num in nums:
            num = int(num)
            if num >= prev:
                subsq.append(num)
            else:
                write(supp1, subsq)
                subsq = [num]
            prev = num
        write(supp1, subsq)


def file_merge(inp_f, out_f):
    clean(out_f)
    with open(inp_f, "r") as file:
        odd = True
        for line in file:
            if odd:
                prev = line
            else:
                arr_merge(list(map(int, prev.split())), list(map(int, line.split())), out_f)
            odd = not odd
        if not odd:
            write(out_f, list(map(int, prev.split())))


if __name__ == '__main__':
    partition()
    i = 0
    while True:
        inp_f = (supp1, supp2)[i % 2]
        out_f = (supp1, supp2)[(i + 1) % 2]
        file_merge(inp_f, out_f)
        if is_simple(out_f):
            break
        i += 1
    print("Ответ лежит в файле: ", out_f)
