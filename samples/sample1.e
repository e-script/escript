{ if } = escript

min = (a, b) {
    result = if(a < b, a, b)
}

min2 = (a, b) {
    result = if(() {
            result = a < b
        }, () {
            result = a
        }, () {
            result = b
        })
}

result = {
    min, min2
}