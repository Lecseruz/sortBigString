import hello

def sort(str, memory):
    i = 0
    if len(str) > memory:
        print "error"
        return
    if len(str) * 2 <= memory:
        text = sorted(str);
        str = ""
        for i in text:
            str += i
        return str

    j = 1
    while i < len(str):
        if (i + memory / 2) > len(str):
            create_file(str[i:len(str)], j)
        else:
            create_file(str[i:i + memory / 2], j)
        i += memory / 2
        j += 1
    str = hello.create_string_from_fileschar(j)
    return str


class Inp:
    def __init__(self, value, file):
        self.file = file
        self.value = value
        return

    def __cmp__(self, other):
        return cmp(self.value, other.value)


def create_file(line, name):
    file = open(str(name) + '.txt', 'w')
    file.write(line)
    file.close()
    sort_file(name)


def sort_file(name):
    file = open(str(name) + '.txt', "rw")
    text = file.read()
    line = sorted(text)
    file.close()
    i = 0
    text = ""
    while i < len(line):
        text += line[i]
        i = i + 1
    file = open(str(name) + ".txt", "w")
    file.write(text)
    file.close()
    return line


def create_string_from_files(count):
    import Queue as Q

    q = Q.PriorityQueue()
    line = ""
    i = 1
    while i < count:
        fin = open(str(i) + ".txt", "r")
        q.put(Inp(fin.read(1), fin))
        i += 1
    while not q.empty():
        inp = q.get()
        line += inp.value
        value = inp.file.read(1)
        if value == "":
            inp.file.close()
        else:
            q.put(Inp(value, inp.file))
    return line


if __name__ == '__main__':
    line = "casnbfghfhg"
    print sort(line, 20)

