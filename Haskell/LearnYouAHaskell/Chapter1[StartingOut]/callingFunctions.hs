-- arithmetics are infix functions
-- most functions are prefix
succ 8 -- 9
min 9 10 -- 9
min 3.4 3.2 -- 3.2
max 100 101 -- 101

succ 9 + max 5 4 + 1 -- 16
(succ 9) + (max 5 4) + 1 -- 16

succ (9 * 10) -- 91

-- can make prefix function infix with ``
div 92 10 -- 9
92 `div` 10 -- 9
