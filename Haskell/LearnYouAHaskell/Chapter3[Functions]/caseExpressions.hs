-- can use pattern matching within case expressions
head' :: [a] -> a
head' xs = case xs of [] -> error "Empty list"
                      (x:_) -> x

{-
case <expression> of <pattern> -> <result>
                     <pattern> -> <result>
                     <pattern> -> <result>
                     ...
-}

-- returns a value, can be used anywhere
describeList :: [a] -> String
describeList ls = "The list is " ++ case ls of [] -> "empty"
                                               [x] -> "a singleton"
                                               xs -> "a long list"
