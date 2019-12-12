a = 5
b = 6
add = (a, b) {
    result = a + b
}

Animal = {
    name = string,
    weight = float,
    shout = () {
        write('Hello World\n');
    }
}

result = {
    add,
    Animal
}