a = 5
b = 6
set = {
    a = 7
    b = 9
    sum = { a = 0, b = 0 } -> {
        result = a + b
    }
}
tmp = set
set.a = 10
set.b = 11
set.c.d.e.f = 99
result = a + tmp.b + set.c.d.e.f