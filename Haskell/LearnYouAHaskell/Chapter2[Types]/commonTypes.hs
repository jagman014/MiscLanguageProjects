-- Int and Integer
-- Int is bounded by -2^(63) to 2^(63)
-- Integer is unbounded
factorial :: Integer -> Integer
factorial n = product [1..n]

-- Float real floating-point with single precision
circumference :: Float -> Float
circumference r = 2 * pi * r

-- Double is a float with double precision
circumference' :: Double -> Double
circumference' r = 2 * pi * r

-- Bool for booleans -> True or False
-- Char represents a unicode char in single quotes
-- String list of Chars, double quotes
