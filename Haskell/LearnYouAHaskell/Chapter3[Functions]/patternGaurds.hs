-- use guards with pattern matching to check condition and increase readability
bmiTell :: Double -> String
bmiTell bmi
    | bmi <= 18.5 = "Underweight" -- like fsharp, | bool = output
    | bmi <= 25.0 = "Healthy weight"
    | bmi <= 30.0 = "Overweight"
    | otherwise = "Obese"

-- can take multiple params
bmiTell' :: Double -> Double -> String
bmiTell' weight height
    | weight / height ^ 2 <= 18.5 = "Underweight"
    | weight / height ^ 2 <= 25.0 = "Healthy weight"
    | weight / height ^ 2 <= 30.0 = "Overweight"
    | otherwise                   = "Obese"

-- reduces amount needed to write
max' :: (Ord a) => a -> a -> a
max' a b
    | a <= b = b
    | otherwise = a

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
    | a == b = EQ
    | a <= b = LT
    | otherwise = GT
