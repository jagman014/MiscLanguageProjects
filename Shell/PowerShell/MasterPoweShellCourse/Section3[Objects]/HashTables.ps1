# collection of key value pairs using @{}
$empNumbers = @{
    "John Doe" = 112233;
    "Bob Jones" = 223344;
    "Sally Smith" = 334455
}

Write-Output $empNumbers

# access using key name
Write-Output `n $empNumbers["John Doe"]
$empNumbers["Bob Jones"] = 998877
$empNumbers["New Name"] = 556677

Write-Output `n $empNumbers

# remove from hash table
$empNumbers.Remove("New Name")
Write-Output `n $empNumbers
