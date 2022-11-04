# import format command
$names = Import-Csv .\Census1000.csv

$names | Format-Table

# custom object with properties for each column
$names | Get-Member
