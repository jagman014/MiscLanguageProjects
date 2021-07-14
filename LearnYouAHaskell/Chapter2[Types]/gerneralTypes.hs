-- in ghci can get explicit type with ":t"
'a' :: Char
True :: Bool
"HELLO!" :: String -- [Char]
(True, 'a') :: (Bool, Char)
4 == 5 :: Bool

-- function type declarations
removeNonUppercase :: [Char] -> [Char]
removeNonUppercase st = [c | c <- st, c `elem` ['A'..'Z']]

-- multiple inputs shown with multiple arrows
-- addThree :: Int -> Int -> Int -> Int
addThree :: Num a => a -> a -> a -> a
addThree x y z = x + y + z
