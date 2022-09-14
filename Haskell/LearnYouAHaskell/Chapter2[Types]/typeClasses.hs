-- type classes define the type of type variables
-- :t (==)
(==) :: Eq a => a -> a -> Bool

-- everything before => is a class constraint
-- not the same as classes in OOP

-- Eq type class
-- used for types that support equality testing
5 == 5 -- True
5 /= 5 -- False
'a' == 'a' -- True
"Ho Ho" == "Ho Ho" -- True
3.432 == 3.432 -- True

-- Ord type class
-- of orderable values
-- :t (>)
(>) :: Ord a => a -> a -> Bool

"Abrakadabra" < "Zebra" -- True
"Abrakadabra" `compare` "Zebra" -- LT
5 >= 2 -- True
5 `compare` 3 -- GT
'b' > 'a' -- True

-- Show type class
-- can be represented as strings
show 3 -- "3"
show 5.334 -- "5.334"
show True -- "True"

-- Read type class
-- opposite of show type, reads strings to value
-- :t read
read :: Read a => String -> a

read "True" || False -- True
read "8.2" + 3.8 -- 12.0
read "5" - 2 -- 3
read "[1, 2, 3, 4]" ++ [3] -- [1, 2, 3, 4, 3]

-- cant use read on its own as it won't know what to return
-- can use with a type annotation

read "5" :: Int -- 5
read "5" :: Float -- 5.0
(read "5" :: Float) * 4 -- 20.0
read "[1, 2, 3, 4]" :: [Int] -- [1, 2, 3, 4]
read "(3, 'a')" :: (Int, Char) -- (3, 'a')

-- can use homogeneity of lists to infer type
[read "True", False, True, False] -- [True, False, True, False]

-- Enum type class
-- sequentially ordered types: 
        -- (), Bool, Char, Ordering, Int, Integer, Float, Double
['a'..'e'] -- "abcde"
[LT .. GT] -- [LT, EQ, GT]
[3..5] -- [3, 4, 5]

-- Bounded type class
-- have an upper and lower bound
minBound :: Int -- -9223372036854775808
maxBound :: Char -- '\1114111'
maxBound :: Bool -- True
minBound :: Bool -- False

-- tuples of bounded types are bounded
maxBound :: (Bool, Int, Char) -- (True, 9223372036854775807, '\1114111')

-- Num type class
-- numerics: Int, Integer, Float, Double
-- :t 20
20 :: Num p => p

20 :: Int -- 20
20 :: Integer -- 20
20 :: Float -- 20.0
20 :: Double -- 20.0

-- :t (*)
(*) :: Num a => a -> a -> a

-- Floating type class
-- Float and Double
-- :t (sqrt)
(sqrt) :: Floating a => a -> a

-- Integral type class
-- Int and Integer
-- :t fromIntegral
fromIntegral :: (Integral a, Num b) => a -> b
length :: [a] -> Int

fromIntegral (length [1, 2, 3, 4]) + 3.2 -- 7.2
