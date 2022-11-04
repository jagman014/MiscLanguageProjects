# equality
Write-Output (12 -eq 37)

# not equal
Write-Output (12 -ne 37)

# greater than
Write-Output (12 -gt 37)

# less than
Write-Output (12 -lt 37)

# greater than or equal
Write-Output (12 -ge 37)

# less than or equal
Write-Output (12 -le 37)

$a = "a"
$b = "b"

Write-Output ($a -ne $b)
Write-Output ($a -lt $b)

# comparisons are case insensitve, unless specified with "c"
Write-Output ("a" -eq "A")
Write-Output ("a" -ceq "A")

# can use wild cards with -like
# * any amount, ? one and only one
Write-Output ("Apple" -like "A*")
Write-Output ("Apple" -like "A*")
Write-Output ("Apple" -like "A??le")

# match substring
Write-Output ("My name is Jag" -match "Jag")
