-- store expressions after function guards
bmiTell :: Double -> Double -> String
bmiTell weight height
    | bmi <= 18.0 = "Underweight"
    | bmi <= 25.0 = "Healthy Weight"
    | bmi <= 30.0 = "Overweight"
    | otherwise   = "Obese"
    where bmi = weight / height ^ 2

-- can define multple variables with where
-- need to  define in the same column, same as fsharp, whitespace matters
bmiTell' :: Double -> Double -> String
bmiTell' weight height
    | bmi <= skinny = "Underweight"
    | bmi <= normal = "Healthy Weight"
    | bmi <= fat    = "Overweight"
    | otherwise     = "Obese"
    where bmi    = weight / height ^ 2
          skinny = 18.0
          normal = 25.0
          fat    = 30.0

-- where bindings are limited to only one function body
-- cannot be shared between function body definitions

-- can use pattern matching within the where block
initials :: String -> String -> String
initials firstName lastName = [f] ++ ". " ++ [l] ++ "."
    where (f:_) = firstName
          (l:_) = lastName

-- can also define functions in where block
calcBmis :: [(Double, Double)] -> [Double]
calcBmis xs = [bmi w h | (w, h) <- xs]
    where bmi weight height = weight / height ^ 2
