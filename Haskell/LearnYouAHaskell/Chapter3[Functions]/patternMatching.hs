-- can write different function bodies for different patterns
-- patterns checked from top to bottom
lucky :: Int -> String
lucky 7 = "Lucky number seven"
lucky x = "Sorry no luck" -- default case is required to avoid exhaustion error

-- more efficient than if/then/else trees
sayMe :: Int -> String
sayMe 1 = "One"
sayMe 2 = "Two"
sayMe 3 = "Three"
sayMe 4 = "Four"
sayMe 5 = "Five"
sayMe x = "Not between 1 and 5"

-- recusive factorial function
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

-- tuple pattern matching

-- previous attempt
addVectors :: (Double, Double) -> (Double, Double) -> (Double, Double)
addVectors a b = (fst a + fst b, snd a + snd b)

-- matching attempt
addVectors' :: (Double, Double) -> (Double, Double) -> (Double, Double)
addVectors' (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

-- can create fst, snd equivalents for triples
first :: (a, b, c) -> a
first (x, _, _) = x -- underscore wildcard

second :: (a, b, c) -> b
second (_, y, _) = y

third :: (a, b, c) -> c
third (_, _, z) = z

-- lists and list comprehensions

xs = [(1, 3), (4, 3), (2, 4), (5, 3), (5, 6), (3, 1)]
[a + b | (a, b) <- xs] -- [4, 7, 6, 8, 11, 4]
-- tuple in pattern match, failed matches are skipped

head' :: [a] -> a
head' [] = error "Can't call head on empty list"
head' (x:_) = x -- use of list slice in pattern match to get first item
-- need () to bind multiple values

tell :: (Show a) => [a] -> String
tell [] = "The list is empty"
tell (x:[]) = "The list has one element: " ++ show x -- could be rewitten as [x]
tell (x:y:[]) = "The list has two elements: " ++ show x ++ " and " ++ show y -- could be rewitten as [x, y]
tell (x:y:_) = "This list is long. The first two elements are: " ++ show x ++ " and " ++ show y

-- as patterns
-- reference pattern as variable
firstLetter :: String -> String
firstLetter "" = "Empty string"
firstLetter all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]
