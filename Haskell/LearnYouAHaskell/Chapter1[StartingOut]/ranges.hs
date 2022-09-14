-- range od numbers [start..end]
[1..20]
['a'..'z']

-- can specify a step size as well
-- [first, next..end]
[2, 4..20]
[3, 6..20]

-- need to specify step to get reversed range
[20, 19..1]

-- can specify the amount or use an infinite list
[13, 26..24 * 13]
take 24 [13, 26..]

-- long lists
take 10 (cycle [1, 2, 3]) -- will repeat list infinitely
take 12 (cycle "LOL ")
take 20 (repeat 5) -- repeats element infinitely
replicate 3 10 -- alternatively use replicate n element
