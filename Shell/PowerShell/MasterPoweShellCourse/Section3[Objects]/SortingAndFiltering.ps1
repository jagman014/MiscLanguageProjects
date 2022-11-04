$files = Get-ChildItem

# sorting
$files | Sort-Object -Property Length -Descending

Write-Output ""

# filtering
$files | Where-Object Length -gt 250

Write-Output ""

$files | Where-Object Name -like "S*"

# braces and $_ used to loop through collection
$files | Where-Object {($_.Length -gt 200) -and ($_.Name -like "S*")}
