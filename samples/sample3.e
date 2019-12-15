'import function'
( printf ) = stdio

'projection'
map1 = { 1, 2 } -> { 3 + 4, 5 - 6 }
a = map1(1)
b = map1(2)
map2 = { a, b } -> { 7 * 8, 9 / 10 }

printf("result of 1 + 2 is: %d\n", project2(3))


'function is a customized projection'
add = ( a, b ) -> {
    result = a + b
}