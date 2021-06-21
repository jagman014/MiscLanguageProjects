-- function syntax similar to execution
doubleMe x = x + x

-- doubleUs x y = x * 2 + y * 2
-- functions can call other functions
doubleUs x y = doubleMe x + doubleMe y

-- if expression must return a value, therefore else if maditory
doubleSmallNumber x = if x > 100
                        then x
                        else x * 2

-- ' used to denote modified function
doubleSmallNumber' x = (if x > 100 then x else x * 2) + 1
