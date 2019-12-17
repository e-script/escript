# Escript

## Introduction

Escript is a scripting language which will support oop but much simpler and has no keyword

## Current supported platform

- Linux 64-bit

## Installation

1. Download latest release at here: [Releases](https://github.com/e-script/escript/releases)
2. Extract:

   `tar -xzvf escript-v0.0.11.tar.gz`

3. Copy escript to /usr/local/bin:

   `sudo cp dist/Release/GNU-Linux/escript /usr/local/bin/`

4. To run the script `samples/sample0.e`:

   `escript samples/sample0.e`

## Building blocks

### Primitive data types

- number
- string

### Set

Set is a sequence of expressions.

```
    teacher = 0
    student = 1
    unknown -1
    jobs = {
        teacher = teacher
        student = student
        unknown = unknown
    }
```

```
    levels = {
        fresher = 0
        junior = 1
        senior = 2
    }
```

### Map matrix to matrix

```
    map = [1, 2] -> [3 + 4, 5 - 6]
    map2 = [map(1), map(2)] -> [7 * 8, 9 / 10]
```

`->` is actually a binary operator, two sides of `->` are two matrix operands.

### Map set to set: function

```
    sum = { a = 0 b = 0 } -> {
        result = a + b
    }
```

Two sides of `->` are two set operands.

The first set is parameter set. The second set is body set.

`result` is a predefined variable help store the return value.

### Invoke map

```
    result = map2(7)                The result should be 56
    result = sum(2, 3)              The result should be 5
    result = sum(map(1), map(2))    The result should be 6
```

### Class

```
    Student = {
        name = "Default name"
        age = 0,
        job = jobs.unknown
        init = { name = string age = char } -> {
            parent.name = name
            parent.age = age
        }
    }
```

`parent` is predefined variable which target Student instance in this case.

There is no class or object in escript, but you can clone any set

```
    clone = escript.clone

    bob = clone(Student) bob.init("Bob", 23)
    alice = clone(Student) alice.init("Alice", 22)

    notBob = clone(bob) notBob.init("Not Bob", 23)
    notBob.job = jobs.teacher
```

#### Polymorphism

```
    for = escript.for
    printf = stdio.printf

    Animal = {
        name = string
        foots = char
        shout = {} -> {}
    }

    Dog = Animal + {
        shout = {} -> {
            printf('Where is the cat!')
        }
    }

    Cat = Animal + {
        shout = {} -> {
            printf('Who let the dog out!')
        }
    }

    animals = [clone(Dog) clone(Cat)]
    i = 0
    for (i < animals.size, i += 1, {animal} -> { animal.shout() })
```

escript and stdio are predefined sets. Documentation on predefined set
is located at [Predefined Sets][https://github.com/e-script/escript/docs/predefined_sets.md]

### Semicolon `;` and comma `,`

Return, Newline, Tab, Feed, Space, Semicolon and Comma
are all considered `space` and are bypassed by the interpreter.

## Operators

* Assignment operator

```
    i = 1
    pi = -3.14
    s = 'escript'
```

* Mapping operator

```
    names = [0, 1, 2] -> ['bob', 'alice', 'deadpool']
    sum = { a = 0, b = 2 } -> {
        result = a + b
    }
```

* Arithmatic operator: `+`, `-`, `*`, `/`

* Execution order: mapping first -> then `*`, `/` -> then `+`, `-` -> then assignment

## Comment

You just type the comment directly into source code.

```
    This function calculate the sum of two number
    sum = { a = 0, b = 0 } -> {
        result = a + b
    }
    sum(1, 2)
```

## Development

Requirements: GCC compiler - Ansi C (C89)

1. Clone git repo:

   `git clone https://github.com/e-script/escript`

2. Make:

   `cd escript`

   `make CONF=Release`

3. The executable is located at `dist/Release/GNU-linux/`

4. Verbose mode: escript will show code explanation at runtime

   `make CONF=Verbose`

> This project is originally developed via Netbeans version 8.1
