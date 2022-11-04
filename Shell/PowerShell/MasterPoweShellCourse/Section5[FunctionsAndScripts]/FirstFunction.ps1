# define with function keyword
function Add-Numbers {
    # define parameters and explicit type
    param ([int]$num1, [int]$num2)
    return $num1 + $num2
}

# add params with spaces (like F#)
Add-Numbers 1 3

# can explicitly define params with -
Add-Numbers -num1 3 -num2 5

# can assign function results to variables
$result = Add-Numbers 1 2
$result += Add-Numbers 3 4
$result
