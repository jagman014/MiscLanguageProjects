-- allow for the storage of heterogeneous elements
-- tuples have a fixed size
(1, 3)
(3, 'a', "hello")

-- [(1, 2), (8, 11, 5), (4, 5)], won't work
-- pairs and triples are distinct tuple types

-- [(1, 2), ("One", 2)], won't work
-- different data types give different types of tuples

-- using pairs
fst (8, 11) -- returns first value of tuple, 8
fst ("Wow", False) -- "Wow"

snd (8, 11) -- returns the second value, 11
snd ("Wow", False) -- False

zip [1, 2, 3, 4, 5] [5, 5, 5, 5, 5] -- produces a list of pairs
-- [(1, 5), (2, 5), (3, 5), (4, 5), (5, 5)]
-- will only give a length of the smaller list
zip [5, 3, 2, 6, 2, 7, 2, 5, 4, 6, 6] ["im", "a", "turtle"]
-- [(5, "im"), (3, "a"), (2, "turtle")]

-- can also zip infinite lists due to haskell being lazy
zip [1..] ["apple", "orange", "cherry", "mango"]
-- [(1, "apple"), (2, "orange"), (3, "cherry"), (4, "mango")]
