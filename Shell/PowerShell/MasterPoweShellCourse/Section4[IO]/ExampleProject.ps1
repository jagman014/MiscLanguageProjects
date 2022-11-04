$names = Import-Csv .\Census1000.csv

$names | Get-Member

# get names with highest percentage hispanic
($names | Sort-Object -Property pcthispanic -Descending)[0..10].name

$names | Sort-Object -Property pcthispanic -Descending | Select-Object -First 10 | Format-Table -Property name

# get top using foreach
$names | ForEach-Object {if($_.pcthispanic -gt $highest.pcthispanic){$highest = $_}}
$highest.name
