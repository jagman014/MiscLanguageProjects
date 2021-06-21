-- lengths of sides are ints
-- length of each side <= 10
-- perimeter = 24

-- all possible triples
triples = [(a, b, c) | c <- [1..10], a <- [1..10], b <- [1..10]]
-- length list = 1000 tuples

-- filter right triangles
rightTriangles = [
                (a, b, c) | 
                c <- [1..10], a <- [1..c], b <- [1..a], 
                a^2 + b^2 == c^2
                ]
-- [(4, 3, 5), (8, 6, 10)]

-- filter perimeter = 24
rightTriangles' = [
                (a, b, c) | 
                c <- [1..10], a <- [1..c], b <- [1..a], 
                a^2 + b^2 == c^2,
                a + b + c == 24
                ]
-- [(8, 6, 10)]
