-- lists are homogeneous data structures, must be of the same type
lostNumbers = [4, 8, 15, 16, 23, 42]

-- concatination
[1, 2, 3, 4] ++ [9, 10, 11, 12]
"hello" ++ " " ++ "world"
['w', 'o'] ++ ['o', 't']

-- : operator adds to the start of the list
'A':" SMALL CAT"
5:[1, 2, 3, 4, 5]

-- accessing elements, 0 indexed
"Steve Buscemi" !! 6
[9.4, 33.2, 96.2, 11.2, 23.25] !! 1

-- lists of list
b = [[1, 2, 3, 4], [5, 3, 3, 3], [1, 2, 2, 3, 4], [1, 2, 3]]
b ++ [[1, 1, 1, 1]]
[6, 6, 6]:b
b !! 2

-- comaparisons done element by element, 
-- only returning on first True for <, >, <=, >= if elements are equal
[3, 2, 1] > [2, 1, 0] -- True
[3, 2, 1] > [2, 10, 100] -- True
[3, 4, 2] < [3, 4, 3] -- True
[3, 4, 2] > [2, 4] -- True
[3, 4, 2] == [3, 4, 2] -- True
-- empty list is always smaller

-- list operations
head [5, 4, 3, 2, 1] -- first element, 5
tail [5, 4, 3, 2, 1] -- everything but the head, [4, 3, 2, 1]
last [5, 4, 3, 2, 1] -- last element, 1
init [5, 4, 3, 2, 1] -- everythin but the last, [5, 4, 3, 2]
length [5, 4, 3, 2, 1] -- length of list, 5
null [1, 2, 3] -- checks if list is empty
reverse [5, 4, 3, 2, 1] -- reverses the list, [1, 2, 3, 4, 5]
take 3 [5, 4, 3, 2, 1] -- takes first n elements, [5, 4, 3]
drop 3 [8, 4, 2, 1, 5, 6] -- drops first n elements, [1, 5, 6]
maximum [1, 9, 2, 3, 4] -- 9
minimum [8, 4, 2, 1, 5, 6] -- 1
sum [5, 2, 1, 6, 3, 2, 5, 7] -- 31
product [6, 2, 1, 2] -- 24
4 `elem` [3, 4, 5, 6] -- is element in list, True
