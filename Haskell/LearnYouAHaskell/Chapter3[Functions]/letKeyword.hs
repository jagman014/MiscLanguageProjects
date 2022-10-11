-- local variable binding, dont span guards
cylinder :: Double -> Double -> Double
cylinder r h =
    let sideArea = 2 * pi * r * h
        topArea = pi * r ^ 2
    in sideArea + 2 * topArea

-- let expressions return a value, can be used anywhere
4 * (let a = 9 in a + 1) + 2 -- 42

-- can introduce function into local scope
[let square x = x * x in (square 5, sqaure 3, square 2)] -- [(25, 9, 4)]

-- can be separated by ; inline
(let a = 100; b = 200; c = 300 in a * b * c, let foo = "Hey "; bar = "there!" in foo ++ bar)
-- (6000000, "Hey there!")

-- can dismantle tuples easily with pattern matching
(let (a ,b, c) = (1, 2, 3) in a + b + c) * 100 -- 600

-- can also be used in list comprehensions
calcBmis :: [(Double, Double)] -> [Double]
calcBmis xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2]

-- can still filter within the comprehension
-- let expression cannot be referenced in the generator, but can in the other parts
calcBmis' :: [(Double, Double)] -> [Double]
calcBmis' xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2, bmi > 25.0]
