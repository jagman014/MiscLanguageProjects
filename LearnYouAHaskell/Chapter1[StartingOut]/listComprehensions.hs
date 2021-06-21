-- creating a list
-- [function | x <- [set of values], condition]
[x * 2 | x <- [1..10]]

[x * 2 | x <- [1..10], x * 2 >= 12]

[x | x <- [50..100], x `mod` 7 == 3]

boomBangs xs = [if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]

[x | x <- [10..20], x /= 13, x /= 15, x /= 19]

-- multiple sources, result in elemental loops
[x + y | x <- [1, 2, 3], y <- [10, 100, 1000]]
-- [11, 101, 1001, 12, 102, 1002, 13, 103, 1003]
-- [x1 y1, x1 y2, ... x1 yn, x2 y1 ... xn yn]

nouns = ["hobo", "frog", "pope"]
adjectives = ["lazy", "grouchy", "scheming"]
[adjective ++ " " ++ noun | adjective <- adjectives, noun <- nouns]

-- can use to make a similar length function
length' xs = sum [1 | _ <- xs] -- _ is a temporary value, don't care what value is

-- can work with string elements
removeNonUpperCase st = [c | c <- st, c `elem` ['A'..'Z']]

-- nested list comprehensions
xxs = [
    [1, 3, 5, 2, 3, 1, 2, 4, 5],
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 4, 2, 1, 6, 3, 1, 3, 2, 3, 6]
    ]

[[x | x <- xs, even x] | xs <- xxs]
