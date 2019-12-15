# Escript - building blocks

## Primitive data types

* char
* byte
* int

## Set

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

## Map matrix to matrix

    ```
        map = [1, 2] -> [3 + 4, 5 - 6]
        map2 = [map(1), map(2)] -> [7 * 8, 9 / 10]
    ```

    `->` is actually a binary operator, two sides of `->` are two matrix operands.

## Map set to set: function

    ```
        sum = { a = 0 b = 0 } -> {
            result = a + b
        }
    ```

    Two sides of `->` are two set operands.
    The first set is parameter set. The second set is body set.

## Invoke map

    ```
        result = map2(7)
        result = sum(2, 3)
        result = sum(map(1), map(2))
    ```

## Class

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

    `parent` is special variable target Student instance.

    There is no class in escript, but you can clone any set

    ```
        bob = clone(Student) bob.init("Bob", 23)
        alice = clone(Student) alice.init("Alice", 22)
        
        notBob = clone(bob) notBob.init("Not Bob", 23)
        notBob.job = jobs.teacher
    ```

### Polymorphism

    ```
        for = escript.for
        { printf } = stdio

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