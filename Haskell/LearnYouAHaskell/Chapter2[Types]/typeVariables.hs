-- type variables can be of any type
-- :t head
head :: [a] -> a

-- functions that use type variables are polymorphic functions
-- can have multiple type variables
-- normally labelled as a, b, c, ...
-- :t fst
fst :: (a, b) -> a
