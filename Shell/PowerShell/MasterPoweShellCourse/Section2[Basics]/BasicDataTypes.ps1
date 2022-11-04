# can do arithmetic
Write-Output (1 + 2)

# assign variables with $ prefix
$a = 1 + 2

# get info of varaible, infered type int
# $a | Get-Member

Write-Output $a

$a += 1
Write-Output $a

$a = "This is a string"
# $a | Get-Member

# now has string methods
Write-Output $a.Length, $a.Substring(0, 5)

$b = 'Jag'

# auto expand expressions with ""
$a = "My name is $b"

Write-Output $a

# literal string with ''
$a = 'My name is $b'

Write-Output $a
